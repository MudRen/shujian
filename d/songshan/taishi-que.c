// ROOM : taishi-que.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"̫����"NOR);
	set("long",@LONG
������ǰ��Ȼ������һ��̫���ڣ�������ɽ�ɵ������Դ��ţ�����
�����ʯ���������ɡ�����ȥ����Ѿ���Զ�����泤������̦��
LONG
	);
	set("exits", ([
            "southdown" : __DIR__"shanlu5",
            "north" : __DIR__"kuangdi",
        ]));
        set("objects", ([ 
            CLASS_D("songshan") + "/wan" : 1,
        ]));        
	set("outdoors", "��ɽ");
	set("coor/x",40);
  set("coor/y",250);
   set("coor/z",110);
   setup();
}	