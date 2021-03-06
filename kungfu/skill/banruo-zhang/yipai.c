//banruo-zhang's perform yipai(一拍两散)
//cool 981226

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, i;
        mapping pre;
        string *skill, a, b;
        
        if( !objectp(target) ) target = offensive_target(me);
        
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) || !living(target) 
         || environment(target)!=environment(me))
                return notify_fail("一拍两散绝招只能对战斗中的对手使用。\n");      

        if((int)me->query_skill("banruo-zhang", 1) < 180 )
                return notify_fail("你的般若掌还不够熟练，不能使用一拍两散绝招对敌！\n");

        if((int)me->query_skill("yijin-jing", 1) < 180 )
                return notify_fail("你的易筋经功还不够熟练，不能使用一拍两散绝招对敌！\n");
 
        if((int)me->query_skill("strike", 1) < 180 )
                return notify_fail("你的掌法不够娴熟，使不出般若掌的绝招！\n");
                
        if(objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「一拍两散」！\n");
        
        if (me->query_skill_prepared("strike") != "banruo-zhang"
         || me->query_skill_mapped("strike") != "banruo-zhang")
                return notify_fail("你必须先将般若掌运用于掌法之中才行。\n");

        if(me->query_skill_mapped("parry") != "banruo-zhang")
                return notify_fail("你必须先将般若掌运用于招架之中才行。\n");

        if((int)me->query("max_neili") < 3000 )
                return notify_fail("你内力修为不足，使不出般若掌的绝招！\n");     

        if( (int)me->query("neili") < (int)me->query("max_neili")*2/3 )
                return notify_fail("你现在内力不足，使不出般若掌的绝招！\n");     

        if( (int)me->query("jingli") < me->query("eff_jingli")/2 )
                return notify_fail("你现在精力不足，使不出般若掌的绝招！\n");   
                
//        me->start_perform(15, "一拍两散");

        message_vision(HIR"\n$N孤注一掷，将全身功力汇于一掌之内拍出！\n" NOR, me);
 
        pre = me->query_skill_prepare();
        skill = keys(pre);     
        for (i=0; i<sizeof(skill); i++){
                if(skill[i]=="strike") continue; 
                a = skill[i];
                b = pre[skill[i]];
                me->prepare_skill(skill[i]);
        }
         
        if ( (int)me->query("combat_exp",1) < (int)target->query("combat_exp",1) )
                damage = me->query("neili")/10;
        else    damage = me->query("neili")/3;
        me->set_temp("brz_yipai", 1);
        me->set("jiali", damage);

        if(wizardp(me))  tell_object(me, "Jiali = "+damage+"。");

        if( !me->query_temp("sl/xiouliqiankun") && !me->query_temp("fumo")){
                me->add_temp("apply/attack", me->query_int());
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); // attack in normal power. snowman@SJ
                me->add_temp("apply/attack", -me->query_int());
        }
        
        me->prepare_skill(a,b);
        
        me->set("neili", 0);
        me->set("qi",10);
//        me->set("eff_qi";10);
//        me->set("jingli",0);
        me->set("jing",0);     
        me->delete("jiali");
//        me->set("jingli", me->query("eff_jingli")/2);
        
        if(!target->is_killing(me->query("id"))) 
                target->kill_ob(me); // hehehehehehe.....
        me->start_busy(5);
        if(!target->is_busy())
                target->start_busy(1); 
        return 1;
}
string perform_name(){ return HIR"一拍两散"NOR; }
