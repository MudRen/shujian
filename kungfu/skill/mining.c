// mining.c

inherit SKILL;

void create() 
{ 
	seteuid(getuid()); 
}

string type() 
{ 
	return "skill"; 
}

int valid_learn(object me) 
{
	return notify_fail("�ɿ���ֻ�ܿ��ɿ�����ߡ�\n");
}

int practice_skill(object me)
{	
	return notify_fail("�ɿ���ֻ�ܿ��ɿ�����ߡ�\n");
}
