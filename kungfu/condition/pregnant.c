// /kungfu/condition/pregnant.c
// by akuma 11:37 PM 2/19/2002

#include <ansi.h>
#include <condition.h>

int update_condition ( object me, int duration )
{
	mapping my;

        my = me->query_entire_dbase();

	if ( duration < 800 && duration >= 300 ) {
		if ( me->query_temp("pregnant") > 0 )
			me->add_temp ("pregnant", -1);
		else {
			if ( me->query("gender") == "Ů��" ) {
				message_vision ("$Nֻ��һ���ʣ��³�һЩ��ˮ��˫�պ���������\n", me);
				if ( my["pur"] > 20 )
					command ("blush");
				if ( my["pur"] < 10 )
					command ("iddle " + my["id"]);
				me->set_temp("pregnant", 5);
			}
		}
	}
	if ( duration < 300 && duration >= 50 ) {
		if ( me->query_temp("pregnant") > 0 )
			me->add_temp ("pregnant", -1);
		else {
			if ( me->query("gender") == "Ů��" ) {
				message_vision ("$N�������Լ�����¡��ĸ���������¶��һ˿���⡣\n", me);
				me->set_temp("pregnant", 5);
			}
		}
	}
	if ( duration < 50 ) {
		if ( me->query_temp("pregnant") > 0 )
			me->add_temp ("pregnant", -1);
		else {
			if ( me->query("gender") == "Ů��" ) {
				switch ( random (1) ) {
				case 0 :
					message_vision ("���ڸ���������¡��$N���ж���ò�����������\n", me);
					break;
				case 1 :
					message_vision ("ͻȻ֮�䣬$Nֻ�����еĺ�������ϰ���ȡ�\n", me);
					break;
				}
				tell_object ( me, HIY"���Ͼ�Ҫ���ˣ���ȥ�Ҹ����ɡ�\n"NOR );
				me->start_busy(1);
				me->set_temp("pregnant", 5);
			}
		}
	}
	me->apply_condition("pregnant", duration-1);
	if ( duration <= 0 ) {
		if ( me->query("gender") == "Ů��" ) {
			me->delete_temp("pregnant");
			message_vision ("$Nһ���ҽУ�¡��ĸ�����ʹ�ޱȡ������˵��ϡ�\n", me);
			tell_object ( me, HIR"��ֻ����ʹ�ޱȣ����Ӻ����Ҫ�����ˡ�\n"NOR );
			me->set_temp("last_damage_from", "�Ѳ�");
			me->die();
		}
		return 0;
	}
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}

