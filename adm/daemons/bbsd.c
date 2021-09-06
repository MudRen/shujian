//Զ���ϴ�����
//������bbs
// Ciwei@SJ 31/3/04
// add ErRoR msg 28/4/04
// add bbs_post to post in bbs by Ciwei@SJ 5/8/2004
// /include/board.h /inherit/misc/bboard.c
inherit F_SAVE;

#include <database.h>
#include <mudlib.h>
#include <net/socket.h>
#include <socket_err.h>

//#define UNIQUE_SERVER_ADDR	"202.100.222.243 80"
#define UNIQUE_SERVER_ADDR	"127.0.0.1 80"
#define UNIQUE_SERVER_FILE	"POST /mud_obj/update_bbs.php"
#define UPDATE_TIME	120
//some about explode
#define EXPLODE_F "}),"
#define EXPLODE_S ","
#define REPLACE_STR "##"
#define REPLACE_STR_ADD ""
#define MAX_SIZE 1300


#define NEW_VERSION "1.0"

void over_set(int fb);
protected string get_read_data(string str);

mapping Bbs_Up_Map;
nosave int debug = 0;

public string query_version(object ob)
{
	if(ob==find_object(BBS_D)) return NEW_VERSION;
}

void create()
{
	seteuid(getuid());
	//restore();
	if(!Bbs_Up_Map) Bbs_Up_Map =([]);
	call_out("update_time",UPDATE_TIME);
	call_out("update_pool",0);
}

string query_save_file()
{
	return DATA_DIR+"bbsup";
}

int test_debug = 0;

int debug()
{
	test_debug = test_debug +1;
	if(test_debug>=2) test_debug = 0;
	return test_debug;
}
//������ϰ�ret������������ob->func(mixed ret)
//void test(mixed ret) Ϊ��������
int add_Bbs_Up_Map(string db,string sql,object ob,string fun,int forbid)
{
	int fd,result;
	
	//�Լ�����	
    if(!test_debug && INTERMUD_MUD_NAME=="SJTX" 
	&& previous_object()
	&& previous_object()!=find_object("/adm/daemons/bbsd.c")
	&& previous_object()!=find_object("/cmds/usr/news.c")
	&& previous_object()!=find_object("/cmds/arch/newucp.c")
	&& previous_object()!=find_object("/cmds/adm/bbs.c")
	&& !forbid
	) return 0;
		
	fd = socket_create(STREAM,"read_callback1","close_callback1");
	if (fd<0) {
		log_file("nosave/bbs", sprintf("error   :%15s:%5d:\n","socket_create",fd), 0);
		return 0;
	}

	if(previous_object() && previous_object()->query_version(this_object())!=NEW_VERSION)
	{
		//message("wizard",sprintf("��ע�⣺BBSD ���㱨�� %s ������Ҫ���°汾��\n",base_name(previous_object())) ,users());
	}
	
	sql = replace_string(sql,REPLACE_STR,"");
	sql = replace_string(sql,REPLACE_STR_ADD,"");
						
	sql = replace_string(sql,"'",REPLACE_STR);
	sql = replace_string(sql,"+",REPLACE_STR_ADD);
	Bbs_Up_Map[fd] = allocate_mapping(6);
	Bbs_Up_Map[fd]["database"] = db;
	Bbs_Up_Map[fd]["sql"] = sql;
	Bbs_Up_Map[fd]["time"] = time();	
	Bbs_Up_Map[fd]["ok"] = 0;
	//hehe
	if(ob) Bbs_Up_Map[fd]["object"] = ob;
	if(fun) Bbs_Up_Map[fd]["fun"] = fun;
	
	result = socket_connect(fd,UNIQUE_SERVER_ADDR,"read_callback2","write_callback2");
	
	if (result != EESUCCESS) {
		log_file("nosave/bbs", sprintf("error   :%15s:%5d:\n","socket_connect",result), 0);
		return 0;
	}	
	return fd;//����socket
}
/*
void write_callback2(int fd)
{
	string str = UNIQUE_SERVER_FILE,str2;
	int result;
	object me;
	
	str2 = "database="
		+Bbs_Up_Map[fd]["database"]
		+"&sql="
		+Bbs_Up_Map[fd]["sql"]
		+"&time="
		+Bbs_Up_Map[fd]["time"];
	str += " HTTP/1.0\r\n";
	str += "User-Agent: Mozilla/4.0 (compatible; MSIE 5.01; Windows 98)\r\n";
	str += "Content-Type: application/x-www-form-urlencoded\r\n";
	str += sprintf("Content-Length: %d\r\n",strlen(str2));
	str += "Cache-Control: no-cache\r\n";
	str += "\r\n";
	str += str2;
		
	if(debug) me = find_player("linux");
	if(me) tell_object(me,sprintf("write(%d): %s\n",fd,str));
	
	Bbs_Up_Map[fd]["ok"] = 1;
	result = socket_write(fd,str);	
	if ( result != EESUCCESS ) {
		log_file("nosave/bbs", sprintf("%-15serror: Ŀ�����ݿ�:%-8s�ύʱ�䣺%sSQL����:%s","socket_write",Bbs_Up_Map[fd]["database"],ctime(Bbs_Up_Map[fd]["time"]),Bbs_Up_Map[fd]["sql"]),0);
		over_set(fd);
		return;
	}
}
*/
int clear_zero(mixed str)
{
	return !intp(str);
}

void read_callback2(int fd, mixed message)
{
	string str;	
	object me;
	mixed ret;		
	
	Bbs_Up_Map[fd]["ok"] = 2;
	str = get_read_data(message);
	if(debug) me = find_player("linux");
	if(me) tell_object(me,sprintf("read(%d): %s\n",fd,str));
	//���󱨸� ��..
	if(sscanf(str,"OK%s",str)==1){
	//���سɹ�ʱcall_out
		if(str!=""){
			string* temp = explode(str,EXPLODE_F);
			ret = allocate(100);
			for(int i=0;i<sizeof(temp);i++)
				ret[i] = explode(temp[i],EXPLODE_S);
		}
		else ret = allocate(1);
		ret = filter_array(ret,(:clear_zero:));
		if(me) tell_object(me,sprintf("Str��%s\n",str));
		if(me) tell_object(me,sprintf("Ret��%O\n",ret));
		if(!undefinedp(Bbs_Up_Map[fd]["object"])&&!undefinedp(Bbs_Up_Map[fd]["fun"]))
		call_other(copy(Bbs_Up_Map[fd]["object"]),copy(Bbs_Up_Map[fd]["fun"]),ret);
	}
	else if(sscanf(str,"%sErRoR",str)==1)
	{
		message("wizard",sprintf("Զ�����ݿ����ʧ�� ��Ϊ��%s��\n",str),users());
		//over_set(fd);
		//destruct(this_object());
		//return;
	}
	over_set(fd);
}

//��������
void test(mixed ret)
{
	if(!ret) ret ="a?";
	CHANNEL_D->do_channel(this_object(),"rumor",sprintf("�õ���ret��%O", ret));
}

void over_set(int fb)
{
	socket_close(fb);
	map_delete(Bbs_Up_Map,fb);
}

protected string get_read_data(string str)
{
	string * tmp = explode(str , "\r\n\r\n");
	if( undefinedp(tmp) || undefinedp(tmp[1])) return "ErRoR";
	return tmp[1];
}

void read_callback1(int fd, mixed message){}

void close_callback1(int fd){}

void update_time()
{
	int* k;
	mapping temp;
		
	k = keys(Bbs_Up_Map);
	if(sizeof(k))
		for(int i=0;i<sizeof(k);i++)
			if(Bbs_Up_Map[k[i]]["ok"]<1){
				temp = copy(Bbs_Up_Map[k[i]]);
				over_set(k[i]);
				add_Bbs_Up_Map(temp["database"],temp["sql"],!undefinedp(temp["object"])?temp["object"]:0,!undefinedp(temp["fun"])?temp["fun"]:"",0);
			}
	save();
	call_out("update_time",UPDATE_TIME);
}
//////////////////////////////about bbs/////////////////////////

nosave mapping* bbs_info;
nosave int in_work=0;
nosave int this_post_is_not_reaply;

string get_data(string data,int part)
{
	string* parts;
	if(!data) return 0;
	do
	{
		if(sizeof(data)<MAX_SIZE)
		{
			if(!parts) parts=({data});
			else parts += ({data});
			data = "";
		}
		else
		{
			if(!parts) parts=({data[0..MAX_SIZE-1]});
			else parts += ({data[0..MAX_SIZE-1]});
			data = data[MAX_SIZE..<0];
		}
	}
	while (data!="");
	if(part > sizeof(parts)) return 0;	
	return parts[part-1];
}
/*
void update_pool()
{
	if(!in_work && bbs_info && sizeof(bbs_info))
	{
		///start work
		string sql;
		in_work=1;
		//have no tid mean need inseat one tread
		if(!bbs_info[0]["tid"])
		{
			this_post_is_not_reaply=1;
			sql = sprintf("PostTothreads INSERT INTO %s (fid, creditsrequire, icon, author, subject, dateline, lastpost, lastposter, topped, digest) VALUES ('%d', '0', '', '%s', '%s', '%d', '%d', '%s', '%d', '%d' )",BBS_THREADS,bbs_info[0]["fid"],bbs_info[0]["author"],bbs_info[0]["subject"],bbs_info[0]["time"],bbs_info[0]["time"],bbs_info[0]["author"],bbs_info[0]["topped"],bbs_info[0]["digest"] );
			add_Bbs_Up_Map(WEB_DB_NAME,sql,this_object(),"back_uid",0);
			call_out("failed",30);
		}
		else
		{
			//there can to be more power lazy ciwei
			//sql = sprintf("INSERT INTO %s (fid, tid, aid, icon, author, subject, dateline, message, useip) values ('%d', '%d', '0', '', '%s', '%s', '%d', '%s', '%s')",BBS_POSTS,bbs_info[0]["fid"],bbs_info[0]["tid"],bbs_info[0]["author"], bbs_info[0]["subject"],bbs_info[0]["time"],bbs_info[0]["message"],MUD_ADDR);
			if(bbs_info[0]["part"]==1) sql = sprintf("INSERT INTO %s (fid, tid, aid, icon, author, subject, dateline, message, useip) values ('%d', '%d', '0', '', '%s', '%s', '%d', '%s', '%s')",BBS_POSTS,bbs_info[0]["fid"],bbs_info[0]["tid"],bbs_info[0]["author"], bbs_info[0]["subject"],bbs_info[0]["time"],get_data(bbs_info[0]["message"],bbs_info[0]["part"]),MUD_ADDR);
			else sql = sprintf("UPDATE %s SET message=CONCAT(message,'%s') WHERE fid='%d' AND tid='%d' AND subject='%s' AND dateline='%d'",BBS_POSTS,get_data(bbs_info[0]["message"],bbs_info[0]["part"]),bbs_info[0]["fid"],bbs_info[0]["tid"],bbs_info[0]["subject"],bbs_info[0]["time"] );
			add_Bbs_Up_Map(WEB_DB_NAME,sql,this_object(),"post_ok",0);
			call_out("failed",30);
		}
	}
	call_out("update_pool",1);
}
*/
void failed()
{
	this_post_is_not_reaply=0;
	in_work=0;
}

void back_uid(mixed ret)
{
	remove_call_out("failed");
	if(!ret || !sizeof(ret)) return;
	in_work=0;
	if(!bbs_info || !sizeof(bbs_info)) return;
	bbs_info[0]["tid"]=atoi(ret[0][0]);//get tid
}

void post_ok(mixed ret)
{
	string sql;
	remove_call_out("failed");
	bbs_info[0]["part"]++;
	in_work=0;
	if(get_data(bbs_info[0]["message"],bbs_info[0]["part"])) return;//�����û������� �Ǽ���	
	sql = sprintf("UPDATE %s SET lastpost='%s', posts=posts+'1'",
		BBS_FORUMS,bbs_info[0]["subject"]+"\t"+bbs_info[0]["time"]+"\t"+bbs_info[0]["author"] );
	if(this_post_is_not_reaply) sql += ",threads=threads+'1'";	
	sql += sprintf(" WHERE fid='%d'",bbs_info[0]["fid"] );
	add_Bbs_Up_Map(WEB_DB_NAME,sql,0,0,0);
	
	if(!this_post_is_not_reaply)
	{
		sql = sprintf("UPDATE %s SET lastposter='%s', lastpost='%d', replies=replies+'1' WHERE tid='%d' AND fid='%d'",BBS_THREADS,bbs_info[0]["author"],bbs_info[0]["time"],bbs_info[0]["tid"],bbs_info[0]["fid"] );
		add_Bbs_Up_Map(WEB_DB_NAME,sql,0,0,0);
	}
	//add postnum but no credit
	sql = "UPDATE "+BBS_MEMBERS+" SET postnum=postnum+'1' WHERE username='"+bbs_info[0]["author"]+"'";
	add_Bbs_Up_Map(WEB_DB_NAME,sql,0,0,0);
	//postnum
	ret = ({({bbs_info[0]["tid"],})});
	if(!undefinedp(bbs_info[0]["object"])&&!undefinedp(bbs_info[0]["function"]))
		if( bbs_info[0]["function"] && bbs_info[0]["object"]  ) call_other(bbs_info[0]["object"],bbs_info[0]["function"],ret);
	if(sizeof(bbs_info)>1) bbs_info = bbs_info[1..<1];
	else bbs_info=0;
	this_post_is_not_reaply=0;
}

int bbs_post(int fid,string author,string subject,string message,int tid,int topped,int digest,object ob,string fun)
{
	//added to bbs_info
	
    if(!test_debug && INTERMUD_MUD_NAME=="SJTX" 
	&& previous_object()!=find_object("/cmds/usr/news.c") 
	&& previous_object()!=find_object("/cmds/arch/newucp.c")
	&& previous_object()!=find_object("/cmds/adm/bbs.c")
	) return 0;
				
	if(!bbs_info) bbs_info = ({});
	bbs_info +=
	({
		([
			"fid":fid,
			"author":author,
			"subject":subject,
			"message":message,
			"tid":tid,
			"topped":topped,
			"digest":digest,
			"object":ob,
			"function":fun,
			"time":time(),
			"part":1,
		])
	});
	
	return 1;
}
