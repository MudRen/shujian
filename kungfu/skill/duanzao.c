// duanzao.c

inherit SKILL;

string type() { return "knowledge"; }
string type2() { return "worker"; }

void skill_improved(object me)
{
}

int valid_learn(object me)
{
	int lvl;
	
	if(me->query_skill("duanzao",1)>220)
	{
		lvl = me->query("forging2/duanzao");
		if(!lvl || lvl < (me->query_skill("duanzao",1)-220)/10 )
		return notify_fail("������ϸ������켼�ܵ�ʱ��ͻȻ���ú���ȱ����Щʲô������\n");
	}
	return 1;
}