// Room: /u/zqb/tiezhang/shangu-1.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ����խ��ɽ��֮�У�����ɽ�������ֱ������������Գ��֮����
�ص��ڼž��Ŀչ�֮�С�
LONG
	);

	set("exits", ([
"northeast" : __DIR__"shangu-2",
"southwest" : __DIR__"pingtai",
]));

	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x",-320);
  set("coor/y",-190);
   set("coor/z",30);
   setup();
}
