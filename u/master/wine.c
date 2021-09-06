 //wine.c 2009 By fengyue
#include <ansi.h>

 
inherit SPEC; 
 
void create()
{
        set_name (HIR"虎骨龙威酒"NOR, ({ "wine", "jiu" }));
        set("long","这是一坛"+HIR"虎骨龙威酒"NOR"，是武林之人常喝(he)的驱寒解乏之物。\n");
        set("unit","小坛");
        set_weight(100);
        set("value",3000000);
        set("no_give",1);
        set("no_drop",1);
        set("no_cun",1);
        set("degree",1);
        set("flag","spec/wine");
        set("desc","强身健体，驱寒解乏。");
        set("credit",2000);
     setup();
} 
 
void init()
{
        add_action("do_he","he");
   
}
 
int do_he(string arg)
{
        object me=this_player();
        
        if (me->query_temp("wine_power"))  return notify_fail("酗酒有害身体健康！本次登陆你已经不能再多喝了！\n");
        if (arg!="wine")
                 return notify_fail("你要喝什么?\n");
        if (!restrict()) return notify_fail("酗酒有害身体健康！本周你已经不能再多喝了！\n");
        me->add_temp("apply/dodge",100);
        me->add_temp("apply/armor",300);
        me->add_temp("apply/force",100);
        me->add_temp("apply/parry",100);
        me->add_temp("apply/damage",100);
        me->add_temp("apply/attack",80);
        me->set_temp("wine_power",1);
      write(HIY"你掏出了一小坛"HIR"虎骨龙威酒"HIY"，狠狠的抿了一口！\n"NOR); 
        degree();
        return 1;
}    
