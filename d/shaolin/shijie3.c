// Room: /d/shaolin/shijie3.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ʯ���������ƺ���ÿ�����Щ�����µ�ɽ��������������˾����Ϊһ
ˬ��Զ����������ˮ�������н�Զ��ɽ���Ϲ����˺��ܵ����ܣ��������ҡ
߮��
LONG
	);

	set("exits", ([
		"eastdown" : __DIR__"shijie2",
		"northup" : __DIR__"shijie4",
	]));

//	set("objects",([
//		__DIR__"npc/xiao-hai" : 1,
//	]));

	set("outdoors", "shaolin");
	set("coor/x",80);
  set("coor/y",120);
   set("coor/z",20);
   set("coor/x",80);
 set("coor/y",120);
   set("coor/z",20);
   setup();
}



