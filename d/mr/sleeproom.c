// /d/mr/sleeproom.c
// by leontt 11/10/2000

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIY"��Ϣ��"NOR);
	set ("long",@long
����һ����Ϣ��, ��������, ֻ�м��Ŵ�, һ��������һ�����ӡ�
long);

	set("no_fight", 1);
	set("sleep_room", 1);
	set("exits",([
             "west" : __DIR__"didao1",

	]));
	setup();
}
