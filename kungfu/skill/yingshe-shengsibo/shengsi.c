// huashan_shengsi.c

// yingshe-shengsibo perform ӥ�������� 

//by daidai 2005-10-07



#include <ansi.h>

#include <combat.h>



inherit F_SSERVER;



void remove_effect(object me);



string perform_name(){ return HIC"ӥ��������"NOR; }



int perform(object me, object target)

{


    int exp,exp1,busy,lvl,lvl1;



      if( !target ) target = offensive_target(me);

     

      if( !target || !me->is_fighting(target) )

      return notify_fail("��ӥ����������ֻ����ս���жԶ���ʹ�á�\n");

         

      if( objectp(me->query_temp("weapon")) )

      return notify_fail("��������ʹ�á�ӥ������������\n");

      

      if( (int)me->query_skill("yingshe-shengsibo",1) < 100 )

      return notify_fail("���ӥ��������������죬����ʹ�á�ӥ������������\n");
      

      if( (int)me->query_str() < 25 )

      return notify_fail("��ı�������ǿ������ʹ�á�ӥ������������\n");

      

      if( (int)me->query("max_neili") < 1000 )

      return notify_fail("�������̫��������ʹ�á�ӥ������������\n");

      

      if( (int)me->query("neili") < 350 )

      return notify_fail("�������̫���ˣ��޷�ʹ�ó���ӥ������������\n");   

                                         

      if (me->query_skill_prepared("hand") != "yingshe-shengsibo"

       && me->query_skill_prepared("claw") != "yingshe-shengsibo")

      return notify_fail("�������޷�ʹ�á�ӥ�������������й�����\n");                                         

      if( me->query_temp("huashan_shengsi"))

      return notify_fail("������ʹ��ӥ�������������⹥����ӥ������������\n");



    if (target->is_busy()) return notify_fail("�Է����Թ˲�Ͼ���ŵ������ɣ�\n");

       

      message_vision( HIC"\n$NͻȻ����$n����������ʹ����ɽ������������ľ���������ʮ��·��ӥ������������

��ӥ��˫ʽ��ʩ����ӥ��ʸ֮�ˣ������鶯֮�ƣ���һʽ��ͬʱ�ֳ���Ѹ�ݺ����������֮��\n" NOR, me, target);

      // message_vision(msg, me, target);   

  message_vision( HIR"\n$N���ֳ�ӥצ״���ܡ��á�Ť������һ��ӥץ������ʹ�ó����뻯������似��\n" NOR, me, target);                                    

    exp=me->query("combat_exp");

    exp1=target->query("combat_exp");

    lvl=me->query_skill("claw");

    lvl1=target->query_skill("dodge");

    busy=3;

    busy=busy+random(lvl)/100;

    if(busy>5) busy=5;

            if( random(exp/100*lvl)>exp1/100*lvl1/4){

        message_vision( HIW"$nһ������$Nץס�ؽ�Ҫ��֮������ʱȫ����ľ���������á�\n"NOR, me, target);

    //    message_vision(msg, me, target); 

if( wizardp(me)) tell_object(me,sprintf("busy=%d\n",busy));

        me->set_temp("huashan_shengsi",1);  

        me->add("neili", -350);    

        target->start_busy(busy);

        me->start_busy(random(2));

        call_out("remove_effect", me->query_skill("yingshe-shengsibo") / 20 + 2, me);

      }

      else {

        message_vision( HIG"$nһ�����ݷɳ����⣬���ݵ��ӳ���$N�Ĺ�����Χ��\n"NOR, me, target);      

    //    message_vision(msg, me, target);                    

        me->start_busy(2);

        me->add("neili", - 100);

   me->start_perform(4,"��ӥ����������");    }

      return 1;

}



void remove_effect(object me)

{

    if (!me) return;

    me->delete_temp("huashan_shengsi");

 tell_object(me,MAG"\n����֪���ס�ӥ���������������Ķ࣬���ֶ��������ܶ�ʹ�������ĵ�ֹͣ��ʹ�á�"NOR);

    message_vision(CYN"\n$Nһ�ס�ӥ����������ʹ����ϣ����������˿�����\n"NOR, me);

}