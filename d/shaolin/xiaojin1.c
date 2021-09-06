// Room: /u/dubei/shaolin/xiaolu
// Date: YZC 96/01/19

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "С��");
	set("long", @LONG
������һ���ž���С����·��һ����Ⱦ����������ݣ��м�ֻ����������
���衣����ǰ��������һ��СԺ��
LONG
	);

	set("exits", ([
		"south" : __DIR__"houyuan",
	]));

	set("outdoors", "shaolin");
	setup();
}

void init()
{
	add_action("do_jump", ({ "jump", "tiao" }));
}

int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "out" ) return 0;
	if ( !arg ) return 0;

	if( (int)me->query_skill("dodge",1) < 100 ) {
		message_vision(HIR"$N�Ṧ�������޷�����ȥ��\n"NOR, me);
		me->unconcious();
		return 1;     
	}  
	message_vision("$N����Ծ��һգ�۾���ʧ�ڴ��� ��\n", me);
	me->move(__DIR__"cjlou1");
	tell_room(environment(me), me->name() + "�Ӵ������Ծ�˹�����\n", ({ me }));
	return 1;
}
