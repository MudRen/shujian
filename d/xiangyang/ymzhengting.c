//Room: /d/xiangyang/ymzhengting.c
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIR"����"NOR);
	set("long", @LONG
���������ŵ����������϶������������������һ������������������ϸ
��������ǽ������һ�����ң����顰����������ĸ���������Ĵ��֡�������
�����ְֳ��Ӳ��������ԣ�����ׯ�����¡�
LONG
	);
        set("xyjob", 1);
	set("exits", ([
		"south" : __DIR__"yamen",
	]));
	set("objects", ([
		__DIR__"npc/lvwende" : 1,
	]));

	set("incity",1);
	setup();
}
