// bangjue.c �򹷰��ķ�
// by shang 97/6

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( (int)me->query_skill("stick", 1) < 30 )
		return notify_fail("��Ļ�������̫��, ����᲻�˰�����\n");
	if (me->query_skill("bangjue", 1) > 200)
		return notify_fail("���Ѿ��޷������İ����ˡ�\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("�򹷰��ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
