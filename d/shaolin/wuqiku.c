// Room: /d/shaolin/wuqiku.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "������");
	set("long", @LONG
�����µ�������ɳ����µ�һ��ʮ�˰�����������νӦ�о��С�����
һ��������ٸ��ۻ����ҡ�ǽ������һ����С���ӣ�ÿ���������˸��ָ���
�ı�����ǽ��һ����׳��ɮ����ƹƹ���ҵ��ڴ���һ�����ȡ���һλ����ɮ
������ǽ�Ƿ���һ�ѽ䵶���������������������������ӭ�˹�����
LONG
	);

	set("exits", ([
//		"west" : __DIR__"zhulin2",
		"south" : __DIR__"lshuyuan",
	]));

//	create_door("west","ľ��","east",DOOR_CLOSED);
	set("objects",([
		CLASS_D("shaolin") + "/dao-chen" : 1,
//		__DIR__"npc/datie-seng" : 1,
		__DIR__"obj/zhujian" : 1,
		__DIR__"obj/mudao" : 1,
	]));
	set("coor/x",20);
  set("coor/y",330);
   set("coor/z",120);
   setup();
}



