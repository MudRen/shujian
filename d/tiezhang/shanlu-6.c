// Room: /u/zqb/tiezhang/shanlu-6.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ����С·��
����һ����ǿ��ȥ��
LONG
	);

	set("exits", ([
"southdown" : __DIR__"pingtai",
"northup" : __DIR__"shanlu-7",
]));

	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x",-330);
  set("coor/y",-190);
   set("coor/z",40);
   setup();
}
