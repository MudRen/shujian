// 亢龙有悔
// by snowman@SJ 16/10/99
// modify by looklove 2001.10.04
// Modify by lsxk@hsbbs 2007/7/2
// By Spiderii@ty 判断绝对有问题,我改了!
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HIY"亢龙有悔"NOR; }
int kanglong_attack(object me, int flag);

int perform(object me, object target)
{
   int tmp,damage,lvl,j;
   string msg;

   if( !target ) target = offensive_target(me);

        if( !objectp(target)
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
               return notify_fail("「亢龙有悔」只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「亢龙有悔」！\n");

	if( (int)me->query_skill("xianglong-zhang", 1) < 200 )
		return notify_fail("你的降龙十八掌还不够娴熟，使不出「亢龙有悔」绝技。\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 180 )
		return notify_fail("你的混天气功等级还不够，使不出「亢龙有悔」绝技。\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("你所用的内功不对，使不出「亢龙有悔」绝技。\n");

	if( (int)me->query_skill("force") < 270 )
		return notify_fail("你的内功等级不够，不能使用「亢龙有悔」。\n");

	if( (int)me->query_str(1) < 40 )
		return notify_fail("你的膂力还不够强劲，使不出「亢龙有悔」绝技。\n");

	if( me->query_skill_prepared("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("parry") != "xianglong-zhang")
		return notify_fail("你现在无法使用「亢龙有悔」！\n");

	if( (int)me->query("max_neili") < 4000 )
		return notify_fail("你现在内力太弱，使不出「亢龙有悔」。\n");

	if( (int)me->query("neili") < 1500 )
		return notify_fail("你现在真气太弱，使不出「亢龙有悔」。\n");

	if( (int)me->query("jingli") < 1000 )
		return notify_fail("你的精力不够，无法使用「亢龙有悔」绝技。\n");
/*
	if( (int)me->query_temp("xlz/xiao") )
		return notify_fail("你已经开始了「降龙啸」。\n");
*/
	if( !me->query("xlz/hang") )
		return notify_fail("你还没领悟到「亢龙有悔」的精髓，无法使用此招数攻击。\n");

   lvl = (int)me->query_skill("xianglong-zhang",1);
   tmp = 1 + (lvl-200)/10;
   if(tmp>18) tmp = 18;

   message_vision(HIY"\n$N叫道：「看招！」左腿微屈，右掌划了个圆圈，平推出去，正是降龙十八掌中的「亢龙有悔」。\n"+
   "初推出去看似轻描淡写，但一遇阻力，刹时之间连加"+ chinese_number(tmp)+ "道後劲，一道强似一道，重重叠叠。\n"+
   "直至无坚不摧，无强不破！\n"NOR,me);

   me->start_perform(3+random(3), "「亢龙有悔」");
 me->receive_damage("neili", 1000+random(500));
 me->receive_damage("jingli", 100+random(200));
   if(((int)me->query("pur")>28 && random(3))
     ||random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2
     ||random((int)me->query_con()) > target->query_con()/2
     ||random((int)me->query_skill("xianglong-zhang",1)) > (int)target->query_skill("parry",1)/2
     ||target->is_busy() ) {
       damage = lvl*(tmp + (int)me->query("str")/10)/2;
       if(me->query("gender")!="男性" || !userp(me)) damage = damage/2;
       if(wizardp(me)) write("damage is "+ damage + "!\n");
       target->receive_damage("qi", damage, me );
       target->receive_wound("qi", damage/2 , me);
       target->set_temp("xlz/kanglong1",1);
       msg = HIR"$n直被这一掌逼得退无可退，让无可让，重重地被击中胸口，口中鲜血狂喷！\n"NOR;
       msg += COMBAT_D->damage_msg(damage,"内伤");
       message_vision(msg,me,target);
       COMBAT_D->report_status(target, 0);
   }
   else{
       message_vision(HIC"$n哪里见过如此刚猛的掌法？连忙就地一滚，远远的躲了开去，只吓地连冒冷汗！\n"NOR,me,target);
       target->add_busy(1+random(2));
       target->delete_temp("xlz/kanglong1");
       me->start_perform(3, "「亢龙有悔」");
   }
   if(userp(me) && lvl>=250 && target->query_temp("xlz/kanglong1") && me->query("combat_exp") > target->query("combat_exp")/2)
       if(random((int)me->query_con()) > target->query_con()/2 || target->is_busy()){
         msg = HIW"这「亢龙有悔」之精要不在‘亢’字而在‘悔’字！$N这"+ chinese_number(tmp)+ "道後劲刚发出，便立即收了回来！\n"+
               "$n却哪里知道？只道是$N奋力一击，便下意识催动全身内劲与之抗衡，可这"+ chinese_number(tmp)+ "道後劲却突然凭\n"+
               "空消失，$n体内这股抗衡内劲却无法收回，顿时便被自己的这股内劲冲得眼前一黑，五脏六腑犹如炸开\n"+
               "一般难受，再也支持不住了！\n"NOR;
         message_vision(msg,me,target);

j = target->query("str");
if (j < 50) j =  target->query("con");
if (j < 50) j =  target->query("dex");
if (j < 50) j =  target->query("int");

         if( j <50 )
         if( (int)target->query("con")<15 
             ||( random(me->query("str")) > target->query("con")*2/3
             && random(me->query("combat_exp")) > target->query("combat_exp")*2/3)){
               target->set("eff_qi",-1);
               target->delete_temp("xlz/kanglong1");
               COMBAT_D->report_status(target,1);
               return 1;
         }
       damage = lvl*(tmp + 4 - (int)target->query("con")/10 + (int)me->query("str")/10)/2;
       if(me->query("gender")!="男性") damage = damage/2;
       if(wizardp(me)) write("damage is "+ damage +"!\n");
       target->receive_damage("qi", damage, me );
       target->receive_wound("qi", damage , me);
       message_vision(COMBAT_D->damage_msg(damage,"内伤"),me,target);
       COMBAT_D->report_status(target, 0);
       target->delete_temp("xlz/kanglong1");
       return 1;
   }
   target->delete_temp("xlz/kanglong1");
   return 1;
}

/*
	tell_object(me, HIC"\n你缓缓将双掌提到胸前，内息在体内重重运转，越来越快，表面上却看不出任何动静...\n\n"NOR);
	me->set_temp("no_fight", 1);
	me->start_busy(random(2));
	me->start_perform(10, "「亢龙有悔」");
	me->start_call_out( (: call_other, __FILE__, "kanglong_attack", me , 1 :), i);
	return 1;
}
*/
int kanglong_attack(object me, int flag)
{
	object target;
	int i;

	if( !me ) return 0;

	me->delete_temp("no_fight");

	if( !living(me) || me->is_ghost() ) return 0;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !living(target)
	 || !me->is_fighting(target)
	 || environment(target) != environment(me) ) {
		tell_object(me,"「亢龙有悔」只能在战斗中对对手使用。\n"); 
		return 1;
	}

	if( me->query_skill_prepared("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("parry") != "xianglong-zhang"
	 || me->query_temp("weapon")){
 		tell_object(me,"你现在无法使用「亢龙有悔」！\n"); 
		return 1;
	}

	if( me->query_skill_mapped("force") != "huntian-qigong" ) {
 		tell_object(me,"你所用的内功不对，无法使出「亢龙有悔」！\n"); 
		return 1;
	}

	if( objectp(me->query_temp("weapon")) ) {
 		tell_object(me,"你现在无法使用「亢龙有悔」！\n"); 
		return 1;
	}

	if( (int)me->query("neili") < 1500 ) {
		tell_object(me,"你现在真气不足，使不出「亢龙有悔」。\n");
		return 1;
	}

	if( (int)me->query("jingli") < 1000 ) {
		tell_object(me,"你现在精力不够，使不出「亢龙有悔」。\n");
		return 1;
	}

	if( (int)me->query_temp("xlz/xiao") ) {
		tell_object(me,"你已经开始了「降龙啸」。\n");
		return 1;
	}

	if( me->is_busy() ) {
		call_out("kanglong_attack", 1, me, 1);
		me->set_temp("no_fight", 1);
		if( wizardp(me) ) tell_object(me,"你手忙脚乱自顾不暇，等待中...\n");
		return 1;
	}

	i = me->query_skill("xianglong-zhang", 1) + random(me->query_str(1));

	if( userp(target) ) i = i*2/3;

//	判断抗龙的威力等级
	if( !flag ) flag = 1;
	i /= flag;

	if( me->query_temp("bishen_target") )
		target->set_temp("xlz/hanglong",1);
	else
		me->set_temp("xlz/hanglong", 1);

	me->add_temp("apply/attack", i);
	me->add_temp("apply/strength", i);
	me->add_temp("apply/damage", i/2);
	me->add_temp("apply/strike", i/2);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

	me->add_temp("apply/attack", -i);
	me->add_temp("apply/strength", -i);
	me->add_temp("apply/damage", -i/2);
	me->add_temp("apply/strike", -i/2);

	me->delete_temp("xlz/hanglong");
	me->receive_damage("neili", 1000+random(500));
	me->receive_damage("jingli", 200);
	me->start_perform(3+random(2),"「亢龙有悔」");
	return 1;
}

int help(object me)
{
	write(YEL"\n降龙十八掌之「亢龙有悔」："NOR"\n");
	write(@HELP
	最能体现降龙十八掌无匹威力，所向披靡。
	当年萧峰用三掌逼走丁春秋，正是此绝招。

	要求：	当前内力 1500 以上；
		最大内力 4000 以上：
		当前精力 1000以上；
		降龙掌等级 200 以上；
		混天气功等级 180 以上；
		内功有效等级 270 以上：
		膂力 40 以上：
		激发招架为降龙掌：
		经洪七公指点后方可使用。
HELP
	);
	return 1;
}
