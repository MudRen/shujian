#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("���϶�", ({ "caoliao dui" }) );
	set_weight(300000);
	set("unit", "��");
	set("long", "����һ���޴�Ĳ��϶ѡ�\n");
	set("value", 1000);
	set("material", "wood");
	set("no_get",1);
	set("no_drop",1);
	setup();
}

void init()
{
	add_action("do_dian", "dian");
}

int do_dian(string arg)
{
	object me, obj;

	me = this_player();

	obj = present("yuan bing",environment(me));
	if(obj)
		return notify_fail("�㻹����ɱ����ǰ�������ٵ��ɡ�\n");

	message_vision(HIR "$N��������ǰ�Ĳ��϶ѣ�ɷʱ�������ܣ�Խ��Խ����\n" NOR, me );
	me->set_temp("gb_job2_finish",me->query_temp("gb_job2_finish")+1);

	if( me->query_temp("gb_job2_finish")==5)
		write("�ã������Ѿ���ɣ����Ի�ȥ�����ˡ�\n" );

	destruct( this_object());

	return 1;
}
