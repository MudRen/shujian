// Room: /d/chengdu/nandajie2.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�ϱ����ϳ���ͨ����⡣��
���Եúܷ�æ��
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"nandajie1",
                "west" : __DIR__"bank",
		"south" : __DIR__"dananmen",
	]));

	set("coor/x",-150);
  set("coor/y",-50);
   set("coor/z",0);
   set("incity",1);
	setup();
}

