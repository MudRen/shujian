// Room: /d/meizhuang/qishi.c
// By Lklv

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�ô�һ�䷿�У�����һ��ʯ������ֻ����֮�⣬�յ�����һ�����У�ʯ��
��������ݺ�ʮ�ŵ���·���Է���һ�к��ӡ�һ�а��ӡ��������г��˼�����
�ӡ�����֮�ⲻ��һ�������öԾ��߷��ġ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"huilang5",
	]));

        set("objects", ([
                __DIR__"npc/heibaizi" : 1,
        ]));

	setup();
}