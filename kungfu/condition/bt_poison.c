#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    	if( !living(me) ){
    		message("vision",HIW + me->name() + "������ͻȻ�鶯��һ�£�\n"NOR, environment(me), me);
    	}
    	    
      	tell_object(me, HIB "���Ȼ�е����彩ֱ���Ѿ�����ʹ���ˡ�\n" NOR );      
      	me->set_temp("last_damage_from", "���ڹ���֮������");      
      	me->receive_wound("qi", 50 + random(50));
      	if( !me->is_busy() ) me->start_busy(3);
      	if(userp(me))
           	me->receive_wound("jing", me->query_skill("force") + 40 + random(50));
      	else 	me->receive_wound("jing", me->query_skill("force") + 120);
      	
      
      	if( me->query("jing") >= 500)
              	tell_room(environment(me), YEL+me->name()+"ͻȻֻϥ�����������������£����з����������޵ĺɺ�֮����\n" NOR, ({ me }));            
      	else if( me->query("jing") < 500 && me->query("jing") >= 350)
              	tell_room(environment(me), BLU+me->name()+"��Ȼ����ѻ�������Ц�����Եù������ס�\n" NOR,  ({ me }));        
      	else if( me->query("jing") < 350 && me->query("jing") >= 150)
              	tell_room(environment(me), HIB+me->name()+"��ʱ���Ǹ��Ӻ�Ϳ��ָ���������ҡ���ҧ��\n" NOR,({ me }));           
      	else    tell_room(environment(me), HIR+me->name()+"ͻȻ����һ�ţ����ڵ��ϲ�ͣ�ط�����\n" NOR,({ me }));

      	if( duration < 1 ) return 0;           
      	me->apply_condition("bt_poison", duration - 1);
      	return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
