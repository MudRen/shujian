// /d/xiangyang/hunanroad1.c

inherit ROOM;
void create()
{
	set("short", "�������");
	set("long", @LONG
����������������·�ϣ�ż��������������ҴҶ����������Ѿ��Ǻ���
�ؽ磬��������������ڡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"north" : __DIR__"outsroad3",
		"southwest" : __DIR__"hunanroad2",
	]));

	setup();
}
