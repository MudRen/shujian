// By Snowman@SJ
// modified by snowman 20/06/2000
// modify by looklove 2001.5.22 update help

#include <ansi.h>

inherit F_SSERVER;

void check_fight(object me,object target);
string perform_name(){ return HIY"降龙啸"NOR; }

int perform(object me, object target)
{
       int skill = me->query_skill("xianglong-zhang",1);

       if(!userp(me)) skill = skill /2;


	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("只能在战斗中使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「降龙啸」！\n");

	if( (int)me->query("neili") < me->query_skill("strike")+400 )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("xlz/xiao") )
		return notify_fail("你已经开始了降龙啸。\n");

	if( (int)me->query_skill("xianglong-zhang", 1) < 100 )
		return notify_fail("你的降龙十八掌还不够娴熟，使不出「降龙啸」来。\n");

	if( (int)me->query_skill("force") < 200 )
		return notify_fail("你的内功等级不够，使不出「降龙啸」来。\n");

	if( (int)me->query_str(1) < 30 )
		return notify_fail("你的膂力还不够强劲，使不出「降龙啸」来。\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 100 )
		return notify_fail("你的混天气功等级还不够，使不出「降龙啸」绝技。\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("你所使用的内功不对。\n");

	if( me->query_skill_prepared("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("parry") != "xianglong-zhang")
		return notify_fail("你现在无法使用「降龙啸」！\n");

	me->add("neili", -400);
	me->add("jingli", -150);
	message_vision(YEL "\n$N仰天狂啸，所使降龙十八掌竟然势力大增，威不可当！源源不绝的掌力排山倒海般地压向$n！\n\n" NOR, me, target);
	if( me->query("jiali") < 50 )
		me->set("jiali", 50);
	 me->set_temp("xlz/xiao", skill);
        me->add_temp("apply/attack", skill /5);
        me->add_temp("apply/strike",skill/2);
        me->add_temp("apply/parry",skill/2);
        me->add_temp("apply/damage",skill/3);

       if( !userp(target) || random( me->query("combat_exp"))  >target->query("combat_exp") /2 || skill>=551   )   
   
      target->apply_condition("no_perform", 1+ random(2));
         me->add_temp("apply/strength", skill/10);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

if(skill<=551) me->start_perform(3, "「降龙啸」");

else  me->start_perform(1+random(2), "「降龙啸」");

	call_out("check_fight", 1 , me, (skill/3 > 10?skill/3:10));
        return 1;
}

void check_fight(object me, int i)
{
	int j;

	if( !me ) return;
	if( !intp(j = me->query_temp("xlz/xiao"))) return;

	i--;
	if( !me->is_fighting()
	 || i < 1
	 || me->query_temp("weapon")
	 || me->query_temp("secondary_weapon")
	 || me->query_skill_prepared("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("force") != "huntian-qigong"
	 || me->query_skill_mapped("parry") != "xianglong-zhang"
	 || me->query("neili") < j + 200) {

                me->add_temp("apply/attack", -j /5);
                me->add_temp("apply/strength", -j/10);
                me->add_temp("apply/strike",-j/2);
                me->add_temp("apply/parry",-j/2);
                me->add_temp("apply/damage",-j/3);
		  me->delete_temp("xlz/xiao");

		me->add("neili", -j );
                me->start_perform(4, "「降龙啸」");
		message_vision(YEL "\n$N长啸完毕，看来好象消耗了不少的内力，降龙十八掌的威力也恢复寻常了。\n" NOR, me);
		return;
	}
	call_out("check_fight", 1, me, i);
}

int help(object me)
{
	write(HIY"\n降龙掌「降龙啸」："NOR"\n");
	write(@HELP
	短时间内可提升降龙掌威力，但同时消耗内力巨大。
	要求：	当前内力 大于掌法有效等级+400；
		降龙掌等级 100 以上；
		混天气功等级 100 以上；
		膂力 30 以上：
		激发招架为降龙掌。
HELP
	);
	return 1;
}
