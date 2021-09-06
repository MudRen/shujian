// linchuang-shu.c
// by akuma

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
    if ( me->query_skill("force", 1) < 50 )
	return notify_fail("����ڹ���˲��ã���ϰ���ٴ�ҽ�����к��ã�\n");

    if ( me->query_skill("linchuang-shu", 1) == me->query_skill("force", 1)+20 )
	return notify_fail("����ڹ��Ѿ��޷�֧������ϰ��������ٴ�ҽ���ˡ�\n");

    if ( me->query_skill("linchuang-shou", 1) == me->query_skill("literate", 1)+50 )
	return notify_fail("��Ķ���ʶ��ˮƽ����ʹ������������ٴ�ҽ���ˡ�\n");

    return 1;
}
