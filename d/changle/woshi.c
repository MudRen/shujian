// Room: /d/changle/woshi.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC"����"NOR);
	set("long", @long
���ڳ��������ݻ�������Ĵ����������������������������ӣ����̽��档
��ǰ���ʵʹ�����Լ���������ƺ����ˡ���ǰ����¯��������������ֻ������
��һ�������磬����������ɶ�����
long
	);

	set("exits", ([
                "south" : __DIR__"xiaoting",
	]));

	set("objects", ([
		__DIR__"npc/shijian": 1,
	]));

	setup();
}
