// by xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�㳡");
	set("long", @LONG
�㳡ռ�����󣬲����Ͻ���������ȥ�ɴ�ƺӰ�ġ�������������Χ����
Щ���ᣬ�����ھ�ס��
LONG );

	set("exits", ([
                "east"  : __DIR__"hhgate",
                "west"  : __DIR__"xyting",
	]));

	set("objects", ([
		__DIR__"npc/wu" : 1,
		__DIR__"npc/qian" : 1,
	]));

	set("outdoors", "�ƺ�");
	setup();
}
