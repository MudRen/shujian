// /d/dzd/obj/yuwang.c

#include <ansi.h>

inherit ITEM;

int do_sa(string arg);

void create()
{
	set_name("����",({"yuwang"}));
	set_weight(50);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("long",HIW"����һ���Լ�ϸ˿�߽�ɵ���١�˿��ϸ��ͷ�����ʵ�͸���������쳣�����Ｔ����
��֪��ս����ʱ���ܲ�����(sa)�����أ�\n"NOR);
		set("value",200000);
		set("unit","��");
		set("material","silk");
             set("dzd",1);

	}
	setup();		
}
void init()
{
	add_action("do_sa","sa");
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

int do_sa(string arg)
{
	object target;
	object me = this_player();
	
	if( environment(me)->query("no_fight"))
	 	return notify_fail("���ﲻ׼ս����\n");
	 
	if( !arg ) 
		target = offensive_target(me);
	else {
		target = present(arg, environment(me));
	}
	if(!target)
		return notify_fail("�����˭ʹ��������\n");
		
	if(!target->is_character()) return notify_fail("���ϸ�Ц����\n");
	
	//if(!target || !target->is_character() || !me->is_fighting(target))
		//return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�ã�\n");
	if(!living(target))
		return notify_fail("�����ܶ����ˣ�\n");
	if(target->is_busy())
		return notify_fail("���������Թ˲�Ͼ����ŵ������ɣ�\n");
	if(me->query_temp("dzd_quest/yuwang_used"))
		return notify_fail("������ʹ��������\n");
	message_vision(HIW"$N����ͻȻ���˼����£�����һ��͸���Ĳ��⣬�������ޣ���֪��ʲô����,��$n��ͷ��ȥ��\n"NOR,me,target);
	me->set_temp("dzd_quest/yuwang_used",1);
	call_out("yuwang_busy",15,me);
	if(random(10) >= 4) {
		message_vision(HIW"$NͻȻ�����һ�����˵ص��ˣ��������ӱ�����һ�š�\n"NOR,target);
		if(random(3)) {
			message_vision(HIW"$Næ������������һʱ��Ͼ���У�\n"NOR,target);
			target->start_busy(9);
			//remove_call_out("out_yuwang");
			call_out("out_yuwang",3+random(3),target);
		} else {
			message_vision(HIW"$N������У�Խ����������ٲ���Խ����Ƭ��֮�䣬�ͳ�Ϊһֻ�����Ӱ㣬���������Զ�����\n"NOR,target);
			target->start_busy(10);
		}
	} else {
		message_vision(HIW"$N���Ų�æ���������˿�ȥ��\n"NOR,target);
		me->start_busy(1);
	}
	return 1;
}

void out_yuwang(object target)
{	
	if(!target) return;
	message_vision(HIW"$Næ�˰��죬���ڽ������⿪��\n"NOR,target);
	target->start_busy(-1);
	target->interrupt_me();
	return;
}
	
int yuwang_busy(object me)
{
	if(!me) return 1;
	me->delete_temp("dzd_quest/yuwang_used");
	return 1;
}