// /d/xiangyang/outsroad1.c

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
���������������һ����ʯ�����·�����������ǳ���æ����ʱ��������
��ҴҶ������������Ͻ�����Ͼ��ڡ�����ͨ�������ǵ�������ȸ�š�
LONG
	);
        set("outdoors", "����");
        set("xyjob", 1);
	set("exits", ([
		"south" : __DIR__"outsroad2",
		"north" : __DIR__"zhuquemen",
	]));
        set("objects", ([
                NPC_D("poorman") : 1,
        ]));
	setup();
}
