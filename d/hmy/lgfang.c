// /d/hmy/liangongfang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ����ķ��䣬�յ�����û���κΰ��裬�������ż�ʵ����ʯ�塣
LONG
	);
	set("exits", ([ 
	  "south" : __DIR__"changlang3",
]));

	setup();
}
