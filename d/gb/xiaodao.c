// /d/gb/xiaodao.c С· for job

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "С·");
	set("long", @LONG
����һ���ּ�С·���˼��������ǳ������������ﲻʱ����Ұ�޵Ľ�����
LONG
        );
	set("outdoors", "�ƺ�");

	set("exits", ([
		"northup" : __DIR__"yading",
		"southdown" : __DIR__"liangcang1",
	]));

	setup();
}
