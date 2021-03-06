// shendao.c  血刀经 [神刀]
// changed by emnil@sj  2/5/2000

#include <ansi.h>
#include <skill.h>
#include <combat.h>
#include <weapon.h>
inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, weaname;
        int lvl,damage;
    
        if( !me->is_fighting() )
                return notify_fail("「神刀穿心」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");

        if((int)me->query_dex() < 28)
                return notify_fail("你的身法不够, 目前还不能使用这项绝技! \n");

        if((int)me->query_skill("dodge") < 110)
                return notify_fail("你的轻功修为不够, 不能使用「神刀穿心」！\n");
 
        if((int)me->query_skill("xuedao-jing",1) < 100)
                return notify_fail("你的刀法修为不够， 目前不能使用「神刀穿心」! \n");

        if((int)me->query_skill("longxiang-boruo",1) < 100)
                return notify_fail("你的龙象般若功修为不够， 目前不能使用「神刀穿心」! \n");

        if( me->query_skill_mapped("blade") != "xuedao-jing")
                return notify_fail("你必须使用血刀经，才能使用「神刀穿心」的绝技！\n");

if (me->query_skill("huoyan-dao", 1) > 1) 
return notify_fail("你修炼火焰刀与血刀经义理相悖，不能施展。\n");
        if( me->query_skill_mapped("force") != "longxiang-boruo" && me->query_skill_mapped("force") != "shenzhao-jing"  )
                return notify_fail("你现在所使用的内功既非龙象功又非神照功，不能使出「神刀穿心」的绝技！\n");

        if( (int)me->query("max_neili") < 1300 )
                return notify_fail("你的内力修为不够！\n");
        if((int)me->query("neili")<600)
                return notify_fail("你的真气不够！\n"); 
        if((int)me->query("jingli")<200)
                return notify_fail("你的精力不够！\n"); 

        ob = me->select_opponent();
        lvl = me->query_skill("xuedao-jing",1);
        weapon = me->query_temp("weapon");
        weaname = weapon->query("name");
        msg = HIR "\n$N狂啸声中，运起「神刀穿心」秘诀，刹时身法如电，"NOR+weaname+HIR"一分为四，劈将出去！\n"NOR;
        
        
        message_vision(msg, me);
        
    if(!userp(target) &&( me->query_skill("xuedao-jing",1)<=250|| me->query_skill("xuedao-jing",1)>=451 ) )    
        target->add_busy(2);
        
        if(me->query_temp("xs/longxiang")) {
                damage = me->query_skill("longxiang-boruo",1)/2;
                if(damage > lvl/3) damage = lvl/3;
                me->add_temp("apply/damage", damage);
                message_vision(MAG"$N更把龙象内劲附于兵刃之上，"+weaname+MAG"通体流淌着异样的紫色光芒！\n"NOR, me,target);
        }

        if(me->query_temp("sjz_power")) {
                damage = me->query_skill("shenzhao-jing",1)/2;
                if(damage > lvl/3) damage = lvl/3;
                me->add_temp("apply/damage", damage);
                message_vision(WHT"$N体内神照真气顺势激荡，刀锋隐隐漾着一缕惨白，透出一股肃杀犀利的气息！\n"NOR, me,target);
                me->set_temp("xdpfm",1);
        }




if (me->query("quest/雪山/shendao/jidao")) {
if (!userp(target)) target->set_temp("must_be_hit",1);
me->add_temp("apply/attack", lvl);
me->add_temp("apply/party", lvl);
me->add_temp("apply/dodge", lvl);
msg = RED"$N将祭刀时领悟的精髓发挥出来，双目赤红，人刀合一，直取$n心脏，正合「神刀穿心」之意。\n"NOR;
 if (present(ob,environment(me)) && me->is_fighting(ob))
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 3);

target->receive_damage("qi", damage*2, me);
target->receive_wound("qi", damage, me);

msg += COMBAT_D->damage_msg(damage,"割伤",me,target);
 message_vision(msg,me,target);
}

 me->add_temp("apply/blade", lvl/4);
 me->add_temp("apply/damage", lvl/2);
 me->add_temp("apply/attack", lvl/2);


        if (present(ob,environment(me)) && me->is_fighting(ob))
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 3);

        if (present(ob,environment(me)) && me->is_fighting(ob))
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 3);

        if(lvl >150)
                if (present(ob,environment(me)) && me->is_fighting(ob))
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 3);

        if(lvl >180)
                if (present(ob,environment(me)) && me->is_fighting(ob))
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 3);

        me->add("neili", -200-random(300));
        if(me->query("neili")<0) me->set("neili",0);
        me->add("jingli", -80);
        
        
  if(me->query_skill("xuedao-jing",1)<=450 )      me->start_busy(random(2)+ 1);
  	
        me->start_perform(3,"神刀穿心");
        me->add_temp("apply/blade", -lvl/4);
        me->add_temp("apply/damage", -lvl/2);
        me->add_temp("apply/attack", -lvl/2);
        
        if(me->query_temp("xs/longxiang")) {
            me->add_temp("apply/damage", -damage);
        }
 if(me->query_temp("sjz_power")) {
            me->add_temp("apply/damage", -damage);
            me->delete_temp("xdpfm");
        }

if (me->query("quest/雪山/shendao/jidao")) {

 me->add_temp("apply/attack", -lvl);
me->add_temp("apply/party", -lvl);
me->add_temp("apply/dodge", -lvl);
target->delete_temp("must_be_hit",1);
}
        return 1;
}

