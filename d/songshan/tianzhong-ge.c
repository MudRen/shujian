// Room: /tianzhong-ge.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"���и�"NOR);
	set("long", @LONG
�˴�λ����ɽ�ɾ�����Ժ���в����������С��ɴ�����ǰ�У�����
��ɽ���ĵ��ã�����������������һ����ʯ·ֱͨ���
LONG);
	set("exits", ([ 
            "north" : __DIR__"shidao2",
            "south" : __DIR__"yaocan-ting",
            "east" : __DIR__"suishilu1",
            "west" : __DIR__"suishilu2",
        ]));
        set("objects", ([ 
            CLASS_D("songshan") + "/tang" : 1,
        ]));
    set("indoors", "��ɽ");
	set("coor/x",40);
  set("coor/y",310);
   set("coor/z",110);
   setup();
}
