#include <ansi.h>


inherit SPEC;

void create()
{
set_name (HIY"书剑宝钞"NOR, ({ "baochao"}));
        set("long","这是一张"HIY"书剑新纪元站流通的宝钞"NOR"，你可以兑换(exchange baochao)它来增加通宝数量。\n");

        set("unit","张");
        set_weight(100);
        set("value",3000000);
//        set("treasure",1); 
        set("degree",1);
        set("flag","spec/baochao");
        set("rest",10);
        set("desc","书剑通宝5000枚整，见票即兑。");
  set("credit",5000);                  
        setup();
}

void init()
{
        
        add_action("do_duihuan","exchange");    
}

int do_duihuan(string arg)
{
        object me=this_player();
        
        if (!arg)
                return notify_fail("你要兑换什么?\n");
            
        if (arg!="zitan baochao" && arg!="baochao")
                return notify_fail("你要兑换?\n");
        
        if (!restrict()&& !me->query("buyvip")) {return notify_fail("本周你已经不能使用"+this_object()->query("name")+"了。\n");}
    
        me->add("SJ_Credit", 5000);
 
        write(HIY"你把宝钞往自动取款机里一插，取出了5000个书剑通宝！\n"NOR);
        degree(); 
        return 1;
}       
