// Room: /d/taishan/.c

inherit ROOM;

void create()
{
	set("short", "̽��ʯ");
	set("long", @LONG
����һ���ɽ�����ͻ���ľ�ʯ����Լ�����࣬��ֱָ��������ʯ����
����ƾ������Ұ�������������о��ߵ�ɫ���ˣ���ͨ��һ�㶼�����ʵ����̽
��ʯ��
LONG
	);

	set("exits", ([
		"westdown" : __DIR__"riguan",
		"east" : __DIR__"dongtian",
	]));

        set("objects",([
                __DIR__"npc/yuyinzi" : 1,
        ]));
	set("outdoors", "̩ɽ");
	setup();
}

