// diqing.c ���ཱུ��
// created by Olives@SJ
// Update By lsxk@hsbbs 2007/6/6

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name() {return HIY"���ཱུ��"NOR;}

void back(object target);

int perform(object me, object target)
{
        int skill,ap,pp,time;
        object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(me->query("family/master_id")!="hong antong")
                return notify_fail("�����ཱུ����ֻ�а��˽���������ã�\n");

        if( (int)me->query_skill("tenglong-bifa", 1) < 120 )
                return notify_fail("�������ذ��������죬����ʹ�õ��ཱུ����\n");

        if( (int)me->query_skill("dagger", 1) < 120 )
                return notify_fail("��Ļ���ذ��������죬����ʹ�õ��ཱུ����\n");

        if( (int)me->query_skill("dulong-dafa", 1) < 120 )
                return notify_fail("��Ķ����󷨲�����죬����ʹ�õ��ཱུ����\n");

    	if( (int)me->query("neili", 1) < 800 )
       		return notify_fail("�������������㣡\n");
       	if( (int)me->query("jingli", 1) < 500 )
       		return notify_fail("�����ھ������㣡\n");

    	if( (int)me->query("max_neili", 1) < 1500 )
       		return notify_fail("��������Ϊ���㣡\n");
        if( (int)me->query_dex() < 30  )
                return notify_fail("�����̫�ͣ�����ʹ�õ��ཱུ����\n");

        if (!weapon
        || me->query_skill_mapped("dagger") != "tenglong-bifa")
                return notify_fail("�������޷�ʹ�õ��ཱུ����\n");

        if(target->query_temp("sld/pfm/diqing")
        || target->query_temp("block_msg/all"))
                return notify_fail("�����۾��Ѿ�Ϲ�ˣ��������õ��ཱུ���ˣ�\n");
        skill = (int)me->query_skill("tenglong-bifa", 1);

	ap = COMBAT_D->skill_power(me,"dagger",SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(me,"parry",SKILL_USAGE_ATTACK);
        if(target->is_busy())
        	pp /= 2;

        me->add("neili", -350);
        me->add("jingli", -200);
message_vision(HIY "\n$Nʹ��һ�С����ཱུ������������ײ��ʮָ��$n�ؿ���ץ���������֮�ʣ�ͻȻһ����������������
Ծ��˫��һ�֣�������$n��ͷ��ͬʱ˫��Ĵָѹס$n̫��Ѩ��ʳָ��ü����ָ���ۡ�\n"NOR,me,target);

        message_vision(HIY"$nһ����æ˫�ۻ�ת���뻤ס˫�ۣ�\n"NOR, me, target);;

  	if(random(ap+pp)>pp)
         {
                message_vision(HIR"\nֻ��$n�ҽ�һ����$N����֧��ָ�Ѿ�����$n���ۿ���ֻ��$n���۽���Ѫֱ����\n"NOR, me, target);
                target->set_temp("sld/pfm/diqing", skill);
                target->add_temp("apply/attack", - skill/3);
                target->add_temp("apply/defense", -skill/3);
                target->receive_damage("qi", skill*5);
                target->receive_wound("qi", skill*5/2);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ skill*5+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ skill*5+ WHT"���˺���\n"NOR); ;
                COMBAT_D->report_status(target);
                target->kill_ob(me);
                target->set_temp("block_msg/all",1);
                me->start_perform(10,"���ཱུ��");
                time = 3+skill/10;
                if(time>60) time = 60;
                call_out("back", time, target);
                }

  	else {
                message_vision(HIY"$n��ͷ����һ������������㿪��$N��һ�С�\n"NOR, me, target);
            if((int)me->query_skill("tenglong-bifa",1)>150){
                message_vision(HIR"\n$N�ĿϾʹ˰��ݣ���æ������ǰһ��ǿ����$n�پ����ɾ���Ϯ��!\n"NOR, me, target);
                me->add_temp("apply/damage",skill/5);
                me->set_temp("tlbf/diqing",1);
                COMBAT_D->do_attack(me,target,weapon,1);
                COMBAT_D->do_attack(me,target,weapon,1);
                COMBAT_D->do_attack(me,target,weapon,1);
                me->delete_temp("tlbf/diqing");
                me->add_temp("apply/damage",-skill/5);
            }
                me->start_perform(2+random(3),"���ཱུ��");
                me->start_busy(3);
                target->kill_ob(me);
        }

        return 1;
}

void back(object target)
{
        int lvl;
        if(!target) return;
        lvl = target->query_temp("sld/pfm/diqing");
        target->add_temp("apply/attack", lvl/3);
        target->add_temp("apply/defense", lvl/3);
        target->set_temp("block_msg/all", 0);
        if(living(target))
              tell_object(target, HIW "��������˫Ŀû�б�ץϹ�����ֿ��Կ�����������\n" NOR);
        target->delete_temp("sld/pfm/diqing");
}

int help(object me)
{
   write(WHT"\n����ذ����"HIY"���ཱུ��"WHT"����"NOR"\n");
   write(@HELP

    Ҫ��������� 1500 ���ϣ�
          ��ǰ���� 800 ���ϣ�
          ��ǰ���� 500 ���ϣ�
          ����ذ���ȼ� 120 ���ϣ�
          ����ذ���ȼ� 120 ���ϣ�
          �����󷨵ȼ� 120 ���ϣ�
          ��ǰ�� 30 ���ϣ�
          �Ա����� ���ԡ�
HELP
   );
   return 1;
}
