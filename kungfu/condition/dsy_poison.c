// dsy_poison.c

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", HIG+me->name() + "ü����б����ͷ�������������˳�����һ��������ĭ˳����������ʡ�\n"NOR, environment(me), me);
   }

      if(me->query("eff_jing") > me->query("max_jing")/2) {
      tell_object(me, CYN "��о�����֮��������ƣ�ȫ����������ɢ�ܡ�\n" NOR );
      }
      else if(me->query("eff_jing") > me->query("max_jing")/4) {
      tell_object(me, CYN "������֮����ʼ���÷����������˼�ֻ��Ӭ����֫��������������\n" NOR );
      }
      else {
      tell_object(me, CYN "�ƶ��Ѿ�������������������������ʧ���е�������������޵�����������\n" NOR );
      message("vision", HIG+me->name() + "ͻȻ�������Ƶ�̱���ڵأ�ȫ����ŧ������һ����Ķ����ͷ��һ���������䣬���Ʈɢ��\n"NOR,
            environment(me), me);
      }

        me->receive_damage("qi", 20, "����ȫ���");
        me->apply_condition("dsy_poison", duration - 1);
        me->receive_wound("jing", 25, "����ȫ���");

     if( duration < 1) return 0;
   return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}