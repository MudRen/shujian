// id.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   int i;
     object *inv;

	if( !arg ) {
		int c = 0;

		inv = all_inventory(me);
		if( !sizeof(inv) )
			return notify_fail("������û���κζ�����\n");
		write( "������Я����Ʒ�ı������(�ҷ�)��\n");
		for(i=0; i<sizeof(inv); i++) {
			if (!me->visible(inv[i]))
				continue;
			if (inv[i]->query("invisible") && !wizardp(me))
				continue;
			write(sprintf("%d: %s = %s\n", ++c, inv[i]->name(),
				implode(inv[i]->parse_command_id_list(), ", ")));
		}
		return 1;
	}

	if( arg=="here" ) {
		inv = all_inventory(environment(me));
		if( !sizeof(inv) )
			return notify_fail("����û���κζ�����\n");
		write( "�����������, ���Ｐ��Ʒ��(Ӣ��)�������£�\n");
		for(i=0; i<sizeof(inv); i++) {
			if (!me->visible(inv[i]))
				continue;
			write(sprintf("%s = %s\n", inv[i]->name(),
				implode(inv[i]->parse_command_id_list(), ", ")));
		}
		return 1;
	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : id [here]

���ָ���������֪����Ʒ��Ӣ�����Ƽ�����. ֻ�� id ����ʾ
��������Я����Ʒ������. 'id here' ����ʾ���и�����ͬһ��
��������������.

HELP
    );
    return 1;
}

