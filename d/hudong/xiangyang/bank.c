// Room: /xiangyang/bank.c
// Looklove y2k/4/09

inherit ROOM;

void create()
{
        set("short", "����ի");
        set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ�������ڰ���ʮ�ּ򵥣�һ���߸ߵĹ�̨����װ
����դ����
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "east" : __DIR__"njie3",
        ]));

        set("objects", ([
                __DIR__"npc/banker" : 1,
        ]));

        set("incity",1);
	setup();
}
