// Room: /d/village/jiusi.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǵ��������һ��С������ƽʱ����������Ͼ��ʱ����������ǲ��һ
�߽�����һ������ˮ�ƵĴ̱�ζ��ֱ�����˹��������ӵ�������ż������ӣ�
�����һ��æµ�š�
LONG
        );
        set("exits", ([
		"south" : __DIR__"shilu3",
	]));

/*
        set("objects", ([
                __DIR__"npc/": 2 ]) );
*/
	setup();
}
