// Room: /d/shaolin/shijie10.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "ʯ��");
	set("long", @LONG
�����������ƺ�������һ�����������⵽�����ø�������ֻ�ڵ�����
�°߲�����Ӱ��������Զ�����һ����������֦�����������
LONG
	);

	set("exits", ([
		"eastdown" : __DIR__"shijie9",
		"northup" : __DIR__"shijie11",
	]));

	set("outdoors", "shaolin");
	set("coor/x",50);
  set("coor/y",170);
   set("coor/z",100);
   set("coor/x",50);
 set("coor/y",170);
   set("coor/z",100);
   setup();
}



