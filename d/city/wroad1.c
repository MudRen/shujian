// /d/city/wroad1.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ����������ҴҶ�����
����������밲�վ��ڡ�����ͨ�����ݳǡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"ximen",
                "west" : __DIR__"wroad2",
                "northwest" : __DIR__"winmo",
	]));
   	setup();
}
