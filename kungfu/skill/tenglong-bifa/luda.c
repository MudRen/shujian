
// pfm luda
// 断别人兵器 & 化学效果
// create by olives@SJ
// 更新 再加一hit物理攻击取消性别限制--by daidai
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include <combat_msg.h>

string perform_name(){ return HIY"鲁达拔柳"NOR; }

int perform2(object me,object target);
int perform(object me, object target)
{
        int skill,ap,pp,damage,effect,p;
        object weapon = me->query_temp("weapon");
	object vweapon;
        string dodge_skill;
        if( !target ) target = offensive_target(me);

        if(!target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用。\n");

	vweapon = target->query_temp("weapon");

        if(userp(me) && me->query("family/master_id")!="hong antong")
                return notify_fail("「鲁达拔柳」只有拜了教主后才能用！\n");

        if( (int)me->query_skill("tenglong-bifa", 1) < 120 )
                return notify_fail("你的腾龙匕法不够娴熟，不会使用鲁达拔柳。\n");

    	if( (int)me->query("neili", 1) < 3000 )
       		return notify_fail("你现在内力不足！\n");
       	if( (int)me->query("jingli", 1) < 500 )
       		return notify_fail("你现在精力不足！\n");

    	if( (int)me->query("max_neili", 1) < 1500 )
       		return notify_fail("你内力修为不足！\n");
        if( (int)me->query_str() < 30  )
                return notify_fail("你的膂力太低，不能使用鲁达拔柳。\n");

        if(!weapon
        || me->query_skill_mapped("dagger") != "tenglong-bifa")
                return notify_fail("你现在无法使用鲁达拔柳。\n");


        skill = (int)me->query_skill("tenglong-bifa", 1);
	 ap = me->query("combat_exp")/100*me->query_str();
        pp = target->query("combat_exp")/100*target->query_dex();
        
	
        me->add("neili", -350);
        me->add("jingli", -200);

 if(objectp(vweapon))
     
  {
		 ap *= weapon->query("sharpness");
	        pp *= vweapon->query("rigidity");

 		message_vision(HIY"\n$N双腿一缩，似欲跪拜，右臂却横掠而出，"+weapon->name()+HIY"急削向$n手中"+vweapon->name()+HIY"！"NOR,me,target);
  		if(random(ap+pp)>pp  )
  		{

  			message_vision(WHT"\n结果$n手中"+vweapon->name()+WHT"应手而断！\n"NOR,me,target);
                	vweapon->unequip();
                	vweapon->move(environment(target));
                	vweapon->set("name", "断掉的" + vweapon->name());
                	vweapon->set("value", 49);
                	vweapon->set("weapon_prop", 0);
                	target->reset_action();
		}
              else message_vision(CYN"\n结果$n向后一缩，躲过了$N这一削！\n"NOR,me,target);
 	}
 else if((int)me->query_skill("tenglong-bifa", 1)>350)
                    { message_vision(HIY"\n$N双腿一缩，似欲跪拜，右臂却横掠而出，"+weapon->name()+HIY"急削向$n！"NOR,me,target);
                     me->add_temp("apply/attack", me->query_skill("tenglong-bifa", 1)/2); 
                     COMBAT_D->do_attack(me,target,me->query_temp("weapon"), 3);
                     me->add_temp("apply/attack", -me->query_skill("tenglong-bifa", 1)/2); 
                    }


 	message_vision( HIY"\n$N突然一个前滚翻，似欲向$n胯下钻过，但只一作势，左手抓向$n右脚足踝，右手"+weapon->name()+HIY"点向$n小腹！\n"NOR, me, target);
	 ap = (int)me->query_skill("dulong-dafa",1) * (int)me->query("neili") * (int)me->query_str();
        pp = (int)target->query_skill("force", 1) * (int)target->query("neili") * (int)target->query_dex();
        ap *= (int)me->query("combat_exp")/200;
        pp *= (int)target->query("combat_exp")/200;
        ap /= 1000;
        pp /= 1000;
	if(!living(target)) pp = 1;


 if(random(ap+pp) > pp/2){
      me->start_perform(4, "「鲁达拔柳」");
        if(!userp(target))   target->start_busy(2);
                damage =  me->query_skill("force")*3;
                damage += me->query("jiali") * 15;
                damage -= target->query_temp("apply/armor") * 2;
                effect = SKILL_D("dulong-dafa")->force_effect(target->query_skill_mapped("force"));
                damage *= (5-effect);
                if (damage < 0) damage = 0;
                damage = damage + random(damage / 2);
                
if(me->query("gender")!="男性")
            damage = damage*2/3; 
 // 非男性威力小   
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", random(damage), me);
                target->receive_damage("neili", damage/4);
                me->receive_damage("neili", damage/6);
                if(damage >= 5000)
                        message_vision(HBYEL"这一招乃是使上了全力，丝毫不留余地，$n的生死存亡，便决于这顷刻之间！\n"NOR, me, target);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
               
message_vision("结果只听见$n一声惨嚎，"+weapon->name()+"已在$p的小腹对穿而出，鲜血溅得满地！！\n"NOR, me, target);
                message_vision( "( $n"+eff_status_msg(p)+" )\n", me, target);

 if((int)me->query_skill("tenglong-bifa", 1)>450) { 
   message_vision( HIY"\n$N一击命中，"+weapon->name()+HIY"一收乘势而前，又向$n连攻数招！"NOR, me, target); 
   perform2(me, target);
   target->add_busy(1);  }
    }

 else {
            me->start_perform(2, "「鲁达拔柳」");
          dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                message_vision( SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
     message_vision( HIY"\n$N一击不中，"+weapon->name()+HIY"一收滚地而前，向$n连攻数招！"NOR, me, target); 
   target->add_busy(1);
    perform2(me, target); 
  }         me->add("neili", -400);
        me->add("jingli", -100);
     
   return 1;
}
 
int perform2(object me, object target)
{int lvl;
object weapon = me->query_temp("weapon");
if( !target
         || !target->is_character()
         || !me->is_fighting(target)
         || !living(target))
            	return notify_fail("只能在战斗中使用。\n");
 lvl = (int)me->query_skill("tenglong-bifa", 1)  /3; 

me->add_temp("apply/attack", lvl); 
me->add_temp("apply/damage", lvl); 
me->add_temp("apply/strength", lvl/6); 
      
weapon->unequip();
 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

 weapon->wield(); 
if ( me->is_fighting(target) && random(me->query_skill("tenglong-bifa", 1)) > 250)
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

me->add_temp("apply/attack", -lvl); 
me->add_temp("apply/damage", -lvl); 
me->add_temp("apply/strength", -lvl/6); 
         me->add("neili", -200);
   me->start_busy(1);
        me->add("jingli", -100);
      }
