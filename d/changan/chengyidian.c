// Write By Yanyang@SJ 2001.9.30
// Room: /d/changan/chengyidian.c

inherit ROOM;

void create()
{
        set("short", "���µ�");
        set("long", @LONG
������һ�ҳ����̣��ǳ������ڵľ��񳣵�֮��������Ҳ��������Ҳҡ�
��Ϊ���������·����������ǵ����⡣�����Ǹ�������������Ů�ӣ���������
�������������Ĺ���Χ��һ������������ʲô��
LONG
        );

        set("item_desc", ([
                "paizi" : "ֻ�����£�ˡ������\n",
        ]));

        set("exits", ([
                "east" : __DIR__"northjie2",
        ]));

        set("objects", ([
                __DIR__"npc/hou" : 1,
        ]));
        set("incity",1);
        setup();
}