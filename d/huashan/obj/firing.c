// ITEM: /d/huashan/obj/firing.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"����"NOR, ({"fire"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
	set("long", "��������Ȼ���еĻ��ۡ�\n");
	set("unit", "֧");
	set("value", 80);
        }
}

void init()
{
	call_out("dest",120,this_object(),this_player());
}

void dest(object ob,object me)
{
	me->delete_temp("marks/study");
	message_vision("$N��$n�Ѿ������ˣ������˼��£���Ϩ���ˡ�\n",me,ob);
	destruct(ob);
}