// irc.c
// by augx@sj  9/24/2001

#include <ansi.h>
inherit F_DBASE;

int help(object me);

void leave_user(object me,string var)
{
	mapping m = CHANNEL_D->query_ircs(var);
	if(!m) return;
	m["user"] -= ({ me->query("id") });
	m["master"] -= ({ me->query("id") });
}

int leave_all_room(object me,string var)
{
	string str;
	if( stringp(me->query_temp(var)) ) {
		str = me->query_temp(var);
		CHANNEL_D->do_channel(me,"irc*","�뿪�������ҡ�");
		leave_user(me,str); 
		me->delete_temp(var); 
		me->set_temp("irc/room_sayin",str);
		return 1;
	}
	else return 0;
}

void delete_busy(object me)
{
	me->delete_temp("irc_busy");
}

void create()
{
	seteuid(getuid());
	set("channel_id", "���쾫��");
	set_temp("irc/room",1);
	set_temp("irc/room1","irc_channel");
	call_out("check_irc",5*60);
}

void check_irc()
{
	mapping m;
	mapping * v;
	string * k;
	int i,j;
	
	remove_call_out("check_irc");
	call_out("check_irc",5*60);
	
	if( !(m=CHANNEL_D->query_all_ircs()) ) return;
	if( (j=sizeof(m)) < 1 ) return;
	
	k = keys(m);
	v = values(m);
	for(i=0;i<j;i++) {	
		if( k[i] == "irc_channel" ) continue;
		if( sizeof(v[i]["user"]) < 1 )
			CHANNEL_D->delete_ircs(k[i]);
	}
}

nosave string * banned_name = ({
"������","�齣","ҥ��","����",	
// Mud ��������
"�Լ�","ɱ��","����","ѩ��","��ң","ĳ��","����","�ܹ�","����","����","��ʦ","���ִ���","����","ӭ��",
// Mud ������������
"��ɽ","��ɽ","��ɽ","��ɽ","̩ɽ","ѩɽ","��ɽ","��ɽ","����","�置","����","��ԭ",
"�Ͻ�","����","�ƺ�","�й�","�л�","����ɽ","����ɽ","����ɽ","�䵱ɽ","����ɽ",
"����","�һ���","��ľ��",
"����","ؤ��","����","����","Ľ��","��Ĺ","ȫ��","����","����","����","�һ�","����",
"������","������","�嶾��","����","а��","��������","�������","�ٸ�","����",
"������","�䵱��","���ư�","��ͨ����","������","����Ľ��","��Ĺ��","��ɽ��","��ɽ��",
"����","������","������",
// ��Ҫ��������
"��ӹ","��Сƽ","������","ë��","���Ż�","�ʵ�","����", "��ϯ",
// �໰
"ͳһ","����","�����о�","���ִ�","����","�����","ȥ���","������","������","����",
"�쵰","����","ɱ��","����","ǿ��","��Ů","̨��","�쵼","����","ƨ��","ƨ��","����",
"��ƨ","����","����","���","��Ѿ","����","����","����","ɵ��","����","����","�Ҳ�",
"̫��","�¹�","�˸�","����","��", "����", "����", "�ּ�", "��", "����", "����",
});
nosave string * banned_ename = ({ "irc_channel","sj","irc","shit","damn","fuck","sex" });

int main(object me, string arg)
{
	string cmd,var, rid,rname,invite,passwd, user;
	mapping m;
	int vars, i;
	object ob;
	
	if (!arg || arg[0]!='/') return 0;
	
	if( (vars = sscanf(arg,"/%s %s",cmd,var)) < 2 )
		if( (vars = sscanf(arg,"/%s",cmd)) < 1 )
			cmd = "dunno";
	if((int)me->query_temp("irc_busy") && cmd!="leaveall") {
		write("����æ���أ�\n");
		return 1;
	}
	switch (cmd) {
		case "?":
		case "help": help(me); break;
		case "list": 
			CHANNEL_D->irc_list(me);
			me->set_temp("irc_busy",1);
			call_out("delete_busy",2,me);
			break;
		case "create": 
			if(vars<2) {
				write("�����ʽ����\n");
				break;
			}
			
			if( !stringp(me->query_temp("user_type")) ) me->query_user_type();
			if( me->query_temp("user_type")=="worker" ) i=100000; else i=200000;
			if( me->query("combat_exp") < i ) {
				write("��ľ��鲻�����������ҡ�\n");
				break;
			}
			if( (string)me->query_temp("irc/create") ) {
				write("���Ѿ�������һ���������ˡ�\n");
				break;
			}

			invite = "no";
			passwd = "nopasswd";
			if( sscanf(var,"%s %s %s %s",rid,rname,invite,passwd)!=4 )
				if( sscanf(var,"%s %s %s",rid,rname,invite)!=3 )
					if( sscanf(var,"%s %s",rid,rname)!=2 ) {
						write("�����ʽ����\n");
						break;
					}
			if( strlen(rid)<3 || strlen(rid)>8 ) {
				write("������Ӣ����������3��8��Ӣ����ĸ��\n");
				break;
			}
			if( strlen(rname)<4 || strlen(rname)>16 ) {
				write("������������������2��8�����֣�\n");
				break;
			}
			if( strlen(passwd)<3 || strlen(passwd)>8 ) {
				write("���������������3��8����ĸ�����֣�\n");
				break;
			}
			if( invite!="invite" && invite!="no" ) {
				write("�������Ƿ����������ܼ��룿\n");
				break;
			}
			if( member_array(rname,banned_name)!=-1 )  {
				write("�����ҵ��������ַǷ������ܻ����������\n");
				break;
			}
			if( member_array(rid,banned_ename)!=-1 )  {
				write("�����ҵ�Ӣ�����ַǷ������ܻ����������\n");
				break;
			}
			
			if( CHANNEL_D->query_ircs(rid) ) {
				write("���������Ѿ���������\n");
				break;
			}
			if( CHANNEL_D->query_ircs_creator(me) != "" ) {
				me->set_temp("irc/create" , CHANNEL_D->query_ircs_creator(me));
				write("���Ѿ�������һ���������ˡ�\n");
				break;
			}
			
			m = ([ "room_name":rname , "creator":me->query("id") , "invite":invite=="no"?0:1 , "passwd":passwd , "user":({ }) , "master":({ }) ]);
			CHANNEL_D->set_ircs(rid , m);	
			me->set_temp("irc/create",rid);
			CHANNEL_D->do_channel(this_object(),"irc",me->query("name")+"������ "+rname+"("+rid+")��");
			var = rid+" "+passwd;
			me->set_temp("invite/"+rid,1);
		case "join":
			if(vars<2) {
				write("�����ʽ����\n");
				break;
			}
			passwd = "nopasswd";
			if( sscanf(var,"%s %s",rid,passwd)!=2 )	rid = var;
			
			if( !(m=CHANNEL_D->query_ircs(rid)) ) {
				write("û����������ҡ�\n");
				break;
			}
			if( m["passwd"] != passwd ) {
				write("������󣬲��ܼ�����������ҡ�\n");
				break;
			}
			if( m["invite"] && m["creator"]!=me->query("id") && !(int)me->query_temp("invite/"+rid) ) {
				write("����������Ҫ������ܼ��롣\n");
				break;
			}
			if( member_array(me->query("id"),m["user"]) != -1 ) {
				write("���Ѿ�������������ˡ�\n");
				break;
			}
			
			if(!stringp(me->query_temp("irc/room1"))) { me->set_temp("irc/room",1); me->set_temp("irc/room1",rid); }
			else if(!stringp(me->query_temp("irc/room2"))) { me->set_temp("irc/room",2); me->set_temp("irc/room2",rid); }
			else if(!stringp(me->query_temp("irc/room3"))) { me->set_temp("irc/room",3); me->set_temp("irc/room3",rid); }
			else if(!stringp(me->query_temp("irc/room4"))) { me->set_temp("irc/room",4); me->set_temp("irc/room4",rid); }
			else if(!stringp(me->query_temp("irc/room5"))) { me->set_temp("irc/room",5); me->set_temp("irc/room5",rid); }
			else { write("���Ѿ���������������ˣ�\n"); break; }

			CHANNEL_D->do_channel(me,"irc*","���������ҡ�");
			me->delete_temp("invite/"+rid);
			
			m["user"] += ({ me->query("id") });
			if( m["creator"]==me->query("id") ) m["master"] += ({ me->query("id") });
			
			me->set_temp("irc_busy",1);
			call_out("delete_busy",1,me);
			break;
		case "close": 
			if(vars<2) {
				var = (string)me->query_temp(sprintf("irc/room%d",(int)me->query_temp("irc/room")));
				if(!var) {
					write("�����ʽ����\n");
					break;
				}
			}
			
			if( !(m=CHANNEL_D->query_ircs(var)) ) {
				write("û����������ҡ�\n");
				break;
			}
			if( !wizardp(me) && member_array(me->query("id"),m["master"])==-1 ) {
				write("��û�йر���������ҵ�Ȩ�ޣ�\n"); 
				break; 
			}

			me->set_temp("irc/room_sayin",var);
			CHANNEL_D->do_channel(me,"irc*","�ر��������ҡ�");
			for(i=0;i<sizeof(m["user"]);i++) {
				if( !(ob=find_player(m["user"][i])) ) continue;
				
				if( ob->query_temp("irc/create")==var ) ob->delete_temp("irc/create");
				if(var==ob->query_temp("irc/room1")) ob->delete_temp("irc/room1");
				else if(var==ob->query_temp("irc/room2")) ob->delete_temp("irc/room2");
				else if(var==ob->query_temp("irc/room3")) ob->delete_temp("irc/room3");
				else if(var==ob->query_temp("irc/room4")) ob->delete_temp("irc/room4");
				else if(var==ob->query_temp("irc/room5")) ob->delete_temp("irc/room5");
			}			
			CHANNEL_D->delete_ircs(var);
			CHANNEL_D->do_channel(this_object(),"irc",me->query("name")+"�ر��� "+m["room_name"]+"("+var+")��");
			
			me->set_temp("irc_busy",1);
			call_out("delete_busy",2,me);
			break;
		case "leave":
			if(vars<2) {
				var = (string)me->query_temp(sprintf("irc/room%d",(int)me->query_temp("irc/room")));
				if(!var) {
					write("�����ʽ����\n");
					break;
				}
			}
			if(var==me->query_temp("irc/room1")) ;
			else if(var==me->query_temp("irc/room2")) ;
			else if(var==me->query_temp("irc/room3")) ;
			else if(var==me->query_temp("irc/room4")) ;
			else if(var==me->query_temp("irc/room5")) ;
			else { write("��Ҫ�뿪�ĸ������ң�\n"); break; }
			
			me->set_temp("irc/room_sayin",var);
			CHANNEL_D->do_channel(me,"irc*","�뿪�������ҡ�");

			if(var==me->query_temp("irc/room1")) me->delete_temp("irc/room1");
			else if(var==me->query_temp("irc/room2")) me->delete_temp("irc/room2");
			else if(var==me->query_temp("irc/room3")) me->delete_temp("irc/room3");
			else if(var==me->query_temp("irc/room4")) me->delete_temp("irc/room4");
			else if(var==me->query_temp("irc/room5")) me->delete_temp("irc/room5");
			else { write("��Ҫ�뿪�ĸ������ң�\n"); break; }

			leave_user(me,var);

			me->set_temp("irc_busy",1);
			call_out("delete_busy",1,me);
			break;
		case "leaveall":
			leave_all_room(me,"irc/room1");
			leave_all_room(me,"irc/room2");
			leave_all_room(me,"irc/room3");
			leave_all_room(me,"irc/room4");
			leave_all_room(me,"irc/room5");
			break;
		case "listuser":
			if(vars<2) {
				var = (string)me->query_temp(sprintf("irc/room%d",(int)me->query_temp("irc/room")));
				if(!var) {
					write("�����ʽ����\n");
					break;
				}
			}
			if( !(m=copy(CHANNEL_D->query_ircs(var))) ) {
				write("û����������ҡ�\n");
				break;
			}
			write("�������ҵ��û��У�");
			for(i=0;i<sizeof(m["master"]);i++)
				write(m["master"][i]+"+ , ");
			m["user"] -= m["master"];
			for(i=0;i<sizeof(m["user"]);i++)
				write(m["user"][i]+" , ");
			write("\n");
			break;
		case "listroom":
			write("�������������У�");
			if(stringp(me->query_temp("irc/room1"))) write(me->query_temp("irc/room1")+" ; ");
			if(stringp(me->query_temp("irc/room2"))) write(me->query_temp("irc/room2")+" ; ");
			if(stringp(me->query_temp("irc/room3"))) write(me->query_temp("irc/room3")+" ; ");
			if(stringp(me->query_temp("irc/room4"))) write(me->query_temp("irc/room4")+" ; ");
			if(stringp(me->query_temp("irc/room5"))) write(me->query_temp("irc/room5")+" ; ");
			write("\n");
			break;
		case "setroom":
			if(vars<2) {
				write("�����ʽ����\n");
				break;
			}
			
			if(var==me->query_temp("irc/room1")) me->set_temp("irc/room",1);
			else if(var==me->query_temp("irc/room2")) me->set_temp("irc/room",2);
			else if(var==me->query_temp("irc/room3")) me->set_temp("irc/room",3);
			else if(var==me->query_temp("irc/room4")) me->set_temp("irc/room",4);
			else if(var==me->query_temp("irc/room5")) me->set_temp("irc/room",5);
			else { write("��Ҫ�趨���ĸ���������˵����\n"); break; }
			write("�趨�ɹ���\n");
			break;
		case "kickout":
			if(vars<2) {
				write("�����ʽ����\n");
				break;
			}
			
			if( sscanf(var,"%s %s",user,rid)!=2 ) {
				user = var;
				rid = (string)me->query_temp(sprintf("irc/room%d",(int)me->query_temp("irc/room")));
				if(!rid) { write("�����ʽ����\n"); break; }
			}
			if( !(m=CHANNEL_D->query_ircs(rid)) ) {
				write("û����������ҡ�\n");
				break;
			}
			if( !wizardp(me) && member_array(me->query("id"),m["master"]) == -1 ) {
				write("��û�����Ȩ�ޡ�\n");
				break;
			}
			if( member_array(user,m["user"])==-1 || !(ob=find_player(user)) ) {
				write("���û����ڴ��������С�\n");
				break;
			}
						
			me->set_temp("irc/room_sayin",rid);
			CHANNEL_D->do_channel(me,"irc*","��"+ob->query("name")+"�߳������ҡ�");
			
			if(rid==ob->query_temp("irc/room1")) ob->delete_temp("irc/room1");
			else if(rid==ob->query_temp("irc/room2")) ob->delete_temp("irc/room2");
			else if(rid==ob->query_temp("irc/room3")) ob->delete_temp("irc/room3");
			else if(rid==ob->query_temp("irc/room4")) ob->delete_temp("irc/room4");
			else if(rid==ob->query_temp("irc/room5")) ob->delete_temp("irc/room5");	
			leave_user(ob,rid);			
			break;
		case "hat":
			if(vars<2) {
				write("�����ʽ����\n");
				break;
			}
			
			if( sscanf(var,"%s %s",user,rid)!=2 ) {
				user = var;
				rid = (string)me->query_temp(sprintf("irc/room%d",(int)me->query_temp("irc/room")));
				if(!rid) { write("�����ʽ����\n"); break; }
			}
			if( !(m=CHANNEL_D->query_ircs(rid)) ) {
				write("û����������ҡ�\n");
				break;
			}
			if( !wizardp(me) && member_array(me->query("id"),m["master"]) == -1 ) {
				write("��û�����Ȩ�ޡ�\n");
				break;
			}
			if( member_array(user,m["user"])==-1 || !(ob=find_player(user)) ) {
				write("���û����ڴ��������С�\n");
				break;
			}
			
			m["master"] += ({ user });
			
			me->set_temp("irc/room_sayin",rid);
			CHANNEL_D->do_channel(me,"irc*","��"+ob->query("name")+"����һ��ñ�ӡ�");
			
			me->set_temp("irc_busy",1);
			call_out("delete_busy",1,me);
			break;
		case "unhat":
			if(vars<2) {
				write("�����ʽ����\n");
				break;
			}
			
			if( sscanf(var,"%s %s",user,rid)!=2 ) {
				user = var;
				rid = (string)me->query_temp(sprintf("irc/room%d",(int)me->query_temp("irc/room")));
				if(!rid) { write("�����ʽ����\n"); break; }
			}
			if( !(m=CHANNEL_D->query_ircs(rid)) ) {
				write("û����������ҡ�\n");
				break;
			}
			if( !wizardp(me) && member_array(me->query("id"),m["master"]) == -1 ) {
				write("��û�����Ȩ�ޡ�\n");
				break;
			}
			if( member_array(user,m["user"])==-1 || !(ob=find_player(user)) ) {
				write("���û����ڴ��������С�\n");
				break;
			}
			if( member_array(user,m["master"])==-1 ) {
				write("���û�������û��ñ�ӡ�\n");
				break;
			}
			
			m["master"] -= ({ user });
			
			me->set_temp("irc/room_sayin",rid);
			CHANNEL_D->do_channel(me,"irc*","ժ��"+ob->query("name")+"ͷ�ϵ�ñ�ӡ�");
			break;
		case "invite":
			if(vars<2) {
				write("�����ʽ����\n");
				break;
			}
			
			if( sscanf(var,"%s %s",user,rid)!=2 ) {
				user = var;
				rid = (string)me->query_temp(sprintf("irc/room%d",(int)me->query_temp("irc/room")));
				if(!rid) { write("�����ʽ����\n"); break; }
			}
			if( !(m=CHANNEL_D->query_ircs(rid)) ) {
				write("û����������ҡ�\n");
				break;
			}
			if( !wizardp(me) && member_array(me->query("id"),m["master"]) == -1 ) {
				write("��û�����Ȩ�ޡ�\n");
				break;
			}
			if( member_array(user,m["user"])!=-1 ) {
				write("���û��Ѿ������������ˡ�\n");
				break;
			}
			if( !(ob=find_player(user)) || !me->visible(ob) ) {
				write("û������û���\n");
				break;
			}
			
			ob->set_temp("invite/"+rid,1);
			tell_object(ob , me->query("name")+"��������� "+m["room_name"]+"("+rid+")��ָ�irc /join "+rid+"��\n");
			write("������"+ob->query("name")+"���� "+m["room_name"]+"("+rid+")��\n");
			
			me->set_temp("irc_busy",1);
			call_out("delete_busy",1,me);
			break;
		default: write("��Ҫʹ��ʲô���������\n"); return 1;
	}
	
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: irc /<����������> <����>
˵����<>��ʾ����Ĳ��� []��ʾ�Ǳ���Ĳ���

���Խ��ܵ������������У�
irc /list       ���г�Ŀǰ���Ե������ҡ�

irc /create <������Ӣ����> <�����ҵ���������> [no/invite] [����������]
                �����������ң���Ҫ200k����(����ֻ��Ҫ100k����)�������
                  �趨���������룬�趨�Ƿ���Ҫ������ܼ���������ң�
                  ÿ��ֻ�ܴ���һ�������ҡ�

irc /invite <�û���> [������Ӣ����]
                �������û�����ĳ�������ң�ֻ�������ҵĹ���Ա����ʦ��ʹ��
                  ����������ָ��������Ӣ������ȱʡ����Ϊָ��ǰ���ڵ�
                  �����ң���ͬ��

irc /join <������Ӣ����> [����]
                ������ĳ�������ң�����ͬʱ������������ҡ�

irc /leave [������Ӣ����]
                ���뿪�����ҡ�

irc /leaveall   ���뿪���м���������ҡ�

irc /listuser [������Ӣ����] 
                : ��ʾ�������е��û���

irc /listroom   ���г�Ŀǰ������������ҡ�

irc /setroom <������Ӣ����>
                ���趨��ǰ�����ң���ֻ���ڵ�ǰ��������˵����

irc /close [������Ӣ����]
                ���ر�ָ���������ң�ֻ����ʦ�������ҹ���Ա��ʹ�á�

irc /kickout <�û���> [������Ӣ����]
                : ��ĳ���߳������ң�ֻ����ʦ�������ҹ���Ա��ʹ�á�

irc /hat <�û���> [������Ӣ����]
                : ����ĳ�������ҹ���ԱȨ�ޣ�ֻ����ʦ�������ҹ���Ա��ʹ�á�

irc /unhat <�û���> [������Ӣ����] 
                : ����ĳ�������ҹ���ԱȨ�ޣ�ֻ����ʦ�������ҹ���Ա��ʹ�á�
 
ʹ�ã���irc �������ݡ� ����Ϳ�����ָ���������������죬��֧�ֱ���(emote)��
      ��������������������Ҫ10k���顣

                                                         ӭ��  AugX@SJ
                                                         9/25/2001
HELP
	);
	return 1;
}
