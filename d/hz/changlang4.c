// changlang4.c ����

inherit ROOM;
void create()
{
	set("short","����");
	set("long", @LONG
���߽����ȣ�������������ȫ��һ�������ʲʻ�������������ԡ�ÿ
һ�������������������㶼�����ˣ���ԭ����·���Ҳ����ˡ�
LONG
	);
	set("exits", ([
		"south" : __FILE__,
		"east" : __FILE__,
		"north" : __FILE__,
		"west" : __DIR__"huanglong",

	]));
	setup();
}
