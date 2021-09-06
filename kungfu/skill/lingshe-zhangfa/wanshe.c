//wanshe.c 万蛇噬体             
#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name() {return HIB"万蛇噬体"NOR;}

int perform(object me,object target)
{
    object weapon;
    
    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("万蛇噬体只能对战斗中的对手使用。\n");
    if((int)me->query_skill("staff", 1) < 300 )
                return notify_fail("你的基本杖法不够娴熟，不能使用万蛇噬体。\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "staff"
        || me->query_skill_mapped("staff") != "lingshe-zhangfa")
                return notify_fail("你手里无杖，如何使用万蛇噬体？\n");
    if (me->query_skill("lingshe-zhangfa", 1) < 300 )
		            return notify_fail("你的灵蛇杖法还不够娴熟，使不出万蛇噬体绝技。\n");
	  if (me->query_skill("hamagong", 1) < 300 )
		            return notify_fail("你的蛤蟆功等级不足，无法使用万蛇噬体。\n");
	  if (me->query_skill("force") < 300 )
		            return notify_fail("你的内功等级不够，使不出万蛇噬体绝技。\n");
	  if (me->query_str(1) < 60)
		            return notify_fail("你的膂力还不够强劲，使不出万蛇噬体绝技。\n");
	  if (me->query_skill_mapped("force") != "hamagong")
		            return notify_fail("「万蛇噬体」需要用蛤蟆功为基础。\n");
    if (me->query("oyf/hamagong") < 3 )         
                return notify_fail("「万蛇噬体」需要在华山之巅得到欧阳锋指点才可学习使用。\n");
	  if (me->query_skill_mapped("staff") != "lingshe-zhangfa"
)
		            return notify_fail("你现在的状态还无法使出「万蛇噬体」绝技。\n");                
    if((int)me->query("max_neili") < 1500 )
                return notify_fail("你的内力修为不够，不能使用万蛇噬体！\n");
    if((int)me->query("neili") < 1000 )
                return notify_fail("你现在真气不足，不能使用万蛇噬体！\n");
                
        message_vision(HIR"\n$N将蛤蟆功凝于气海穴，口中发出「咕、咕、咕、咕、咕、咕、咕」的声音！\n"+
        ""HIB"突然只见$N使出灵蛇杖法最后一招「"HIM"万蛇噬体"NOR"」"HIB"，手中"+weapon->name()+HIB"向狂罩而去！\n"+
        ""HIG"此招乃欧阳锋于华山之巅为克打狗棒法第六变之天下无狗，殚精竭虑，耗尽心血而创，此招一出，便是洪七公再世，也得甘拜下风！\n"NOR,me,target);
    me->start_perform(5,"「万蛇噬体」");
    me->set_temp("lszf/wanshe",1);
    me->add("neili", -500);
    me->add_temp("apply/attack",  me->query_skill("lingshe-zhangfa", 1)/2);
    me->add_temp("apply/damage",  me->query_skill("lingshe-zhangfa", 1)/2);

target->start_busy(3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);


    me->delete_temp("lszf/wanshe");
     if (me->is_fighting(target)
     	&&  random(me->query_con()) > target->query_con()/3) {
     	message_vision(HBRED"\n突见"+weapon->name()+HBRED"极速的旋转，宛若两条怪蛇交互疾行飞速缠住了$n身体！两条怪蛇迅速上串，\n"NOR,me,target);
     	target->start_busy(4+random(2));
     	message_vision(HBRED"飞身急发向$n咽喉部咬去，稳稳当当地咬住中了$n要害，$n像是中了蛇毒了！\n"NOR,me,target);
     	target->add_condition("snake_poison",5+random(5));
     	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    };
     	    if (me->is_fighting(target))
     	message_vision(HIY"\n$N右手握"+weapon->name()+HIY"直挺，凝聚功力于"+weapon->name()+HIY"上，身行随风飘摆，而杖尖任他狂风暴雨也不移动，\n"+
					           HIY"单单直指$n心口，正是打狗棒第三十六路棒法「"HIG"天下无狗"NOR"」"HIY"的第六变的棒心所在！\n"NOR, me, target);
					                             COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
					                      
					if ( me->is_fighting(target)&&me->query_temp("hmg_nizhuan"))
						message_vision(HIB"\n九阴逆转之力在华山之巅再得欧阳锋指点之后，御蛇之术更胜从前，$N将九阴真力汇聚于"+weapon->name()+HIB"\n$N将凝聚蛤蟆之力在九阴真力驱使下使出，犹如万千怪蛇凝立刻聚成一体向$n胸口重击而去！\n"NOR,me,target);
						COMBAT_D->do_attack(me, target, me->query_temp("weapon"),4);
						
    me->add_temp("apply/attack",  -me->query_skill("lingshe-zhangfa", 1)/2);
    me->add_temp("apply/damage",  -me->query_skill("lingshe-zhangfa", 1)/2);     	
     	
    return 1;
}


