
inherit NPC;

nosave int wa = 0;

void create()
{
	set_name("��",({"god"}));
	wa = 0;
	setup();
}
/*
varargs mixed query(string prop, int raw)
{
	if(prop=="id")
	{
		wa = wa + 1;
		if(wa < 4 ) return "";
		return sprintf("system%droot",getoid(this_object()));
	}
	return ::query(prop,raw);	
}
*/