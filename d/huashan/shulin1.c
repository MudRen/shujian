// Room: /d/huashan/shulin1.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡���ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ
��������գ��������ڵ�˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�һ�Ų���ȥ����
��β�������
LONG);

	set("exits", ([
		"east" : __FILE__,
		"south" : __DIR__"kongdi",
		"west" : __FILE__,
		"north" : __DIR__"shulin2",
	]));

	set("outdoors", "��ɽ");

	set("coor/x",40);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}


