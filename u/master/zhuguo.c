//fengyue 2009.1.17
#include <ansi.h>


inherit SPEC; 

void create()
{
     set_name (HIR"万年朱果"NOR, ({ "zhuguo"}));
     set("long",HIR"这是一枚天神闪电精心培育的万年朱果,吃(eat)下它会发生奇怪的事情。\n"NOR);

     set("unit","枚");
     set_weight(100);
     set("value",3000000);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("degree",2);
     set("flag","spec/zhuguo");
     set("rest",9);
     set("desc","神奇物品。");
     set("credit",15000);
     setup(); 

 }
 
void init()
 {
    add_action("do_eat","eat");
   
 }

int do_eat(string arg)
 {
     object me=this_player();
     
         
     if (arg!="zhuguo")
                     return notify_fail("你要吃什么?\n");
            
            if (!restrict()) {return notify_fail("本周你已经不能再吃"+this_object()->query("name")+"了。\n");}   

            me->add("potential",100000);
//            me->add("SJ_Credit",1000);
//            me->add("balance",1000000);
            me->add("combat_exp",100000);
    write(HIY"你吃下一枚"HIR"万年朱果"HIY"发现自己武学修为大增!\n"NOR);
     degree();
    return 1;
}    
