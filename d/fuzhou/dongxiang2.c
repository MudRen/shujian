// Room: /d/fuzhou/dongxiang2.c
// Lklv 2001.9.10
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ��ݳǳǶ���һ��С����Ƕ�����������������������߶���
��Ǯ�˼ҵ�լԺ���������˲�������������Σ������Ǻ��ٵ������������Ӷ�
����һ�Źžɵ��Ŵ�������һ���ű��Ϲ���һ������Ԫ���Ļ��ӣ�����������
һ��Ǯׯ��
LONG
	);

	set("exits", ([
                "east" : __DIR__"bank",
                "south" : __DIR__"dongxiang",
	]));

	set("outdoors", "����");
	setup();
}
