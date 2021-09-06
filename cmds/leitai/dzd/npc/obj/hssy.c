// /d/dzd/obj/hssy.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("��ɳ��Ӱ",({"hansha sheying","hansha"}));
	set_weight(50);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("long","������װ��һֻ�ֺУ��и��������С��,����װ����ǰ������ʱ������ȡ׼ͷ��ֻ�����Ӷ�������,����������һ����
һ��������ǿ�����ɼ������,������֪���������ο������ϸ��Ϊ���ֶ࣬һöմ�����о綾,ʵ�����µ�һ��������!
��ô�����İ�����Ҫ�����һ��(sheying)�����ٺ١�\n");
		set("value",200000);
		set("unit","ֻ");
		set("material","steel");
             set("dzd",1);

	}
	setup();
}

void init()
{
	add_action("do_an","sheying");
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

int do_an(string arg)
{
	int dmg;
	object target;
	object me = this_player();
	
	if( environment(me)->query("no_fight"))
	 	return notify_fail("���ﲻ׼ս����\n");
	if( me->is_busy()) return notify_fail("��������æ���ء�\n");			
	if( !arg ) 
		target = offensive_target(me);
	else {
		if(!objectp(target = present(arg, environment(me))))
		return notify_fail("�����˭ʹ�ú�ɳ��Ӱ��\n");	
	}
	if(!target)
		return notify_fail("�����˭ʹ�ú�ɳ��Ӱ��\n");	
	if(!target->is_character()) return notify_fail("���ϸ�Ц����\n");
	//if(!target || !target->is_character() || !me->is_fighting(target))
		//return notify_fail("��ɳ��Ӱֻ�ܶ�ս���еĶ���ʹ�ã�\n");
	
	if(!living(target))
		return notify_fail("�������ˣ��������Ҫ��\n");;
	/*
	dzd_quest/hansha/used
	dzd_quest/hansha/num	
	*/
	if(me->query_temp("dzd_quest/hansha/used"))
		return notify_fail("������ʹ�ú�ɳ��Ӱ��\n");
	message_vision(HIW"$N�����Ӷ������ˣ�����������һ����$nͻȻ����ǰ�������,һ�������$N���伤�������\n"NOR,me,target);
	me->set_temp("dzd_quest/hansha/used",1);
	me->add_temp("dzd_quest/hansha/num",1);
	remove_call_out("hansha_busy");
	call_out("hansha_busy",15,me );
	if(random(10) >= 3) {
		message_vision(HIW"�����ϸ��Ϊ���ֶ࣬$N��֮�£����������������˸����ţ�\n"NOR,target);
		dmg = target->query("eff_qi")/2;
		target->receive_damage("qi",dmg);
		target->receive_wound("qi",dmg);
		target->add_condition("snake_poison",10);	
	} else {
		message_vision(HIW"$N���һ����֪�������æ��һ�ɳ��죬Ծ��Ѱ�ɣ�ֻ����һ��ϸ΢����֮������ʮö���������ڵ��ϡ�\n"NOR,target);
		me->start_busy(1);
	}
	if(me->query_temp("dzd_quest/hansha/num")>=5)
		destruct(this_object());
	return 1;
}

	
void hansha_busy(object me)
{
	if(!me) return;
	me->delete_temp("dzd_quest/hansha/used");	
}