// Room: /d/meizhuang/road4.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
����ׯ�ڵ�һ��Ժ�ӣ����������������ʯ��Ժ����������÷��������
��ׯ�ڵķ�����һ��ߴ�����ӡ�������ׯ�š�
LONG
	);
	set("outdoors","÷ׯ");

	set("exits", ([
		"south" : __DIR__"hall",
		"north" : __DIR__"entrance",
	]));
	setup();
}

