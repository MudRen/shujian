// Room: suishilu2.c
// Created by Numa 1999-11-21

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
�����и�����������������С��ʯ���̳ɵ�ʯ·��ֱͨ�����ߵ�ҩ
���������ĵ��汻��ɨ�ĸɸɾ�����΢�紵������·���ߵ��ɰ���ɳɳ
���죬����ȴ��������ҳ���
LONG);
	set("exits", ([ 
            "east" : __DIR__"tianzhong-ge",
            "west" : __DIR__"yaofang",
        ]));
	set("outdoors", "��ɽ");
	set("coor/x",30);
  set("coor/y",310);
   set("coor/z",110);
   setup();
}
