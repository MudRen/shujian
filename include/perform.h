// perform.c
// Create by athoi@sj

// ���ʹ��perform����Ҫ�ı�Ҫ����
int perform_check(object me)
{
	int num;
	string *skill, *gift, *other;

	// ����书
	skill = keys(requirement["skill"]);
	num = sizeof(skill);
	while (num--)
		if (me->query_skill(skill[num], 1) < requirement["skill"][skill[num]])
			return notify_fail("���" + to_chinese(skill[num]) + "�ȼ�������������ʹ�á�" + perform_name() + "��\n");
	// �������
	gift = keys(requirement["gift"]);
	num = sizeof(gift);
	while (num--)
		if (me->query_gift(gift[num], "postnatal") < requirement["gift"][gift[num]])
			return notify_fail("���" + to_chinese(gift[num]) + "������������ʹ�á�" + perform_name() + "��\n");
	// ��������������������Ҫquery()���صĶ���
	other = keys(requirement["other"]);
	num = sizeof(other);
	while (num--)
		if (me->query(other[num]) < requirement["other"][other[num]])
		{
			if (is_chinese(to_chinese(other[num])))
				return notify_fail("���" + to_chinese(other[num]) + "������������ʹ�á�" + perform_name() + "��\n");
			else
				return notify_fail("����������δ�ܴﵽ�����Ķ������ļ���\n");
		}

	return 1;
}
// ȡ��ʩ��perform��skill��Ӣ������
string skill_name()
{
	string skill, *name;

	skill = file_name(this_object());
	name = explode(skill, "/");

	return name[2];
}
// ���ʹ��perform����Ҫ����ʱ����
// type 0��������书 1��������书
// flag 0����ս���в���ʹ�� 1������Ҫս����
varargs int perform_temp_check(object me, object target, int type, string skill_type, int flag)
{
	object weapon;
	int num;
	string *query, *query_temp;

	if ( me->is_busy() && skill_name() != "tenglong-bifa" && perform_name() != HIG"������β"NOR )
		return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");

	if ( me->is_lost() && perform_name() != HIG"������β"NOR )
		return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");

	if(!flag && (!target || !me->is_fighting(target)))
		return notify_fail("��" + perform_name() + "��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	query = keys(requirement_temp["query"]);
	num = sizeof(query);
	while (num--)
		if (me->query(query[num]) < requirement_temp["query"][query[num]])
			return notify_fail("���" + to_chinese(query[num]) + "�������޷�ʩչ��" + perform_name() + "��\n");

	query_temp = keys(requirement_temp["query_temp"]);
	num = sizeof(query_temp);
	while (num--)
		if (me->query_temp(query_temp[num]) == requirement_temp["query_temp"][query_temp[num]])
			return notify_fail("������ʹ�á�" + to_chinese(query_temp[num]) + "����\n");

        if (type == 1)
        {
        	if (!objectp(weapon = me->query_temp("weapon")))
        		return notify_fail("��û��ʹ�����������ʩչ��" + perform_name() + "����\n");
                if (weapon->query("skill_type") != skill_type)
        		return notify_fail("��ʹ�õ��������ԣ�����ʩչ��" + perform_name() + "����\n");
	}

        if (!type && me->query_temp("weapon"))
        	return notify_fail("������������ô��ʹ�á�" + perform_name() + "����\n");

       	if (skill_type != "dodge")
       	{
        	if (me->query_skill_mapped(skill_type) != skill_name()
         	 || (!type && me->query_skill_prepared(skill_type) != skill_name()))
        		return notify_fail("��ʹ�õ��⹦���ԣ��޷�ʹ�á�" + perform_name() + "����\n");
        	if (me->query_skill_mapped("parry") != skill_name()
        	 && me->query_skill_mapped("parry") != "douzhuan-xingyi"
        	 && me->query_skill_mapped("parry") != "qiankun-danuoyi"
        	 && !SKILL_D(me->query_skill_mapped("parry"))->valid_combine(skill_name()))
        	 	return notify_fail("��ʹ�õ��мܲ��ԣ��޷�ʹ�á�" + perform_name() + "����\n");
	}
	else
	{
		if (me->query_skill_mapped(skill_type) != skill_name())
			return notify_fail("��ʹ�õ��Ṧ���ԣ��޷�ʹ�á�" + perform_name() + "����\n");
	}

	return 1;
}
// ������call_out��perform�Ƿ���Լ�������
// flag 0������Ҫս���в��ܳ��� 1������Ҫ
int checking(object me, object target, object weapon, string skill_type, int flag)
{
	if (!me
	|| !target
	|| !living(me)
	|| me->is_ghost()
	|| target->is_ghost()
	|| !present(target, environment(me))
	|| me->query_skill_mapped(skill_type) != skill_name()
	|| me->query_skill_mapped("parry") != skill_name())
		return 1;
	if (flag)
	{
		if (!weapon
		&& (me->query_temp("weapon")
	           || me->query_temp("secondary_weapon")
	           || me->query_skill_prepared(skill_type) != skill_name()))
	        	return 1;
	        if (weapon && (me->query_temp("weapon") != weapon))
	        	return 1;
	}
	else if (target == me)
	{
		if (!weapon
		&& (!me->is_fighting()
	           || me->query_temp("weapon")
	           || me->query_temp("secondary_weapon")
	           || me->query_skill_prepared(skill_type) != skill_name()))
	        	return 1;
	        if (weapon
	        && (!me->is_fighting() || me->query_temp("weapon") != weapon))
	        	return 1;
	}
	else
	{
		if (!weapon
		&& (!me->is_fighting(target)
	           || me->query_temp("weapon")
	           || me->query_temp("secondary_weapon")
	           || me->query_skill_prepared(skill_type) != skill_name()))
	        	return 1;
	        if (weapon
	        && (!me->is_fighting(target) || me->query_temp("weapon") != weapon))
	        	return 1;
	}
	return 0;
}
// ����������
string dodge_msg(object target)
{
	string dodge_skill;

	dodge_skill = target->query_skill_mapped("dodge");
        if( !dodge_skill )
              	dodge_skill = "dodge";
        return SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
}
// ��ǰ����״̬������
varargs string status_msg(object ob, int effective)
{
	int jing_ratio, qi_ratio;

	if ( effective )
	{
		jing_ratio = ob->query("eff_jing") * 100 / ob->query("max_jing");
		qi_ratio = ob->query("eff_qi") * 100 / ob->query("max_qi");

		return jing_ratio > qi_ratio
		? "( $n" + COMBAT_D->eff_status_msg(qi_ratio) + " )\n"
		: "( $n" + COMBAT_D->eff_status_msg(jing_ratio) + " )\n";
	}
	else
	{
		jing_ratio = ob->query("jing") * 100 / ob->query("max_jing");
		qi_ratio = ob->query("qi") * 100 / ob->query("max_qi");

		return jing_ratio > qi_ratio
		? "( $n" + COMBAT_D->status_msg(qi_ratio) + " )\n"
		: "( $n" + COMBAT_D->status_msg(jing_ratio) + " )\n";
	}
}
// help function
int help(object me)
{
	int num;
	string *skill, *gift, *other;

	write("\n" + to_chinese(skill_name()) + "֮" + perform_name() + "��\n");
	write("\n" + perform_help());

	write("\nҪ��\n");
	skill = keys(requirement["skill"]);
	num = sizeof(skill);
	while (num--)
		write("\t" + to_chinese(skill[num]) + "��" + requirement["skill"][skill[num]] + "\n");
	gift = keys(requirement["gift"]);
	num = sizeof(gift);
	while (num--)
		write("\t" + to_chinese(gift[num]) + "��" + requirement["gift"][gift[num]] + "\n");
	other = keys(requirement["other"]);
	num = sizeof(other);
	while (num--)
		write("\t" + to_chinese(other[num]) + "��" + requirement["other"][other[num]] + "\n");

	return 1;
}

mapping get_requirement()
{
	return requirement;
}

mapping get_requirement_temp()
{
	return requirement_temp;
}