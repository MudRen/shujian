// political.c

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
	return notify_fail("����ֻ��ͨ���Ķ���ʷ�伮�ſ���������\n");
}

int practice_skill(object me)
{	
	return notify_fail("����ֻ��ͨ���Ķ���ʷ�伮�ſ���������\n");
}