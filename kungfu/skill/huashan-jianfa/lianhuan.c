// lianhuan.c for huashan-jianfa
// by tiantian@SJ 11/05/2000.
// update by lsxk@hsbbs 2007/7/26 for增强剑宗使用威力.

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name() {return MAG"夺命连环三仙剑"NOR;}

int perform(object me,object target)
{
    object weapon;
    
    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("夺命连环三仙剑只能对战斗中的对手使用。\n");

    if(me->query_skill_mapped("force") != "huashan-qigong"
      &&me->query_skill_mapped("force") != "zixia-gong" )
                return notify_fail("你的特殊内功不对，无法使用夺命连环三仙剑！\n");
    if( (int)me->query_skill("huashan-qigong", 1) < 160
      &&(int)me->query_skill("zixia-gong", 1) < 160 )
                return notify_fail("你的内功还未练成，不能使用夺命连环三仙剑！\n");
    if( (int)me->query_skill("huashan-jianfa", 1) < 160 ) 
                return notify_fail("你的剑法还未练成，不能使用夺命连环三仙剑！\n");
    if((int)me->query_skill("sword", 1) < 160 )
                return notify_fail("你的基本剑法不够娴熟，不能在剑招中使用夺命连环三仙剑。\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "huashan-jianfa")
                return notify_fail("你手里无剑，如何使用夺命连环三仙剑？\n");
                
    if((int)me->query("max_neili") < 2500 )
                return notify_fail("你的内力修为不够，不能使用夺命连环三仙剑！\n");
    if((int)me->query("neili") < 2000 )
                return notify_fail("你现在真气不足，不能使用夺命连环三仙剑！\n");
    if((int)me->query_temp("wudui"))
                return notify_fail("你正在使用无双无对！\n");

        message_vision(MAG"\n$N"MAG"长啸一声，使出平生绝技，连环三击，正是华山剑宗绝学“"HIR"夺命连环三仙剑"MAG"”！\n"NOR, me,target);
if(!userp(target) && me->query_skill("huashan-jianfa,1")>=450 ) target->add_busy(2);
    me->start_perform(3,"「夺命连环三仙剑」");
    me->set_temp("hsjf/lianhuan",1);
    me->add("neili", -500);
    me->add_temp("apply/attack",  me->query_skill("huashan-jianfa", 1)/4);

    if(me->query("quest/huashan")=="剑宗" || me->query_temp("zxg"))
{
        target->start_busy(1+ random(2));
        me->add_temp("apply/damage",  me->query_skill("huashan-jianfa", 1)/3);
        me->add_temp("apply/sword",     me->query_skill("huashan-jianfa", 1)/3);
}

if(me->query("quest/zixia/pass")&& me->query_temp("zxg"))
	{
                  message_vision(HIM"\n$N"HIM"将紫霞神功都运到了剑上，呼的一剑，当头直劈。随即圈转长剑，拦腰横削。跟着挥剑反撩，疾刺$n后心，\n"NOR, me,target);
                  message_vision(HIM"这连环三击变招快极，剑法精妙，几近魔道，$N将紫霞内劲附在剑上，威力更是不凡！\n"NOR, me,target);
		  target->add_busy(2);
      target->set_temp("must_be_hit",1);
      me->add_temp("apply/damage",  me->query_skill("huashan-jianfa", 1)/4);
      me->add_temp("apply/attack",  me->query_skill("huashan-jianfa", 1)/4);
      me->set_temp("zx_up",1);
     }




    COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
   
 me->add_temp("apply/attack",  -me->query_skill("huashan-jianfa", 1)/4);

    if(me->query("quest/huashan")=="剑宗"|| me->query_temp("zxg"))
{
        me->add_temp("apply/damage", - me->query_skill("huashan-jianfa", 1)/3);
        me->add_temp("apply/sword",    - me->query_skill("huashan-jianfa", 1)/3);
}
    if(me->query_temp("zx_up")){
      me->add_temp("apply/damage", -me->query_skill("huashan-jianfa", 1)/4);
      me->add_temp("apply/attack", -me->query_skill("huashan-jianfa", 1)/4);

    	        me->delete_temp("zx_up");
    	                          }


    me->delete_temp("hsjf/lianhuan");
    
    
    if(target) target->delete_temp("must_be_hit");
   
   if(!me->query_temp("zxg"))
   	                         me->start_busy(1);
    return 1;
}

int help(object me)
{
   write(WHT"\n华山剑法「"MAG"夺命连环三仙剑"WHT"」："NOR"\n");
   write(@HELP
    这就是华山剑宗绝技「夺命连环三仙剑」！当年华山派剑宗、气宗之
    争，乃在华山玉女峰比剑争夺，剑宗弟子正是用了此招杀害了数名气
    宗好手，回想起当年战场，也令现在的气宗弟子骇然。气宗弟子虽视
    剑宗弟子为魔道，但心下却不禁佩服此招之高明，华山玉女峰一战后
    有少数气宗弟子竟然也在练习此招，但只是徒有架势，威力乃不及剑
    宗弟子之三、四成。
    华山剑法等级450级以后效果飞跃。
    指令：perform lianhuan

    要求：华山气功 或者 紫霞神功 160级
          华山剑法160级，
          基本剑法160级，
          最大内力2500以上，
          当前内力2000以上。
HELP
   );
   return 1;
}
