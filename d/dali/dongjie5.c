// Room: ������� /dali/dongjie5
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ǵ�����֣�����һЩ����������е�ס�����·��վ�ż�����
���˼ҵļҶ������ﰲ�����ˣ���������ߵ�����޲������˽Ų����Ծ���
��Ŀ���򶫿�ȥ���������ӵ������������������������
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"north" : __DIR__"dongjie4",
		"south" : __DIR__"dongjie6",
		"east" : __DIR__"wangfu/damen",
	]));

	setup();
}
