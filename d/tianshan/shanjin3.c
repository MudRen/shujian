// Room: /d/tianshan/shanjin3.c
// By Linux

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ��ʯŪ��Ҳ�Ƶ�խ����Խ��Խ�ߣ��������֣���Լ�ɼ���������
���ʵ�ʯ�ڣ�����ֻ��һ�ߣ��㲻�ɵļӿ��˲�����
LONG);
	 set("exits", ([
                "east" : __DIR__"shanjin4",
		"west" : __DIR__"shanjin2",
        ]));       
	set("outdoors", "��ɽ");
	setup();
}

#include "shanjin.h"
