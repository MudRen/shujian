// Room: /d/emei/gudelin.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "�ŵ���" NOR);
	set("long", @LONG
����һƬ���ܵ��ľ�֣�������ͦ���Σ�֦Ҷ����������������ӵ�𣬾�
˵��������֮�࣬Ҫ�ǲ���Ϥ���κ�������·��
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([
 	 "east" : __FILE__,
	 "west" : __FILE__,
	 "south" : __DIR__"bailongdong",
	 "north" : __DIR__"gudelin3",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
	object me;
	me = this_player();
	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("����æ���ģ�\n");

	if( arg == "zhuang" ) {
	message_vision("$N������÷��׮��\n", me); 
	me->move(__DIR__"muzhuang"); 
        message_vision("$N����������\n", me);
    return 1;
}
}
