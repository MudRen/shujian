// Room: /d/emei/jiulaodong.c ������ ���϶�

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",BLU "���϶�" NOR);
	set("long", @LONG
����Ƕ��ҵ�һ�󶴣���������ޱȣ������Ѳ⡣��һ�߽������㷢����
�в涴�����Թ�������Ī�⣬�ƺ�����޵ס����ǿ���뿪�ɡ�
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"jiudaoguai4",
		"northwest" : __DIR__"lianhuashi",
	        "enter" : __DIR__"dongkou",
		"west" : __DIR__"wanfoding",
	]));

	setup();
}

