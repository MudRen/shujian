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
	 "south" : __FILE__,
	 "north" : __DIR__"gudelin2",
]));
	set("no_clean_up", 0);

	setup();
}
