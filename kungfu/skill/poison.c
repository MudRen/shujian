// poison.c ����
// by pishou

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        int i = (int)me->query_skill("poison", 1);
        int t = 1, j;
if (i>180) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ������ˡ� \n");
        for (j = 1; j < i / 10; j++) t*= 2;
       	if( (int)me->query("shen") > 0 )
		return notify_fail("����������ʿ, ��ô������������ݵĶ���? \n");
        if (i > 10 && (int)me->query("shen") > t * 100)
        return notify_fail("ֻ�д����֮�˲��ܼ�������������\n");
        if( (int)me->query_skill("poison", 1) >= 200 )
        return notify_fail("�㲻�������������ˡ�\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("��������ͨ������ϰ������ߡ�\n");
}
