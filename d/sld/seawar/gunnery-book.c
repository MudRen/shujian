// by 无名英雄

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIM"『海战对阵炮术谋略』"NOR, ({ "gunnery's book", "book" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", HIY"这是一本施琅将军手书的海战对阵炮术谋略笔记，\n"+
			"你觉得自己应该仔细研读（Read）一下。\n"NOR);
		set("value", 1);
		set("material", "paper");
                            set("treasure", 1);
		set("jing_cost", 18);
		set("difficulty", 1);
//                 set("max_skill", 1);
                            set("treasure", 1);
set("unique", 1);


	}
}

void init()
{
	if( environment() == this_player() )
		add_action("do_du", "read");
}

int do_du(string arg)
{
	object me,ob;
	int i, j;

	me = this_player();
	ob = this_object(); 

	i = (int)me->query_skill("gunnery", 1);
	j = (int)me->query_skill("literate", 1);

	if( !(arg == ob->query("id") || arg == "book") ) return 0;

	if( !me->query_skill("literate", 50) )
		return notify_fail("你几乎算是个文盲，先学点文化(literate)吧。\n");	   

	if( me->is_busy() )
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() ) 
		return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if( !id(arg) )
		return notify_fail("你要读什么？\n");

	if( !random(5) )
		message("vision", me->name() + "正专心地研读" + this_object()->name()+"。\n", environment(me), me);

	if( (int)me->query("jing") < ob->query("jing_cost") )
		return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");

	if( me->query_int() < ob->query("difficulty") )
		return notify_fail("你研读了一会儿，发现根本不能领悟到上面写些什么。\n");

	if( i > ob->query("max_skill") )
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");

	me->receive_damage("jing", ob->query("jing_cost")); 
	me->improve_skill("gunnery", me->query_int() + 30);
	write("你仔细研读着"+ob->name()+"，觉得自己海战对敌炮术受益良多。\n");
	return 1;
}
