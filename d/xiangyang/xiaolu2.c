// /d/xiangyang/xiaolu2.c
// Lklv Modify 2001.9.22

inherit ROOM;
void create()
{
	set("short", "С·");
	set("long", @LONG
�������˶��������С·�ϣ�ż��������������ҴҶ������������ĳ�
����������ͨ�������ǣ�����������Ĵ��Ĵ����
LONG
	);
        set("outdoors", "����");
        set("xyjob", 1);
	set("exits", ([
		"northeast" : __DIR__"xiaolu1",
		"west" : "/d/group/entry/cderoad4",
	]));

	setup();
}
