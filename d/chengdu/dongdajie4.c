// Room: /d/chengdu/dongdajie4.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣�����Ƕ�����ͨ����⡣��
���Եúܷ�æ���������ų�ǽ������·��
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"chenggenlu5",
		"west" : __DIR__"dongdajie3",
		"east" : __DIR__"dadongmen",
	]));

	set("coor/x",-110);
  set("coor/y",-30);
   set("coor/z",0);
   setup();
}

