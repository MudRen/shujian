// Room: /d/chengdu/chenggenlu2.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·�����߲�Զ�����Ǳ���֡�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"west" : __DIR__"chenggenlu1",
		"southeast" : __DIR__"chenggenlu3",
	]));

	set("coor/x",-130);
  set("coor/y",10);
   set("coor/z",0);
   setup();
}

