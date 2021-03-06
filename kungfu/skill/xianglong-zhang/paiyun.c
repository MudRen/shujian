// 排云双掌
// by snowman@SJ
// Modify by Lklv for npc can't add gift
// Modify by Lane@SJ 2005.08.03 
// Update by lsxk@hsbbs 2007/7/3

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#define KANGLONG "/kungfu/skill/xianglong-zhang/kanglong"

string perform_name(){ return WHT"排云双掌"NOR; }

int perform(object me, object target)
{
	int i, j, ap, dp, jiali;

	i = me->query_skill("xianglong-zhang", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !me->is_fighting(target)
	 || !living(target)
	 || environment(target) != environment(me) )
		return notify_fail("「排云双掌」只能在战斗中对对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「排云双掌」！\n");

	if( (int)me->query_skill("xianglong-zhang", 1) < 150 )
		return notify_fail("你的降龙十八掌还不够娴熟，使不出「排云双掌」绝技。\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 150 )
		return notify_fail("你的混天气功等级还不够，使不出「排云双掌」绝技。\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("你所使的内功不对，使不出「排云双掌」绝技。\n");

	if( (int)me->query_skill("force") < 200 )
		return notify_fail("你的内功等级不够，不能使用「排云双掌」。\n");

	if( (int)me->query_str(1) < 36 )
		return notify_fail("你的膂力还不够强劲，使不出「排云双掌」来。\n");

	if( me->query_skill_prepared("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("parry") != "xianglong-zhang")
		return notify_fail("你现在无法使用「排云双掌」！\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("你现在内力太弱，使不出「排云双掌」。\n");

	if( (int)me->query("neili") < 1500 )
		return notify_fail("你现在真气太弱，使不出「排云双掌」。\n");

	if( (int)me->query("jingli") < 800 )
		return notify_fail("你的精力不足以让你使出「排云双掌」。\n");

        if( (int)me->query_temp("xlz/xiao") && userp(me) && i<551 )
		return notify_fail("你正在使用「降龙啸」。\n");

	if( me->query_temp("xlz/py") )
		return notify_fail("你正在使用「排云双掌」。\n");

if(!userp(me)) i =  i  /3 ;

	j = i / 3;

	if( i > 350 )
		j = to_int( i / 2.5 * i/ 350.0);
	else if( i > 250 )
		j = to_int( i / 3.0 * i/ 250.0);


message_vision(HIW"\n$N一声断喝，双掌齐出，挟起满天飞沙！使的正是萧峰的得意功夫「排云双掌」！\n"NOR,me);
	me->add_temp("apply/damage", i/5);
	me->add_temp("apply/attack", j);
	me->add_temp("apply/strike", j);
	me->add_temp("apply/strength", i/15);
if (i>=400)         
	me->set_temp("xlz/py", 1);

   if( userp(me) )
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	else
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

	if( me->is_fighting(target) )
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);



        ap = COMBAT_D->skill_power(me,"strike",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"parry",SKILL_USAGE_DEFENSE);

	if( target->is_busy() ) dp /= 2;

	if( ap < 1 ) ap = 1;
	if( dp < 1 ) dp = 1;

 jiali = me->query("jiali");

	if( random(ap + dp ) > dp / 2 && i >= 451  && userp(me) ) {
		me->set_temp("xlz/py_add", 1);
		if( random(me->query_str(1)) > target->query_con(1)/2 ) {
			target->set_temp("must_be_hit", 1);
			me->set("have_master", 1);
			if( wizardp(me) ) tell_object(me, HIG"降龙十八掌高效果“必中！”"NOR);
		}
		if( wizardp(me) ) tell_object(me, HIG"降龙十八掌高效果“追加掌力！”"NOR);
         	if( wizardp(me) ) tell_object(me, HIG"命中率对比 "+ap+" : "+dp+"\n"NOR);
	message_vision(HIC"\n$N一掌既出，身子已抢到离他三四丈外，后掌推前掌，双掌力道并在一起，排山倒海般的涌出。\n"NOR,me,target);
	me->set("jiali", jiali +(i-400));

	me->add_temp("apply/damage", i/10);
	me->add_temp("apply/attack", j*2);
	me->add_temp("apply/strike", j*2);
	me->add_temp("apply/strength", i/10);
	me->set_temp("xlz/py_power", 1);

COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	me->add_temp("apply/damage", -i/10);
	me->add_temp("apply/attack", -j*2);
	me->add_temp("apply/strike", -j*2);
	me->add_temp("apply/strength", -i/10);

	me->set("jiali", jiali);
	me->delete_temp("xlz/py_power");
	me->delete_temp("xlz/py_add");
	target->delete_temp("must_be_hit");
	me->delete("have_master");
	me->start_busy(random(2));
	me->add("neili", -400);

}

	me->add_temp("apply/damage", -i/5);
	me->add_temp("apply/attack", -j);
	me->add_temp("apply/strike", -j);
	me->add_temp("apply/strength", -i/15);

	me->add("jingli", -100);
	me->delete_temp("xlz/py");
	me->start_busy(random(2));
	me->start_perform(3,"「排云双掌」");

 if( i >= 350  && userp(me)){
        	
        tell_object(me, HIC"\n你缓缓将双掌提到胸前，内息在体内重重运转，越来越快，表面上却看不出任何动静...\n\n"NOR);

         	me->start_call_out( (: call_other, __DIR__"kanglong", "kanglong_attack", me, 2 :), 1 );
        }

	
	me->start_perform(3,"「排云双掌」");

	return 1;
}



int help(object me)
{
	write(WHT"\n降龙掌「排云双掌」："NOR"\n");
	write(@HELP
	排云双掌为降龙掌有数绝技之一，常为两掌。绝顶高手，或可不同。
	要求：	最大内力 2000 以上；
		当前内力 1500 以上；
		当前精力 800 以上；
		降龙掌等级 150 以上；
		混天气功等级 150 以上；
		内功有效等级 230 以上；
		膂力 36 以上：
		激发招架为降龙掌。
HELP
	);
	return 1;
}
