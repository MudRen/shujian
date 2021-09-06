#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

#include <combat_msg.h>

int update_condition(object me, int duration)
{
    string msg;
    int k;
      switch(random(5)){
      case 0 : 
              msg = HIR"$NͻȻ����һ����������ȵ�Ѩ������ס�ˣ�\n"NOR;
              me->add_busy(3);
              break;
      case 1 : 
              msg = HIR"$NͻȻüͷһ�壬�������������ˣ�\n"NOR;
              me->receive_damage("qi", 100);
              me->receive_wound("qi", 50);
              break;
      case 2 : 
              msg = HIR"$N������ͻȻ�������Σ��������������������ˣ�\n"NOR;
              me->receive_damage("neili", 250);
              break;
      case 3 : 
              msg = HIR"$NͻȻ����һ�Σ����������˰��ˣ�\n"NOR;
              me->receive_damage("jing", 50);
              me->receive_wound("jing", 30);
              break;
      case 4 : 
              msg = HIR"$N���»�㱣������ܼ��У��������������ˣ�\n"NOR;
              me->receive_damage("jingli", 150);
              break;
      }
      message_vision(msg, me);      
      if((int)me->query_temp("qishang")>0 && random(3)){
          k = (int)me->query("qi")*100/(int)me->query("max_qi");
          message_vision(HIW"$NͻȻȫ��һ������Ѫɫ����Ȼ�����ڵ�"+chinese_number((int)me->query_temp("qishang"))+"�������ھ����������ۡ���һ�����³���һ����Ѫ��\n"NOR,me);
          me->receive_wound("qi", (int)me->query_con()*10*(int)me->query_temp("qishang"));
          message_vision("( $N"+(random(2)?status_msg(k):eff_status_msg(k))+" )\n", me);
      }
      me->apply_condition("qishang_poison", duration - 1);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
