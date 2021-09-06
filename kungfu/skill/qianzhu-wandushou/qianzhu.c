// qianzhu.c ǧ����
// by Lsxk@HSBBS

#include <ansi.h>

inherit F_SSERVER;

int perform_jigong(object,object);
int perform_normal(object,object);

string perform_name(){ return HIR"ǧ"HIG"��"HIW"��"HIB"��"NOR;}

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);
        
        if( !objectp(target) || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("��ǧ���򶾡�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("qianzhu-wandushou", 1) < 150 )
                return notify_fail("���ǧ�����ֹ�����ԶԶ�������޷�ʹ�á�ǧ���򶾡����У�\n");

        if( me->query_temp("weapon") )
                return notify_fail("�������ֲ���ʹ�á�ǧ���򶾡���\n");

        if (me->query_skill_prepared("hand") != "qianzhu-wandushou" ||
            me->query_skill_mapped("parry") != "qianzhu-wandushou")
                return notify_fail("������Ƚ�ǧ�������������ַ�֮�в��С�\n");

        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("���������Ϊ���㣬ʹ������ǧ���򶾡����У�\n");     

        if( (int)me->query("neili") < 500 )
                return notify_fail("����������㣬ʹ������ǧ���򶾡����У�\n");     

        if( (int)me->query_skill("hand", 1) < 150 )
                return notify_fail("����ַ�������죬ʹ������ǧ���򶾡����У�\n");

        if( me->query("env/ǧ����")=="����"){
             perform_jigong(me,target);
        }
        else{
             msg= HIB "\n$N����ǧ������˫�֣���������ʱ��ʱ�֣�\n"NOR;
             message_vision(msg, me, target); 
             perform_normal(me,target);
        }
    return 1;
}

int perform_jigong(object me,object target)
{
    int i,j,k;
    string msg;
    if( !target ) target = offensive_target(me);
    i = (int)me->query("per",1)/10;
    i = 4 - i;
    j = (int)me->query_skill("qianzhu-wandushou", 1)*2/3;
    k = (int)me->query_skill("hand", 1)/2;
    if (i>3) i=3;
    else if (i<1) i=1;
    if (wizardp(me))
        write("i is "+i+".\n");
    me->set_temp("qzwd_pfm", 1);
    me->add_temp("apply/attack", j);
    me->add_temp("apply/damage", j/2);
    me->add_temp("apply/hand", k);
    msg= HIR "\n$N����ǧ���򶾹��������ڻ���綾����˫�ִ����ȵ�����С���ˣ����������缱�籩���ع���$n��\n"NOR;
    message_vision(msg, me, target);
    me->start_perform(4, "��ǧ���򶾡�");
if(!userp(target))  target->start_busy(2);
                                 target->apply_condition("no_fight",1);
                                 target->apply_condition("no_perform",1);

    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), i);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), i);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), i);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), i);
    me->add_temp("apply/attack", -j);
    me->add_temp("apply/damage", -j/2);
    me->add_temp("apply/hand", -k);
    me->delete_temp("qzwd_pfm");
    return 1;
}

int perform_normal(object me,object target)
{
    int i=random(2)+1,j;
    if( !target ) target = offensive_target(me);
    if (me->is_fighting()
     && (int)me->query_skill("qianzhu-wandushou",1)>500
     && random(4)==2
     && me->query_skill_prepared("hand") == "qianzhu-wandushou"
     && me->query_skill_mapped("parry") == "qianzhu-wandushou"){
      perform_jigong(me,target);
      call_out("perform_normal",4,me,target);
      return 1;
    }
    if (me->is_fighting()
    && me->query_skill_prepared("hand") == "qianzhu-wandushou"
    && me->query_skill_mapped("parry") == "qianzhu-wandushou")
    {
      me->start_perform(i+1,"��ǧ���򶾡�");
      me->set_temp("qzwd_pfm2", 1);
      me->add_temp("apply/attack", (int)me->query_skill("qianzhu-wandushou", 1)/4);
      me->add_temp("apply/hand", (int)me->query_skill("hand", 1)/3);
      for(j=0;j<i;j++)
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(3)+1);
      call_out("perform_normal",i,me,target);
      me->delete_temp("qzwd_pfm2");
      me->add_temp("apply/attack", -(int)me->query_skill("qianzhu-wandushou", 1)/4);
      me->add_temp("apply/hand", -(int)me->query_skill("hand", 1)/3);
      return 1;
    }
    else
    message_vision(HIB"\n$N��ǧ���򶾾���ʹ����ϣ������غ�����һ������\n"NOR,me);
    return 1;

}

int help(object me)
{
   write(WHT"\nǧ�����֡�"HIR"ǧ"HIG"��"HIW"��"HIB"��"WHT"����"NOR"\n");
   write(@HELP
   ���С�ǧ���򶾡�������Ч��������ͨ��SET���õ���
   1��set ǧ���� ����  Ч��������˷���ǿ������������
   2��unset ǧ���� Ч���������Թ������֣�500���󽫻��ڻ��ͨ��

   Ҫ��  ���� 500 ���ϣ�
           ������� 2000 ���ϣ� 
           ǧ������ 150 ���ϣ�
           �����ַ� 150 ���ϣ�
           ���ֱ��ַ�Ϊǧ�����֡�

HELP
   );
   return 1;
}
