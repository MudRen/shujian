// buddhism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( (int)me->query("guilty") > 0 )
		return notify_fail("���ŷ�ɮ�����䣬����֮��̫�أ��޷����������ķ���\n");
        if( (int)me->query_skill("buddhism", 1) >= 200 )
        return notify_fail("�㲻����ѧϰ�����ķ��ˡ�\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("�����ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
