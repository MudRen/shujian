// Room: /d/changle/xiaowu.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "С��");
	set("long", @long
���ǰ�������ƶ�Ǯ�ĵ�С�ݣ����еķ����ϱ����Ǽ�����������һ�ԣ�
�������¡����Ⱥ�������һ�Ŷ�����������������ߺ������ض�Ǯ���������
ҡҷ���ƺ�û����ע���������
long
	);

	set("exits", ([
		"north" : __DIR__"zoulang1",
	]));

	set("objects", ([
		__DIR__"npc/bangzhong" : 1,
	]));

	setup();
}
