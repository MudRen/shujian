// Room: suishilu4.c
// Created by Numa 1999-11-21

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
���˾��������������С��ʯ���̳ɵ�ʯ·��ֱͨ�����ߵ�����
¥�������ĵ��汻��ɨ�ĸɸɾ�����΢�紵������·���������де���
����ɳɳ���죬����ȴ��������ҳ���
LONG);
	set("exits", ([ 
            "east" : __DIR__"junji-dian",
            "west" : __DIR__"yushu-lou",
        ]));
	set("outdoors", "��ɽ");
	set("coor/x",30);
  set("coor/y",340);
   set("coor/z",120);
   setup();
}
