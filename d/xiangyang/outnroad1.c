// /d/xiangyang/outnroad1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ����������ҴҶ�����
��������������������Ͼ��ڡ��ϱ�ͨ�������ǡ�
LONG
	);
        set("outdoors", "����");
        set("xyjob", 1);
	set("exits", ([
		"north" : __DIR__"outnroad2",
		"south" : __DIR__"xuanwumen",
	]));

	setup();
}
