// Room: /d/meizhuang/huashi.c
// By Lklv

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�仭�ң�������������ڷ��ż������ӣ��ı��Ϲ��ż��������Զ
�ľ��ᡣ�߽�����ϸ����ֻ��һ����ˮī���࣬�ʷ����񹤡����߷��裬��
Ȼ���Դ��֮�֡�
LONG
	);
	set("exits", ([
		"east" : __DIR__"huilang6",
	]));

        set("objects", ([
                __DIR__"npc/danqingsheng" : 1,
        ]));

	setup();
}