// Room: /d/tianshan/shiku.c
// By Linux

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������һ��ʯ�ߣ�����ĿẮ�����ʯ�߱����ͬһ��������һ��������
���ǹ⻬�ı��棬�������ˡ�
LONG);
	 set("exits", ([
                "east" : __FILE__,
		"south" : __FILE__,
		"west" : __FILE__,
		"north" : __FILE__,
        ]));       
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "west") me->add_temp("mark/steps",-1);
	if (dir == "south") me->add_temp("mark/step",1);
	if (dir == "east") me->add_temp("mark/steps",1); 
	if (dir == "north") me->add_temp("mark/step",-1);
	if (me->query_temp("mark/steps") >= 3
	 && me->query_temp("mark/step") <= -7) {
		me->move(__DIR__"shishi");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail(YEL"���������ѵ�ָʾ��Ĭ����·������һ��ʯ��ǰ��\n"NOR);
        }
        return ::valid_leave(me, dir);
}
