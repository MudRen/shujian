//guigushu.c created by campsun 2003.12.4
//LinuX@SJ 2004.2.28


#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int sNow;
	int sLeftTime;
	int sStartTime;
	int this_week = time()/86400/7;
	int user_time;
	//int an_hour = 60*60;
	
	if(!me->query("ggs/started")) return 0;
	
	if(me->query("registered")!=3)
	{
		tell_object(me, HIG"\n���ͻȻ���˼������ף�ԭ����Ĺ��ʱ�䵽���ˣ���Ĺ�������Զ���ֹ����\n"NOR);	
		
		if (me->query("ggs/left_time") < 0 ) //��ֹbug
			me->set("ggs/left_time",0);
			
		me->set_temp("ggs/started",0);//��Ҫdelete������������¼�����������2��10��Сʱ�ˡ�
		me->set("ggs/started",0);
		me->set("ggs/start_time","");
		me->set("ggs/over_time","");
					
		me->clear_condition("guigushu"); //�����	
			
		return 0;
	}	
	
	if(me->query("ggs/started") && !me->query_temp("ggs/started"))
	{
		tell_object(me, YEL"\n��о������ù��������������п��ƣ�ԭ�������ϴ�����ǰû�н����������״̬��\n"NOR);
		tell_object(me, YEL"���������񹦰����������Ľ���ʱ��������ϴ�����ʱ�䡣\n"NOR);
		me->set("ggs/over_time",FINGER_D->get_last_on(me->query("id")));
		user_time=(int)me->query("ggs/over_time")-(int)me->query("ggs/start_time");
		me->set("ggs/left_time",me->query("ggs/left_time") - user_time);
		
		if (me->query("ggs/left_time") < 0 ) //��ֹbug
			me->set("ggs/left_time",0);
			
		if (me->query("ggs/left_time")) 
			tell_object(me, YEL"�㱾�ܻ�����ʹ�ù������"+CHINESE_D->chinese_time(me->query("ggs/left_time"))+"��\n"NOR);
		else
			tell_object(me, YEL"�㱾�ܵĹ������ʱ�������ˡ�\n"NOR);
		
		me->set_temp("ggs/started",0);
		me->set("ggs/started",0);
		me->set("ggs/start_time","");
		me->set("ggs/over_time","");	
		
		me->clear_condition("guigushu"); //�����
		
		
		return 0;
	}
	
	sNow = time();
	
	sStartTime =(int) me->query("ggs/start_time");
	
	
	if ( (sNow - sStartTime) == 3600 )
	{
		tell_object(me, HIG"ʱ����ĺܿ죬��֪���������ù�������Ѿ�һ��Сʱ��ȥ�ˡ�\n"NOR);
		//me->add("ggs/left_hours",-1);
		return 0;
	
	}
	
	if (me->query("ggs/left_time") < 0 ) //��ֹbug
			me->set("ggs/left_time",0);
		
	sLeftTime =(int) me->query("ggs/left_time");
			
	if (sLeftTime < (sNow - sStartTime))
	{
		tell_object(me, HIR"���������˵�һ�£��о�����ƣ��֮������������������޷���֧�Ź������״̬�ˡ�\n"NOR);
		message_vision(BLU"$Nһ��ͷ��Ŀѣ���޷���ʹ�ù��������ǿѧϰ�����ˣ�\n"NOR, me);
		log_file( "quest/ggs",sprintf("%s(%s)�ڵ�%d��û��ѯ��over�Զ�����.\n",
			me->name(),
			me->query("id"),
			this_week
			));
		
		me->set_temp("ggs/started",0);
		me->set("ggs/started",0);
		me->set("ggs/start_time","");
		me->set("ggs/over_time","");
		me->set("ggs/left_time",0);
		
		me->clear_condition("guigushu"); //�����˾����
		return 0;
	}
	
	if (this_week > me->query("ggs/last_week"))
	{
		me->set("ggs/left_time",me->query("ggs/left_time") - sNow + sStartTime);
		tell_object(me, HIR"\n���������˵�һ�£��о�����ƣ��֮������������������޷���֧�Ź������״̬�ˡ�\n"NOR);
		tell_object(me, HIR"��Ϊ�Լ��˷��˹������ʱ����ûڲ��ѣ������˷���"+	CHINESE_D->chinese_time(me->query("ggs/left_time"))+"��\n"NOR);
		message_vision(BLU"$Nһ��ͷ��Ŀѣ���޷���ʹ�ù��������ǿѧϰ�����ˣ�\n"NOR, me);
		
		log_file( "quest/ggs",sprintf("%s(%s)�ڵ�%d���Զ�����,�˷�:%s\n",
			me->name(),
			me->query("id"),
			this_week,
			CHINESE_D->chinese_time(me->query("ggs/left_time"))
			));
		
		me->set_temp("ggs/started",0);
		me->set("ggs/started",0);
		me->set("ggs/start_time","");
		me->set("ggs/over_time","");
		me->set("ggs/left_time",0);
		
		me->clear_condition("guigushu"); //�����˾����
		return 0;
	}
	
	if(random(10)==1)
	{
		tell_room(environment(me), me->name() + "��������Ŀ���ʣ���˼���ݡ�\n", ({ me }));
		tell_object(me, HIG"�ڹ�������������£���о����֮��û���㲻�������¡�\n"NOR);
	}
    	return CND_CONTINUE;
}

string query_type(object me)
{
        return "guigushu";
}