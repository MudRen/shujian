// /d/hmy/shidao2.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
һ·�����½̽��ڰ������ܣ���������ɽ��������һ��ˮ̲֮ǰ��������
һ��ʯ��ͨ��ˮ̲��
LONG
	);
	set("outdoors", "��ľ��");
	set("exits", ([ 
          "westdown" : __DIR__"xxtan",
	  "east" : __DIR__"liangting",
	  "south" : __DIR__"shidao",
	]));

	set("objects", ([ 
		__DIR__"npc/wang" : 1,
	]));

	setup();
}
