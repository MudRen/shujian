// Room: /d/chengdu/chenggenlu4.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·���ϱ߲�Զ�����Ƕ���֡�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"northwest" : __DIR__"chenggenlu3",
		"south" : __DIR__"chenggenlu5",
	]));

	set("coor/x",-110);
  set("coor/y",-10);
   set("coor/z",0);
   setup();
}

