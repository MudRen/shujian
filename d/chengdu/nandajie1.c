// Room: /d/chengdu/nandajie1.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
���ǳɶ����ϴ�֡��ϱ�ͨ���ϳ��ţ������ǳ����ġ�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"south" : __DIR__"nandajie2",
		"north" : __DIR__"center",
	]));

	set("coor/x",-150);
  set("coor/y",-40);
   set("coor/z",0);
   set("incity",1);
	setup();
}

