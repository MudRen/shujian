// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "������Ұ");
	set("long", @LONG
�����������Ұ���ϣ����������԰��⣬�㲻����������һ���������
������Ŀ�����
LONG
	);
	set("outdoors", "����Ǳ�");
	set("exits", ([
		"west" : __DIR__"xiaodao2",
		"northeast" : "/d/dali/dadao1",
        ]));

	setup();
}
