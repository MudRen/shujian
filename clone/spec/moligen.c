//flowray 2005.6.20
#include <ansi.h>


inherit SPEC; 

void create()
{
	set_name (HIC"百年茉莉根"NOR, ({ "moligen","gen"}));
	set("long","这是一根拥有百年历史的茉莉花的"HIW"百年茉莉根"NOR"，据说对它能让人变的丑陋不堪?
你可以服用（"HIY"fu"NOR"）它来降低容貌1-3点n");
	set("unit","只");
	set_weight(100);
	set("value",3000000);
  set("no_give",1);
  set("no_drop",1);	
  set("no_get",1);
	set("degree",1);
	set("flag","spec/moligen");
	set("desc","减少一至三点容貌。");
        set("credit",200);
	
	setup();
}

void init()
{
	add_action("do_eat","fu");
  
}

int do_eat(string arg)
{
	object me=this_player();
	    
	if (!arg)
      		return notify_fail("你要服用什么?\n");
      		
	if (arg!="gen" && arg!="huagen")
      		return notify_fail("你要服用什么?\n");
      	
      	if (me->query("per")<2)
      		return notify_fail("你都丑成这样了，还想出去吓人!\n");
      		
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("本周你已经不能使用"+this_object()->query("name")+"了。\n");}

	me->add("per",-(1+random(2)));
	write(HIW"你服下一只百年茉莉根觉得脸上发出一阵阵抽搐，显得格外难受。\n"NOR);
	degree();
	return 1;
}	 
