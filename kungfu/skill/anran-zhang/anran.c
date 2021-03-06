// 黯然销魂
// By River 
#include <ansi.h>
#include <combat.h> 

inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl, i;

        lvl = me->query_skill("anran-zhang", 1) *2;

        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target) )
                return notify_fail("「黯然销魂」只能在战斗中使用。\n");

        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「黯然销魂」！\n");   

        if( (int)me->query_skill("anran-zhang", 1) < 150 )
                return notify_fail("你的黯然销魂掌还不够娴熟，使不出「黯然销魂」绝技。\n");

        if( (int)me->query_skill("yunu-xinjing", 1) < 150 )
                return notify_fail("你的玉女心经等级还不够，使不出「黯然销魂」绝技。\n");

        if ( me->query_skill_mapped("strike") != "anran-zhang"
         || me->query_skill_mapped("parry") != "anran-zhang"
          || me->query_skill_prepared("strike") != "anran-zhang"
          || me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("你现在无法使用「黯然销魂」绝技！!!!!!!!!!!!!\n");

        if((int)me->query_temp("xinjing")) 
                return notify_fail("你正在使用「心经」字诀。\n");

        if((int)me->query("max_neili") < (me->query_skill("force")+lvl+100) )
                return notify_fail("你现在内力太弱，使不出「黯然销魂」。\n");      

        if((int)me->query("neili") < (me->query_skill("force")+lvl) )
                return notify_fail("你现在真气太弱，使不出「黯然销魂」绝技。\n");

        if((int)me->query("eff_qi") >= (int)me->query("max_qi"))
                return notify_fail("你现在心情很好，怎么使得出「黯然销魂」绝技。\n");

        if((int)me->query_temp("xiaohun")) 
                return notify_fail("你现在正在使用「消魂」绝技。\n"); 

        if((int)me->query("qi") == 0 )
                return notify_fail("你现在无法使用「黯然销魂」绝技。\n");

        me->add_temp("anran", 2);
        i = (int)me->query("max_qi") / (int)me->query("eff_qi");

        if( i > 3 ) i = 3;
        if( i < 1 ) i = 1;

        if( i > 1 ){
           me->add_temp("apply/strength",lvl/3);
           me->set_temp("hurt", 1);
        } 
        
        me->add_temp("apply/damage", lvl/2);
        me->add_temp("apply/strike", lvl);
        target->set_temp("must_be_hit",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), i);
        if (present(target,environment(me)) && me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), i);

        me->add_temp("apply/damage", -lvl/2);
        me->add_temp("apply/strike", -lvl);

        if(me->query_temp("hurt")){
           me->add_temp("apply/strength",-lvl/3);
            me->delete_temp("hurt");
        }
        me->add("neili", -(me->query_skill("force") + random(lvl)));
        me->add("jingli", -50);
        me->delete_temp("anran");
        me->start_perform(5,"黯然销魂");
         target->delete_temp("must_be_hit");
        me->start_busy(1+random(2));
        return 1;
}
string perform_name(){ return HIB"黯然"NOR; }
int help(object me)
{
         write(HIB"\n黯然销魂掌「黯然」："NOR"\n");
        write(@HELP
杨过自和小龙女在绝情谷断肠崖前分手，心中日夜思念期盼小龙女，
渐渐形销骨立，了无生趣。他在海潮之中苦练，终于悟出了一十七招
掌法。他将这套掌法定名为黯然销魂掌，取的是江淹「别赋」中那句
黯然销魂者，唯别而已矣之意。这掌法中逆中有正，正反相冲，无一
不是妙到巅毫。受伤越重威力越大,实是置死地而得后生!

要求：
        玉女心经：150
        黯然销魂掌：150
HELP
        );
        return 1;
}
