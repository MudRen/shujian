// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/jiangjunfu.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǳ������سǽ����ĸ�լ��������������ͷ�ߴ��ʯʨ�ӣ����м���
�ٱ������š�������һ�û����������дУ��ڸ��˴���Ժ�ӣ�����Ժ������
�������ġ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"jjfzht",
                "west"  : __DIR__"jjfxf",
                "north" : __DIR__"westjie2",
        ]));

        set("objects", ([
                __DIR__"npc/bing" : 2,
        ]));

        set("incity",1);
	setup();
}
