// Room: /d/chengdu/beidajie3.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǳɶ��ı���֡�����ͨ�򱱳��ţ��ϱ��Եúܷ�æ��
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"beidajie4",
		"south" : __DIR__"beidajie2",
	]));

	set("coor/x",-150);
  set("coor/y",0);
   set("coor/z",0);
   set("incity",1);
	setup();
}

