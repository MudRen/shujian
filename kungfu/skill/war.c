// war.c

inherit SKILL;

void create() 
{ 
	seteuid(getuid()); 
}

string type() 
{ 
	return "knowledge"; 
}

int valid_learn(object me) 
{
	return notify_fail("ս��ֻ��ͨ���������鼮��ս���ſ���������\n");
}

int practice_skill(object me)
{	
	return notify_fail("ս��ֻ��ͨ���������鼮��ս���ſ���������\n");
}