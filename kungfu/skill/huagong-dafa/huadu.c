// huadu.c ����
// By Spiderii@ty����Ч��
#include <ansi.h>

inherit F_CLEAN_UP;
void remove_effect(object me,int count);

int exert(object me)
{      
int skill;
skill = me->query_skill("huagong-dafa");
if( !me->is_fighting() && (int)me->query_skill("huagong-dafa",1)<350 )
return notify_fail("��ֻ����ս����ʹ�á���������\n");

if( (int)me->query_skill("huagong-dafa", 1) < 100 )
return notify_fail("��Ļ�������Ϊ��������\n");

if (me->query_skill_mapped("force") != "huagong-dafa")
return notify_fail("�����ڹ��С���������\n");

if( (int)me->query_skill("poison", 1) < 100 )
return notify_fail("�����ڵĶ��ز������޷�ʹ�á���������\n"); 

if( (int)me->query("max_neili") < 1000 )
return notify_fail("���������Ϊ��ô�����ʹ�á���������\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

if( me->query_temp("hgdf_power"))
                return notify_fail("���Ѿ���ʹ���ˡ�\n");

message_vision(BLU"$N��Ŀ���񣬽������̻��Ķ���������Ϊ��������ɢ����֫�ڡ�\n" NOR, me);
if(me->is_fighting())
        me->start_busy(1);
me->add_temp("apply/strength", me->query_skill("huagong-dafa", 1)/8);
me->add_temp("apply/attack", me->query_skill("huagong-dafa", 1)/4);
me->add_temp("apply/armor_vs_force", me->query_skill("poison", 1)/8);
        me->add("neili", -400);
me->set_temp("hgdf_power",1);
call_out("remove_effect", 1, me, skill/3);
me->start_exert(1, "����");
        return 1;
}
void remove_effect(object me, int count)
{
if (!me) return;
if( count < 1){
me->delete_temp("hgdf_power");
me->add_temp("apply/strength", -me->query_skill("huagong-dafa", 1)/8);
me->add_temp("apply/attack", -me->query_skill("huagong-dafa", 1)/4);
me->add_temp("apply/armor_vs_force", -me->query_skill("poison", 1)/8);
message_vision(BLU"$N�˹�������ϣ����������ض����̻����ڡ�\n"NOR, me);

            return;

        }
call_out("remove_effect", 1 , me ,count -1);
}
string exert_name(){ return BLU"����"NOR; } 
int help(object me)
{
          write(BLU"\n�����󷨡���������"NOR"\n");
          write(@HELP
          �����ɵĹ�����Ҫ����<��>�����¹������������������ζ
          ���������������������쳣���������������޲�̸��ɫ�䡣
          �⻯��һʽ���ǽ�ƽʱ���������ڵľ綾����������߻�����֫
          ����Ϊ�������ս���У��𵽸����˵е����ã�

          Ҫ��:   ������ 100 ����
                  ����     100 ����
                  ��ǰ���� 500 �㣻
                  ������� 1000 �㡣
HELP
);
return 1;
}
