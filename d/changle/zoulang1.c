// Room: /d/changle/zoulang.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"������"NOR);
	set("long", @long
����������������Щ�����治�ϴ���������֮������ʱ��������ŭ���
��С������������̾���ζ�������Ե����ǰ��࣬������һЩ����Ĳи�ʣ�ˡ�
long
	);

	set("exits", ([
		"west" : __DIR__"zoulang4",
		"east" : __DIR__"zoulang2",
		"south" : __DIR__"xiaowu",
	]));

	set("outdoors", "���ְ�");
	setup();
}
