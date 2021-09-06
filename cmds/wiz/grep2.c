// grep.c
// by augx@sj  10/18/2001

#define BUFFER_SIZE		1024
#define MAX_LINE_SIZE		1024
#define MAX_FILE_SIZE		550000
#define PAGE_LINE		20

inherit F_CLEAN_UP;
#include <ansi.h>
#include <localtime.h>

void searchdir(object me);
void searchstr(object me);
int mktime(int year,int mon,int day,int hour,int min,int sec);
int help(object me);

nosave int use = 0;
nosave mapping mp = ([ ]);
nosave string file = "";
nosave int location = 0;
nosave int line = 0;
nosave string buf = "";
nosave int show_dir = 0;
nosave int find_file = 0;
nosave int match_all = 0;
nosave int page_line = PAGE_LINE;
nosave int match_time = 0;

int main(object me, string arg)
{
	string cmd,dir,str,cwd="";
	string *cmds;
	int i;

	seteuid(geteuid(me));
	if ( !arg || 
	 ( sscanf(arg,"%s at %s %s",str,dir,cmd)<3 && sscanf(arg,"%s %s %s",str,dir,cmd)<3 &&
	   sscanf(arg,"%s at %s",str,dir)<2        && sscanf(arg,"%s %s",str,dir)<2 ) )
		return notify_fail("ָ���ʽ ��grep <�ַ���> <������Ŀ¼> [����]\n           grep <�ַ���> at <������Ŀ¼> [����]\n");
		
	if ( str=="InPuT" && dir=="iNpUt" && use ) {
		input_to("donext",me);
		return 1;
	}
	
	if( dir=="-t" && me->query("id")=="augx" ) {
		tell_object(me,sprintf("mp:\n%O\nfile:%s ,location:%d ,line:%d\nbuf:%s\n",mp,file,location,line,buf));
		return 1;
	}
	
	if( use ) return notify_fail("grep ָ������ʹ���У����Ժ����ԡ�\n");

	cwd = (string)me->query("cwd");
	if( file_size(dir)==-1 && file_size( (dir = cwd+dir) )==-1 ) {
		return notify_fail("û�����������Ŀ¼��\n");
	}
	else if( file_size(dir)==-2 ) {
		if ( dir[<1]!='/' ) dir += "/";
	}
	else if( file_size( cwd+dir )==-2 ) {
		dir = cwd + dir;
		if ( dir[<1]!='/' ) dir += "/";
	}

	show_dir = 0;
	find_file = 0;
	match_all = 0;
	match_time = 0;
	page_line = PAGE_LINE;
	if( stringp(cmd) && strlen(cmd)>0 ) {
		cmds = explode(cmd,"-");
		for(i=0;i<sizeof(cmds);i++) {
			if( strlen(cmds[i]) < 1 ) continue;
			cmds[i] = lower_case(cmds[i]);
			if( strsrch(cmds[i],"d",1) >= 0 )
				show_dir = 1;
			else if( strsrch(cmds[i],"f",1) >= 0 )
				find_file = 1;
			else if( strsrch(cmds[i],"u",1) >= 0 ) {
				match_all = 1;
				str = lower_case(str);
			}
			else if( strsrch(cmds[i],"p",1) >= 0 ) {
				sscanf(replace_string(cmds[i],"p",""),"%d",page_line);
				if(page_line<5) page_line=5;
			}
			else if( strsrch(cmds[i],"t",1) >= 0 ) {
				string * dt;
				int dy,dm,dd,th,tm,ts;
				int * nd;
				
				cmds[i] = replace_string(cmds[i],"t","");
				dt = explode(cmds[i],"|");
				if(sizeof(dt)<1) { 
					tell_object(me,"grep: ʱ���ʽ���󣬺���-t������\n"); 
					continue; 
				}
				if(sizeof(dt)==1) {
					if(sscanf(dt[0],"%d:%d:%d",th,tm,ts)<3) { 
						tell_object(me,"grep: ʱ���ʽ���󣬺���-t������\n");
						continue;
					}
					nd = localtime(time());
					dy = nd[LT_YEAR];
					dm = nd[LT_MON]+1;
					dd = nd[LT_MDAY];
				}
				else {
					if( sscanf(dt[0],"%d/%d/%d",dy,dm,dd)<3 || sscanf(dt[1],"%d:%d:%d",th,tm,ts)<3 ) {
						tell_object(me,"grep: ʱ���ʽ���󣬺���-t������\n"); 
						continue; 
					}
				}
				match_time = mktime(dy,dm,dd,th,tm,ts);
				//tell_object(me,sprintf("%d/%d/%d %d:%d:%d [%s]\n",dy,dm,dd,th,tm,ts,ctime(match_time)));
			}
		}
	}

	mp["str"] = str;
	mp["count"] = 0;
	mp["catch"] = 0;
	mp["timeout"] = (int)(eval_cost()/5);
	mp["dirs"] = ({ });
	mp["files"] = ({ });
	use = 1;
	if ( file_size(dir) == -2 )
		mp["dirs"] += ({ dir });
	else
		mp["files"] += ({ dir });
	searchdir(me);

	return 1;
}

int mktime(int year,int mon,int day,int hour,int min,int sec)
{
	if (0 >= (int) (mon -= 2)) {	/* 1..12 -> 11,12,1..10 */
		mon += 12;		/* Puts Feb last since it has leap day */
		year -= 1;
	}
	
	hour -= 8; // �й���ʱ��

	return ((( (year/4 - year/100 + year/400 + 367*mon/12 + day) + year*365 - 719499
		)*24 + hour /* now have hours */
		)*60 + min /* now have minutes */
		)*60 + sec; /* finally seconds */
}

void reset_grep()
{
	mp = ([ ]);
	file = "";
	location = 0;
	line = 0;
	buf = "";
	use = 0;
	show_dir = 0;
	find_file = 0;
	match_all = 0;
	match_time = 0;
	page_line = PAGE_LINE;
}

void searchdir(object me)
{
	int i,j,k;
	string *files,*files2;
	string dir;

	if( !use ) return;
	if( !me ) { reset_grep(); return; }
	
	if( sizeof(mp["files"]) ) {
		mp["catch"] = 0;
		dir = mp["files"][0];
		mp["files"] -= ({ dir });
		
		if( file_size(dir) <= MAX_FILE_SIZE ) {
			file = dir;
			location = 0;
			line = 1;
			buf = "";
			searchstr(me);
		}
		else
			searchdir(me);
	}
	else if( sizeof(mp["dirs"]) ) {
		dir = mp["dirs"][sizeof(mp["dirs"])-1];
		mp["dirs"] -= ({ dir });
		files = get_dir(dir);
		if(match_time) files2 = get_dir(dir,-1);
		
		if(show_dir) tell_object(me,GRN"[DIR: "+dir+"]\n"NOR);
		k = sizeof(files);
		for(i=0;i<k;i++) {		
			j = file_size( dir+files[i] );
			if( j == -1 ) continue;
			if( j == -2 )
				mp["dirs"]  += ({ dir+files[i]+"/" });
			else {
				if(!find_file)
					mp["files"] += ({ dir+files[i] });
				else {
					if( match_time ) {
						if( files2[i][2] >= match_time )
							tell_object(me,sprintf("%-35s : %s\n" , dir+files[i],ctime(files2[i][2])));
					}
					else {
						if( strsrch(files[i],mp["str"],1) >= 0 )
							tell_object(me,dir+files[i]+"\n");
					}
				}
			}
		}
		
		if(!find_file)
			searchdir(me);
		else {
			if( eval_cost() > mp["timeout"] )
				call_out("searchdir",0,me);
			else
				call_out("searchdir",1,me);
		}
	} 
	else {
		reset_grep();
		tell_object(me,"\n����������\n");
	}
}

void searchstr(object me)
{
	string * lines;
	int i,j,len,r;
	
	if( !use ) return;
	if( !me ) { reset_grep(); return; }
	
	len = file_size(file);
	while ( location < len ) {
		if ( (location+BUFFER_SIZE) > len )
			i = len - location;
		else 
			i = BUFFER_SIZE;

		buf += read_bytes(file,location,i);
		lines = explode(buf,"\n");
		location += i;
		
		if( buf[<1] != '\n' ) {
			buf = lines[sizeof(lines)-1];
			j = 1;
		}
		else {
			buf = "";
			j = 0;
		}
		if(sizeof(buf)>MAX_LINE_SIZE) buf = buf[0..<MAX_LINE_SIZE];
		
		j = sizeof(lines) - j;
		for (i=0;i<j;i++) {
			if(!match_all)
				r = strsrch(lines[i],mp["str"],1);
			else
				r = strsrch(lower_case(lines[i]),mp["str"],1);
			if( r >= 0 ) {
				if( !mp["catch"] ) {
					mp["catch"] = 1;
					tell_object(me,CYN"["+file+"]\n"NOR);
				}
				tell_object(me,sprintf("%d: ",line)+lines[i]+"\n");
				mp["count"]++;
			}
			line++;
		}
		
		if ( mp["count"] >= page_line ) {
			mp["count"] = 0;
			tell_object(me,"== δ����� == (ENTER ������һҳ��q �뿪)");
			me->force_me("grep2 InPuT iNpUt");
			return;
		}
		
		if( eval_cost() < mp["timeout"] ) {
			call_out("searchstr",1,me);
			return;
		}
	}
	
	if( eval_cost() > mp["timeout"] )
		call_out("searchdir",0,me);
	else
		call_out("searchdir",1,me);
	
	return;
} 

void donext(string arg,object me)
{
	if( !use ) return;
	if( !me ) { reset_grep(); return; }
	
	if( arg[0]!='q' && arg[0]!='Q' ) {
		call_out("searchstr",0,me);
	}
	else {
		tell_object(me,"\n��ѯ��ֹ��\n");
		reset_grep();
	}
}

int help(object me)
{
write(@HELP

�����޵���Ͱ� grep   
by augx@sj   10/19/2001

ָ���ʽ : grep <�ַ���> <������Ŀ¼> [����]
      ��   grep <�ַ���> at <������Ŀ¼> [����]
 
���ܣ��ڵ�����Ѱ��ָ�����ַ���������Ŀ¼��Ѱ��ָ�����ļ���

����˵����
    -f  Ѱ���ļ���
    -d  ��ʾ��������Ŀ¼
    -u  ��Сд�޹�
    -pd ��ҳ��ʾ��dΪÿҳ��ʾ�����У�ȱʡΪ20��
    -t  ����ʱ���������˲�������-f��������ʱ����Ч���ҽ���
        ���ļ�������ʽ��y/m/d|h:m:s�� ���û���������ڣ�ȱ
        ʡ����Ϊʱ��Ϊ���졣
        ���磺grep2 time / -f-t2001/10/18|20:11:25
              ���Ӹ�Ŀ¼��ʼ������������޸�ʱ������2001��
              10��18��20��11��25����ļ���

���ϲ������Ե���ʹ�ã����磺-d-u-p25

ע�⣺������ͬʱֻ��һ��ʹ�ã�ʹ�ñ���������ӵ�о����ĵ���
      Ŀ¼��һ����Σ���ԡ�
HELP
	);
	return 1;
}
