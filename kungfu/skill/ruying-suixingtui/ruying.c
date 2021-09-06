// ruying 如影随形
// by snowman@SJ 
// Modify by snowman@SJ 22/02/2000

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	mapping pre;
	string *skill, a, b;
	int i;

	if( !target ) target = offensive_target(me);

    if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("「如影随形」只能在战斗中对对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("使用「如影随形」时双手必须空着！\n");
	if( me->query_temp("fumo"))
		 return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
	if( (int)me->query_skill("ruying-suixingtui", 1) < 120 )
		return notify_fail("你的如影随形腿不够娴熟，不会使用「如影随形」。\n");

	if( (int)me->query_skill("yijin-jing", 1) < 120 )
		return notify_fail("你的易筋经等级不够，不能使用「如影随形」。\n");

	if (me->query_skill_mapped("force") != "yijin-jing")
		return notify_fail("你目前的内功无法支持你使用「如影随形」进行攻击。\n");  
			
	if( (int)me->query_dex() < 30 )
		return notify_fail("你的身法不够强，不能使用「如影随形」。\n");

	if (me->query_skill_prepared("leg") != "ruying-suixingtui"
	|| me->query_skill_mapped("leg") != "ruying-suixingtui")
		return notify_fail("你现在无法使用「如影随形」进行攻击。\n");  
											       
	if( (int)me->query("max_neili") < 1800 )
		return notify_fail("你现在内力修为太弱，不能使用「如影随形」。\n");
	if( (int)me->query("neili") < 1500 )
		return notify_fail("你目前内力太少，不能使用「如影随形」。\n");

	if( (int)me->query("jingli") < 500 )
		return notify_fail("你现在精力太少，不能使用「如影随形」。\n");


	tell_object(me,YEL"\n你猛吸一口真气，体内劲力瞬时爆发！\n" NOR,me, target);
	pre = me->query_skill_prepare();
	skill = keys(pre);     
	for (i=0; i<sizeof(skill); i++){
		if(skill[i]=="leg") continue; 
		a = skill[i];
		b = pre[skill[i]];
		me->prepare_skill(a);
	}

	i = (int)me->query_skill("ruying-suixingtui", 1)+(int)me->query_skill("yijin-jing",1)/3;
 
        me->add_temp("apply/attack", i/2);
        me->add_temp("apply/strength", i/8);
        me->add_temp("apply/leg",i/3);
        me->add_temp("apply/damage", i/3);
        me->add_temp("apply/dodge", i);


	me->set_temp("sl_rysxt", 5);
if(!userp(target)) target->add_busy(2);
 	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	me->add("neili", -80);
	if(me->is_fighting(target)){
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
		me->add("neili", -80);
	}
	if(me->is_fighting(target) && me->query_skill("ruying-suixingtui", 1) >= 150){
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
		me->add("neili", -80);
	}
	if(me->is_fighting(target) && me->query_skill("ruying-suixingtui", 1) >= 180){
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
		me->add("neili", -100);
	}
	
	// 5th kick is type_super. cannot be done in normal fight.
	if(me->is_fighting(target) && me->is_killing(target->query("id"))
	   && random(me->query_skill("ruying-suixingtui", 1)) >= 100) {
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		me->add("neili", -150);
	}
	
	message_vision(YEL "\n$N连环飞腿使完，全身一转，稳稳落在地上。\n" NOR,me, target);
	me->prepare_skill(a,b);
	me->reset_action();

        me->add_temp("apply/attack",- i/2);
        me->add_temp("apply/strength",- i/8);
        me->add_temp("apply/leg",-i/3);
        me->add_temp("apply/damage",- i/3);
        me->add_temp("apply/dodge", -i);

	me->delete_temp("sl_rysxt");

	me->start_busy(2);           

   me->start_perform(4,"「如影随形腿」");

	return 1;
}


string perform_name(){ return HIY"如影随行"NOR; }
