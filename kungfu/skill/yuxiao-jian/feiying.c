// feiying.c
// YUJ@SJ 2002-07-12

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int lvl,j, qi2;

        lvl = me->query_skill("yuxiao-jian", 1);
        lvl += me->query_skill("tanzhi-shentong", 1);
        lvl += me->query_skill("luoying-zhang", 1);
        lvl += me->query_skill("lanhua-shou", 1);
        lvl += me->query_skill("xuanfeng-tui", 1);
        lvl += me->query_skill("suibo-zhuliu", 1);
        lvl /= 6;


        if (!target) target = offensive_target(me);

        if (!objectp(target)
        || !me->is_fighting(target))
                return notify_fail("你只能对战斗中的对手使用飞影。\n");

        weapon = me->query_temp("weapon");

        if (!weapon || !(weapon->id("xiao")))
                return notify_fail("你手里没有拿箫，无法施展出飞影。\n");

        if (me->query_skill("yuxiao-jian", 1) < 350)
                return notify_fail("你的玉箫剑法不够娴熟，无法施展出飞影。\n");

        if (me->query_skill("qimen-bagua", 1) < 180)
                return notify_fail("你的奇门八卦不够娴熟，无法施展出飞影。\n");

        if (me->query_skill("tanzhi-shentong", 1) < 350)
                return notify_fail("你的弹指神通不够娴熟，无法施展出飞影。\n");

        if (me->query_skill("lanhua-shou", 1) < 350)
                return notify_fail("你的兰花拂穴手不够娴熟，无法施展出飞影。\n");

        if (me->query_skill("luoying-zhang", 1) < 350)
                return notify_fail("你的落英神剑掌不够娴熟，无法施展出飞影。\n");

        if (me->query_skill("xuanfeng-tui", 1) < 350)
                return notify_fail("你的旋风扫叶腿不够娴熟，无法施展出飞影。\n");

        if (me->query_skill("bihai-chaosheng", 1) < 350)
                return notify_fail("你的碧海潮生功火候不够，无法施展出飞影。\n");

        if (me->query_skill("suibo-zhuliu", 1) < 350)
                return notify_fail("你的随波逐流火候不够，无法施展出飞影。\n");

        if ( me->query_skill_mapped("sword") != "yuxiao-jian"
        || (me->query_skill_mapped("parry") != "yuxiao-jian"&&me->query_skill_mapped("parry") != "tanzhi-shentong")
        || me->query_temp("thd/feiying"))
                return notify_fail("你暂时无法使用飞影绝技。\n");

        if (me->query("max_neili") < 7500)
                return notify_fail("你的内力不够，无法施展出飞影。\n");

        if (me->query("neili") < 4000)
                return notify_fail("你的真气不够，无法施展出飞影。\n");

        if (me->query("jingli") < 2500)
                return notify_fail("你的精气不够，无法施展出飞影。\n");

        me->set_temp("thd/feiying", 1);
        message_vision(HIW"\n$N深吸一口气，使出桃花绝技「飞影」攻向$n！\n\n"NOR,me, target);

        lvl = to_int( lvl/3.0 * lvl/350.0);//4 -> 3

 if( me->query("quest/jiuyin2/pass")
  && me->query_skill("jiuyin-baiguzhua",1) >450
  && me->query_skill("cuixin-zhang",1) >450 )
 {   j=1;
 target->add_busy(2);
 if(!userp(target))   target->set_temp("must_be_hit",1);
  }
else j = 0;


        me->add_temp("apply/attack", lvl);
        me->add_temp("apply/damage", lvl);

        message_vision(HIG"$N手中的"+weapon->query("name")+HIG"如行云流水一般，向$n潇洒地攻去！"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
        message_vision(HIG"$n只觉得四面八方都是箫影，不知所措！\n"NOR,me, target);
        weapon->unequip();
        me->prepare_skill("hand");
        me->prepare_skill("strike");
        me->prepare_skill("cuff");
        me->prepare_skill("finger");
        me->prepare_skill("leg");
        me->prepare_skill("claw");

        if (me->is_fighting(target)) {
                message_vision(HIC"\n$N把"+weapon->query("name")+HIC"插回腰间，双手如清风拂晓般向$n拂去！"NOR,me, target);
                me->prepare_skill("hand", "lanhua-shou");
                qi2 = target->query("qi");
                me->add_temp("apply/hand", lvl*2);
                COMBAT_D->do_attack(me, target, 0, userp(target)?1:3);
                me->add_temp("apply/hand", -lvl*2);
                if (target->query("qi") < qi2)
                        message_vision(HIC"$N正好拂到了$n的小腹关元穴！$n觉得真气无法重新凝聚！\n"NOR,me, target);
        }
        if ( me->is_fighting(target)) {
                message_vision(HIM"\n$N倏地转手为掌，$n觉得到处是掌影，虚虚实实无法捉摸。"NOR,me, target);
                me->prepare_skill("hand");
                me->prepare_skill("strike","luoying-zhang");
                qi2 = target->query("qi");
                me->add_temp("apply/strike", lvl*2);
                COMBAT_D->do_attack(me, target, 0, userp(target)?1:3 );
                me->add_temp("apply/strike", -lvl*2);
                if (target->query("qi") < qi2)
                        message_vision(HIM"$N突然打在$n后心至阳穴上，$n不由得吐了口鲜血。\n"NOR,me, target);
        }

 if ( me->is_fighting(target)) {
message_vision(HIB"\n$N掌法一变成爪，突然使出九阴真经上的功夫"HIW"「九阴白骨爪」"HIB"。"NOR,me, target);

  if(j>0) {
  message_vision(HIG"\n这"HIW"九阴白骨爪"HIG"乃是黑风双煞的成名武功，此刻$N突然使将出来，$n猝不及防，登时被抓出了几个窟窿。"NOR,me, target);
  target->set_temp("must_be_hit",1);
  me->add_temp("apply/strike", lvl*2);
           }
                me->prepare_skill("hand");
                me->prepare_skill("strike","luoying-zhang");
                qi2 = target->query("qi");
                me->add_temp("apply/strike", lvl*2);
                COMBAT_D->do_attack(me, target, 0, 3 );
                me->add_temp("apply/strike", -lvl*2);
 if(j>0)        me->add_temp("apply/strike", -lvl*2);               
target->delete_temp("must_be_hit");
                if (target->query("qi") < qi2)
                        message_vision(HIB"$N突然爪在$n前心，$n不由得心下大骇。\n"NOR,me, target);
        }



        if ( me->is_fighting(target)) {
                message_vision(HIR"\n$N尚未收掌，旋风扫叶腿已经攻到$n面前！"NOR, me, target);
                me->prepare_skill("strike");
                me->prepare_skill("leg","xuanfeng-tui");
                qi2 = target->query("qi");
                me->add_temp("apply/leg", lvl*2);
                COMBAT_D->do_attack(me, target, 0,3 );
                me->add_temp("apply/leg", -lvl*2);
                if (target->query("qi") < qi2)
                        message_vision(HIR"$N连出好几腿，$n连连后退，无暇出力！\n"NOR,me, target);
        }
        if (me->is_fighting(target)) {
                message_vision(HIY"\n$N收掌出指，连点$n身前大穴！"NOR,me, target);
                me->prepare_skill("leg");
                me->add_temp("apply/finger", lvl*2);
                me->prepare_skill("finger","tanzhi-shentong");
                me->add_temp("apply/finger", -lvl*2);
                qi2 = target->query("qi");
                COMBAT_D->do_attack(me, target, 0, 3);
                if (target->query("qi") < qi2)
                        message_vision(HIY"$N突然一指向$n太阳穴戳去！$n摇摇晃晃，举步维艰。\n"NOR,me, target);
        }





        message_vision(HIW"\n$N飞影使完，手一晃将"+weapon->query("name")+HIW"拿回手中。\n"NOR,me, target);
        weapon->wield();
        me->start_busy(random(2));
        me->add_temp("apply/attack", -lvl);
        me->add_temp("apply/damage", -lvl);
        me->add("neili", -450);
        me->add("jingli", -180);
        me->start_perform(2+random(2), "「飞影」");
        me->delete_temp("thd/feiying");
        return 1;
}

string perform_name(){ return HIW"飞影"NOR; }

int help(object me)
{
        write(HIW"\n玉箫剑法之「飞影」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 4000 以上；
                最大内力 7500 以上；
                当前精力 2500 以上；
                玉箫剑法等级 350 以上；
                奇门八卦等级 180 以上；
                弹指神通等级 350 以上；
                兰花拂穴手等级 350 以上；
                落英神剑掌等级 350 以上；
                旋风扫叶腿等级 350 以上；
                碧海潮生功等级 350 以上；
                随波逐流等级 350 以上；
                手持箫。

HELP
        );
        return 1;
}


