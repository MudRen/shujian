// Room: /d/changle/yongdao.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"��"NOR);
	set("long", @long
��������ͨ��һ��ʯ�ң��Ա߱���ÿ����Զ����һյ�͵ƣ�ͷ���Ǹ߸�
�Ĺ������Ե���Щ��ɭ�ɲ�������������������أ������˵Ȳ�������ǰ����
long
	);

	set("exits", ([
		"south" : __DIR__"huayuan",
		"east" : __DIR__"shishi",
	]));

	set("objects", ([
		__DIR__"npc/bangzhong" : 1,
	]));

	set("outdoors", "���ְ�");
	setup();
}
