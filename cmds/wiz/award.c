
inherit F_CLEAN_UP;

#include <ansi.h>
#include <login.h>
#include <mudlib.h>
#include <database.h>

#define SYNTAX  "ָ���ʽ��award <ĳ��> because <ԭ��> <����>\n"

int main(object me, string str)
{
	object ob, where;
	int point;
	string name, reason;
	mapping note;

	if(!str || sscanf(str, "%s because %s %d", name, reason, point)!=3 )
		  return notify_fail(SYNTAX);

	if (!objectp(ob = LOGIN_D->find_body(name)))
		  return notify_fail("���...���... ���������?\n");;

	if (!objectp(where = environment(ob)))
		  return notify_fail("����˲�֪��������Ү... :-( \n");
		  
	if ( (point < 10) || (point > 50))
		  return notify_fail("������������10�㣬���50�㡣\n");

	if (base_name(ob) == "/cmds/leitai/leitaiuser")
		return notify_fail(ob->name() + "�����Ǳ�����̨Clone�����ģ������ڽ����ɡ�\n");

	tell_room(where, MAG"�����Ʈ��һ����ò��Ů��������"+ob->query("name")+MAG"��ͷ��\n"NOR, ob);

	tell_object(ob, "����Ϊ��" + reason + "�ݣ�������Ա���轱���齣����" + CHINESE_D->chinese_number(point) + "�㡣\n"
	);
 	
 	if (!dbquery("update Users set U_Credit = U_Credit + " + point + " where U_Username = \"" + name+ "\""))
		write("���"+ob->query("name")+"("+capitalize(ob->query("id"))+")���ֽ�������ʧ�ܡ�\n");
	else
		write("���"+ob->query("name")+"("+capitalize(ob->query("id"))+")���ֽ������óɹ���\n");
	
	message("channel", HIG "\n��������"+ob->query("name")
		+"("+capitalize(ob->query("id"))
		+")��Ϊ��" + reason + "�ݣ��������轱���齣����" 
		+ CHINESE_D->chinese_number(point) + "�㡣\n\n" NOR, users()
	);
	//����������POSTר�����԰�	
	note = (["title":"�������"+ob->query("name")+"("+capitalize(ob->query("id"))+")����",
		"author":me->query("name") + "(" + getuid(me) + ")",
		"time":0,
		"msg":0,]);
	"/clone/board/wizto_b"->done_post(this_object(),note,"��������"+ob->query("name")
		+"("+capitalize(ob->query("id"))
		+")��Ϊ��" + reason + "�ݣ��������轱���齣����" 
		+ CHINESE_D->chinese_number(point) + "�㡣\n");
		
	BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,"UPDATE members SET credit_total = credit_total+'"+point+"' WHERE username = '"+getuid(ob)+"@"+lower_case(INTERMUD_MUD_NAME)+"' limit 1",0,0);
	///credit_total 	
	/*		
	"/clone/board/wizto_b"->auto_post("�������"+ob->query("name")
		+"("+capitalize(ob->query("id"))
		+")����","��������"+ob->query("name")
		+"("+capitalize(ob->query("id"))
		+")��Ϊ��" + reason + "�ݣ��������轱���齣����" 
		+ CHINESE_D->chinese_number(point) + "�㡣\n");
	*/	

	log_file("static/AWARD",
		sprintf("%s ��Ϊ [%s] �� %s(%s) �����齣���� %d �㡣\n",
			name, reason, (string)me->query("name"),me->query("id"), point
		), ob, ({ me })
	);

	return 1;
}

string query(string arg)
{
	if(arg=="id") //return now_id;
	return "Wizard";
}

int help(object me)
{
	write(@HELP
ָ���ʽ��award <ĳ��> because <ԭ��> <����>
����������ָ���һЩ����Ϸ�������׵���ҡ�
HELP
	);
	return 1;
}
