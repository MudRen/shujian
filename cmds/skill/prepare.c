// prepare.c
// YUJ@SJ 2001-0610 ֧�� prepare basic_skill �ĸ�ʽ

inherit F_CLEAN_UP;

mapping valid_types =
([
	"claw":		"צ��",
	"cuff":		"ȭ��",
	"finger":	"ָ��",
	"hand":		"�ַ�",
	"leg":		"�ȷ�",
	"strike":	"�Ʒ�",
]);

int main(object me, string arg)
{
	mapping smap, pmap;
	string *skill, basic1, basic2, arg1, arg2;

	smap = me->query_skill_map();

	if (userp(me) && arg && (me->query_temp("no_prepare") || me->is_busy() || me->query_temp("thd/xinghe")
	|| me->query_condition("no_perform") || me->is_perform()))
		return notify_fail("�����ڲ���׼�����⼼�ܡ�\n");

	if (!sizeof(smap))
		return notify_fail("������û�м����κ���Ч���⼼�ܡ�\n");

	pmap = me->query_skill_prepare();
	if (!pmap) pmap = ([]);

	if (!arg) {
		if (!sizeof(pmap))
			return notify_fail("������û��׼���κ����⼼�ܡ�\n");

		skill = keys(pmap);
		write("��������Ŀǰ����е����⼼�ܣ�\n");
		foreach (string item in skill) {
			if (!me->query_skill(item))
				continue;
			write(valid_types[item] + sprintf("%-10s",
				"(" + item + ")") +
				to_chinese(pmap[item]) + "\n"
			);
		}
		return 1;
	}

	if (arg == "?") {
		write("�����ǿ���ʹ�õ�����ȭ�ż������ࣺ\n");
		skill = sort_array(keys(valid_types), (: strcmp :));
		foreach (string item in skill)
			write(sprintf("  %s: (%s)\n", valid_types[item], item));
		return 1;
	}

	if (arg == "none") {
		if (!sizeof(pmap))
			return notify_fail("������û������κ�����ȭ�ż��ܡ�\n");

		skill = keys(pmap);
		foreach (string item in skill)
			me->prepare_skill(item);

		me->reset_action();
		write("ȡ��ȫ������׼����\n");
		return 1;
	}

	if (sizeof(pmap) >= 2)
		return notify_fail("�������Ѿ�������������⼼�ܡ�\n");

	if (sscanf(arg, "%*s %*s %*s") == 3)
		return notify_fail("ָ���ʽ��prepare|bei [<��������һ>|<�������ƶ�>]\n");

	if (sscanf(arg, "%s %s", arg1, arg2) == 2)
	{
		if (sizeof(pmap) == 1)
			return notify_fail("����׼����һ�ּ����ˡ�\n");
		if (!undefinedp(valid_types[arg1])) {
			basic1 = arg1;
			arg1 = me->query_skill_mapped(basic1);
			if (!arg1)
				return notify_fail("��û�м��������" + valid_types[basic1] + "��\n");
		}
		if (!undefinedp(valid_types[arg2])) {
			basic2 = arg2;
			arg2 = me->query_skill_mapped(basic2);
			if (!arg2)
				return notify_fail("��û�м��������" + valid_types[basic2] + "��\n");
		}
		if (!me->query_skill(arg1, 1) || !me->query_skill(arg2, 1))
			return notify_fail("�����ٲ���������ȭ�ż��ܵ�����֮һ��\n");

		if (!SKILL_D(arg1)->valid_combine(arg2) || !SKILL_D(arg2)->valid_combine(arg1))
			return notify_fail(to_chinese(arg1)+"��"+to_chinese(arg2)+"������ϡ�\n");

		skill = keys(valid_types);
		foreach (string item in skill) {
			if (!basic1 && smap[item] == arg1) basic1 = item;
			if (!basic2 && smap[item] == arg2) basic2 = item;
		}

		if (!basic1 || !basic2)
			return notify_fail("�����ּ�����δ��������ȭ�ż��ܡ�\n");

		me->prepare_skill(basic1, arg1);
		me->prepare_skill(basic2, arg2);
	} else {
		arg1 = arg;
		if (!undefinedp(valid_types[arg1])) {
			basic1 = arg1;
			arg1 = me->query_skill_mapped(basic1);
			if (!arg1)
				return notify_fail("��û�м��������" + valid_types[basic1] + "��\n");
		}
		if (!me->query_skill(arg1, 1))
			return notify_fail("�㲻�����ּ��ܡ�\n");

		skill = keys(pmap);
		if ( sizeof(pmap)
		&& (!SKILL_D(arg1)->valid_combine(pmap[skill[0]])
		|| !SKILL_D(pmap[skill[0]])->valid_combine(arg1)) )
			return notify_fail(to_chinese(arg1)+"�������������е�ȭ�ż�����ϡ�\n");

		skill = keys(valid_types);
		foreach (string item in skill)
			if (!basic1 && smap[item] == arg1) basic1 = item;

		if (!basic1)
			return notify_fail("���ּ�����δ��������ȭ�ż��ܡ�\n");

		me->prepare_skill(basic1, arg1);
	}
	me->reset_action();
	write("���ȭ�ż���׼����\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : prepare|bei [<���������⼼��һ>|<���������⼼�ܶ�>|none]
	   prepare|bei ?

���ָ������ָ����Ҫ�õ�ȭ�ż��ܣ� ��ָ��һ�ֻ����ϵ���Ӧ�������ơ�
������Ӳ��������ʾ���������༰��Ŀǰ��ʹ�õļ������� �������һ
�� ? ���г�������ʹ������ȭ�ż��ܵļ������ࡣ

HELP
	);
	return 1;
}
