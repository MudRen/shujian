// Room: /d/huashan/laojun.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "�Ͼ���");
	set("long", @LONG
��������Ҫ�������£����Ѿ�ʮ��ƣ�룬������������ЪϢ���Ͼ�����һ
������೤��ɽ�����ഫΪ̫���Ͼ������������Ͼ�����
LONG
	);
	set("exits", ([
		"westdown" : __DIR__"baichi",
		"southup" : __DIR__"husun",
	]));

	set("objects", ([ 
		__DIR__"npc/monkey" : 1,
	]));

	set("no_clean_up", 0);
	set("outdoors", "��ɽ" );

	set("coor/x",70);
  set("coor/y",70);
   set("coor/z",40);
   setup();
}
