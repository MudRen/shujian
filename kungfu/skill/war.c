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
	return notify_fail("战术只能通过读军事书籍或战争才可以提升。\n");
}

int practice_skill(object me)
{	
	return notify_fail("战术只能通过读军事书籍或战争才可以提升。\n");
}