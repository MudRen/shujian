// /d/dzd/obj/huqin.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("����",({"huqin","jian","sword"}));
	set_weight(1000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("value","10000");
		set("material","steel");
		set("long","����һ�Ѳоɵĺ���,�����Ӻ�����Щ�����ˣ���˵�ǵ���Ī���������á�
��˵ʱ�䡢�ص㲻ͬ������(playqin)��Ч��Ҳ��һ������֪���ǲ�����ģ�\n");
		set("wield_msg",HIC"��Ȼ��ǰ���һ����$N�Ӻ����г��һ��ϸϸ�ĳ�����\n"NOR);
		set("unwield_msg",HIC"$N�����������Ӻ��ٵײ����룬����û��\n"NOR);
             set("dzd",1);

	}
	init_sword(80);
	setup();
}

void init()
{
       	add_action("do_playqin","playqin");
}

object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int do_playqin(string arg)
{
	int dmg;
	object target;
	object me = this_player();
	if( !arg ) 
		target = offensive_target(me);
	else {	
		target = present(arg, environment(me));		
	}
	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(me->query_temp("dzd_quest/play_huqin"))
		return notify_fail("�������������أ�\n");		
	if( !target ) {
		message_vision(BLU"��Ȼ������ѽѽ�������˺���֮��,һ��������ҹ�ꡱ��������𣬽���Զȥ�������ĺ���������ԼԼ������\n"NOR,me);
		return 1;
	}
	//|| !me->is_fighting(target)
	if(!me->query_temp("dzd_quest/look_bei")
	 || !target	 
	 || !environment(me)->query("play_huqin") ) {
		message_vision(BLU"��Ȼ������ѽѽ�������˺���֮��,һ��������ҹ�ꡱ��������𣬽���Զȥ�������ĺ���������ԼԼ������\n"NOR,me);
	}
	else {
		message_vision(BLU"��Ȼ����д��뼸�����ĵĺ���������������������̾Ϣ�����ƿ�������������������
����ɪɪɪ����֮��������һ�ε�С��������Ҷ��$NĬ��ʯ���ϵ�ʫ�䣬�����顢�˾�ˮ�齻�ڣ�������������ࡣ\n"NOR,me);
		me->set_temp("dzd_quest/play_huqin",1);
		remove_call_out("out_play");
		call_out("out_play",15,me);
			if(!random(2)) {
				message_vision(HIW"$N������ɫ������������ߡ�$Nֻ����̨һƬ����������֪�Լ����ںδ�,���Ǻ��ֻ��������һ�ж�����ǣ�ң���������������ײ��Ĺ����\n"NOR,target);
				if(random(4)) { 
					message_vision(HIW"$N��ͷ��������Ĺ����ֻ��������ת����ǰһ�ڣ����˹�ȥ��\n"NOR,target);
					target->unconcious();
				} else {
				message_vision(HIR"$N��ͷ��������Ĺ������Ѫ������Ĺ��,�����������ѡ�\n"NOR,target);
				dmg = target->query("max_qi")/5;
				target->receive_damage("qi",dmg);
				target->receive_wound("qi",dmg);
				}
			} else 
				if(!random(3)) {
				message_vision(HIW"$N������ɫ������������ߣ����������㱣���־���ᣬ��������������\n"NOR,target);
				target->start_busy(11);
				//remove_call_out("out_qinyin");
				call_out("out_qinyin",3+random(6),target);
			}
			else {
				message_vision(HIW"$N������ɫ������������ߣ��о�����������ص��������С�\n"NOR,target);
				me->start_busy(1);	

		}
	}
	return 1;
}

void out_qinyin(object target)
{
	if( !target ) return;
	message_vision(HIW"$N�͵�һ����ͻȻ�������о��ѹ�������æ�����Ż���������С�\n"NOR,target);
	target->start_busy(-1);
	target->interrupt_me();
}

void out_play(object me)
{
	if(!me) return;
	me->delete_temp("dzd_quest/play_huqin");	
}