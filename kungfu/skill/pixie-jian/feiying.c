// feiying.c ������Ӱ��

#include <ansi.h>
string perform_name(){ return MAG"������Ӱ��"NOR; }

inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if( !target ) target = me;
//        if(!me->is_fighting())
//                return notify_fail("������Ӱ��ֻ����ս����ʹ�á�\n");

        
        if( (int)me->query("neili") < 500  ) 
                return notify_fail("�������������\n");
        if( (int)me->query("jingli") < 200  ) 
                return notify_fail("��ľ���������\n");
        if( (int)me->query_temp("feiying") ) 
                return notify_fail("���Ѿ������ÿ�����Ӱ���ˡ�\n");
        if( (int)me->query_skill("pixie-jian", 1) < 120 )
                return notify_fail("��ı�а������û���ɣ��޷�ʹ�ÿ�����Ӱ����\n");
        if( (int)me->query_dex() < 30  )
                return notify_fail("�����̫�ͣ�����ʹ�ÿ�����Ӱ����\n");
       

        skill = me->query_skill("dodge",1);
        skill = skill + me->query_skill("pixie-jian",1);
        skill = skill / 12;
        me->add("neili", -200);
        me->add("jingli", -150);
        me->receive_damage("qi", 50);

        message_vision(
        MAG "ֻ��$N�������һ����ƾ�շ�����س��࣬����Ʈ������������Ӱ��һ�㡣\n" NOR, me);
        tell_object(me, MAG "��Ĭ�˿�����Ӱ�����ھ���й��������ƾ��̧��������\n" NOR);

   if ( me->query_skill_mapped("force") == "kuihua-shengong") me->add_temp("apply/armor",me->query_skill("dodge",1) + me->query_skill("kuihua-shengong",1));


        me->add_temp("apply/dodge", skill);
        me->set_temp("feiying", 1);

        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
	if(!me) return;
//   if ( me->query_skill_mapped("force") == "kuihua-shengong"))  me->add_temp("apply/armor",- me->query_skill("dodge"));
     if ( me->query_skill_mapped("force") == "kuihua-shengong")   me->add_temp("apply/armor",-me->query_skill("dodge",1) - me->query_skill("kuihua-shengong",1));
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("feiying");
        tell_object(me, MAG "��һ�������Ӱ���Ѿ�ʹ�꣬���ָֻ�������\n" NOR);
}
