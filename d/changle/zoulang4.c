// Room: /d/changle/zoulang.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"����"NOR);
	set("long", @long
�����������������������ڱ����ܶ����լ�ˡ������������̾���ζ��
�����Ե����ǰ��ࡣһЩ�ճ������İ��ھ����ע����ÿ���ˡ�
long
	);

	set("exits", ([
		"south" : __DIR__"dating",
		"north" : __DIR__"xiaoting",
		"east" : __DIR__"zoulang1",
		"west" : __DIR__"zoulang3",
	]));

	set("objects", ([
		__DIR__"npc/bangzhong" : 2,
	]));

	set("outdoors", "���ְ�");
	setup();
}
       