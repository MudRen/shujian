// qishang.c 
// Update By lsxk@hsbbs 2007/6/11

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
void remove_effect(object target,int damage);

string *songs = ({"五行之气调阴阳","损心伤肺摧肝肠","藏离精失意恍惚","三焦齐逆兮魂魄飞扬"});
string *num_color = ({HIR,HIC,HIG,HIM,HIY,HIB,HBRED});

int perform(object me, object target)
{
	string msg, song;
   int p, damage, ap, dp, jiali, qi_wound;
	song = songs[random(sizeof(songs))];

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) || !living(target) )
		return notify_fail("「七伤总诀」只能在战斗中对对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手使用「七伤总诀」！\n");

   if( (int)me->query_skill("qishang-quan",1) < 200 )
		return notify_fail("你的七伤拳不够娴熟，不会使用「七伤总诀」！\n");

   if(!me->query_skill("jiuyang-shengong", 1) || (int)me->query_skill("jiuyang-shengong",1)< 200 )
   if(userp(me) && (int)me->query_skill("shenghuo-shengong",1) < 200 )
           return notify_fail("你的特殊内功等级不够，不能使用「七伤总诀」！\n");

   if(userp(me) && me->query_skill_mapped("force") != "shenghuo-shengong" && me->query_skill_mapped("force") != "jiuyang-shengong" )
           return notify_fail("你没有圣火神功或者明教九阳功内功，无法使用「七伤总诀」进行攻击。\n");

   if( (int)me->query_con(1) < 38 )
		return notify_fail("你的身体不够强壮，不能使用「七伤总诀」！\n");

   if( (int)me->query("max_neili") < 3000 )
		return notify_fail("你的内力太弱，不能使用「七伤总诀」！\n");

   if( (int)me->query("neili") < 1200 )
		return notify_fail("你的内力太少了，无法使用出「七伤总诀」！\n");

	if( me->query_temp("qkdny/yin") )
		return notify_fail("你正在施展乾坤大挪移「引」字诀呢！\n");
/*
	if( me->query_temp("qkdny/hua") )
		return notify_fail("你正在施展乾坤大挪移「化」字诀呢！\n");
*/
   if( (int)me->query("jingli") < 800 )
		return notify_fail("你的精力太少了，无法使用出「七伤总诀」！\n");

	if( me->query_skill_mapped("parry") != "qishang-quan"
	&& me->query_skill_mapped("parry") != "qiankun-danuoyi")
		return notify_fail("你需要激发招架为七伤拳，方能使用「七伤总诀」进行攻击。\n");

	if (me->query_skill_prepared("cuff") != "qishang-quan"
	 || me->query_skill_mapped("cuff") != "qishang-quan")
           return notify_fail("你现在无法使用「七伤总诀」进行攻击。\n");

   if((int)target->query_temp("qishang")>6)
           return notify_fail("对方已经身受七股「七伤内劲」，你不用费劲了！\n");

	message_vision(HIR"\n突然$N眼射精光，朗声念出句似歌非歌、似诗非诗的拳诀：“"+song+"”，砰的一拳击向$n！\n"NOR,me, target);

   me->start_perform(2+random(4),"「七伤总诀」");

	ap = COMBAT_D->skill_power(me, "cuff", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
   if(target->is_busy()) dp=dp/2;

   jiali = (int)me->query("jiali")/60;
   jiali = jiali+(int)target->query_temp("qishang");
   if(jiali<1) jiali = 1;

   if ( random(ap + dp ) > dp/2 ){
            qi_wound = ((int)me->query_skill("cuff",1)+(int)me->query_skill("qishang-quan",1)) * jiali;
           if(wizardp(me)) write("damage is :"+qi_wound+"!\n");
		target->receive_damage("qi", qi_wound, me);
		target->receive_wound("qi", qi_wound/2, me);
		target->add_busy(1);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"你对"+ target->query("name") +"造成了"HIR+qi_wound+ WHT"点攻击伤害。\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"的攻击对你造成了"HIR+qi_wound+ WHT"点伤害。\n"NOR);
		if((me->query("neili") + me->query_con(1)*(20+random(40))) < target->query("neili"))
			tell_object(me, HIR"你只觉"+target->name()+"体内内力极强，你暗藏在拳内的各种力道根本送不出去！\n"NOR);
		else{
			damage = target->query_str(1)/2;
			damage += target->query_int(1)/2;
			damage += target->query_con(1)/2;
			damage += target->query_dex(1)/2;
                   damage /= 8;
                   tell_object(me, num_color[(int)target->query_temp("qishang")]+"在刚一触到"+target->name(1)+"的身体时，你便暗暗发力，将隐藏在拳内的第"+HIW+chinese_number(1+(int)target->query_temp("qishang"))+NOR+num_color[(int)target->query_temp("qishang")]+"股内劲送了过去！\n"NOR);
                   tell_object(target, HIW"你一晃眼，只见"+me->name(1)+"的拳已经打在你的身上，跟着一股说不出的暗劲顺势传了过来！\n"NOR);
			me->add("neili", -400);
			me->add("jingli", -50);
			me->start_perform(4, "「七伤总诀」");
			target->set("qishang", damage);
                   if(!target->query_temp("qishang")){
			target->add_temp("apply/strength", -damage);
			target->add_temp("apply/dexerity", -damage);
			target->add_temp("apply/intelligence", -damage);
			target->add_temp("apply/constitution", -damage);
                   target->add_condition("qishang_poison", 9);
                   target->add_condition("no_perform", 6);
			target->start_call_out( (: call_other, __FILE__, "remove_effect", target ,damage :), me->query_skill("cuff", 1)/4);
                   }
                   target->add_temp("qishang", 1);
		}
		if (random(2)) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg = COMBAT_D->damage_msg(qi_wound, "内伤");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg = COMBAT_D->damage_msg(qi_wound, "内伤");
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
	}
	else {
		me->start_busy(1+random(2));
		me->add("neili", -150);
		me->add("jingli", -200);
		msg = "只见$p轻轻一转身，已经绕到了$P身后。而$N却因劲力打空不受控制，头脑眩晕！\n";
	}
	message_vision(msg, me, target);
	return 1;
}

void remove_effect(object target,int damage)
{
	if( ! target || !target->query_temp("qishang")) return;
	target->add_temp("apply/strength", damage);
	target->add_temp("apply/dexerity", damage);
	target->add_temp("apply/intelligence", damage);
	target->add_temp("apply/constitution", damage);
	target->clear_condition("no_perform");
	target->delete_temp("qishang");
	tell_object(target, HIW"\n终于体内那几股暗劲在遍布你的全身之后，开始慢慢散去了。\n"NOR);
}

string perform_name(){ return HIR"七伤总诀"NOR; }

int help(object me)
{
	write(HIR"\n七伤拳之「七伤总诀」："NOR"\n\n");
	write(@HELP
   要求：  当前内力 1200 以上；
           最大内力 3000 以上；
           当前精力 800 以上；
           七伤拳等级 200 以上；
           圣火神功等级 200 以上 或者 明教九阳功等级 200 以上；
           后天根骨 38 以上；
		激发拳法为七伤拳；
		激发招架为七伤拳或乾坤大挪移；
		备拳法为七伤拳。

HELP
	);
	return 1;
}
