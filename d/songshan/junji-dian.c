// Room: junji-dian.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"������"NOR);
	set("long", @LONG
��������ǽ���ߣ���̻Իͣ�����ɽ�ɵ�������������
������ɽ�ʰݴ��ڴ˵Ⱥ����������ټ����ɴ˿ɼ�����������һͳ��
�ֵ�Ұ�ġ�
LONG);
	set("exits", ([ 
            "northup" : __DIR__"shidao3",
            "south" : __DIR__"junji-fang",
            "east" : __DIR__"suishilu3",
            "west" : __DIR__"suishilu4",
        ]));
       	set("objects", ([ 
            CLASS_D("songshan") + "/zhong" : 1,
            __DIR__"npc/ssdizi" : 2,
        ]));
    set("indoors", "��ɽ");
	set("coor/x",40);
  set("coor/y",340);
   set("coor/z",120);
   setup();
}
