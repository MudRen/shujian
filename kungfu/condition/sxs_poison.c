#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if (duration % 2) {
   if( !living(me) ) {
      message("vision", me->name() + "���Ϻ��ֹŹ�Ц�ݡ�\n", environment(me), me);
   }
   else {
      message("vision", me->name() + "ͻȻ��΢΢һЦ����ɫ�Ź֡�\n",
            environment(me), me);
   }
	}

      me->apply_condition("sxs_poison", duration - 1);
   if( duration < 1 ) {
      tell_object(me, BLU "ͻȻ�����������ֹ���֮����Ц�ݡ�\n" NOR );
      message("vision", me->name() + "ͻȻ����̱��Ť���˼��£������ڵأ�һ��Ҳ�����ˣ�\n",
      environment(me), me);
      me->set_temp("last_damage_from", "����Цɢ֮��");
      me->die();
      return 0;
      }
      return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
