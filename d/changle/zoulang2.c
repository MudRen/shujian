// Room: /d/changle/zoulang.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"������"NOR);
	set("long", @long
����������������Щ�������Ǹ������������������̾���ζ�������Ե���
�ǰ��࣬������һЩ����Ĳи�ʣ�ˡ�
long
	);

	set("exits", ([
		"west" : __DIR__"zoulang1",
		"south" : __DIR__"chufang",
	]));

	set("outdoors", "���ְ�");
	setup();
}
