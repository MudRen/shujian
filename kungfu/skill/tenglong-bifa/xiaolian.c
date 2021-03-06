// guifei 小怜横陈
// created by olives@SJ
// Update By lsxk@hsbbs 2007/6/6
/*
     蓦见夫人脑袋向着她自己胸口钻落，敌人架颈中的一刀自然落空，她顺势在
地下一个筋斗在教主胯下钻过，握着匕首的右手成拳，轻轻一拳击在教主后心，
只是剑尖向上。倘若当真对敌，这一剑自然插入了敌人背心。韦小宝又大叫一声
：“好！”

*/
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include <combat_msg.h>

string perform_name() {return HIR"小怜横陈"NOR;}

int perform(object me, object target)
{
        object weapon;
        string msg;
        int lvl,i;

        if(!target) target = offensive_target(me);

         if( !objectp(target)
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("「小怜横陈」只能在战斗时使用！\n");

        if(me->query("family/master_id")!="hong antong")
                return notify_fail("「小怜横陈」只有拜了教主后才能用！\n");

        if(!objectp(weapon=me->query_temp("weapon"))
        || weapon->query("skill_type") != "dagger")
             return notify_fail("你手上没有匕首，如何使用「小怜横陈」。\n");
        
        if((int)(me->query("dex")+me->query_skill("dodge",1)/10) < 30 )
                return notify_fail("你身法不够，使用「小怜横陈」，恐怕会伤到自己！\n");

        if((int)me->query_skill("tenglong-bifa", 1) < 250 )
                return notify_fail("你的腾龙匕法还不够熟练，不能使用「小怜横陈」！\n");

        if((int)me->query_skill("dagger",1) < 250)
                return notify_fail("你的基本匕法不够熟练，不能使用「小怜横陈」！\n");
/*
        if(me->query_skill_mapped("strike") != "huagu-mianzhang"
        || me->query_skill_prepared("strike") != "huagu-mianzhang")
                return notify_fail("你现在没有做好准备，无法使用「小怜横陈」！\n");
*/
        
        if(me->query_skill_mapped("dagger") != "tenglong-bifa")
                return notify_fail("只有使用腾龙匕法时才能使用「小怜横陈」！\n");

        if( (int)me->query_skill("dulong-dafa", 1) < 250 )
                return notify_fail("你的毒龙大法功力不足，不能用「小怜横陈」。\n");

        if( (int)me->query_skill("force", 1) < 250 )
                return notify_fail("你的基本内功功力不足，不能用「小怜横陈」。\n");

        if((int)me->query("max_neili", 1) < 4000)
                return notify_fail("你现的内力修为不足，不能使用「小怜横陈」！\n");

        if((int)me->query("eff_jingli", 1) < 2500)
                return notify_fail("你现的精力修为不足，不能使用「小怜横陈」！\n");

        if((int)me->query("jingli", 1) < 800)
                return notify_fail("你现在精力不足，不能使用「小怜横陈」！\n");

        if((int)me->query("neili", 1) < 1500)
                return notify_fail("你现在内力不足，不能使用「小怜横陈」！\n");
/*
        if(me->query("gender") == "男性" )
                return notify_fail("不是女人怎么能使用「小怜横陈」呢！\n");
*/
        if( me->query_skill_mapped("force") != "dulong-dafa")
                return notify_fail("你现在所使用的内功同毒龙大法相互抵触，不能使用「小怜横陈」。\n");

        msg = HIR"$N乘$n稍稍走神之机，拼尽全力使出苏夫人不传之绝技－－「小怜横陈」"NOR;
        msg +=MAG "\n$N使出一招「小怜横陈」，脑袋蓦地向自己胸口钻落，顺势在地上一个斛斗，\n从$n胯下钻过，握着兵器的右手成拳向$n后心连捶数下。\n"NOR;
        lvl = ((int)me->query_skill("tenglong-bifa",1)+(int)me->query_skill("huagu-mianzhang",1)+(int)me->query_skill("dagger",1))/3;
        message_vision(msg,me,target);
        me->receive_damage("jingli",100);
        me->receive_damage("neili",300);
        me->add_temp("apply/strength",lvl/8);
        me->add_temp("apply/attack",lvl/2);
        me->add_temp("apply/damage",lvl/3);
        me->set_temp("sld/pfm/xiaolian",1);
             i=3;
if(!userp(target) || lvl>=450 ) target->add_busy(2);
        COMBAT_D->do_attack(me,target,weapon,i);
        if(objectp(target) && me->is_fighting(target))
        {
//                weapon->unequip();
                COMBAT_D->do_attack(me,target,weapon,i);
//                weapon->wield();
        }
        if(objectp(target) && me->is_fighting(target))
                COMBAT_D->do_attack(me,target,weapon,i);
        if(objectp(target) && me->is_fighting(target))
        {
                if(random(me->query("combat_exp"))>target->query("combat_exp")/3)
                        COMBAT_D->do_attack(me,target,weapon,i);
                else
                        COMBAT_D->do_attack(me,target,weapon,TYPE_RIPOSTE);
        }
        me->delete_temp("sld/pfm/xiaolian");
        me->add_temp("apply/strength",-lvl/8);
        me->add_temp("apply/attack",-lvl/2);
        me->add_temp("apply/damage",-lvl/3);

        me->start_busy(1);
        me->start_perform(3+random(2),"「小怜横陈」");
        return 1;
}

int help(object me)
{
   write(WHT"\n腾龙匕法「"HIR"小怜横陈"WHT"」："NOR"\n");
   write(@HELP

    要求：最大内力 4000 以上；
          最大精力 2500 以上；
          当前内力 1500 以上；
          当前精力 800 以上；
          腾龙匕法等级 250 以上；
          基本匕法等级 250 以上；
          毒龙大法等级 250 以上；
          基本内功等级 250 以上；
          后天身法 30 以上；
          性别需求 女性。
HELP
   );
   return 1;
}
