//���ָ�����û�˶��� LinuX@SJ

inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
	object ob;
    	string msg;

	if (me->query("marry"))
		return notify_fail("���Ѿ�����ˡ�\n");

	if (me->query_temp("marry"))
		return notify_fail("���Ѿ������ˡ�\n");

	if (me->query_temp("pending/marry"))
		return notify_fail("���Ѿ�������ˡ�\n");

	if (me->query("gender") == "Ů��")
		return notify_fail("���ֻ�����з�����\n");

	if (!arg || !(ob = present(arg, environment(me))) || me == ob)
		return notify_fail("��Ҫ��˭��飿\n");

	if (!userp(ob))
		return notify_fail("��ֻ���������顣\n");

	if (me->query("age") < 18)
		return notify_fail("������"+ob->name()+"��飬�����㻹û�г��ꡣ\n");

	if (ob->query("age") < 18)
		return notify_fail(ob->name()+"���������ҲС��һ�㣬�ȳ��ɴ����������Ҳ���ٰ���\n");

	/*if (ob->query("registered") < 3)
		return notify_fail("��ֻ������ʽ�����顣\n");*/
		

	if (ob->query("gender") != "Ů��")
		return notify_fail("�����ĶԷ�����Ů�ԡ�\n");
	
	if ( stringp( msg = me->query( "env/qiuhun_msg" ) ) ) 
            {
                message_vision( msg+"\n", me, ob );           }	
	else
	message_vision( CYN+"$N�¸ҵ���$n�������������ע����$n��˫����˵����\n" +
                    "�����ҽ���Ψһ���ġ������ġ��ᰮ���ˣ�" + ob->name() + "�޸��Ұɣ�" +
                    "���ǽ��ǽ������������۵�һ�Եģ�\n"+NOR, me, ob );
 	tell_object( ob, YEL + me->name() + "������飬�����Ը��;͵��ͷ, �����ͬ���ҡҡͷ�������̫Ϊ�ѾͲ������ˣ�\n" + 
                "������뿼�����ĳ��⣬�������Ҫ�󿴿����ܲ���������\n" );                                   
	tell_object(ob, YEL "�����Ը���"+me->name()+"��Ϊ�������� (marry) ָ�\n\n" NOR);
	me->set_temp("pending/marry", ob);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: qiu <��ҵ� ID>

����������ԣ����ָ���������������ͬһ�������ĳ�������顣
�������Ů�ԣ����ָ����Կ���������˭������顣

��ص�ָ�marry
��صİ�����help marriage
HELP
	);
	return 1;
}

