// hsroad1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ݱ��Ž����һ����ʯ�����·�����������ǳ����֣���ʱ������
������ҴҶ�������������ϱ�ֱͨ�����ݳǡ���������һ������С��������
ͨ��һ��Сɽ�ԡ�������һƬ���֡�
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"north" : "/d/huanghe/caodi1",
		"south" : __DIR__"beimen",
		"northwest" : __DIR__"shangang",
	]));
        set("objects", ([
                NPC_D("poorman") : 1,
        ]));
	setup();
}
