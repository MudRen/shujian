// by xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������һ��������Ĳݵأ�����һ����ɫ��̺�����ڵ��ϡ��ݴ��п���һ
Щ��֪����С�����к�ġ��Ƶģ������ϵġ������ϡ���Ҷ�ϵ�¶�����ž�Ө
�Ĺ⡣
LONG );
	set("exits", ([
                "south" : "/d/city/hsroad1",
		"west" : __DIR__"caodi2",
	]));

	set("outdoors", "�ƺ�");
	setup();
}
