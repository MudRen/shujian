// give.c

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("��Ҫ��˭ʲô������\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");

	if( who == me) return notify_fail("���Լ���\n");
	if (userp(me) && me->is_busy()) return notify_fail("����æ���ء�\n");
	if (userp(me) && !wizardp(me) && who->query("env/no_accept"))
		return notify_fail("�Է����ڲ������κζ�����\n");
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( !wizardp(me) && userp(who) && (obj->query("no_drop")
		|| (userp(me) && obj->query("unique") && !mapp(obj->query("skill")))))
			return notify_fail("�����������������ˡ�\n");
		if (!wizardp(me) && userp(who) && userp(me) && obj->query("no_give"))
			return notify_fail("�����������������ˡ�\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		if( obj->query("weapon_prop") && me->is_exert() &&
			obj == me->query_temp("weapon"))
			       return notify_fail("������ʹ��"+me->query_exert()+"���޷�����"+obj->name()+"��\n");
		if( obj->query("weapon_prop") && me->is_perform() &&
			obj == me->query_temp("weapon"))
			       return notify_fail("������ʹ��"+me->query_perform()+"���޷�����"+obj->name()+"��\n");

		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			obj2->set("broken", obj->query("broken"));
			obj2->move(environment(me));
			if (obj2 && do_give(me, obj2, who))
				return 1;
			if (obj2)
				obj2->move(me);
			return 0;
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
	if( obj->query("weapon_prop") && me->is_exert() &&
	    obj == me->query_temp("weapon"))
		 return notify_fail("������ʹ��"+me->query_exert()+"���޷�����"+obj->name()+"��\n");
	if( obj->query("weapon_prop") && me->is_perform() &&
	    obj == me->query_temp("weapon"))
		 return notify_fail("������ʹ��"+me->query_perform()+"���޷�����"+obj->name()+"��\n");

	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	string unit;

	if( !wizardp(me) && userp(who) && (obj->query("no_drop")
	|| (userp(me) && obj->query("unique") && !mapp(obj->query("skill")))))
		return notify_fail("�����������������ˡ�\n");

	if (!wizardp(me) && userp(who) && userp(me) && obj->query("no_give"))
		return notify_fail("�����������������ˡ�\n");

	if (!wizardp(me) && obj->query("embedded"))
		if (!stringp(obj->query("embedded")))
			return notify_fail("�������������Ķ���Ҳ�ܸ��ˣ����������˵�ɡ�\n");
		else return notify_fail(obj->query("embedded"));

	notify_fail("�Է�����������������\n");
	if( !interactive(who) && !who->accept_object(me, obj) )
		return 0;

	if (!obj) return 0;
	if (obj->query("invisible") && !wizardp(me)) return 0;
	if ( !userp(who) && obj->value() ) {
		message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
		destruct(obj);
		return 1;
	}
	if (obj->query_amount()) unit = chinese_number(obj->query_amount()) + obj->query("base_unit");
	else unit = "һ" + obj->query("unit");
	if( obj->move(who) ) {
		write(sprintf("���%s%s%s��\n", who->name(), unit,
			obj->name()));
		message("vision", sprintf("%s����%s%s��\n", me->name(),
			unit, obj->name()), who );
		message("vision", sprintf("%s��%sһ%s%s��\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		return 1;
	}
	return 0;
}

int help(object me)
{
write(@HELP
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>

���ָ��������㽫ĳ����Ʒ������, ��Ȼ, ������Ҫӵ��������Ʒ.

HELP
    );
    return 1;
}
