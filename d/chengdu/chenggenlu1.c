// Room: /d/chengdu/chenggenlu1.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·�����������ϣ������Ǳ���֡�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : __DIR__"chenggenlu2",
		"west" : __DIR__"beidajie4",
	]));

	set("coor/x",-140);
  set("coor/y",10);
   set("coor/z",0);
   setup();
}

