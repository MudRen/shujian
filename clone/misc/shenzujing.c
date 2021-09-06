#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("梵文经书", ({ "fanwen book", "jingshu", "fanwen", "book" }));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "每一页上都写满了弯弯曲曲的文字，没一字识得。\n");
                set("value", 500);
                set("material", "steel");
                set("no_give",1);
                set("no_get",1);
                set("no_drop",1);
                set("no_cun",1);

        }
}

void init()
{
	if (environment() == this_player())
		add_action("do_du", "read");
}

int do_du(string arg)
{
	object me = this_player();

	if (!id(arg)) 
		return notify_fail("你要读什么？\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	
	if ( query("owner") != me->query("id") )
		return notify_fail("你是怎么得到「神足经」的啊？\n");

	if ( me->query("neili") < 1500 )
		return notify_fail("你的真气不够。\n");

	if (environment(me)->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (environment(me)->query("pending"))
		return notify_fail("此地不宜研习「神足经」！\n");

	if (environment(me)->query("sleep_room"))
		return notify_fail("卧室不宜修练，会影响别人休息。\n");
 
	if (environment(me)->query("no_fight"))
		return notify_fail("此地不宜研习「神足经」！\n");

	if ( me->query("jing") < 40 )
		return notify_fail("你的精太少了，不够研读「神足经」。\n");

if((int)me->query("potential") < 1 )
return notify_fail("你的潜能已经用完了，再怎么读也没用。\n");



	

	tell_object(me, "你仔细研读着「神足经」的精妙之处。\n");
	me->receive_damage("jing", 30 );
	me->add("neili", - 50);
         me->add("potential", - random(3));

	me->improve_skill("yijin-jing", me->query_int());
	if (!random(8))
		message("vision", me->name() + "仔细研读着「神足经」的精妙之处。\n", environment(me), me); 
	return 1;
}
