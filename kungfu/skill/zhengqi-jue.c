// zhengqi-jue.c ������
// cck 3/7/97

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
	if( (int)me->query("shen") < 0 )
	return notify_fail("��ɽ������ô�ݵô��ж���֮��ѧϰ��������\n");
        if( (int)me->query_skill("zhengqi-jue", 1) >= 200 )
        return notify_fail("�㲻����ѧϰ�������ˡ�\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("������ֻ�ܿ�ѧ(learn)����ߡ�\n");
}

