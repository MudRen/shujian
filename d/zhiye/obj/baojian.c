// baojian.c ���Ʊ���
// by augx@sj  9/11/2001

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIY"���Ʊ���"NOR, ({ "dingzhi baojian","baojian","sword","jian" }));
	set_weight(9000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ɿ��˶��Ƶľ��ֽ�����Ҫ����(song)���ͻ���\n");
		set("value", 1500);
		set("no_give", 1);
		set("no_get", 1);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(25);
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
	
	if(!arg) return notify_fail("��Ҫ�ѱ����͸�˭��\n");
	if(!(int)me->query("worker/job2"))
		return notify_fail("��Ҫ�ѱ����͸�˭��\n");			
	if( !objectp(room = environment(environment(this_object())) ))
		return notify_fail("��Ҫ�ѱ����͸�˭��\n");
	if( !objectp(target = present(arg, room)) )
		return notify_fail("��Ҫ�ѱ����͸�˭��\n");
	if( me->query("worker/job2_target")!=target->query("name") )
		return notify_fail("�ⲻ����Ҫ�ͻ��Ķ���\n");
	if( me->query("worker/job2_room")!=base_name(room) )
		return notify_fail("�ⲻ����Ҫ�ͻ��Ķ���\n");
	if((int)me->query("worker/job2_far")>0) {
		if( target->query("player")!=me->query("id") )
			return notify_fail("�ⲻ����Ҫ�ͻ��Ķ���\n");
	}
	
	message_vision(HIY"$N�Ѹոմ���õĶ��Ʊ����͸�$n��\n"NOR, me,target);
	
	me->set("worker/job2_finish",1);
	if((int)me->query("worker/job2_far")>0) target->finish();
	call_out("destroying", 1, this_object());	
	return 1;
}