// beauty.c

inherit SKILL;

int valid_learn(object me)
{
	if (me->query("gender") == "����" && me->query("age") < 50)
		return notify_fail("��һ������ү��ѧ��������\n");
	return 1;
}

string type() { return "knowledge"; }
