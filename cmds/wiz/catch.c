// Write by look
// Modify by bbb
// Modify by snowman@SJ 17/02/2000
// check leitaiuser.

#include <ansi.h>
#include <login.h>
#define SYNTAX  "ָ���ʽ��catch <ĳ��> because <ԭ��> <����>\n"

inherit F_CLEAN_UP;


int main(object me, string str)
{
	object ob, where;
	int times;
	string name, reason;
	mapping note;
	
	if(!str || sscanf(str, "%s because %s %d", name, reason, times)!=3 )
		  return notify_fail(SYNTAX);

	if (!objectp(ob = LOGIN_D->find_body(name)))
		  return notify_fail("���...���... ���������?\n");

	if (wiz_level(ob))
		  return notify_fail("�Է��ǹ�ͬ�ܶ���ս���ޣ�����������̫�ðɣ�\n");

	if (!objectp(where = environment(ob)))
		  return notify_fail("����˲�֪����������Ү... :-( \n");

	if (file_name(where) == RELAX_ROOM)
		  return notify_fail("���Ѿ����һ�Դ˼���ˣ�������ץ�ˡ�\n");

	if (base_name(ob) == "/cmds/leitai/leitaiuser")
		return notify_fail(ob->name() + "�����Ǳ�����̨Clone�����ģ�����̨�������뿪�����ˡ�\n");

	tell_room(where, MAG"�����Ʈ����λ��ò��Ů������"+ob->query("name")+MAG"�ڿն�ȥ�ˡ�\n"NOR, ob);
	tell_object(ob, MAG"��λ��ò��Ů����������ǰ�������㻺��Ʈ������....\n"NOR);

	tell_object(ob, "����Ϊ��" + reason + "�ݣ�Υ���齣��Ϸ���򣬾�������ؽ������һ�Դ" + CHINESE_D->chinese_number(times) + "���ӵĴ�����\n"
	);

	message("channel", HIC "\n�����ɡ�"+ob->query("name")
		+"("+capitalize(ob->query("id"))
		+")��Ϊ��" + reason + "�ݣ�Υ���齣��Ϸ���򣬾�������ؽ���"
		"���һ�Դ" + CHINESE_D->chinese_time(times*60) + "�Ĵ�����\n\n" NOR, users()
	);
	
	note = (["title":"�������"+ob->query("name")
		+"("+capitalize(ob->query("id"))
		+")������",
		"author":me->query("name") + "(" + getuid(me) + ")",
		"time":0,
		"msg":0,]);
	"/clone/board/wizto_b"->done_post(this_object(),note,"�����ɡ�"+ob->query("name")
		+"("+capitalize(ob->query("id"))
		+")��Ϊ��" + reason + "�ݣ�Υ���齣��Ϸ���򣬾�������ؽ���"
		"���һ�Դ" + CHINESE_D->chinese_time(times*60) + "�Ĵ�����\n");
		
	//����������POSTר�����԰�
	/*
	"/clone/board/wizto_b"->auto_post("�������"+ob->query("name")
		+"("+capitalize(ob->query("id"))
		+")������","�����ɡ�"+ob->query("name")
		+"("+capitalize(ob->query("id"))
		+")��Ϊ��" + reason + "�ݣ�Υ���齣��Ϸ���򣬾�������ؽ���"
		"���һ�Դ" + CHINESE_D->chinese_time(times*60) + "�Ĵ�����\n");
	*/
			
        ob->add_condition("relax", times*6);
	ob->set("relax_timeout_room", file_name(where));
	ob->move(RELAX_ROOM);

	tell_object(me, "���"+ob->query("name")+"ץ�����һ�Դ��\n");
	tell_room(environment(ob), MAG"��λ��Ů����"+ob->name()+MAG"Ʈ������"+ob->name()+MAG"����������\n"NOR, ob);

	log_file("static/CATCH",
		sprintf("%s ��Ϊ [%s] �� %s(%s) ץ���һ�Դ������ʱ�� %d ���ӡ�\n",
			name, reason, (string)me->query("name"),me->query("id"), times
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
ָ���ʽ : catch <ĳ��> because <ԭ��> <����>

��ָ������㽫ĳ��Υ�������������͵��һ�Դ��
����ʱ�䵽���Զ��ͷš�
��������Զ��ۼӡ�
HELP
    );
    return 1;
}
