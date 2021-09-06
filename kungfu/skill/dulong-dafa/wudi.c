// wudi.c 
// by fengyue

#include <ansi.h>
inherit F_CLEAN_UP;

string exert_name() {return HIR"无敌大法"NOR;}

void remove_effect(object me, int amount);
void remove_effect2(object me, int amount);

int exert(object me)
{
        int i;
        string s;

        if((int)me->query_skill("dulong-dafa",1) < 100  )
                return notify_fail("你的毒龙大法功力不够，无法施用「无敌」大法。\n");
        
        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够，无法使用「无敌」大法。\n");
 
        if((int)me->query("eff_qi") < me->query("max_qi")/3 )
            return notify_fail("你现在受伤过重，不能使用「无敌」大法。\n");

        if( me->query_temp("sld/wudi") && environment(me)->query("no_death"))
               return notify_fail("没必要生死相搏吧。\n");

        if( (int)me->query_temp("sld/wudi2") )
                return notify_fail("你已经发挥了你的最大潜力。\n");

        if((int)me->query("neili") < 400  )
                return notify_fail("你的真气不够，无法使用「无敌」大法。\n");

        i = me->query_skill("dulong-dafa", 1);
      
 //  if( me->query_temp("sld/wudi") && me->query("eff_qi") < me->query("max_qi") && me->query_temp("sld/wudi1") && !me->query_temp("sld/wudi2") )
     
     if( me->query_temp("sld/wudi") && me->query("eff_qi") < me->query("max_qi") && me->query_temp("sld/wudi1") && !me->query_temp("sld/wudi2") )
     
  {
           if( me->is_fighting() )
          {   
                s=RED"\n$N发疯般的叫道：“洪教主神通护佑，众弟子勇气百倍，以一当百，以百当万。\n"+
                "洪教主神目如电，烛照四方。我弟子杀敌护教，洪教主亲加提拔，升任圣职。\n"+ 
                "我教弟子护教而死，同升天堂！”，突然喷出一口鲜血，似乎已经忘记了伤痛！\n\n"NOR;

            //    me->delete_temp("sld/wudi");
                me->add("max_neili", -2); // 两点max neili作为代价得到高攻击力
                me->add_temp("apply/strength", i/20);
                me->reincarnate();
                me->set("neili", me->query("max_neili")*2);
                me->set("jingli", me->query("eff_jingli")*2);
                me->set_temp("double_attack",1);
                me->add_temp("apply/attack", i/3);
                me->set_temp("sld/wudi2", i);

       call_out("remove_effect2", 1, me, i/5);

                me->start_exert(1,"「无敌」");
                message_vision(s, me);
                return 1;
          }
      return notify_fail("你又没在战斗，用得着这么拼命么？\n");

        }
           

 
  if( !me->query_temp("sld/wudi2") && !me->query_temp("sld/wudi") && !me->query_temp("sld/wudi1") )
        {  
                me->add("neili", - 200);
                s=HIR"\n$N大声叫道：“洪教主神通广大，我教战无不胜，攻无不克，无坚不摧，无敌不破，\n"+
                "敌人望风披靡，逃之夭夭！”，双眼突然冒出一丝红光，似乎突然增加了功力！\n\n"NOR;
                 
                 me->add_temp("apply/attack", i/4);
                 me->add_temp("apply/strength", i/20);
                 me->set_temp("sld/wudi", i);
                 me->set_temp("sld/wudi1",i);
                 

           call_out("remove_effect", 1, me, i/3);
          
                me->start_exert(1,"「无敌」");
                message_vision(s, me);
                return 1;
       }

     return notify_fail("你现在不需要使用「无敌」大法。\n");
}

void remove_effect(object me, int count)
{
        int i;
        if( objectp(me) && me->query_temp("sld/wudi1") ) 
            {
               if( count-- > 0 ) { 
                      call_out("remove_effect", 1, me, count);
                     return;
                                 }
           i = me->query_temp("sld/wudi1");
           me->add_temp("apply/strength", -i/20);
           me->add_temp("apply/attack", -i/4);
           me->delete_temp("sld/wudi");
           me->delete_temp("sld/wudi1"); 
    message_vision(HIR"\n$N好象虚脱了一样，突然垮了下来！\n\n"NOR,me);
            }
}

void remove_effect2(object me, int count)
{
        int i;
        if( objectp(me) && me->query_temp("sld/wudi2") ) 
            {
               if( count-- > 0 ) { 
                      call_out("remove_effect2", 1, me, count);
                     return;
                                 }
       
        i = me->query_temp("sld/wudi2");
        me->add_temp("apply/strength", -i/20);              
        me->add_temp("apply/attack", -i/3);
        me->delete_temp("double_attack");
        me->delete_temp("sld/wudi2");
        message_vision(RED"\n$N心神一松，再也支持不主！\n"NOR,me);   
     // me->unconcious();

          }
}
