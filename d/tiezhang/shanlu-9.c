// Room: /u/zqb/tiezhang/shanlu-9.c

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
"southdown" : __DIR__"shanlu-8",
"northup" : __DIR__"zzfeng",
]));

	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x",-330);
  set("coor/y",-120);
   set("coor/z",70);
   setup();
}
