// wield.c
// Modified by snowman@SJ 01/05/2001
inherit F_FROZEN;
inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if (userp(me) && (me->is_busy() || me->query_temp("thd/xinghe")))
		return notify_fail("����æ���ء�\n");
                
	if (userp(me) && me->is_exert()) 
		return notify_fail("������ʹ��"+me->query_exert()+"��\n");

	if (userp(me) && me->is_perform() ) 
		return notify_fail("������ʹ��"+me->query_perform()+"��\n");

	if (!arg) return notify_fail("��Ҫװ��ʲô������\n");

	if (arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if((int)me->query("max_neili") < (int)inv[i]->query("wield_maxneili")) continue;
			if((int)me->query("neili") < (int)inv[i]->query("wield_neili")) continue;
			if((int)me->query_str() < (int)inv[i]->query("wield_str")) continue;
			if(inv[i]->query("no_wield") && me->query("family/family_name")!=inv[i]->query("family_required")) continue;
			if(do_wield(me, inv[i]) ) count ++;
		}
		write("װ����ϡ�\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped"))
		return notify_fail("���Ѿ�װ�����ˡ�\n");
	if (ob->query("no_wield"))
		if(me->query("family/family_name")!=ob->query("family_required"))
			return notify_fail("�㲻��ʹ�����������\n");
	if((int)me->query("max_neili") < (int)ob->query("wield_maxneili"))
		return notify_fail("��о�ȫ����Ϣ���ڣ�ԭ������������������װ��"+ob->name()+"��\n");
	if((int)me->query("neili") < (int)ob->query("wield_neili"))
		return notify_fail("��о�ȫ����Ϣ���ڣ�ԭ������������������װ��"+ob->name()+"��\n");
	if((int)me->query_str() < (int)ob->query("wield_str"))
		return notify_fail("�������"+ob->name()+"����������������ֻ�����ա�\n");
	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;

	notify_fail("��ֻ��װ���ɵ��������Ķ�����\n");
	if (ob->wield()) {
		if (userp(me) && me->is_fighting()) me->start_busy(1);
		if( !stringp(str = ob->query("wield_msg")) )
			str = "$Nװ��$n��������\n";
		message_vision(str, me, ob);
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��wield <װ������>
 
���ָ������װ��ĳ����Ʒ������, �����Ҫӵ��������Ʒ.
 
HELP
	);
	return 1;
}

