// qimen-bagua.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( me->query_skill("qimen-bagua", 1 ) >= 200 ) 
              return notify_fail("�㲻����������Ű��Եĵȼ��ˡ�\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("���Ű���ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
