// Room: suishilu3.c
// Created by Numa 1999-11-21

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
���˾��������������С��ʯ���̳ɵ�ʯ·��ֱͨ�����ߵ��޵�
�������ĵ��汻��ɨ�ĸɸɾ�����΢�紵������·���������де��ɰ�
��ɳɳ���죬����ȴ��������ҳ���
LONG);
	set("exits", ([ 
            "west" : __DIR__"junji-dian",
            "east" : __DIR__"qindian",
        ]));
	set("outdoors", "��ɽ");
	set("coor/x",50);
  set("coor/y",340);
   set("coor/z",120);
   setup();
}
