// Room: /gaibang/xinglin.c
// by pishou
// Lklv modify 2001.9.27

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֣�һ�߽�������·���ʧ�˷��������ӻ����Ҵ�, ��ͼ
���ֳ��ֵ�·�������ϵ��ʻ������ͷ�Ѥ������ֱ�ֲ������򣬷�����ȥ����
������ʢ�����ʻ���
LONG
	);
	set("outdoors", "����");

	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"xinglin7",
		"south" : __DIR__"tianjing",
		"north" : __FILE__,
	]));
	set("objects", ([
                CLASS_D("gaibang/qnqigai") : 1,
	]));

	setup();
}
