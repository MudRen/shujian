// /u/dubei/�置

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ľ������ǰ������Ѿ�û��·�ˡ��Ա���һ��ɽ�£����������һ��
ɽ��(shandong)�����ڴ��м���Ұ�޵ĹǺ���
LONG
        );

	set("exits", ([
		"west" : __DIR__"slu8",
		"enter" : __DIR__"shandong",
	]));
	set("item_desc", ([
		"shandong" : HIY "�����ϵģ�Ҳ��֪���ж��\n"NOR,
	]));
 
	set("outdoors", "�置");

        setup();
}

void init()
{
	add_action("do_look", "look");
	add_action("do_pa", ({ "zuan", "zuan" }));
} 

int do_look(string arg)
{
	if( !arg || arg == "" || arg !=  "guanmu") return 0;

	write("����ϸ�鿴�Ź�ľ�ԣ������ƺ��������ȥ��\n");
	this_player()->set_temp("marks/��ľ", 1);
	return 1;
}

int do_pa(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "guanmu" ) return 0;
	if ( !arg ) return 0;

	if (!me->query_temp("marks/��ľ"))
		return notify_fail("��Ҫ��ʲ�᣿\n");
 
	message_vision("$N�ο���ľ��һ�������˽�ȥ��\n", me);
	me->move(__DIR__"shangu1");
	tell_room(environment(me), me->name() + "�ӹ�ľ�������˳�����\n", ({ me }));
	me->delete_temp("marks/��ľ");
	return 1;
}
