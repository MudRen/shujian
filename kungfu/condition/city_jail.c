// city_jail.c
// Modified by snowman 21/05/2000

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
      	string room;
      	
      	if ( !stringp(room = base_name(environment(me))) )
      		return 0;
      		
      	if (!duration || duration < 1){
      		if ( room != "/d/city/dalao" )
      			return 0;
      		me->move("/d/city/chmiao");
                message("vision",HIW "\nֻ�������������˵ĽŲ��������������������һ���廨���ļһ��ת���뿪�ˣ�\n\n" NOR, environment(me), me);
                tell_object(me, HIW "ֻ���Ƚ����������������ӽ��˼�����\n" NOR);
                me->set("startroom", "/d/city/chmiao");
                return 0;
        }
     
        if ( room !="/d/city/dalao" ) {           
                message_vision(HIR "\nͻȻ�����һ��Ⱥ���䣬ָ��$N���������������ӷ������ӵ��Ķ�ȥ����\n"
				"���ű����Ұ����£���ʱ��$N��û�����ȥ......\n" NOR, me);
                me->unconcious();
                message_vision("�����ǿ���������ȥ��$N�����Ҵҵ����ˡ�\n", me);
                me->set("eff_qi", 1);
                me->set("qi", 1);
                me->apply_condition("city_jail", me->query_condition("city_dail") + 10 +(random(20)) );
                me->move("/d/city/dalao");
                message("vision", HIW "ֻ�������������ж��������˵ĽŲ��������������������\n"
                        "�㶨��һ����ԭ����һ���廨���ļһ�������ⱻ���˽�����\n" NOR, environment(me), me);
        }
        me->apply_condition("city_jail", duration - 1);
        return 1;
}

string query_type(object me)
{
        return "jail";
}


