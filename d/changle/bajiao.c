// Room: /d/changle/bajiao.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR"�˽�ͤ"NOR);
	set("long", @long
���ǻ�԰��һ��С�ɵ�ͤ�ӣ����ͻ�ʱ��Ϣ֮�á�ͤ��ʯ��ʯ�ʾ�ȫ��ʯ
���ϻ��ڷ��ż��̵��ġ�Ժ�л��ܰ��㸡����������ɽ�������Ǳ��¡�
long
	);

	set("exits", ([
		"west" : __DIR__"huayuan",
	]));

	set("objects", ([
		__DIR__"npc/ding": 1,
	]));

	set("outdoors", "���ְ�");
	setup();
}
