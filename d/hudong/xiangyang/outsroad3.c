// /d/xiangyang/outsroad3.c

inherit ROOM;

void create()
{
	set("short", "�����·");
	set("long", @LONG
�����ڶ��潻�����·�ϣ�ż��������������ҴҶ��������Ͼ��Ǻ��Ͼ�
���ˣ�����ͨ�������Ƿ���
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"south" : __DIR__"hunanroad1",
		"north" : __DIR__"outsroad2",
		"westup" : __DIR__"conglin1",
	]));
	setup();
}
