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
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if(me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("����ڹ�������Ԫ�����޷�ʹ�þ������£�\n");


 if(me->query("quest/junlin/pass")!=1)
                return notify_fail("����Ȼ��˵���������¾���������һֱû���������о��ϣ����������ã�\n");

if( me->query_skill("shenyuan-gong", 1) < 300 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ�þ������£�\n");

if( me->query_skill("canhe-zhi", 1) < 300 )
                return notify_fail("���ָ����δ���ɣ�����ʹ�þ������£�\n");

 if( me->query_temp("weapon"))
                        return notify_fail("���������ű������޷�ʹ�þ������£�\n");
   
if (me->query_skill_prepared("finger") != "canhe-zhi"
            || me->query_skill_mapped("finger") != "canhe-zhi")
                return notify_fail("�������޷�ʹ�á��������¡����й�����\n");  


        if(me->query("max_neili") < 1200 )
                return notify_fail("���������Ϊ����������ʹ�þ������£�\n");
        if(me->query("neili") < 1000 )
                return notify_fail("�������������㣬����ʹ�þ������£�\n");
        if(me->query("jingli") < 600 )
                return notify_fail("�����ھ������㣬����ʹ�þ������£�\n");
        if(me->query_temp("chz/ch"))
                return notify_fail("������ʹ�þ������£�\n");

        if(me->query_skill("finger", 1) < 120 )
                return notify_fail("��Ļ���ָ��������죬�����ڽ�����ʹ�þ������¡�\n");


msg = HIY"\n$Nͻ�ذεض���ʮָ������ָ����$n�����ȥ�����϶��£��������磬�������߷緶������һ��"HIR"���������¡�"HIY"!\n"NOR;

 message_vision(msg, me, target);
me->start_perform(3, "���������¡�");

        me->set_temp("chz/ch", 1); //��������Ϊ�˴����κ�ָ��auto
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

msg = HIC"\n$N�̶���Цһ�����ȵ������ڶ�ָ"HIM"���������̺᡹"HIC"С���ˣ���\n"+
"����ֳ�һָ��$nӲ���µ�һʽ�������в�������ڶ������Ҳ����Ӳ��,��ʱ��æ���ң�ƣ���мܣ����޻���֮��!\n"NOR;

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
                me->start_perform(3 + random(2),"���������¡�");
 
  call_out("back", 5 + random(me->query("jiali") / 20), target);               
        } 
        else {
                msg = msg + HIW "$nһ�������ţ�������󷽲ſ����ܹ���\n" NOR;
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

msg = HIC"\n������$N��һָ���յ��������һ��"HIR"����ָ��ɽ�ơ�"HIC"����ɽ�续���쳾���Σ�ָ���絶��\n"+
         "$n������֮�£�����ָ��Ϭ����������ǻ�������ȴ�������������\n"NOR;
        ap = me->query("combat_exp", 1) * me->query_con(1)/100000;
        dp = target->query("combat_exp", 1) * target->query_con(1)/100000;
//�����100000��Ϊ�˷�ֹexp��ֵ�����ʱ����ִ������


if( random(ap + dp) > dp||  me->query("con",1) > 40)
{
             if(weapon1) msg += HIG"$nֻ�ý��������ڵ���һ����ȴ����ֵ���ס��"HIW+weapon1->name()+HIG"���±���ɣ����ġ���һ��������¡�\n"NOR;
        
                damage =  me->query_skill("canhe-zhi",1)*3;
                damage += me->query_skill("finger")* 3;
                damage += random(damage);

             if ( damage > 2500 )
                        damage = 2500 + (damage - 2500)/10;

//���Բ��ܴ򱬡����˺���ͳ�����
             if ( damage >= target->query("qi",1) ) 
                        damage = target->query("qi",1) -1;
           	        
         if(weapon1) {      weapon1->unequip();
			                      weapon1->move(environment(target));
                     }

                target->add("neili",-(300+random(150)));
                target->apply_condition("no_exert", 1+ random(2));
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
//��������    msg += damage_msg(damage, "����");
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

                msg  += CYN"\n$n�͵�ʮ�˹���Σ��֮�ж������һ�����Ǳ�֮����\n"NOR;
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
//���о�ҪCD�����ٺٹ���
                me->start_perform(6, "���������¡�");
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

string perform_name(){ return HIG"��������"NOR; }
int help(object me)
{
        write(HIG"\n�κ�ָ֮���������¡���"NOR"\n\n");
        write(@HELP
        Ҫ��  ���ճɹ���
                ��ǰ���� 1000 ���ϣ�
                ������� 1200 ���ϣ�
                ��ǰ���� 600 ���ϣ�
                �κ�ָ�ȼ� 300���ϣ�
                ��Ԫ���ȼ� 300 ���ϣ�
                ����ָ���ȼ� 300 ���ϣ�
                ����ָ��Ϊ�κ�ָ��
                �����ڹ�Ϊ��Ԫ����
HELP
        );
        return 1;
}
