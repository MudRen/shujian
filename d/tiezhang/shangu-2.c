// Room: /u/zqb/tiezhang/shangu-2.c

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
"northeast" : __DIR__"juebi-1",
"southwest" : __DIR__"shangu-1",
]));

	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x",-310);
  set("coor/y",-180);
   set("coor/z",30);
   setup();
}
