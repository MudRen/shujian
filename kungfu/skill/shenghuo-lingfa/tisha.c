// tisha.c 踢沙
// Update By lsxk@hsbbs 2007/6/11 

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int j, f, flag;


	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target))
		return notify_fail("「圣火绝学」只能对战斗中的对手使用。\n");

   if(me->query_skill("shenghuo-lingfa", 1) < 200 )
		return notify_fail("你的圣火令法功力太浅，不能使用。\n");

   if(!me->query_skill("jiuyang-shengong", 1)||(int)me->query_skill("jiuyang-shengong",1)<200)
   if(me->query_skill("shenghuo-shengong", 1) < 200 )
           return notify_fail("你的特殊内功功力太浅，不能使用。\n");

   if(me->query_skill("dagger", 1) < 200 )
		return notify_fail("你的基本匕法功力太浅，不能使用。\n");

   if(me->query_skill("cuff", 1) < 200)
		return notify_fail("你的基本拳法功力太浅，不能使用。\n");

   if(me->query_skill("qiankun-danuoyi", 1) < 200 )
		return notify_fail("你的乾坤大挪移功力太浅，不能使用。\n");

   if(me->query("max_neili") < 3000 )
		return notify_fail("你的内力太浅，不能使用。\n");

	if(me->query("neili") < 1000 )
		return notify_fail("你的真气不够，不能使用。\n");

	if(me->query("jingli") < 1000)
		return notify_fail("你的精力不够，不能使用。\n");

	if( me->query_temp("qkdny/yin") )
		return notify_fail("你正在施展乾坤大挪移「引」字诀呢！\n");

	if( me->query_temp("qkdny/hua") )
		return notify_fail("你正在施展乾坤大挪移「化」字诀呢！\n");

        if( me->query_skill_mapped("parry") != "shenghuo-lingfa" 
        && me->query_skill_mapped("parry") != "qiankun-danuoyi" )
                return notify_fail("你需要激发招架为圣火令法，方能使用此绝技。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	 || weapon->query("skill_type") != "dagger"
	 || me->query_skill_prepared("cuff") != "shenghuo-lingfa"
	 || me->query_skill_mapped("dagger") != "shenghuo-lingfa"
    || me->query_skill_mapped("cuff") != "shenghuo-lingfa" 
    || (me->query_skill_mapped("force") != "shenghuo-shengong" && me->query_skill_mapped("force") != "jiuyang-shengong") )
		return notify_fail("你不能使用这个绝招！\n");

   if((int)me->query_temp("ling")
     && me->query_skill_prepared("force") != "jiuyang-shengong"
     && (int)me->query_skill("jiuyang-shengong",1)<200)
		return notify_fail("你正在使用「心魔」中，无暇使用「踢沙」绝技。\n");

   if ( !me->query_skill("jiuyang-shengong", 1)||(!userp(me) && userp(target)))
		flag = 3;
	else
		flag = 4;


   f = ((int)me->query_skill("shenghuo-lingfa", 1) + (int)me->query_skill("jiuyang-shengong", 1))/2;
   j = f / (7-flag);
 
	message_vision(HIY"\n$N突然横腿疾扫，卷起地下大片沙石，身子一分为二，前后夹击、连攻"+chinese_number(flag)+"招！\n" NOR, me);

	me->set_temp("tisha", 4);
if( !userp(target) && me->query_skill("shenghuo-lingfa",1)<=251  ) target->add_busy(2);
if( !userp(target) && me->query_skill("qiankun-danuoyi",1)>=451  ) { target->add_busy(2);
                                                                      j=j*5/4;}

   if(userp(me))
   me->add_temp("apply/damage", j);
   me->add_temp("apply/attack", j);

	       weapon->unequip();
	       me->set_temp("type", 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	       me->delete_temp("type", 1);

	       weapon->wield();
 if (present(target,environment(me)) && me->is_fighting(target))
               COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	       weapon->unequip();
	       me->set_temp("type", 1);
 if (present(target,environment(me)) && me->is_fighting(target))
               COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	       weapon->wield();
	       me->delete_temp("type");

 if (present(target,environment(me)) && me->is_fighting(target) && flag >=4 )
	       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

   if(userp(me))
   me->add_temp("apply/damage", -j);
   me->add_temp("apply/attack", -j);
   me->delete_temp("tisha");
 
if (present(target,environment(me)) && me->is_fighting(target) )
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

   me->add("neili", -600);
   me->add("jingli", -300);
   me->start_perform(3+random(2), "踢沙");
   me->start_busy(random(2));
	return 1;
}

string perform_name(){ return YEL"踢沙"NOR; }

int help(object me)
{
	write(YEL"\n圣火令法之「踢沙」："NOR"\n\n");
	write(@HELP
	要求：	当前内力 1000 以上；
           最大内力 3000 以上；
		当前精力 1000 以上；
           圣火令法等级 200 以上；
           乾坤大挪移等级 200 以上：
           圣火神功等级 200 以上 或者 明教九阳功等级 200 以上；
           基本令法等级 200 以上；
           基本拳法等级 200 以上；
		激发令法为圣火令法；
		激发拳法为圣火令法；
		激发招架为圣火令法；
		备拳法为圣火令法；
		且手持兵器。

HELP
        );
        return 1;
}
