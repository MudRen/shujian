// Room: /d/shaolin/shijie11.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���ֽ�����������ǰ������һ������ʯ�������ֱͨ��ǰ�����ص�ϡ
ϡ��������ż��ð�����ȴ�Եøߴ�ͦ�Σ��������֦������ո߸���չ��
��
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"shijie10",
		"north" : __DIR__"shifang",
	]));

	set("outdoors", "shaolin");
	set("coor/x",50);
  set("coor/y",180);
   set("coor/z",110);
   set("coor/x",50);
 set("coor/y",180);
   set("coor/z",110);
   setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "southdown" ) return 0;

	return ::valid_leave(me, dir);
}


