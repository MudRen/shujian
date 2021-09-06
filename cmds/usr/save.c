// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;

	seteuid(getuid());

    if (me->query_temp("saved")) return notify_fail("���������к�ϵͳӲ�̽��������Ժ����ԡ�\n");
    me->set_temp("saved", 1);
    me->start_call_out( (: call_other, me, "delete_temp", "saved" :), 60 + random(60));
	if( !objectp(link_ob = me->query_temp("link_ob")) )
		return notify_fail("�㲻�Ǿ����������߽��룬���ܴ��档\n");

	if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
		write("�����´����߽���ʱ��������￪ʼ��\n");
	}

	if( (int)link_ob->save() && (int)me->save() ) {
        write("����������ϡ�\n");
		return 1;
	}

	return notify_fail("����ʧ�ܡ�\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ��save

��������ܶ��Ľ����������
HELP
	);
	return 1;
}
