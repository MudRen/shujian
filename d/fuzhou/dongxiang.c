// Room: /d/fuzhou/dongxiang.c
// Lklv 2001.9.10
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ��ݳǳǶ���һ��С����Ƕ�����������������������߶���
��Ǯ�˼ҵ�լԺ���������˲�������������Σ������Ǻ��ٵ��������������
���������ֵĶ���֣���������������м��ҵ��̡�
LONG
	);

	set("exits", ([
                "north" : __DIR__"dongxiang2",
                "south" : __DIR__"dongjie",
                "east" : __DIR__"jiuguan",
	]));

	set("outdoors", "����");
	setup();
}
