// Room: /d/putian/xm-dian.c ���ֵ�
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���ֵ�");
        set("long", @LONG
���������ֵ��һ��Ҳ���������������ȴ��ǰ������С�öࡣ���з�
���������ţ������Ա��м������ӣ����м������ӣ�ǽ���м��Ż��񣬶��Ƿ�
����ʡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"houdian",
                "south" : __DIR__"jcyuan",

        ]));
        set("objects",([
		__DIR__"npc/shami" : 2,
        ]));

        setup();
}
