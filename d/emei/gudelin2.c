// Room: /d/emei/gudelin.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "�ŵ���" NOR);
	set("long", @LONG
����һƬ���ܵ��ľ�֣�������ͦ���Σ�֦Ҷ����������������ӵ�𣬾�
˵��������֮�࣬Ҫ�ǲ���Ϥ���κ�������·��
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([
 	 "east" : __FILE__,
	 "west" : __FILE__,
	 "south" : __DIR__"gudelin3",
	 "north" : __FILE__,
]));
	set("no_clean_up", 0);

	setup();
}
