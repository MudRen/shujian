// follow.c
// Modified by snowman@SJ 28/11/2000

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if (!arg){
		if (me->query_leader())
			return notify_fail("�����ڸ�����"+me->query_leader()->name()+"�ж���\n");
		return notify_fail("ָ���ʽ��follow <ĳ��>|none��\n");
	}

	if (arg=="none")
		if (me->query_leader()) {
			me->set_leader(0);
			message_vision("$N�����Լ������ж���\n", me);
			return 1;
		} else {
			write("�����ڲ�û�и����κ��ˡ�\n");
			return 1;
		}

	if (!objectp(ob = present(arg, environment(me))))
		return notify_fail("����û�� " + arg + "��\n");

	if (!ob->is_character())
		return notify_fail("ʲô������...." + ob->name() + "��\n");

	if (!living(ob))
		return notify_fail("ʲô��" + ob->name() + "��û�ѹ����ء�\n");

	if (ob == me)
		return notify_fail("�����Լ���\n");

	if (ob == me->query_leader())
		return notify_fail("���Ѿ��������ˡ�\n");
	me->set_leader(ob);
	if (!ob->visible(me))
		write("��ʼ���٣�С�ı𱻷��֣��ꡭ��\n");
	else
		message_vision("$N��������$nһ���ж���\n", me, ob);
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ : follow [<����>|none]

���ָ�������ܸ���ĳ�˻����
������� follow none ��ֹͣ���档

HELP
);
	return 1;
}
