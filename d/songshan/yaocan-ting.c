// Room: /yaocan-ting.c
// Created by Numa 1999-11-21
// Modify by Lklv 2001.10.19

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"ң��ͤ"NOR);
	set("long", @LONG
����һ����ɫ�����̨ͤ������ש�����̹����ɣ�ͤ�Ϻ���һ�ң���д��
��ң��ͤ������������֡��򱱱���ȥ��ԶԶ�ܿ���������һ��������ߵĴ�
��ò�׳�ۡ�
LONG);
	set("exits", ([
            "north" : __DIR__"tianzhong-ge",
            "south" : __DIR__"shidao1",
        ]));
	set("objects", ([
		CLASS_D("songshan") + "/bu" : 1,
	]));
	set("outdoors", "��ɽ");
	setup();
}
