// Room: /gaibang/xinglin7.c
// by pishou
// Lklv modify 2001.9.27

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֣������Ͽ������ʻ���һ�߽�������·���ʧ�˷�����
���ӻ����Ҵ�, ��ͼ���ֳ�·�����Ǻ������ܶ���һ���ġ���ֻ�۷������Է�
����ȥ��������Լ����������
LONG
	);
	set("outdoors", "����");

	set("exits", ([
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"tianjing",
		"north" : __DIR__"xinglin8",
	]));
	setup();
}
