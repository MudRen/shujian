#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
 if( duration < 1 ) return 0;
 if( !living(me) ) {
 message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
 }
else {
tell_object(me, HIB "��Ȼһ������֮�������������������������£������Ϣ�޷���˳��\n" NOR );
 message("vision", me->name() + "�Ų����ģ��������á�\n",
  environment(me), me);
   }
me->add_busy(random(3)+2);
    me->apply_condition("fx_busy", duration - 1);
 if( duration < 1 ) return 0;
  return CND_CONTINUE;
}
