// Room: xiaolu1.c

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
		"southeast" : "/d/group/entry/xsxiao2",
		"northeast" : __DIR__"tianhu",
	]));
        set("outdoors", "ѩɽ");
	setup();
}
