//fengyue 2009.1.17
#include <ansi.h>


inherit SPEC; 

void create()
{
     set_name (HIG"神奇葡萄"NOR, ({ "putao"}));
     set("long",GRN"这是一串由达摩传入中土的神奇葡萄,吃(eat)下它会发生奇怪的事情。\n"NOR);

     set("unit","串");
     set_weight(100);
     set("value",3000000);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("degree",3);
     set("flag","spec/putao");
     set("rest",9);
     set("desc","增加潜能三千点。");
     set("credit",20);
     setup(); 

 }
 
void init()
 {
    add_action("do_eat","eat");
   
 }

int do_eat(string arg)
 {
     object me=this_player();
     
         
     if (arg!="putao")
                     return notify_fail("你要吃什么?\n");
            
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("本周你已经不能使用"+this_object()->query("name")+"了。\n");}

            me->add("potential",1000);
    write(HIY"你吃下一颗"HIG"神奇葡萄"HIY"发现自己的潜能大增!\n"NOR);
set("no_cun",1);
     degree();
    return 1;
}    
