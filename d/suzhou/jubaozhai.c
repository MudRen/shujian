#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"�۱�ի"NOR);
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ��
���е���Ʊ�����ǳ��ã�ͨ��ȫ�������������ݷֵꡣ
LONG
	);

	set("exits", ([
		"east" : __DIR__"nandajie1",
	]));

	set("objects", ([
		__DIR__"npc/laoban2" : 1,
	]));

	set("coor/x",100);
  set("coor/y",240);
   set("coor/z",0);
   set("incity",1);
	setup();
}

