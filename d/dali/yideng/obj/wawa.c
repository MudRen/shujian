// By River@sj 2002.6.5

 inherit ITEM;
#include <ansi.h>

void check_time(object me, int count);

void create()
{
	set_name(HIY"������"NOR, ({ "jin wawa", "jin", "wawa", "yu"}));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��β�������ڷ������������۶��У�������䡣\n");
		set("unit", "��");
		set("value", 2000);
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_get", 1);
	}
	setup();
}

void init()
{
	check_time(this_player(), 60);
}

void dest(object ob, object me)
{
	if (!ob || ! me) return;
	message_vision("$N��$n��ע�⣬һ˲�������ˡ�\n", ob, me);
	me->delete_temp("yideng/yuren_done");
	destruct(ob);
}

void check_time(object me, int count)
{
	if (! me) return;
	if ( count-- < 1) {
		dest(this_object(), me);
		return;
	}
	else
		call_out("check_time", 1, me, count );
}
