// medicine.c ��������

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int i = me->query_skill("medicine", 1);
	int j = me->query_skill("literate", 1);

	if(i <= 100 && i > j+10)
		return notify_fail("��Ķ���д�ֵȼ��������޷��о�������ı�������\n"); 
	if(i > 100 && i <= 150 && i > j+15)
		return notify_fail("��Ķ���д�ֵȼ��������޷��о�������ı�������\n");
	if(i > 150 && i > j+20)
		return notify_fail("��Ķ���д�ֵȼ��������޷��о�������ı�������\n");
	if (me->query_temp("mark/medicine")) {
		me->delete_temp("mark/medicine");
		return 1;
	}	   
	return notify_fail("��������ֻ��ͨ����ϰҽѧ�鼮����ߡ�\n"); 
}

int practice_skill(object me)
{	
	return notify_fail("����������ͨ������ϰ������ߡ�\n");
}
