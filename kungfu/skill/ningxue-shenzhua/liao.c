// liao.c  ��Ѫ��צ֮�����־���
// Create By lsxk@hsbbs 2007/5/13 
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string *xue_name = ({"��׶Ѩ","�ٻ�Ѩ","־��Ѩ","�羮Ѩ","�͹�Ѩ","�ڹ�Ѩ","���Ѩ","����Ѩ",
                     "����Ѩ","����Ѩ","����Ѩ","�׺�Ѩ","��̨Ѩ","�縮Ѩ","���Ѩ","����Ѩ",
                     "����Ѩ","����Ѩ","˿����Ѩ","����Ѩ","����Ѩ","��׵Ѩ","����Ѩ","����Ѩ", });

string perform_name() {return HIY"���־�"NOR;}

 int perform(object me, object target)
 {
         int j;
         string msg,xuedao;
         j = me->query_skill("ningxue-shenzhua", 1);

         if( !target ) target = offensive_target(me);

         if( !target 
           || target->is_fighting()
           || me->is_fighting()
           || !living(target)
           || environment(target)!= environment(me))
                 return notify_fail("�㲻����ս����ʹ��,���߶���ս���е����ʹ�á����־�����\n");

         if( target->is_busy() )
                 return notify_fail("�Է���æ���أ�\n");

         if( me->is_busy() )
                 return notify_fail("����æ���أ�\n");

         if( !target->query_condition("nxsz_hurt") )
                 return notify_fail("�Է�δ���ܵ���Ѫ�˺�����Ҫʹ�á����־�������?\n");

         if( objectp(me->query_temp("weapon")) )
                 return notify_fail("�������ֲ���ʹ�á����־�����\n");

         if( (int)me->query_skill("ningxue-shenzhua", 1) < 200 )
                 return notify_fail("�����Ѫ��צ������죬ʹ���������־���������\n");

         if( (int)me->query_skill("force", 1) < 300 )
                 return notify_fail("������ڹ�������ʹ���������־���������\n");

         if( (int)me->query_con() < 35 )
                return notify_fail("���ڸ��ǲ��㣬�޷�ʹ�á����־�������!\n");

         if( (int)me->query_skill("medicine", 1) < 120 )
                 return notify_fail("��Ա���������о������٣�ʹ���������־���������\n");

         if (me->query_skill_prepared("claw") != "ningxue-shenzhua"
          || me->query_skill_mapped("claw") != "ningxue-shenzhua" )
                 return notify_fail("��Ҫȫ��������Ѫ��צ�������ʹ�������־���������\n");

         if( (int)me->query("max_neili") < 3000)
                 return notify_fail("��������Ϊ̫��޷�ʹ�á���Ѫ����������\n");

         if( (int)me->query("neili") < 2500 )
                 return notify_fail("����������̫�����޷�ʹ�á���Ѫ����������\n");
         
         xuedao = xue_name[random(sizeof(xue_name))];

         msg = HIY "\n$N����������$n����ǰ�����ƽ���$n�괦�������ڹ�����$n����֮��"HIR"��Ѫ����"HIY+"��������ȥ......\n"NOR;

         message_vision(msg, me, target);

         target->apply_condition("nxsz_hurt", -j/50);
         me->add("neili", -2000);
         me->start_busy(random(5)+4);
         target->start_busy(random(5)+4);
         
         me->start_perform(random(4),"����Ѫ����");
         return 1;
 }

int help(object me)
{
   write(WHT"\n��Ѫ��צ��"HIY"���־�"WHT"����"NOR"\n");
   write(@HELP
   �ˡ����־�����ר����������������Ѫ��צ�˺����ˡ�

   Ҫ��  ���� 2500 ���ϣ�
           ������� 3000 ���ϣ� 
           ������� 35 ���ϣ� 
           ��Ѫ��צ�ȼ� 200 ���ϣ�
           �����ڹ��ȼ� 300 ���ϣ�
           ��������ȼ� 120 ���ϣ�
           ����צ��Ϊ��Ѫ��צ��
           ��צ�������ޱ�����

HELP
   );
   return 1;
}
