// By Spiderii �ϲ���Щ���߰����pobian.posuo�ȵȡ�����

#include <ansi.h>
inherit F_SSERVER;

string perform_name() { return HIG"����"NOR; }

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
                return notify_fail("�����С�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (skill < 200 )
                return notify_fail("��Ķ��¾Ž����������\n");

        if ((string)me->query_skill_mapped("sword") != "dugu-jiujian" 
            && userp(me))
                return notify_fail("�������޷�ʹ�á����С���\n");

        if ((string)me->query_skill_mapped("parry") != "dugu-jiujian" 
            && userp(me))
                return notify_fail("�������޷�ʹ�á����С���\n");


	if(target->query_temp("dgjj/pozhao"))
	       return notify_fail("�����Ѿ�������ס�ˡ�\n");

        if((int)me->query("jingli") < 2000)
                return notify_fail("��ľ���������\n"); 

        msg = HIC"\n$N�زؽ��⣬���������������������$n��ʽ�е��������ڣ����Ƕ��¾Ž��Ѵﵽ�շ�����ľ��磡\n"NOR;

        me->add("jingli", -1000);
if(skill<=451) 
        me->start_perform(3,"�����С�");

        if ( random(me->query("int")) >= target->query("int") /3  || (me->query("int",1)>35 && !userp(target)) ) {

           msg += HIG"\n$n����$Nһ��������ʱ���������գ�ʱ��������ơ��Ļ�����֮�䣬ֻ�������书�����Ӳ���ƽʱһ�룡\n"NOR;

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
            msg += HIG"\n$nͻ��$N����һ�ͣ��޷����ᣬ����ѹ����ʱ�����ˡ�\n"NOR;
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
        message_vision(HIW"\n$N���书�ָ������ˡ�\n", target);
}

int help(object me)
{
	write(HIG"\n���¾Ž������С���"NOR"\n");
	write(@HELP
	      �˶��¾Ž����⣬�Ƶ�֮������������ʤ���С�

          Ҫ��      �Զ��¾Ž�Ϊ������
                      �Զ��¾Ž�Ϊ�мܣ�
                      ���¾Ž� �ȼ� 200 ���ϣ�
                      ����� ��С�� 2000��

                      ��ս���гֽ�ʹ�á�
HELP
        );	
        return 1;
}
