//piao.c Ʈ
//BY BOBO@SJ
// modified by darken@SJ

#include <combat.h>
#include <ansi.h>

inherit F_SSERVER;

string perform_name(){ return HIC"ˮ��Ʈ"NOR; }

void remove_effect(object me, int improve);

int perform(object me)
{
      string msg;                                   
      int improve;
      
      if( (int)me->query_skill("shuishangpiao",1) < 140 )
           return notify_fail("���ˮ��Ʈ������죬����ʹ�á�Ʈ����\n");

      if( (int)me->query_skill("guiyuan-tunafa",1) < 140 )
           return notify_fail("��Ĺ�Ԫ���ɷ��ȼ�����������ʹ�á�Ʈ����\n");  

      if (me->query_skill_mapped("force") != "guiyuan-tunafa")
           return notify_fail("����ڹ����ԣ�����ʹ�á�Ʈ����\n");

      if( (int)me->query_dex() < 28 )
           return notify_fail("�����̫�ͣ�����ʹ�á�Ʈ����\n");
      
      if( (int)me->query_skill("dodge", 1) < 120 )
           return notify_fail("��Ļ����Ṧ̫����屿׾������ʹ�á�Ʈ����\n");
      
      if( (int)me->query("neili") < 400 )
           return notify_fail("�������̫���ˣ��޷�ʹ�ó���Ʈ����\n");   
    
      if (me->query_skill_mapped("dodge") != "shuishangpiao")
           return notify_fail("�����ڼ������Ṧ�޷��á�Ʈ��������\n");

      if( me->query_temp("piao"))
           return notify_fail("������ʹ��ˮ��Ʈ�����������Ʈ����\n");
       
      msg = HIC"$NͻȻ����һ������˫Ŀ����һ����һ̧�������ѵ�ˮ�㣬��������Ʈ������" +
               "������Ʈ�˹�����\n" NOR;
      
      message_vision(msg, me); 
      improve = (int)me->query_skill("dodge");
      me->add_temp("apply/dexerity", improve/10);
      me->set_temp("piao", 1);  
      me->add("neili", -(100 + (int)me->query_skill("shuishangpiao",1)/10));           
      me->start_call_out((: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("shuishangpiao", 1)/5);
      return 1;
}

void remove_effect(object me, int improve)
{
      if(!me) return;
      me->add_temp("apply/dexerity", - improve/10);
      me->delete_temp("piao");
      tell_object(me, HIC"���������һ������ɢȥ�˵������۵�������\n"NOR);
}
