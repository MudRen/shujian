// music.c

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
	return notify_fail("音律只能通过吹奏乐器或者研习乐谱提升。\n");
}

int practice_skill(object me)
{	
	return notify_fail("音律只能通过吹奏乐器或者研习乐谱提升。\n");
}