#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIM"ӣ��԰"NOR);
set("long",@long
����һƬӣ��԰�����Ͽ�����ӣ�һ���
long);
set("exits",([
"northwest" : __DIR__"midao2",
"east" : __DIR__"ytyuan1",
]));
	setup();
}
