// Room: /d/chengdu/beidajie1.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǳɶ��ı���֡�����ͨ�򱱳��ţ��ϱ��ǳ����ġ�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"beidajie2",
		"south" : __DIR__"center",
	]));

	set("coor/x",-150);
  set("coor/y",-20);
   set("coor/z",0);
   set("incity",1);
	setup();
}

