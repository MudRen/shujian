#include <ansi.h>
#include <condition.h>
//modify By Ziqing Y2k
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{    
      	tell_object(me, HIC "����������а�̵����ֹ���֮����һǻ������Ҳ�᲻������\n" NOR );
      	message_vision(HIC"$NͻȻһ��־壬˲Ϣ֮��·����˼�ʮ�ꡣ\n"NOR, me);
        
        me->set_temp("last_damage_from", "�־��");
        me->receive_wound("jing", random(me->query_skill("force"))/2 );
        me->receive_damage("jingli", random(me->query_skill("force")) );
        me->add_condition("sld_shexin",-1);
      	if( duration < 1 ) 
      		return 0;
      	return CND_CONTINUE;
}

string query_type(object me)
{
        return "hurt";
}

