// Room: /u/firefox/miao.c

inherit ROOM;

void create()
{
        set("short", "Ӣ�ҷ�����");
        set("long", @LONG
�������Ӣ�ҷ�����������Ǻ����ҷ��ˣ����������ҷ�������������
Ů����˼�Ůÿ��ص�Ӣ�ҷ�����������Ը������λ�γ��İ����������飬
�չ˺����ͬ�н��á�
LONG    );
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"winmo",
        ]));
        set("objects", ([
                __DIR__"npc/xiangnu" : 2,
	]));
        set("no_fight", 1);
	setup();
}
