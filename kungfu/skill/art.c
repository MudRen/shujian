// art.c �����黭
// cck 3/7/97
//cool 10/10/98

inherit SKILL;
void init();

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
	if(me->query_int() < 32)
		return notify_fail("�����黭���Ǽ������֮�£����ƺ�̫����������Щ��\n");
        if((int)me->query("shen") < -200000 )
		return notify_fail("��ɱ�����飬����������ƽϢ����ͷħ������ֻ�����˼�������壿\n");
	if((int)me->query_skill("art", 1) >= 200 )
		return notify_fail("�㲻����ѧϰ�����黭�ˡ�\n");
/*
	if(me->query("family/master_name") != "�����" )
		return notify_fail("��һ������Ĵ��ˣ�ѧ��Щ�ḯ���˵Ķ�����ʲô��\n");
*/
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�����黭ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
