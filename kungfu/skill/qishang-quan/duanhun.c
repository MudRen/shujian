// 断魂夺魄
// by Looklove@SJ
// Update By lsxk@hsbbs 2007/6/11

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
   int i, j, p, flag;
   i = (int)me->query_skill("qishang-quan", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !me->is_fighting(target)
	 || !living(target)
	 || environment(target)!=environment(me))
		return notify_fail("「断魂夺魄」只能在战斗中对对手使用。\n");

	if( objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用「断魂夺魄」！\n");

   if( (int)me->query_skill("qishang-quan", 1) < 250 )
		return notify_fail("你的七伤拳还不够娴熟，使不出「断魂夺魄」绝技。\n");

   if(!me->query_skill("jiuyang-shengong", 1) || (int)me->query_skill("jiuyang-shengong",1)<250)
   if( (int)me->query_skill("shenghuo-shengong", 1) < 250 )
           return notify_fail("你的圣特殊等级还不够，使不出「断魂夺魄」绝技。\n");

   if( (int)me->query_skill("force",1) < 250 )
		return notify_fail("你的内功等级不够，不能使用「断魂夺魄」。\n");

   if( me->query_str(1) < 45 )
		return notify_fail("你的膂力还不够强劲，使不出「断魂夺魄」来。\n");

	if( me->query_skill_prepared("cuff") != "qishang-quan"
	 || me->query_skill_mapped("cuff") != "qishang-quan")
		return notify_fail("你现在无法使用「断魂夺魄」！\n");

   if( me->query_skill_mapped("force") != "jiuyang-shengong"
    && me->query_skill_mapped("force") != "shenghuo-shengong")
           return notify_fail("你的特殊内功不对，无法使用「断魂夺魄」！\n");

	if( me->query_skill_mapped("parry") != "qishang-quan"
	&& me->query_skill_mapped("parry") != "qiankun-danuoyi")
		return notify_fail("你需要激发招架为七伤拳，方能使用「断魂夺魄」。\n");

   if (target->query_temp("qishang") && (int)me->query_skill("qishang-quan",1)<350)
		return notify_fail("对方已经身中七伤拳内伤了。\n");

	if( me->query_temp("qkdny/yin") )
		return notify_fail("你正在施展乾坤大挪移「引」字诀呢！\n");

	if ( me->query_temp("qsq/duanhun"))
		return notify_fail("你正在使用「断魂夺魄」。\n");

   if( (int)me->query("max_neili") < 4000)
		return notify_fail("你的内力太弱，使不出「断魂夺魄」。\n");

   if( (int)me->query("neili") < 1500 )
		return notify_fail("你现在真气太弱，使不出「断魂夺魄」。\n");

   if( (int)me->query("jingli") < 2000 )
           return notify_fail("你现在太累了，使不出「断魂夺魄」。\n");

	message_vision(HIR"\n$N口中念起七伤断魂夺魄歌诀，将七伤拳意发挥得淋漓尽致，大喝一声全力打出！！\n"NOR,me);

   if( me->query_skill_mapped("force") == "jiuyang-shengong" && userp(me))
       flag=1;
   else flag = 0;

	p = me->query_skill("qishang-quan", 1) / 50;
	if ( p > 5 ) p = 5;

	if (!me->query_skill("jiuyang-shengong", 1))
		if ( p > 4 ) p = 4;

   i = i/5*3 + (int)me->query_skill("jiuyang-shengong", 1)/5*2;   

   j = i/(7-p);                //有9yang是1/2,否则是1/3

	if ( i > 300 && p>4 )
		j = to_int( i/3.0 * i/ 300.0);  // 9yang 300级小飞

if(random(2)&&userp(me)) target->start_busy(2);

   me->add_temp("apply/cuff", j);
   me->add_temp("apply/attack", j );
   me->add_temp("apply/parry", j);
	
   if( userp(me) ) {
   me->add_temp("apply/strength",j/5);
   me->add_temp("apply/damage", j);

   }

if(me->query_skill("jiuyang-shengong",1)>300)

	me->set_temp("qsq/duanhun",p);

   COMBAT_D->do_attack(me, target, 0, 3);

	if ( me->is_fighting(target))
           COMBAT_D->do_attack(me, target, 0, 3);

	if ( me->is_fighting(target))
           COMBAT_D->do_attack(me, target, 0, (flag==1)?3:1);

	if ( me->is_fighting(target) && p > 3)
           COMBAT_D->do_attack(me, target, 0, (flag==1)?3:1);

	if ( me->is_fighting(target) && p > 4)
           COMBAT_D->do_attack(me, target, 0, (flag==1)?3:1);

   me->add_temp("apply/cuff", -j);
   me->add_temp("apply/attack",-j );
   me->add_temp("apply/parry", -j);
	
   if( userp(me) ) {
   me->add_temp("apply/strength",-j/5);
   me->add_temp("apply/damage",-j);
     }
	me->delete_temp("qsq/duanhun");
   me->add("jingli", -100*p);
   me->add("neili", -200*p);
   me->start_busy(random(2));
   me->start_perform(4+ random(1),"「断魂夺魄」");
	return 1;
}

string perform_name(){ return HIR"断魂夺魄"NOR; }

int help(object me)
{
	write(HIR"\n七伤拳之「断魂夺魄」："NOR"\n\n");
	write(@HELP
           最大内力 4000 以上；
           最大内力 3000 以上；
           当前精力 2000 以上；
           七伤拳等级 250 以上；
           圣火神功等级 250 以上 或者 明教九阳功等级 250 以上；
           基本内功等级 250 以上；
           后天膂力 45 以上；
		激发拳法为七伤拳；
		激发招架为七伤拳或乾坤大挪移：
		备拳法为七伤拳且空手。

HELP
	);
	return 1;
}
