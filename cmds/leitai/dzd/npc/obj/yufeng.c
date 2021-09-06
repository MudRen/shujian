// /d/dzd/obj/yufeng.c
#include <ansi.h>
inherit ITEM;

int do_zhao(string arg);

void create()
{
	set_name("���ƿ",({"yufeng ping","ping"}));
	set_weight(500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("long","���ǵ���С��Ů�����õ����ƿ�����ľ����쳣��
��֪�����ڻ��ɲ�������(zhao)��䣿\n");
		set("value",200000);
		set("unit","��");
             set("dzd",1);

	}
	setup();
}

void init()
{
	add_action("do_zhao","zhao");
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

int do_zhao(string arg)
{
	object target;
	object me = this_player();
	
	if( environment(me)->query("no_fight"))
	 	return notify_fail("���ﲻ׼ս����\n");	 	
	//if(!arg || arg!= "yufeng")
	//	return notify_fail("������ʲô��\n");	
	if( !arg ) 
		target = offensive_target(me);
	else {
		target = present(arg, environment(me));
	}
	if(!target) return notify_fail("�����˭�ã�\n");
	if(!target->is_character()) return notify_fail("���ϸ�Ц����\n");
	//if(!target || !target->is_character() || !me->is_fighting(target))
		//return notify_fail("���ֻ�ܶ�ս���еĶ���ʹ�ã�\n");
	if(!living(target))
		return notify_fail("�������ˣ���Ͳ��ط��Ļ��ˡ�\n");	
	if(me->query_temp("dzd_quest/yufeng_used"))
		return notify_fail("����������䣡\n");
	message_vision(HIW"$N�ӻ���ȡ����ƿ������������ס���ο�ƿ����Ǳ�����������������Ĵ���ƿ�У�
������ʱ��һ�ɷҷ�������������˳�ȥ����\n"NOR,me);
	me->set_temp("dzd_quest/yufeng_used",1);
	//remove_call_out("zhao_yf1");
	call_out("zhao_yf1",2,me,target);
	//remove_call_out("yufeng_busy");
	call_out("yufeng_busy",20,me);
	return 1;
}

void zhao_yf1(object me,object target)
{
	int dmg;
	//object target;
	//object me = this_player();
	if(!me || !living(me)) return;
	if( !target ) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target)) return;
	if(!living(target)) return;
	message_vision(HIW"ͻȻ�����л�Ӱ�������ɳ�һȺ��䡣$NСָָ��������ƿ������һ�������$n��ȥ��
����ʳָ��$n���һ�㣬�ұ�һ�㣬���к�Хߺ�ȣ���ǧֻ���ת����$n��ȥ��\n"NOR,me,target);
	if(random(10) >= 3) {
		message_vision(HIW"$N�󾪣��Ӷ�����Ҫ������������\n"NOR,target);
		if(random(3)) {
			message_vision(HIW"��Ⱥͻ��Ϊ����һȺ������������һȺȴ�Ӻ�����$N�����ľ������ҵ�����
˫����裬��סȫ��,һʱ��Ͼ���С�\n"NOR,target);
			target->start_busy(5);
		} else {
			message_vision(HIW"$Nֻ��������ɫ���������ܷ�����ȥ�����������ľ�������֮����
�������΢һ��������ֻ����͵شӿ�϶�з��˽�ȥ����$N�����ϸ����һ�롣\n"NOR,target);
			target->add_condition("yufeng_poison",6);
			dmg = target->query("max_qi")/5;
			target->receive_damage("qi",dmg);
			target->receive_wound("qi",dmg);
		}
	} else {
		message_vision(HIW"$N�󾪣�æǱ���������Ӷ����佫��価��������\n"NOR,target);
		me->start_busy(1);
	}
}
	
void yufeng_busy(object me)
{
	if(!me) return;
	me->delete_temp("dzd_quest/yufeng_used");
	return;
}