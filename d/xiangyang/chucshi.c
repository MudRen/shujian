//Room: /d/xiangyang/chucshi.c
// Lklv 2001.9.25

inherit ROOM;
void create()
{
	set("short","������");
	set("long", @LONG
������ǰ���������һ��������������ĳ��˴����ң����������߰����
���˶������������м�ֻ���������ȥ�����׵�ǽ�Ϲ���һ����������Ϊ���
��Զ���Ѿ��޷��ֱ����������ּ���
LONG
	);
       set("xyjob", 1);
	set("exits", ([
		"north" : __DIR__"yamen",
	]));
	set("incity",1);
	setup();
}
