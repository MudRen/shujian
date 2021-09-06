// by darken@SJ

#include <ansi.h>
#include <login.h>
#define SYNTAX "ָ���ʽ��lock <ĳ��> because <ԭ��>\n"
#define BLOCK "/d/death/block"

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, where;
	string name, reason;
 
	if(!str || sscanf(str, "%s because %s", name, reason)!=2 )
		  return notify_fail(SYNTAX);
       
	if (!objectp(ob = LOGIN_D->find_body(name))) 
		  return notify_fail("û������˰�?\n");

	if (wiz_level(ob))
		 return notify_fail("ץ��ʦ������Ϊ����darken����\n");

	if(!objectp(where = environment(ob)))
		  return notify_fail("����˲�֪����������Ү... :-( \n");
	
	if (ob->query("registered") < 2)
		return notify_fail("����˲�����ʽע�����ҡ�\n");

	if (file_name(where) == BLOCK)
		  return notify_fail(ob->query("name") + "�Ѿ������̷�˼���ˣ�������ץ�ˡ�\n");

	if (base_name(ob) == "/cmds/leitai/leitaiuser")
		return notify_fail(ob->name() + "�����Ǳ�����̨Clone�����ģ�����̨�������뿪�����ˡ�\n");

	tell_room(where, WHT HBMAG"ͻȻ���������������֣���"+ob->query("name")+"�ܵ����̷�ȥ�ˡ�\n"NOR, ob);
	tell_object(ob, MAG"���������ְ����ƽ������̷��....\n"NOR);

	message("shout", YEL HBRED "\n�����ɡ�"+ob->query("name")+"("+capitalize(ob->query("id"))
		+")��Ϊ��" + reason + "�ݣ�Υ���齣��Ϸ���򣬾�������ؽ����̷��Ĵ�����\n\n" NOR, users());

	log_file("static/LOCK",
		sprintf("%s(%s) ��Ϊ [%s] �� %s(%s) ץ�����̷���\n",
			ob->query("name"),ob->query("id"), reason, (string)me->query("name"),me->query("id")
		), me, ({ ob })
	);
	ob->delete("enter_wuguan");
	ob->move(BLOCK);
	return 1;
}
