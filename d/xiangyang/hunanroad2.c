// /d/xiangyang/hunanroad2.c

inherit ROOM;

void create()
{
	set("short", "��Ϫ��");
	set("long", @LONG
����������������·�ϣ�ż��������������ҴҶ����������Ѿ��Ǻ���
�ؽ磬����������������ڡ��ϱ���С����Ϫ��
LONG
	);
        set("outdoors", "����");

	set("objects", ([
		__DIR__"npc/dujiao-dadao" : 1,
	]) );
	set("exits", ([
		"northeast" : __DIR__"hunanroad1",
                "southwest" : "/d/group/entry/mjshan2",
		"south" : "/d/tiezhang/lx",
	]));

	setup();
}
