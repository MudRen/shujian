// Room: /d/shaolin/shijie8.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���￴���ǰ�ɽ���ˡ���Զ��ǰ����һ��Сʯͤ����λ�ο�������ЪϢ
��ɽ·��������ʮ��ƽ̹�����ߵ�ɽ�������������˼������µ�ʫ�䡣Զ
��ɽ�ּ���͵��֣���Ŀ�δ䡣
LONG
	);

	set("exits", ([
		"northup" : __DIR__"ting",
		"eastdown" : __DIR__"shijie7",
	]));
         set("objects",([
                  CLASS_D("shaolin") + "/fangtian" : 1,
                   CLASS_D("shaolin") + "/pantian" : 1,
         ]));
	set("outdoors", "shaolin");
	set("coor/x",60);
  set("coor/y",150);
   set("coor/z",70);
   set("coor/x",60);
 set("coor/y",150);
   set("coor/z",70);
   setup();
}



