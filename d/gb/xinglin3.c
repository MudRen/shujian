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
		"east" : __FILE__,
		"west" : __DIR__"xinglin4",
		"south" : __DIR__"tianjing",
		"north" : __FILE__,
	]));
	setup();
}
