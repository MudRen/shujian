// Room: /d/xiangyang/bingying.c
// Lklv 2001.9.25

inherit ROOM;

void create()
{
        set("short", "��Ӫ");
        set("long", @LONG
������һ����Ӫ����ΪҪ�����ɹ�����Ľ��������Գ���ı���඼����
����ͳ�ǽ���س�ȥ�ˣ�����ֻ�м������صĹٱ��������佫������ɫ�ش���
һ����̸����ʲô��
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "south" : __DIR__"ncx3",
        ]));

        set("objects", ([
                NPC_D("guanfu/wujiang") : 2,
                NPC_D("guanfu/bing") : 4,
	]));
	set("incity",1);
	setup();
}
