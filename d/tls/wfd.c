// /u/cool/tls/wanfodong.c
// cool 1998.2.13

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���߳���ѩͤ����ɽ�ڱߣ���ǰһ���Ŷ���������������������
�֡���𶴡����ⶴ�������º����Ѱ���˵ȿ�����Ҳ�Ҳ������
LONG);
	set("exits", ([
	      "up" : __DIR__"wxt",
              "enter" : __DIR__"wfd2",	
        ]));
	set("coor/x",-390);
  set("coor/y",-250);
   set("coor/z",30);
   setup();
}

