// Room: donglang2.c  ��������

#include <ansi.h>


inherit ROOM;

void create()
{
    set("short", "��������");
    set("long", @LONG
������һ��ľ�ƽṹ�������ϣ�������һ����ݣ��ſڹ���һ��ǣ�����
(pai)�����ģ��������䵱�ɵ���ƽʱ���ŵĳ�����
LONG
    );
        set("exits", ([
            "east" : __DIR__"chufang",
            "south":__DIR__"xiuxishi1",
            "west" : __DIR__"xiaolu1",
        ]));

        set("item_desc",([
           "pai" : HIB"\t\t\tǬ\n"NOR,
        ]));
        setup();
}


int valid_leave(object me, string dir)
{
        if ((me->query("gender") == "Ů��") && dir == "south") 
           return notify_fail("Ů���˼һ��ǲ�Ҫ����ȥ�ĺã�����Ͳ������ż��ˡ�\n");
        return ::valid_leave(me, dir);
}
