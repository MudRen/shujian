#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�뷿");
        set("long", @LONG
������С��Ĺ뷿��һ���������������һ����齷���ǽ�ǣ�����ϸɴ��
��С��������һ��ջ��ڳ�˼������������԰��
LONG
        );

        set("exits", ([
                "south" : __DIR__"houyuan",
                "west" : __DIR__"huayuan",
        ]));

        set("objects", ([
                __DIR__"npc/shuanghua" : 1,
        ]));
        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("no_quest") && dir == "west")
		return 0;
	return ::valid_leave(me, dir);
}
