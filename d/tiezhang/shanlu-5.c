// Room: /u/zqb/tiezhang/shanlu-5.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��ʯ���̳ɵ�С·�ϣ������Ǹߴ�Ĵ��������ڽ����ƻ�����գ�
������ˬ���ˡ���ΪСָ�������������˽϶࣬��������·Ҳ�����ĺܺá�
LONG
	);

	set("exits", ([
"westup" : __DIR__"sblu-1",
"eastdown" : __DIR__"pingtai",
]));

	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x",-340);
  set("coor/y",-200);
   set("coor/z",40);
   setup();
}
