// Room: /gaibang/xinglin.c
// by pishou

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
		"west" : __FILE__,
		"south" : __DIR__"tianjing",
		"north" : __DIR__"xinglin5",
	]));
	setup();
}
