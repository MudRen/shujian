inherit SKILL;
void init();

void create() { seteuid(getuid()); }

string type() { return "martial"; }

int valid_learn(object me)
{
	return notify_fail("�����񽣵���������ֻ�д�[�����񽣾�]������\n");
}

int practice_skill(object me)
{
	return notify_fail("�����񽣵���������ֻ�д�[�����񽣾�]������\n");
}



