//updata by Jpei 2010 
//������Ч��������death_times��������

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name(){ return HIB"�����޹�"NOR; }

int perform(object me,object target)
{
    object weapon;
    int i,j;
    
    if( !target ) target = offensive_target(me);
     
    if( !objectp (target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("�����޹�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if(me->query_skill_mapped("force") != "huntian-qigong")
                return notify_fail("����ڹ����ǻ����������޷�ʹ�������޹���\n");
    if( (int)me->query_skill("huntian-qigong", 1) < 250 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ�������޹���\n");
    if( (int)me->query_skill("dagou-bang", 1) < 250 ) 
                return notify_fail("��Ĵ򹷰�����δ���ɣ�����ʹ�������޹���\n");
    if((int)me->query_skill("stick", 1) < 250 )
                return notify_fail("��Ļ�������������죬������ʹ�������޹���\n");
    if((int)me->query_skill("bangjue", 1) < 180 )
                return notify_fail("��Ĵ򹷰���������죬������ʹ�������޹���\n");
    if((int)me->query_con(1) < 45 )
                return notify_fail("������岻��ǿ׳������ʹ�������޹���\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "stick"
        || me->query_skill_mapped("stick") != "dagou-bang"
        || me->query_skill_mapped("parry") != "dagou-bang")
                return notify_fail("������ʹ���������޹�ô��\n");
                
    if((int)me->query("max_neili") < 4500 )
                return notify_fail("���������Ϊ����������ʹ�������޹���\n");
    if((int)me->query("neili") < 2000 )
                return notify_fail("�������������㣬����ʹ�������޹���\n");

        message_vision(HIW"\n$N�����������һ·���򹷰�����ʹ�ñ仯�򷽣�������ȥ������ز�ã����������������裬������ʽ,����������\n",me);
        message_vision(HIG"�����Ǵ򹷰����ľ��С������޹���,��˵�����ֱ仯��һ��ʹ��,��������,����˷�ȫ�ǰ�Ӱ��\n",me);
        message_vision(HIG"��ʱ�����м�ʮ����ȮҲ��һ�������ˣ���ν�������޹������Ǵ��⣬����֮������ף�������ѧ�еľ���!\n"NOR,me);

    me->start_perform(2+random(2),"�������޹���");
    i = (int)me->query_skill("dagou-bang",1);
    if ( me->query("death_times")) j = me->query("death_times");
     if(j>500) j = 500;

    me->add("neili", -300);
        me->add_temp("apply/attack",  i);
        me->add_temp("apply/damage",  i/3);
    me->add_temp("dgb/wugou",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    me->add_temp("dgb/wugou",1);
    if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    me->add_temp("dgb/wugou",1);
    if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    me->add_temp("dgb/wugou",1);
        me->add_temp("apply/attack",  -i);
        me->add_temp("apply/damage",  -i/3);

    if(me->query("dgb/wugou")){
        message_vision(HBRED"$N�ѵá������޹�������֮��Ҫ������������ˮ��ɲ�Ǽ�����İ�Ӱ����$n!\n"NOR,me,target);
   if( j>100 && me->is_fighting(target)&&!userp(target) ) target->add_busy(j/30);
   if( j>200 && me->is_fighting(target)&& userp(target) ) target->start_busy( (j/100) );
        i = i + j/10;
    me->add_temp("apply/stick",  i );
    me->add_temp("apply/strength",  i /10);
    me->add_temp("apply/attack",  i/2);
    me->add_temp("apply/damage",  i/2);
 
      if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        me->add_temp("dgb/wugou",1);
     if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        me->add_temp("dgb/wugou",1);
     if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
       
        me->add_temp("apply/stick", - i );
        me->add_temp("apply/strength",  - i /10 );
        me->add_temp("apply/attack",  -i/2 );
        me->add_temp("apply/damage",  -i/2);
        me->start_perform(5,"�������޹���");
    }
    me->delete_temp("dgb/wugou");
    me->start_busy(1);
    return 1;
}

int help(object me)
{
   write(HIB"\n�򹷰��������޹�����"NOR"\n");
   write(@HELP
   ���й������䣬Ϊ�򹷰����ռ��ľ��У��佭����ʢ��ؤ��
   �����У�������Ϊ�ߣ���Ȼѧ��þ�������ֻ��������ʽ��
   �ѣ��������ҵ�ؤ���������ү���׿ڴ��ڸþ���������
   �������޹���֮�����ʹ���������������

   Ҫ��  ������� 4500 ���ϣ�
           ���� 2000 ���ϣ�
           �򹷰��ȼ� 250 ���ϣ�
           ���������ȼ� 250 ���ϣ�
           ������� 45 ���ϣ�
           �򹷰����ȼ� 180 ���ϣ�
           �����м�Ϊ�򹷰���
           ��QUEST�Ժ��������
           ��Ч�����������������ʵսЧ����
HELP
   );
   return 1;
}
