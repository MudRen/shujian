// Room: /gaibang/xinglin.c
// by pishou

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֣�һ�߽�������·���ʧ�˷��������ӻ����Ҵ�, ��ͼ
���ֳ��ֵ�·�������ϵ��ʻ������ͷ�Ѥ������ֱ�ֲ������򣬷�����ȥ����
������ʢ�����ʻ���������һ���﹡��
LONG
	);
	set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"xinglin2",
		"west" : __FILE__,
		"south" : __DIR__"tianjing",
		"north" : __FILE__,
	]));
	setup();
}
