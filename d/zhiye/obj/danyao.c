// danyao.c 
// by augx@sj  3/4/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"��ҩ"NOR, ({ "dan yao","danyao" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ҩ�����ƹ����Ƶĵ�ҩ��Ҳ��֪�кι�Ч����Ҫ����(song)���ͻ���\n");
		set("value", 1500);
		set("no_give", 1);
		set("no_get", 1);
	}
	setup();
}

void init()
{
	add_action("do_give","song");
}

void destroying(object obj)
{     
	if (!obj) return;
	destruct(obj);
}

int do_give(string arg)
{
	object me = this_player() , room , target;
	
	if(!arg) return notify_fail("��Ҫ�ѵ�ҩ�͸�˭��\n");
	if(!(int)me->query("worker/djob"))
		return notify_fail("��Ҫ�ѵ�ҩ�͸�˭��\n");			
	if( !objectp(room = environment(environment(this_object())) ))
		return notify_fail("��Ҫ�ѵ�ҩ�͸�˭��\n");
	if( !objectp(target = present(arg, room)) )
		return notify_fail("��Ҫ�ѵ�ҩ�͸�˭��\n");
	if( me->query("worker/djob_target")!=target->query("name") )
		return notify_fail("�ⲻ����Ҫ�ͻ��Ķ���\n");
	if( me->query("worker/djob_room")!=base_name(room) )
		return notify_fail("�ⲻ����Ҫ�ͻ��Ķ���\n");
	if((int)me->query("worker/djob_far")>0) {
		if( target->query("player")!=me->query("id") )
			return notify_fail("�ⲻ����Ҫ�ͻ��Ķ���\n");
	}
	
	message_vision(HIY"$N��ҩ���ƹ����Ƶĵ�ҩ�͸�$n��\n"NOR, me,target);
	
	me->set("worker/djob_finish",1);
	if((int)me->query("worker/djob_far")>0) target->finish();
	call_out("destroying", 1, this_object());	
	return 1;
}