// Room: shanfang.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"�ŷ�"NOR);
	set("long", @LONG
����ʯ·�����������ŷ����������������Ʈ�������淹������
���������ǧ��ͬʱ���ţ��Ӷ������ڷ���һ���ŵĲ����ͳ��ʡ���
����ʦ���ڽ��ŵ�æµ�ţ�Ҳ�в��ٵ���ɽ���������������Ӹɻ
LONG);
	set("exits", ([ 
            "west" : __DIR__"suishilu1",
        ]));
    set("objects", ([ 
            __DIR__"npc/chuzi" : 1,
    ]));
    set("no_fight_room",1);
    set("no_steal_room",1);
    set("indoors", "��ɽ");
	set("coor/x",60);
  set("coor/y",310);
   set("coor/z",110);
   setup();
}
