// Room: /u/zqb/tiezhang/shanlu-4.c

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
"southdown" : __DIR__"shanlu-3",
"northup" : __DIR__"pingtai",
]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x",-330);
  set("coor/y",-210);
   set("coor/z",20);
   setup();
}
