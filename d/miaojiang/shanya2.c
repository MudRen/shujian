// /u/dubei/�置

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�������嶾���Աߵ�һ��С�յأ�һ����Χǽ��һ���Ƕ��͵�ʯ�ڡ�ʯ��
�ǳ��⻪�������Ӻ�������ȥ��
LONG
        );
        set("exits", ([
		"west" : __DIR__"wddamen",
	]));

        set("outdoors", "�置");

        setup();
}

void init()
{
        add_action("do_pa", ({ "climb", "pa" }));
} 

int do_pa(string arg)
{
	object me;
	object *inv;

	me = this_player(); 
	if ( arg != "shanya" && arg != "shibi") return 0;
	if ( !arg ) return 0;

	if (!living(me)) return 0;

	inv = filter_array(deep_inventory(me), (: userp :));
	if (sizeof(inv)) {
		message_vision("$N���ϱ����ˣ���������ȥ��\n", me);
		me->unconcious();
		return 1;
	} 
	if( (int)me->query_skill("dodge",1) < 100 ) { 
		message_vision(HIR"$N��Ҫ����ɽ���������Ṧ������ˤ��������\n"NOR, me);
		me->unconcious();
		return 1;     
	}
	message_vision("$N΢΢����������Խ����ȥ��\n", me);
	me->move(__DIR__"gmcong1");
	tell_room(environment(me), me->name() + "����������������\n", ({ me }));
	return 1;
}
