// Room: /d/chengdu/chenggenlu3.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǳɶ�������ǽ����һ��С·��С·�������߲�Զ���۶��������ڶ���
�߲�Զ���۶����ϡ�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"northwest" : __DIR__"chenggenlu2",
		"southeast" : __DIR__"chenggenlu4",
	]));

	set("coor/x",-120);
  set("coor/y",0);
   set("coor/z",0);
   setup();
}

