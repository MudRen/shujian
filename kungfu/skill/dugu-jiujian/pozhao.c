// By Spiderii 合并那些乱七八糟的pobian.posuo等等。。。

#include <ansi.h>
inherit F_SSERVER;

string perform_name() { return HIG"破招"NOR; }

int perform(object me, object target)
{
        string msg, *skillname, *skilltype = ({});
        object weapon;
	 mapping skills;
        int i, skill = me->query_skill("dugu-jiujian",1);

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("「破招」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (skill < 200 )
                return notify_fail("你的独孤九剑还不够火候。\n");

        if ((string)me->query_skill_mapped("sword") != "dugu-jiujian" 
            && userp(me))
                return notify_fail("你现在无法使用「破招」！\n");

        if ((string)me->query_skill_mapped("parry") != "dugu-jiujian" 
            && userp(me))
                return notify_fail("你现在无法使用「破招」！\n");


	if(target->query_temp("dgjj/pozhao"))
	       return notify_fail("对手已经被克制住了。\n");

        if((int)me->query("jingli") < 2000)
                return notify_fail("你的精力不够！\n"); 

        msg = HIC"\n$N胸藏剑意，剑招随意挥洒而出，便是$n招式中的破绽所在，显是独孤九剑已达到收发自如的境界！\n"NOR;

        me->add("jingli", -1000);
if(skill<=451) 
        me->start_perform(3,"「破招」");

        if ( random(me->query("int")) >= target->query("int") /3  || (me->query("int",1)>35 && !userp(target)) ) {

           msg += HIG"\n$n但觉$N一剑攻出，时若游龙穿空，时若惊鸿渡云。心慌意乱之间，只觉周身武功竟发挥不出平时一半！\n"NOR;

           weapon = target->query_temp("weapon");
           if (weapon) {
               switch((string)weapon->query("skill_type"))
               {
                  case("sword")    : skilltype += ({"apply/sword"}); 
                                     break;
                  case("blade")    : skilltype += ({"apply/blade"}); 
                                     break;
                  case("axe")      : skilltype += ({"apply/axe"}); 
                                     break;
                  case("brush")    : skilltype += ({"apply/brush"}); 
                                     break;
                  case("club")     : skilltype += ({"apply/club"}); 
                                     break;
                  case("hammer")   : skilltype += ({"apply/hammer"}); 
                                     break;
                  case("dagger")   : skilltype += ({"apply/dagger"}); 
                                     break;
                  case("spear")    : skilltype += ({"apply/spear"}); 
                                     break;
                  case("hook")     : skilltype += ({"apply/hook"}); 
                                     break;
                  case("stick")    : skilltype += ({"apply/stick"}); 
                                     break;
                  case("staff")    : skilltype += ({"apply/staff"}); 
                                     break;
                  case("whip")     : skilltype += ({"apply/whip"}); 
                                     break;
                  case("throwing") : skilltype += ({"apply/throwing"}); 
                                     break;
               }
            } else {
                  skills = target->query_skill_prepare();
                  if ( skills ) {
                       skillname = keys(skills);
                       foreach (string item in skillname) {
                          if (!target->query_skill(item))
                                  continue;
                          switch(item) { 
                              case("cuff")   : skilltype += ({"apply/cuff"}); 
                                               break;
                              case("strike") : skilltype += ({"apply/strike"}); 
                                               break;
                              case("finger") : skilltype += ({"apply/finger"}); 
                                               break;
                              case("hand")   : skilltype += ({"apply/hand"}); 
                                               break;
                              case("leg")    : skilltype += ({"apply/leg"}); 
                                               break;
                              case("claw")   : skilltype += ({"apply/claw"}); 
                                               break;
                          }
                          i++;
                       }
                  }
            }

            if (sizeof(skilltype) == 0) skilltype += ({"apply/unarmed"});

            for (i=0; i < sizeof(skilltype); i++)
                 target->add_temp(skilltype[i],-skill);

            target->apply_condition("no_perform", 1+random(3));
            target->set_temp("dgjj/pozhao",1);
            target->delete("jiali");

            call_out("remove_effect", skill/10, target, skill, skilltype);
        } else {
            msg += HIG"\n$n突觉$N剑法一滞，无法连贯，周身压力顿时减轻了。\n"NOR;
        }
        message_vision(msg,me,target);
        return 1;
}

void remove_effect(object target, int skill, string *skilltype)
{
        int i;
        if (!target) return;

        for (i=0; i < sizeof(skilltype); i++)      
              target->add_temp(skilltype[i],skill);
	 target->delete_temp("dgjj/pozhao");
        message_vision(HIW"\n$N的武功恢复正常了。\n", target);
}

int help(object me)
{
	write(HIG"\n独孤九剑「破招」："NOR"\n");
	write(@HELP
	      运独孤九剑剑意，破敌之招数，以无招胜有招。

          要求：      以独孤九剑为剑法；
                      以独孤九剑为招架；
                      独孤九剑 等级 200 以上；
                      最大精力 不小于 2000；

                      在战斗中持剑使用。
HELP
        );	
        return 1;
}
