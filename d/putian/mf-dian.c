// Room: /d/putian/mf-dian.c ���
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
���������������ܶ࣬�ſ���һ���ο̵�ʮ�־����Ĵ���¯����
¯ǰ����һ����ɫ�Ĺ���������������һ���ܴ�����硣�������ȥ�������
�ؾ����ˡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"xj3",
                "southup" : __DIR__"cjg",
                "east" : __DIR__"dmyuan",
        ]));

        set("objects",([
                __DIR__"npc/wuseng" : 4,
        ]));

        setup();
}
int valid_leave(object me, string dir)
{
	if (objectp(present("wu seng", environment(me))) && dir == "southup")
		return notify_fail("��ɮ�����ؾ����صأ�û���벻Ҫ�Ҵ���\n");

	return ::valid_leave(me, dir);
}