// Room: /u/xdd/gumu/shulin1.c
// Modify By River 98/09
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"����"NOR);
	set("long", @LONG
��ѹѹ��һ�������֣�һ��С������ͨ�ġ�����һƬ�ž������ް����Ϣ��
�����м���������һ��ʯ��(bei)��
LONG        );

	set("exits", ([
		"east" : __DIR__"sl1",
                "west" : __DIR__"lyy",
                "south" : "d/quanzhen/shulin1",
	]));    

	set("outdoors","��Ĺ");

	set("item_desc", ([
		"bei" :HIR"\n\t\t��������������������������������������\n"+
			"\t\t����������                    ��������\n"+
			"\t\t��������    ��  Ĺ  ��  ��    ��������\n"+
			"\t\t��������                      ��������\n"+
			"\t\t��������������������������������������\n\n"NOR,
	]));
	setup();
}
