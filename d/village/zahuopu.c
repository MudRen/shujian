// Room: /d/village/zahuopu.c

inherit MISC_ROOM;

void create()
{
        set("short", "�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��꣬ǽ�ǰ���һ�ѶѵĻ����ɽ���οͿ���������
Щ��ɽ��Ʒ��ǽ�����Ÿ����ӣ��Ǹ���Ŀ��
    ��ǰ���˸�����(sign)��
LONG
        );
        set("exits", ([
		"south" : __DIR__"shilu4",
	]));


        set("objects", ([
		__DIR__"npc/xiaofan": 1
        ]));
	setup();
}
 