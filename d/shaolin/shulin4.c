// Room: /d/shaolin/shulin4.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "������");
	set("long", @LONG
����ǰ��Ȼһ�ڣ������У�ֻ������ǰ�󣬵�����������ǵص�������
����ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�����
���ڵ�˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�һ�Ų���ȥ������β���������
�ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
	);

	set("exits", ([
		"east" : __DIR__"shulin5",
		"south" : __DIR__"shulin"+(random(10)+2),
		"west" : __DIR__"shulin"+(random(10)+2),
		"north" : __DIR__"shulin3",
	]));

	set("outdoors", "shaolin");
	set("coor/x",80);
  set("coor/y",540);
   set("coor/z",160);
   setup();
}



