// Room: /d/shaolin/shulin1.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡���ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����
ɡ��������գ��������ڵ�˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�һ�Ų���ȥ
������β�������
LONG
	);

	set("exits", ([
		"east" : __DIR__"shulin"+(random(10)+2),
		"south" : __DIR__"shanlu8",
		"west" : __DIR__"shulin2",
		"north" : __DIR__"shulin"+(random(10)+2),
	]));

//      set("no_acc_drop",1);
	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"obj/fake-gold" : 1,
	]));
	set("coor/x",70);
  set("coor/y",520);
   set("coor/z",160);
   setup();
}


