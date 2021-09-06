//flowray 2005.6.16
// By Spiderii 放宽每周的使用次数限制
#include <ansi.h>


inherit SPEC;

void create()
{
	set_name (HIR"极品"HIW"玉肌丸"NOR, ({ "jipinwan","wan","jipin wan" }));
	set("long","这是一颗"HIR"极品"HIW"玉肌丸"NOR"，你可以服(fu)下它提高精力和内力修为。\n");

	set("unit","颗");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
        set("no_get",1);
	set("degree",1);
	set("flag","spec/yuji1");
	set("rest",5 );
	set("desc","提高大量内力、精力的上限。");
        set("credit",1000);
	setup();
}

void init()
{
	add_action("do_eat","eat");
	add_action("do_eat","fu");    
}

int do_eat(string arg)
{
	object me=this_player();
	
	if (!arg)
		return notify_fail("你要服用什么?\n");
	    
	if (arg!="jipin wan" && arg!="wan")
		return notify_fail("你要服用什么?\n");
      	
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("本周你已经不能使用"+this_object()->query("name")+"了。\n");}
  
    
	me->add("neili", 900 + random(200) );
	me->add("max_neili", 900 + random(200) );
	me->add("jingli", 900 + random(200) );
	me->add("max_jingli", 900 + random(200) );

      me->setup();
	write(HIY"你服下一颗"HIR"极品"HIW"玉肌丸"HIY",顿觉精力内力大增!\n"NOR);
	degree(); 
	return 1;
}	 
