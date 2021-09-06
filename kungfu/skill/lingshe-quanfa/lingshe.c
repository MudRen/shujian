// lingshe.c 灵蛇拳法之「灵蛇劲」
// Modified by fengyue@SJ

inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

string perform_name(){ return HIR"灵蛇劲"NOR; }

int perform(object me, object target)
{
	int damage, p,lvl;
	string msg;
        
        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("「灵蛇劲」只能对战斗中的对手使用。\n");



	if( userp(me)&&( me->query_skill_mapped("force") != "hamagong"
        && me->query_skill_mapped("cuff") != "lingshe-quanfa") )
                return notify_fail("「灵蛇劲」必须用灵蛇拳法配合蛤蟆功才能使用。\n");

        if( me->query_skill_prepared("cuff") != "lingshe-quanfa")
                return notify_fail("你的拳法不对，根本不能用出「灵蛇劲」。\n");  

        if( me->query_skill("lingshe-quanfa", 1) < 150 )
                return notify_fail("你的拳法修为还不够！\n");

        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("你的真气不够，发挥不了威力！\n");                   
        if( me->query_temp("weapon"))
                return notify_fail("你先放下手中的武器再说吧？！\n");     

msg = MAG"\n蛇身虽有骨而似无骨，能四面八方，任意所之，$N招式一变，使出了灵蛇拳法不传之秘"HIR"「灵蛇劲」"MAG"！\n"NOR;

	damage = me->query_skill("cuff") + me->query_skill("lingshe-quanfa");
	damage += random(me->query("jiali") * 3);
	damage += random(damage/2);
         damage *= 2;

if(target->query("neili") < me->query("neili")) damage *= 2;

if (damage > 3000 && me->query("oyf/hamagong")<3 ) damage = 3000+random(500); 
if(!userp(target)) damage /=2;

target->receive_damage("qi", damage, me);
target->receive_wound("qi", damage/2, me);

	p = (int)target->query("qi")*100/(int)target->query("max_qi");

	msg += HIR"$n左手挥出挡格，只道已将来拳架开，哪知便在最近之处，忽有一拳从万难料想的方位打来，结果重重的打在$n的胸口！\n"NOR;
	msg += "( $n"+eff_status_msg(p)+" )\n"; 
        message_vision(msg, me, target);

if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"你对"+ target->query("name") +"造成了"RED+ damage+ WHT"点伤害。\n"NOR);  
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"的攻击对你造成了"RED+ damage+ WHT"点伤害。\n"NOR);   

lvl = me->query_skill("lingshe-quanfa",1) + me->query_skill("hamagong",1);

me->add_temp("apply/attack",lvl/4);
me->add_temp("apply/damage",lvl/4);
me->add_temp("apply/strength",lvl/10);


if(userp(me)) target->start_busy(1+random(2));
        me->set_temp("lsqf/ls",1);
if ( me->is_fighting(target))
           COMBAT_D->do_attack(me, target, 0, 3);
if ( me->is_fighting(target))
           COMBAT_D->do_attack(me, target, 0, 3);
if ( me->is_fighting(target))
           COMBAT_D->do_attack(me, target, 0, 3);

me->add_temp("apply/attack",-lvl/4);
me->add_temp("apply/damage",-lvl/4);
me->add_temp("apply/strength",-lvl/10);

        me->delete_temp("lsqf/ls",1);
	me->add("neili", -350);
	me->add("jingli", -150);
	me->start_busy(random(1));
	me->start_perform(3+random(2),"灵蛇劲");
	return 1;
}


int help(object me)
{
        write(HIR"\n灵蛇拳法之「「灵蛇劲」」"NOR"\n\n");
      
        return 1;
}
