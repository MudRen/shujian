// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/shiji.c

inherit ROOM;

void create()
{
        set("short", "�м�");
        set("long", @LONG
�ߵ��ڽֵľ�ͷ����һ�����ַǷ����м����������������������˵Ц��
����һ�š��м������˼��ˣ������������ò�Ҷ����������޴��½š�����
��Ѳ�����м�������ϸ��Ѳ�ӣ���ֹ���������ﷷ��˽�Ρ�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"  : __DIR__"neijie1",
                "south" : __DIR__"minju2",
                "west"  : __DIR__"heishi",
                "north" : __DIR__"minju1",
        ]));

        set("objects", ([
                __DIR__"npc/xunbu" : 2,
        ]));

        set("incity",1);
	setup();
}

