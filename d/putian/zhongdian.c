// Room: /d/putian/zhongdian.c �е�
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"�е�"NOR);
        set("long", @LONG
�������е��е����������Ǻܴ󣬵��Ǹо�����ܿ�������������һ
����ɫ�ķ�ש����������Щ����ƽ�����ﲻ�������˽������ο�ֻ���ߵ�ǰ
����ſڣ�����һ���ǽ������ġ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"qiandian",
                "south" : __DIR__"houdian",

        ]));
        set("objects",([
		__DIR__"npc/shami" : 1,
        ]));

        setup();
}
