// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/ljzhangfang.c

inherit ROOM;

void create()
{
        set("short", "�ʷ�");
        set("long", @LONG
��������Ա��ҵĵ��˷�����Ҵ��СС������֧����Ҫͨ���������
�������ɼ�Ӳ�Ļ���ʯ���ɵġ���Ψһ��һ��С���϶�����Ĵָ��ϸ�ĸ�����
������ˣ����л��л�ͭ���壬����һ�죬��ҵļҶ�����ӵ������
LONG
        );
        set("exits", ([
                "south" : __DIR__"lijia",
        ]));

        set("objects", ([
                __DIR__"npc/zhfxsh" : 1,
        ]));

        set("incity",1);
	setup();
}
