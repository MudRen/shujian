#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string* ra = ({
 	"$N���һ����һ��ץס$n���ݺݵ����˹�ȥ��\n", 
	"$N����һ������$n˵�����ң��ң����ܲ�������\n", 
	"$N����ͨ�죬���Ŵ�����ֱ�����Ķ���$n��\n", 
	"$N��ס�������������Ȱ������Ȱ���˵���ڼ�����ץ������Ѫ�ۣ�\n", 
	"$N��߯�����ض���$n��һ���߹�ȥ������䣬һ�������ҽУ��ҵ�����С������Ӵ��\n", 
	"$N����һ��������С��ð�ϣ�������ȣ�����������¯��ֻ��ץס$n§�ڻ��\n", 
	"$N���С��ɺɡ��ͺߣ�������$n��Ұ�ް��Ŀ���ƺ���$n���·�һ����ȥ��\n", 
});

int update_condition(object me, int duration)
{
	object *ob;
	int i;
	string msg;

	if (me->query("gender") == "����") msg = "���������������﷢��Ұ��һ��ġ�������֮��";
		else msg = "������˿��������˼���������������ʴ�ǵ���ζ";

   	if( !living(me) ) {
      		message("vision", me->name() + "ʹ���������һ����\n", environment(me), me);
   	}
   	else {
      		tell_object(me, HIM"��ֻ������һƬ���ȣ�����������˺�������ϵ��·�������\n" NOR );
      		message_vision(HIM"$N����һƬ���죬������⣬"+msg+"��\n"NOR, me);
   	}
//      	me->receive_wound("jing", 10, "");
      	
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me || !me->visible(ob[i]) ) 
			continue;
		message_vision(CYN""+ra[random(sizeof(ra))]+""NOR, me, ob[i]);
		break;
	}

	me->apply_condition("miyao", duration - 1);
	
   	if( duration < 1 ) return 0;
   	return CND_CONTINUE;
}
