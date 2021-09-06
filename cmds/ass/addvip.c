// addvip.c 
// by LinuX@SJ 2004/02/18

#include <ansi.h>

#define VIP_FILE       "/data/vip"
#define NULL 0

inherit F_SAVE;

mapping *notes;
string query_save_file();
void list_viplist(object me, int num);
void search_viplist(object me, string arg, int flag);
void do_read(object me, int i);
int search_mail(string mail);
int search_player(string player,string site);


void create()
{
	seteuid(getuid());
	restore();
}

int main(object me, string arg)
{
	mapping note;
	string key;
	string player,mail;
	string site;
	string s;
	int num,renew,i,day;
	
	if (!arg) {
		list_viplist(me, 10);
		return 1;
	}
		
	if (sscanf(arg, "%d", num) == 1) {
		do_read(me,num);
		return 1;
	}
	
	if (sscanf(arg, "%s -p", key) == 1) {
		search_viplist(me,key,1);
		return 1;
	}
	
	if (sscanf(arg, "%s -m", key) == 1) {
		if (!stringp(key) || sscanf(key, "%*s@%*s.%*s") != 3) 
			return notify_fail("��Ҫ�����ĵ����ʼ���ַ���� \n");
		search_viplist(me,key,0);
		return 1;
	}
	
    	if (sscanf(arg, "%s", s) == 1) {
		if ( s == "all" ) {
			list_viplist(me,0);
			return 1;
		}
	}

	if (sscanf(arg, "%s %s %s %d", site, player, mail, day) == 4) {
		if (wiz_level(me)<4)
			return notify_fail("ֻ��arch�ſ��Խ��������VIP�ܹ��������� \n");
			
	   site = lower_case(site);
	   player = lower_case(player);
	    if ( site!="ln"&& site!="ln2" && site!="bx" && site!="ty" && site!="cq") 
           	 	return notify_fail("������LN,LN2,BX,TY,CQ�⼸��վ�����!\n");
	    if (!stringp(mail) || sscanf(mail, "%*s@%*s.%*s") != 3) 
			return notify_fail("�����ʼ���ַ���� \n");
		site = upper_case(site);
		i = search_mail(mail);
		if (i > 0) {
			write(" "+HIY+mail+NOR+" ��������ַ�Ѿ�����ʹ���ˣ����Ϊ��" + HIW + i + NOR + " ��");
			search_viplist(me,mail,0);
			return 1;
		
		}
		i = search_player(player,site);
		if (i > 0) {
			write(" "+HIY+player+"@"+site+NOR+" �������Ѿ��Ǽǹ��ˣ����Ϊ��" + HIW + i + NOR + " ��");
			search_viplist(me,player,1);
			return 1;
		
		}
	
		note = allocate_mapping(6);
		note["time"] = time(); 	//ʱ��
		note["wiz"] = me->query("id"); //������ʦ
		note["player"] = player+"@"+site; //���ID�
		note["mail"] = mail; 	//�������
		note["day"] = sprintf("%d",day); 	//���ʱ��
		note["renew"] = NULL;	//�Ƿ�����
		
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });
		save();
		write("��� " + HIY + player + "@" + site + NOR + " �ɹ�������VIP�ܹ��������������ע������Ϊ "+HIY+mail+NOR"�������Ч��Ϊ "+HIY+day+NOR+" �졣\n");
		return 1;
	}

	if (sscanf(arg, "-d %d", num)== 1) {
		if ( wiz_level(me)<4 )
			return notify_fail("ֻ��arch�ſ���ɾ��VIP�ܹ��������ϵ����ݡ� \n");
		if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
			return notify_fail("VIP�ܹ���������û�������ŵ����ݡ�\n");
		num--;
		notes = notes[0..num-1] + notes[num+1..<1];
		save();
		write("�� "+HIY+ (num+1) +NOR+ " ��VIP�ܹ��������������Ѿ�ɾ����\n");
		return 1;
	}

	if (sscanf(arg, "-r %d %d", num, renew)== 2) {
		if ( wiz_level(me)<4 )
			return notify_fail("ֻ��arch�ſ����޸�VIP�ܹ��������ϵ����ݡ� \n");
		if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
			return notify_fail("VIP�ܹ���������û�������ŵ����ݡ�\n");
		notes[num-1]["renewwiz"]=me->query("id");
		notes[num-1]["renew"]=renew;
		save();
		write("�� "+HIY+ (num) + NOR+" ��VIP�ܹ��������������Ѿ���ϡ�\n");
		return 1;
	}


	write("�﷨������help addvip��\n");
	return 1;
}

string query_save_file()
{
	return VIP_FILE ;
}


void list_viplist(object me, int num)
{
	int i;
	string str;

	i = sizeof(notes);
	if( i < 1 ) write("�齣VIP�ܹ�������Ŀǰû���κ����ݡ�\n");
	else {
		str="�齣VIP�ܹ���������\n";
		str += repeat_string("��", 55) + "\n";
		while (i-- && (i>=sizeof(notes)-num || num==0)) {
			str += sprintf("%3d %s %-12s���䣺%-=20s ���ڣ�%s ��   ������ʦ��%s��%s\n",
				i+1,
				ctime(notes[i]["time"])[4..15],
				capitalize(notes[i]["player"]),
				notes[i]["mail"],
				notes[i]["day"],
				capitalize(notes[i]["wiz"]),
				notes[i]["renew"]?
					("���ѣ�"+notes[i]["renew"]+
						" �� ������ʦ��"+capitalize(notes[i]["renewwiz"]))
					:"�����û������"
			);
			str += repeat_string("��", 55) + "\n";
		}
	}
	me->start_more( str );
}

int search_mail(string mail)
{
    int i;
    if( !(i = sizeof(notes)) ) return 0;
    for( ; i > 0; i-- ) 
	if( notes[i-1]["mail"] == mail ) break;
    return i;
}

int search_player(string player,string site)
{
    int i;
    if( !(i = sizeof(notes)) ) return 0;
    for( ; i > 0; i-- ) 
	if ((strsrch(notes[i-1]["player"],player) > -1) && (strsrch(notes[i-1]["player"],site) > -1 ))break;
    return i;
}


void do_read(object me, int i) 
{
    string s;
    if( i > sizeof(notes) || i < 1) {
	write("�齣VIP�ܹ����������޴˱��!!\n");
	return;
    }
    s="�齣VIP�ܹ���������ţ�"+HIG+i+NOR+"\n";
    s += repeat_string("��", 55) + "\n";
    s += sprintf("%3d %s %-12s���䣺%-=20s ���ڣ�%s ��   ������ʦ��%s��%s\n",
				i,
				ctime(notes[i-1]["time"])[4..15],
				capitalize(notes[i-1]["player"]),
				notes[i-1]["mail"],
				notes[i-1]["day"],
				capitalize(notes[i-1]["wiz"]),
				notes[i-1]["renew"]?
					("���ѣ�"+notes[i-1]["renew"]+
						" �� ������ʦ��"+capitalize(notes[i-1]["renewwiz"]))
					:"�����û������"
			);
    s += repeat_string("��", 55) + "\n";
			
    me->start_more(s);
}
void search_viplist(object me, string arg, int flag)
{
	int i;
	string str,str2;
	str2 = "";

	i = sizeof(notes) -1;
	if( i < 0 ) write("�齣VIP�ܹ�������Ŀǰû���κ����ݣ��޷�����������\n");
	else {
		str="�齣VIP�ܹ�������������ǰ�����Ĺؼ����ǣ�" + HIY + arg + NOR"\n";
		str += repeat_string("��", 55) + "\n";
		while (i>=0) {
			
			if (notes[i]["mail"] == arg){
			str2 += sprintf("%3d %s %-12s���䣺"HBRED+HIY"%-=20s "+NOR+"���ڣ�%s ��   ������ʦ��%s��%s\n",
				i+1,
				ctime(notes[i]["time"])[4..15],
				capitalize(notes[i]["player"]),
				notes[i]["mail"],
				notes[i]["day"],
				capitalize(notes[i]["wiz"]),
				notes[i]["renew"]?
					("���ѣ�"+notes[i]["renew"]+
						" �� ������ʦ��"+capitalize(notes[i]["renewwiz"]))
					:"�����û������"
			);
			str2 += repeat_string("��", 55) + "\n";
		}
		
			if (strsrch(notes[i]["player"],arg) > -1 && flag){
			str2 += sprintf("%3d %s %-12s���䣺%-=20s ���ڣ�%s ��   ������ʦ��%s��%s\n",
				i+1,
				ctime(notes[i]["time"])[4..15],
				HBRED+HIY+capitalize(notes[i]["player"])+NOR,
				notes[i]["mail"],
				notes[i]["day"],
				capitalize(notes[i]["wiz"]),
				notes[i]["renew"]?
					("���ѣ�"+notes[i]["renew"]+
						" �� ������ʦ��"+capitalize(notes[i]["renewwiz"]))
					:"�����û������"
			);
			str2 += repeat_string("��", 55) + "\n";			
		}
		i--;
		}
		if (str2==""){
			str += "û���ҵ��� " + arg + " Ϊ����Ĺ����ҡ�\n";
			str += "��ȷ�ϸ������Ƿ�Ϊ��ʽ�ɷ����䣬����ǣ����ȵǼǣ�Ȼ������Ϸ�м���ҵĹ��ʱ�䡣\n";
			str += repeat_string("��", 55) + "\n";	
		}
		else
			str = str + str2;	
	}
		me->start_more( str );
}

int help(object me)
{
        write(@HELP
ָ���ʽ :
addvip [site] [player] [mail] [day] ��������ҵ� �齣VIP���� ���б�
site 	�������齣վ�㣬��ǰֻ���� LN,LN2,BX,TY,CQ�⼸��վ����� 
player 	�����ID
mail	�����������ʱ�����Ч����Email
day	����ҵĹ����Ч��

addvip [num] �鿴����ĳ����ŵľ���
num	���б��еı��

addvip [key] -m ����keyΪ�ؼ��֣�������û��ʹ��[key]Ϊע���������ҡ�
addvip [key] -p ����keyΪ�ؼ��֣�������û��ʹ��[key]����ҡ�

addvip -d [num] ɾ��һ����¼
num	���б��еı��

addvip -r [num] [day] ���ѹ���
num	���б��еı��
day	�����ѵľ���ʱ��

HELP);
 
        return 1;
}
