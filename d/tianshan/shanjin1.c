// Room: /d/tianshan/shanjin1.c
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
                "northup" : __DIR__"shanjin2",
		"southdown" : __DIR__"xcmen",
        ]));       
	set("outdoors", "��ɽ");
	setup();
}

#include "shanjin.h"
