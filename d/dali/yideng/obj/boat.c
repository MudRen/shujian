// By River@sj 2002.6.5

 inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIB"����"NOR, ({ "tie zhou", "zhou", "boat"}));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�Һ������С����\n");
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
	if (environment() == this_player())
		add_action("do_pao", ({"pao", "zhi" }));
}

int do_pao(string arg)
{
	object room, me = this_player();

	if (!id(arg)) return 0;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if (! objectp(present("tie jiang", me)))
		return notify_fail("��������أ�\n");

	if ( !environment(me)->query("yideng_boat"))
		return notify_fail("�������������۰���\n");

	if(!( room = find_object("/d/dali/yideng/boat")))
		room = load_object("/d/dali/yideng/boat");

	if ( room->query("ppl"))
		return notify_fail("�ٲ���ˮ�������ļ��������Ѿ����������ں����ˣ��㻹���ȵȻ�ɡ�\n");

	message_vision(HIW"\n$Nת��ɽ�ǣ���һ�������𣡡����������ٲ������Σ�����һ��������������\n"+
		"Ю����Ҹ֮�£�ֻ��������˳��ˮ���嵽��ǰ��ӿ��ǰԾ���������С�\n\n"NOR, me);
	me->delete_temp("yideng");
	me->move(room);
	room->set("ppl", me->name(1));
	call_out("dest", 1, this_object());
	return 1;
}

void dest(object ob)
{
	if ( ! ob) return;
	destruct(ob);
}
