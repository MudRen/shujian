// Room: /d/city/chemahang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�������У���Ӧ�������Լ�������ϵȣ���������ֻ��������վר
�õģ�����û���������㡣
LONG
	);

	set("exits", ([
		"west" : __DIR__"guangchangdong",
	]));

/*	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));*/

	set("coor/x",130);
  set("coor/y",-10);
   set("coor/z",0);
   set("coor/x",130);
  set("coor/y",-10);
   set("coor/z",0);
   set("coor/x",130);
  set("coor/y",-10);
   set("coor/z",0);
   set("incity",1);
	setup();
}

