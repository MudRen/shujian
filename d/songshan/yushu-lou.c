// Room: yushu-lou.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"����¥"NOR);
	set("long", @LONG
������ʯ·������������������¥��ǰ��������ɽ�ɵ���ѧ�ؼ���
����鼮�Ĳؾ�֮����������ר����������ϰ�书�Ĳ�����ϱ��Ƿ�
�ñ�������ԯ�����������о������������鷿��
LONG);
	set("exits", ([ 
            "north" : __DIR__"cangshu-ge",
            "south" : __DIR__"jiange",
            "east" : __DIR__"suishilu4",
            "west" : __DIR__"shufang",
        ]));
        set("objects", ([ 
            CLASS_D("songshan") + "/deng" : 1,
        ]));
	set("outdoors", "��ɽ");
	set("coor/x",20);
  set("coor/y",340);
   set("coor/z",120);
   setup();
}
