// Room: /d/city/eroad1.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
������������������ǳ����֡���ʱ����������������߷ɳ۶���������
һ·��������·��������������������֡�
LONG
	);

	set("exits", ([
		"west" : __DIR__"dongmen",
		"east" : __DIR__"eroad2",
	]));

	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
	]));

 	set("outdoors", "����");
	set("coor/x",140);
  set("coor/y",-10);
   set("coor/z",0);
   setup();
}



