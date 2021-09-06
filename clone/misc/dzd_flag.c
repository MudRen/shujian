// flag

inherit ITEM;

#define XKD_D "/d/foshan/xkdd.c"

int do_check(string arg);

void create()
{
	set_name("�����־",({"dzd's flag"}));
	set_weight(1);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("env/invisibility",1);
		set("no_get",1);
		set("no_drop",1);
		set("no_give",1);
		set("dzd_obj",1);
	}
	setup();	
}

void init()
{
	//if(mapp(this_player()->query_temp("job_xkd")))
		add_action("do_check",({"chakan"}));
}

int do_check(string arg)
{
	object me;
	
	me = this_player();
	if(!mapp(me->query_temp("job_xkd"))) return 0;
	if(arg=="list") me->start_more(XKD_D->query_score(me,1));
	else me->start_more(XKD_D->query_score(me,0));
	return 1;
}

