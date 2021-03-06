//updata by Jpei 2010 
//增加有效死亡次数death_times的威力。

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name(){ return HIB"天下无狗"NOR; }

int perform(object me,object target)
{
    object weapon;
    int i,j;
    
    if( !target ) target = offensive_target(me);
     
    if( !objectp (target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("天下无狗只能对战斗中的对手使用。\n");

    if(me->query_skill_mapped("force") != "huntian-qigong")
                return notify_fail("你的内功不是混天气功，无法使用天下无狗！\n");
    if( (int)me->query_skill("huntian-qigong", 1) < 250 )
                return notify_fail("你的内功还未练成，不能使用天下无狗！\n");
    if( (int)me->query_skill("dagou-bang", 1) < 250 ) 
                return notify_fail("你的打狗棒法还未练成，不能使用天下无狗！\n");
    if((int)me->query_skill("stick", 1) < 250 )
                return notify_fail("你的基本棒法不够娴熟，不能在使用天下无狗。\n");
    if((int)me->query_skill("bangjue", 1) < 180 )
                return notify_fail("你的打狗棒诀不够娴熟，不能在使用天下无狗。\n");
    if((int)me->query_con(1) < 45 )
                return notify_fail("你的身体不够强壮，不能使用天下无狗。\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "stick"
        || me->query_skill_mapped("stick") != "dagou-bang"
        || me->query_skill_mapped("parry") != "dagou-bang")
                return notify_fail("你现在使得了天下无狗么？\n");
                
    if((int)me->query("max_neili") < 4500 )
                return notify_fail("你的内力修为不够，不能使用天下无狗！\n");
    if((int)me->query("neili") < 2000 )
                return notify_fail("你现在真气不足，不能使用天下无狗！\n");

        message_vision(HIW"\n$N竹棒抖动，将一路“打狗棒法”使得变化万方，但见棒去如神龙夭矫，棒来又似灵蛇盘舞，奥妙招式,信手拈来！\n",me);
        message_vision(HIG"这正是打狗棒法的绝招「天下无狗」,据说共六种变化，一招使出,劲力所至,四面八方全是棒影，\n",me);
        message_vision(HIG"此时纵是有几十条恶犬也可一并打死了，所谓“天下无狗”便是此意，棒法之精妙绝伦，已臻武学中的绝诣!\n"NOR,me);

    me->start_perform(2+random(2),"「天下无狗」");
    i = (int)me->query_skill("dagou-bang",1);
    if ( me->query("death_times")) j = me->query("death_times");
     if(j>500) j = 500;

    me->add("neili", -300);
        me->add_temp("apply/attack",  i);
        me->add_temp("apply/damage",  i/3);
    me->add_temp("dgb/wugou",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    me->add_temp("dgb/wugou",1);
    if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    me->add_temp("dgb/wugou",1);
    if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    me->add_temp("dgb/wugou",1);
        me->add_temp("apply/attack",  -i);
        me->add_temp("apply/damage",  -i/3);

    if(me->query("dgb/wugou")){
        message_vision(HBRED"$N已得「天下无狗」六变之精要，出招行云流水，刹那间漫天的棒影挥向$n!\n"NOR,me,target);
   if( j>100 && me->is_fighting(target)&&!userp(target) ) target->add_busy(j/30);
   if( j>200 && me->is_fighting(target)&& userp(target) ) target->start_busy( (j/100) );
        i = i + j/10;
    me->add_temp("apply/stick",  i );
    me->add_temp("apply/strength",  i /10);
    me->add_temp("apply/attack",  i/2);
    me->add_temp("apply/damage",  i/2);
 
      if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        me->add_temp("dgb/wugou",1);
     if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        me->add_temp("dgb/wugou",1);
     if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
       
        me->add_temp("apply/stick", - i );
        me->add_temp("apply/strength",  - i /10 );
        me->add_temp("apply/attack",  -i/2 );
        me->add_temp("apply/damage",  -i/2);
        me->start_perform(5,"「天下无狗」");
    }
    me->delete_temp("dgb/wugou");
    me->start_busy(1);
    return 1;
}

int help(object me)
{
   write(HIB"\n打狗棒「天下无狗」："NOR"\n");
   write(@HELP
   此招共有六变，为打狗棒最终极的绝招，虽江湖上盛传丐帮
   弟子中，年轻有为者，已然学会该绝技，但只仅仅是招式而
   已，若能有幸得丐帮帮主洪老爷子亲口传授该绝技，领会该
   「天下无狗」之妙处，则使将出来乃威力无穷！

   要求：  最大内力 4500 以上；
           内力 2000 以上；
           打狗棒等级 250 以上；
           混天气功等级 250 以上；
           后天根骨 45 以上；
           打狗棒诀等级 180 以上；
           激发招架为打狗棒；
           解QUEST以后威力无穷。
           有效死亡次数极大的增加实战效果。
HELP
   );
   return 1;
}
