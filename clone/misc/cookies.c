
// By fengyue
// 礼物3

#include <ansi.h>

inherit SPEC;
void create()
{
        set_name(HIY"神秘小甜饼"NOR, ({ "cookie" }) );
        set_weight(10);
                set("unit", "个");
                set("long", "这是一盒包装精美的神秘小甜饼，仔细品尝(pinchang)它吧。\n");
                set("value", 0);
                set("material", "wood");
                set("no_drop", "这样贵重的东西怎么能随便乱丢呢。\n");
                set("no_get", "这样东西不能离开那儿。\n");
                set_weight(100);
                set("value",3000000);
                set("treasure",1);
                set("degree",1);
                set("flag","spec/gqcookie");
                set("desc","神秘小甜饼");
                set("credit",150);    
       setup();
}

void init()
{
        add_action("do_chai", "pinchang");
}



int do_chai(string arg)
{        
        object me = this_player();
        int t, ts, exp, total;
        object obj,obn, obm;
        

        if(arg!="cookie"&&arg!="bing")
           return notify_fail("你要品尝什么?\n");  
 /*
      if(me->query("wizpot1")) 
         return notify_fail("你吃那么多不怕撑死？\n"); 
 */              

      message_vision(HIW"$N津津有味的品尝着一个"+HIY+"神秘小甜饼"+HIW+" 。\n"NOR,me); 
    

        obj = new("/cmds/leitai/bwdh/obj/danwan");
        obj->set("owner",me->query("id"));
        obj->set("secret_obj",1);
        obj->set("bonus","combat_exp");
        obj->move(me);          
     message_vision(HIC"$N从"+HIY+"神秘小甜饼"+HIC+"中发现一颗"+obj->name()+"。\n"NOR, me);  

        obn = new("/cmds/leitai/bwdh/obj/danwan");
        obn->set("owner",me->query("id"));
        obn->set("secret_obj",1);
        obn->set("bonus","combat_exp");
        obn->move(me);          

     message_vision(HIC"$N从"+HIY+"神秘小甜饼"+HIC+"中发现一颗"+obn->name()+"。\n"NOR, me);  

        obm = new("/cmds/leitai/bwdh/obj/danwan");
        obm->set("owner",me->query("id"));
        obm->set("secret_obj",1);
        obm->set("bonus","combat_exp");
        obm->move(me);          

     message_vision(HIC"$N从"+HIY+"神秘小甜饼"+HIC+"中发现一颗"+obm->name()+"。\n"NOR, me);  


if(me->query("relife/combat_exp"))
{
      t = (int)me->query("relife/time",1);
     ts = (int)me->query("relife/times",1);
    exp = (int)me->query("relife/combat_exp",1);
  total = (int)me->query("relife/gift/total",1);


   if(total>50)  total = (int)me->query("relife/gift/total",1);
   if(total>40 && total< 50 )  total = 45+random(5);
   if(total>30 && total< 40)  total = 35+random(5);
   if(total <30)  total = 25+random(5);
 
 
      me->delete("relife");       
      me->set("relife/time",t); 
      me->set("relife/times",ts);
      me->set("relife/combat_exp",exp);
      me->set("relife/gift/now",total);
      me->set("relife/gift/total",total);
      me->set("wizpot1",1);

if((int)me->query("relife/combat_exp",1)>= 50000000)
      { me->set("relife/exp_ext",25); }
       
       else if((int)me->query("relife/combat_exp",1)>= 40000000)
           {me->set("relife/exp_ext",20);}

            else if((int)me->query("relife/combat_exp",1)>= 30000000)
                {me->set("relife/exp_ext",15);}

                 else{ me->set("relife/exp_ext",10); }
      tell_object(me, HIG"你得到了女神奥黛雷赫的祝福，你的转生exp光环强度增加了！\n"NOR);
   
      tell_object(me, HIM"你得到了女神奥黛雷赫的祝福，天赋重新分配!你现在有"+ HIR + chinese_number(total) + CYN +"点「"+HIM+"天赋技能"+CYN+"」！\n"NOR);
}
      me->set("kar,30");
      message_vision(HIW"$N的运气提高了！ \n"NOR,me); 
      destruct(this_object());
        return 1;
                
}

