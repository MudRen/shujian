// ziyin-yin.c �����
// cck 3/7/97

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{

	if( (int)me->query("shen") < 0 )
	return notify_fail("��ɽ������ô�ݵô��ж���֮��ѧϰ�������\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�����ֻ�ܿ�ѧ(learn)����ߡ�\n");
}

