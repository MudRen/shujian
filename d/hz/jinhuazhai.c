// /u/beyond/hz/jinhuazhai.c
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"��ի"NOR);
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ��
���е���Ʊ�����ǳ��ã�ͨ��ȫ����
LONG
	);

	set("exits", ([
		"east" : __DIR__"qsddao4",
	]));

	set("objects", ([
		__DIR__"npc/qzlaoban" : 1,
	]));

	set("coor/x",90);
  set("coor/y",-340);
   set("coor/z",0);
   setup();
}

