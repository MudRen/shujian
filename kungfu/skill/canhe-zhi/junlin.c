// pfm canhe by hongba

#include <ansi.h>
inherit F_SSERVER;
#include <combat_msg.h>

int next1(object me, object target, int i);
int next2(object me, object target, int i);

int perform(object me,object target)
{
        object weapon;
        string msg;
        int ap,dp;
        int i = me->query_skill("canhe-zhi",1) / 3 + me->query_skill("finger",1) /3 + me->query_skill("shenyuan-gong",1) /3;

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail("君临天下只能对战斗中的对手使用。\n");


        if(me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("你的内功不是神元功，无法使用君临天下！\n");


 if(me->query("quest/junlin/pass")!=1)
                return notify_fail("你虽然听说过君临天下绝技，但是一直没有领悟其中诀窍，还不会运用！\n");

if( me->query_skill("shenyuan-gong", 1) < 300 )
                return notify_fail("你的内功还未练成，不能使用君临天下！\n");

if( me->query_skill("canhe-zhi", 1) < 300 )
                return notify_fail("你的指法还未练成，不能使用君临天下！\n");

 if( me->query_temp("weapon"))
                        return notify_fail("你手里拿着兵器，无法使用君临天下！\n");
   
if (me->query_skill_prepared("finger") != "canhe-zhi"
            || me->query_skill_mapped("finger") != "canhe-zhi")
                return notify_fail("你现在无法使用「君临天下」进行攻击。\n");  


        if(me->query("max_neili") < 1200 )
                return notify_fail("你的内力修为不够，不能使用君临天下！\n");
        if(me->query("neili") < 1000 )
                return notify_fail("你现在真气不足，不能使用君临天下！\n");
        if(me->query("jingli") < 600 )
                return notify_fail("你现在精力不足，不能使用君临天下！\n");
        if(me->query_temp("chz/ch"))
                return notify_fail("你正在使用君临天下！\n");

        if(me->query_skill("finger", 1) < 120 )
                return notify_fail("你的基本指法不够娴熟，不能在剑招中使用君临天下。\n");


msg = HIY"\n$N突地拔地而起，十指连弹，指风向$n激射而去，自上而下，挥洒自如，颇有王者风范，正是一招"HIR"「君临天下」"HIY"!\n"NOR;

 message_vision(msg, me, target);
me->start_perform(3, "「君临天下」");

        me->set_temp("chz/ch", 1); //这个标记是为了触发参合指的auto
        me->add_temp("apply/attack", i /4);
        me->add_temp("apply/damage", i /3);

        
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->add_temp("apply/attack", -i /4);
        me->add_temp("apply/damage", -i /3);
        me->add("neili", -150);

 

if ( me->query_skill("shenyuan-gong", 1) > 120)
                next1(me, target, i);
        else 
                me->delete_temp("chz/ch");
        return 1;
}

int next1(object me, object target, int i)
{
        string msg;
        int damage, ap, dp;
        object weapon;
        if( !me ) return 0;

weapon = me->query_temp("weapon");
        if (weapon || !target || !living(me) || !me->is_fighting(target)) {
                me->delete_temp("chz/ch");
                return 0;
        }

msg = HIC"\n$N继而冷笑一声，喝道：“第二指"HIM"「剑气碧烟横」"HIC"小心了！”\n"+
"凌空又出一指，$n硬接下第一式已是力有不逮，这第二招如何也不敢硬碰,登时手忙脚乱，疲于招架，毫无还手之力!\n"NOR;

                message_vision(msg, me, target);
        
        ap = me->query("combat_exp", 1) * me->query_str(1);
        dp = target->query("combat_exp", 1) * target->query_str(1);
  
  if (ap>dp/3 || me->query_int() > 40){
                   target->apply_condition("no_perform", 1+ random(2));
                   target->apply_condition("no_exert", 1+ random(2));
        me->set("chz/ch",1);
        me->add_temp("apply/attack", me->query_skill("shenyuan-gong") );
        me->add_temp("apply/damage", me->query_skill("shenyuan-gong") );

                target->add_temp("apply/attack", -80);
                target->add_temp("apply/dodge", -80);
                target->add_temp("apply/parry", -80);
               
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
  if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
  if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);

        
        me->add_temp("apply/attack", -me->query_skill("shenyuan-gong") );
        me->add_temp("apply/damage", -me->query_skill("shenyuan-gong") );
                me->add("neili",- 150);
                me->add("jingli",-80);
                me->start_perform(3 + random(2),"「君临天下」");
 
  call_out("back", 5 + random(me->query("jiali") / 20), target);               
        } 
        else {
                msg = msg + HIW "$n一个铁板桥，弯腰向后方才堪堪避过。\n" NOR;
                message_vision(msg, me, target);
                me->add("neili", -70);
                me->add_busy(random(2));


        }

 if (me->query_skill("canhe-zhi", 1) > 160)
                next2(me, target, i);
        me->delete_temp("chz/ch");
        return 1;
}




int next2(object me, object target, int i)

{
        string msg;
        int damage, ap,dp;
        object weapon,weapon1;

        if (!me) return 0;
        if(!target) return 0;
weapon = me->query_temp("weapon");
weapon1 = target->query_temp("weapon");

        if (weapon || !living(me) || !me->is_fighting(target))
         {
                me->delete_temp("chz/ch");
                return 0;
         }

msg = HIC"\n紧跟着$N又一指隔空点出，正是一招"HIR"「弹指江山破」"HIC"！江山如画，红尘如梦，指风如刀！\n"+
         "$n神情恍惚之下，但觉指风犀利，胸中满腔豪气如今却哪里提得起来？\n"NOR;
        ap = me->query("combat_exp", 1) * me->query_con(1)/100000;
        dp = target->query("combat_exp", 1) * target->query_con(1)/100000;
//这里除100000是为了防止exp数值过大的时候出现大数溢出


if( random(ap + dp) > dp||  me->query("con",1) > 40)
{
             if(weapon1) msg += HIG"$n只得将兵器横在当中一挡，却哪里抵挡得住？"HIW+weapon1->name()+HIG"当下被震飞，“拍”地一声插入地下。\n"NOR;
        
                damage =  me->query_skill("canhe-zhi",1)*3;
                damage += me->query_skill("finger")* 3;
                damage += random(damage);

             if ( damage > 2500 )
                        damage = 2500 + (damage - 2500)/10;

//绝对不能打爆。打爆了后面就出错了
             if ( damage >= target->query("qi",1) ) 
                        damage = target->query("qi",1) -1;
           	        
         if(weapon1) {      weapon1->unequip();
			                      weapon1->move(environment(target));
                     }

                target->add("neili",-(300+random(150)));
                target->apply_condition("no_exert", 1+ random(2));
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
//这句多余啦    msg += damage_msg(damage, "内伤");
                message_vision(msg, me, target);
                COMBAT_D->report_status(target, random(2));
if(target){
        me->add_temp("apply/attack", me->query_skill("canhe-zhi") );
        me->add_temp("apply/damage", me->query_skill("canhe-zhi")  );

COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->add_temp("apply/attack", -me->query_skill("canhe-zhi") );
        me->add_temp("apply/damage", -me->query_skill("canhe-zhi") );
        }      
                me->add("neili",-200);
                me->add("jingli",-80);
 

    } 

        else {

                msg  += CYN"\n$n就地十八滚，危急之中躲过致命一击，狼狈之极。\n"NOR;
                message_vision(msg, me, target);
                me->add("neili", -80);
                target->add_busy(random(2));
                
                me->add_temp("apply/attack", me->query_skill("canhe-zhi") /2);
                me->add_temp("apply/damage", me->query_skill("canhe-zhi") /2 );

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);

        me->add_temp("apply/attack", -me->query_skill("canhe-zhi") /2);
        me->add_temp("apply/damage", -me->query_skill("canhe-zhi") /2);
                               
         }

                me->delete_temp("chz/ch");
//猛招就要CD长。嘿嘿哈哈
                me->start_perform(6, "「君临天下」");
}


void back(object target)
{
object me = this_player();
        if (!target) return;
        target->add_temp("apply/attack", 60);
        target->add_temp("apply/dodge", 60);
        target->add_temp("apply/parry", 60);
        me->delete_temp("chz/ch");
}

string perform_name(){ return HIG"君临天下"NOR; }
int help(object me)
{
        write(HIG"\n参合指之「君临天下」："NOR"\n\n");
        write(@HELP
        要求：  解谜成功；
                当前内力 1000 以上；
                最大内力 1200 以上；
                当前精力 600 以上；
                参合指等级 300以上；
                神元功等级 300 以上；
                基本指法等级 300 以上；
                激发指法为参合指；
                激发内功为神元功。
HELP
        );
        return 1;
}
