// Room: xiaolu3.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������ߵ�һ��С·����ǰ��������ͷ����֪��ͨ�����·��Ұ���ҷ���
�������裬�������Լ��ĽŲ�����������ֻ����һ����һ���͵�������
LONG
	);

	set("exits", ([
		"north" : __DIR__"hubian",
		"west" : "/d/group/entry/xsxiao2",
		"east" : __DIR__"fozhaomen",
	]));
        set("outdoors", "ѩɽ");
	setup();
}
