//���ָ�����û�˶��� LinuX@SJ

inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
	object ob;

	if (!arg || !(ob = present(arg, environment(me))) || me == ob || !ob->is_character())
		return notify_fail("��Ҫ�޸�˭��\n");

	if (me->query("gender") != "Ů��") {
		message_vision("$N��������ض���$n˵��С�๫���ǲ��Ǻܼ�į����\n", me, ob);
		return 1;
	}

	if (me->query("marry"))
		return notify_fail("���Ѿ�����ˡ�\n");

	if (me->query_temp("marry"))
		return notify_fail("���Ѿ������ˡ�\n");

	switch (me->query("class")) {
		case "bonze":
                case "huanxi":if(me->query_skill("huanxi-chan",1)>180) break;
		case "lama":
		case "taoist":
			return notify_fail("���Ȼ�����˵�ɡ�\n");
	}

	switch (ob->query("class")) {
		case "bonze":
                case "huanxi":if(ob->query_skill("huanxi-chan",1)>180) break;
		case "lama":
		case "taoist":
			return notify_fail("�����Ȼ�����˵�ɡ�\n");
	}

	if (me->query("age") < 18) {
		message_vision("$N��޸�$n������$N��С���ٵȼ���ɡ�\n", me, ob);
		return 1;
	}

	if (ob->query("gender") != "����")
		return notify_fail("����޵��˲������ԡ�\n");
//
//	if (ob->query("registered") < 3)
//		return notify_fail("��ֻ�ܼ޸���ʽ��ҡ�\n");

	if (ob->query_temp("pending/marry") != me)
		return notify_fail("����޸�"+ob->name()+"������"+ob->name()+"��û��������顣\n");

	message_vision("$N�ߴ��ش�Ӧ�޸�$n��\n", me, ob);
	tell_object( ob, YEL+"�ۣ�" + me->name() + "��Ӧ���������ˡ�\n"+NOR );
	ob->delete_temp("pending/marry");
	me->set_temp("marry", ob);
	ob->set_temp("marry", me);
	return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ: marry <ĳ�������ID>

��Ӧ���ĳ������ߵ���顣
���ָ��Ů��ר�á�

��ص�ָ�propose
��صİ�����help marriage

HELP
    );
    return 1;
}
