// Room: /d/chengdu/beidajie4.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣��
���Եúܷ�æ���������ų�ǽ������·��
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
                "east" : __DIR__"cgenlu1",
		"south" : __DIR__"beidajie3",
		"north" : __DIR__"dabeimen",
	]));

	set("coor/x",-150);
  set("coor/y",10);
   set("coor/z",0);
   set("incity",1);
	setup();
}

