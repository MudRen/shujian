// Room: yaofang.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"ҩ��"NOR);
        set("long", @LONG
�Ӷ��ߵ���ʯ·һ������������ŵ�һ��ŨŨ��ҩ�㣬���˾���Ϊ
֮һ������������ˬ�����������ɽ�ɵ�ҩ������������鵤��ҩӦ
�о��У��Ա߻��м�����ɽ�������ڷ�ҩ���ˡ�
LONG);
        set("exits", ([ 
            "east" : __DIR__"suishilu2",
        ]));
	set("indoors", "��ɽ");
    set("no_fight_room", 1);
    set("no_steal_room", 1);
	set("objects", ([
        	__DIR__"npc/yaoshi" : 1,
    	]));

        set("coor/x",20);
  set("coor/y",310);
   set("coor/z",110);
   setup();
}
