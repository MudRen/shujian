// caiji.c

inherit SKILL;

string type() { return "knowledge"; }
string type2() { return "worker"; }

void skill_improved(object me)
{
}

int valid_learn(object me)
{
	int lvl;
	
	if(me->query_skill("caiji",1)>220)
	{
		lvl = me->query("forging2/caiji");
		if(!lvl || lvl < (me->query_skill("caiji",1)-220)/10 )
		return notify_fail("������ϸ����ɼ����ܵ�ʱ��ͻȻ���ú���ȱ����Щʲô������\n");
	}
	return 1;
}
