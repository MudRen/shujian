//flowray 2005.6.20
#include <ansi.h>


inherit SPEC; 

void create()
{
	set_name (HBMAG"洗髓丹"NOR, ({ "xisui dan","dan","xisui"}));
	set("long","这是一颗江湖人士梦寐以求的"HBMAG"洗髓丹"NOR"，据说使用("HIY"use xisui"NOR")后可以脱胎换骨。\n");

	set("unit","颗");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
        set("no_get",1);
        set("no_cun",1);
	set("degree",1);
	set("flag","spec/xishui");
        set("rest",7);
	set("desc","可以免费调整天赋一次（限定次数，不可保存）。");
        set("credit",2500);       
	setup();
}

void init()
{
	add_action("do_pray","use");
  
}

int do_pray(string arg)
{
	object me=this_player();
	    
	if (!arg)
      		return notify_fail("什么?\n");
      		
	if (arg!="xisui" && arg!="xisui dan" && arg!="dan")
      		return notify_fail("什么?\n");
       if (me->is_busy() || me->is_fighting() ) return notify_fail("你正忙着呢。\n");      	

      	if (me->query("can_cgift"))
      		return notify_fail("你上次服用的洗髓丹的效力尚未退去，还是等等再用吧!\n");
      		
      	if (!restrict()) {return notify_fail("本周你已经不能使用"+this_object()->query("name")+"了。\n");}   


	write(HIY"你吃下一颗"MAG"洗髓丹"HIY"，顿时觉得耳聪目明，筋骨强健......\n"NOR);
	write(HIW"你觉得自己的天赋分配好像有些不太合适，应该使用cgift来调整一下。\n"NOR);
         me->set("can_cgift",1);
	degree();
	return 1;
}	 
