#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    string msg;
      switch(random(5)){
      case 0 : 
              msg = HIM"$N����ͨ�죬���в��ϵķ���Ұ�ް�ĵͺ�\n"NOR;
              me->add_busy(5);
              me->add("jingli", -300);
              break;
      case 1 : 
              msg = HIM"$Nֻ�������ѵ�����ͷ��ͣ���������Լ���˫����\n"NOR;
              me->add_busy(5);
              me->add("jingli", -400);
              break;
      case 2 : 
              msg = HIM"$N˫�ֽ��渧Ħ���Լ���˫�ۼ����˻�У�������...������...��Ҫ���ˡ�\n"NOR;
              me->add_busy(5);
              me->add("jingli", -500);
              break;
      case 3 : 
              msg = HIM"$Nɫ���ԵĿ������ǣ����ﲻͣ�Ľл��ţ������ҵ�С��������\n"NOR;
              me->add_busy(5);
              me->add("jingli", -600);
              break;
      case 4 : 
              msg = HIM"$N���Լ����·���ͣ��˺����ָ�����ؿڻ�����һ������Ѫ�ۡ�\n"NOR;
              me->add_busy(5);
              me->add("jingli", -700);
              break;
      }
      message_vision(msg, me);      
      me->apply_condition("yysan_poison", duration - 1);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

