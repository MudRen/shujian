// huanxi-chan.c ��ϲ��

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
    if( me->query("class") != "huanxi")
        return notify_fail("��Ǵ����µ��ӣ�ѧϰ��ϲ���к��ã�\n");
    if( (int)me->query_skill("huanxi-chan", 1) >= 200 )
        return notify_fail("�㲻����ѧϰ��ϲ���ˡ�\n");
    return 1;
}

int practice_skill(object me)
{       
        return notify_fail("��ϲ��ֻ�ܿ�ѧϰ����ߡ�\n");
}
