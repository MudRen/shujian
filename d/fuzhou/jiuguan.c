// Room: d/fouzhou/jiuguan.c
// lklv 2001.9.7

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","�ƹ�");
        set("long", @LONG
����һ��С�ƹݣ�ֻ��һЩ�򵥵ķ�ʳ���Ӵ����ơ������Ŀ��˴�඼��
�Ǻ����ޣ����Ե�������⻹����ȥ��������ϰ����첻¶�棬���˴�˵����
һ�������Ľ�������ƽ����ֻ��һλ���������æµ�š�
LONG
        );

        set("exits", ([
                "west" : __DIR__"dongxiang",
        ]));

        set("objects", ([
                __DIR__"npc/paotang" : 1,

        ]));

	setup();
}
