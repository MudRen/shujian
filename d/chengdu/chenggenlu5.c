// Room: /d/chengdu/chenggenlu5.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·�����������������ϱ��Ƕ���֡�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"chenggenlu4",
		"south" : __DIR__"dongdajie4",
	]));

	set("coor/x",-110);
  set("coor/y",-20);
   set("coor/z",0);
   setup();
}

