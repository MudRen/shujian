#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIW"����Ժ"NOR);
	set("long", @LONG
�������һ��С��ľ�ݣ�ľ�����Ϲ���һ�����ң��ϱ�д�š�����Ժ����
�����һ�����벻����������������������Ժ��Ȼ�������С�ݡ�
LONG);
	set("indoors", "������");
	set("exits", ([             
		"out" : __DIR__"songlin-1",
	]));
	set("cant_hubiao", 1);
	set("objects",([
		__DIR__"npc/kurong" : 1,
	]));

	setup();
}
