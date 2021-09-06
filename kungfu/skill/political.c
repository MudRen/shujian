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
	return notify_fail("政治只能通过阅读历史典籍才可以提升。\n");
}

int practice_skill(object me)
{	
	return notify_fail("政治只能通过阅读历史典籍才可以提升。\n");
}