// training.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
	return notify_fail("ѵ����ֻ��ͨ��ʵ������ߡ�\n");
}

int practice_skill(object me)
{
	return notify_fail("ѵ����ֻ��ͨ��ʵ������ߡ�\n");
}