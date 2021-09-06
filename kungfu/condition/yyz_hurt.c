#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
	int i=200;
	switch(random(4))
	    {

	    case 0 :
			tell_object(me, HIY "ͻȻ������һ��,һ������������Ϯ�����ҪѨ��\n" NOR );
			message("vision", me->name() + "��ɫ����,�˹��ֿ����˵ķ�����\n",environment(me), me);
			me->add_busy(2);
			if(me->query_temp("sandie/jingshen"))
				me->add_condition("no_exert", 3);
			break;
	    case 1 :
			tell_object(me, HIY "��Ȼ��ȫ���ʹ�ޱ�,����������ǧ��֧���ȵ�������һ����\n" NOR );
			message("vision", me->name() + "���������۵�ȫ������һ�ţ������ֵ���ʹ��\n",environment(me), me);
			me->receive_damage("qi", 100);
			me->receive_wound("qi", 50);
			if(me->query_temp("sandie/jingshen"))
				me->add_condition("no_perform", 3);
			break;
	    case 2 :
                    tell_object(me, HIY "��о�����һ����ȫ��ͬ���Լ����ڵ��ھ��ڸ���������,���������Ϣ��\n" NOR );
			message("vision", me->name() + "��ɫһ��,�ƺ�������ʲô���⡣\n",environment(me), me);
			if(me->query_temp("sandie/busy"))
				i+=i;
			me->receive_damage("neili", i);
			break;
	    case 3 :
			tell_object(me, HIY "һ�ɳ����ޱȵ��ھ�ͻȻ������ֱ����ͷ������ҪѨ,����ǰһ����ѣ.\n" NOR );
			message("vision", me->name() + "����һ��,������˾��Ƶ�,���ǵ�ͨ�졣\n",environment(me), me);
			me->receive_damage("jing", 70);
			me->receive_wound("jing", 40+random(30));
			if(me->query_temp("sandie/busy"))
				me->add_condition("no_perform", 3);
			break;
	    }
	me->set_temp("last_damage_from", "���˷���");
	me->apply_condition("yyz_hurt", duration - 1);
	if( duration < 2 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
