// By Spiderii@yt 新写 铁掌擒拿手

#include <ansi.h>
string perform_name(){ return HBBLU"铁掌擒拿手"NOR; }
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;


        if( !target )
             target = offensive_target(me);
        if( !target 
          || !me->is_fighting(target)
          || !objectp(target)
          || !living(target)
          || environment(target)!= environment(me))return notify_fail("铁掌擒拿手只能在战斗中使用。\n");

          weapon = target->query_temp("weapon");

        if( userp(me) 
        &&( me->query_skill_mapped("parry") != "tiezhang-zhangfa"))
                return notify_fail("「铁掌擒拿手」必须在用铁掌掌法激发招架的情况下才能使用。\n");
/*
        if( userp(me) && (me->query_skill_mapped("force") != "guiyuan-tunafa"
        || me->query_skill_prepared("strike") != "tiezhang-zhangfa") )
                return notify_fail("你的内功或掌法不对，根本不能发挥出「铁掌擒拿手」的优势。\n");  

        if((int)me->query_skill("guiyuan-tunafa", 1)  < 150 )
             return notify_fail("你的归元吐呐法等级还不够，使不出「铁掌擒拿手」。\n");
*/
        if((int)me->query_skill("tiezhang-zhangfa",1) < 150 ) 
             return notify_fail("你的铁掌掌法等级不够，不会使用「铁掌擒拿手」。\n");


        if( me->query_temp("weapon"))
                return notify_fail("你先放下手中的武器再说吧？！\n");     


        if((int)me->query("neili") < 1500)
             return notify_fail("你的内力不够用来「铁掌擒拿手」。\n");

        if((int)me->query("jingli") < 500)
             return notify_fail("你的精力不够用来「铁掌擒拿手」。\n");
      
       message_vision(HIM"\n$N身形一晃突然变招，以迅雷不及掩耳之势，向$n肩上拿去！\n" NOR, me, target);

        if (objectp(weapon)) //如果对方手中有兵器,那么打掉
        {

              message_vision(HIM"\n$n急忙举起" + weapon->name() + HIM"挡格，$N变招快极，左手下压，已抓住" + weapon->name() + HIM"头部。掌缘甫触，尚未抓紧，已向里夺。\n"NOR, me, target);
              if (random(me->query_str()) > target->query_str()/2 ){

                          message_vision(HIM"\n$n浑身一热，手掌虎口巨痛，手中" + weapon->name() + HIM"脱手而出。\n"NOR, me, target);
                       weapon->unequip();
                        weapon->move(environment(target));
                        target->start_busy(1);
                       me->start_perform(5,"「铁掌擒拿手」");
                }
                else
                {
                        message_vision( HIM"\n怎料$n武功殊非泛泛，一惊之下，抓住" + weapon->name() + HIM"不放，你竟没有夺到！\n"NOR, me, target);
                        me->start_busy(1);
                       me->start_perform(3,"「铁掌擒拿手」");
              }
                return 1;
        }
        // 如果对手不是用的兵器的话 ,抓对方脉门,busy
           if (random(me->query_con()) > target->query_con()/2 ){
           message_vision(HIW"\n$n闪身急避，怎料$N双掌犹如附骨之蛆一般，一个不察，脉门要穴已被$N死死拿住。\n"NOR, me, target);
           target->add_busy(2+random(3));
           me->start_perform(5,"「铁掌擒拿手」");
               }
        else{
           message_vision( HIM"\n$n已有防备，知你手掌厉害，不敢硬接，猛地里身形急转，后退数步。\n"NOR, me, target);
           me->start_busy(1);
           me->start_perform(3,"「铁掌擒拿手」");
        }
                return 1;

}


