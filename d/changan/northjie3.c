// Write By Yanyang@SJ 2001.9.30
// Room: /d/changan/northjie3.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣��
�����ǳ����ĵ���¥���ֵ��Ա���һ������������ڽ֣��ڽֺܳ�������Ҳ��
���С�͵ĵ��̣�ƽ�����ռҶ�ס�����档
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"neijie2",
                "south"  : __DIR__"northjie2",
                "west"   : __DIR__"neijie1",
                "north"  : __DIR__"northmen",
        ]));

        set("incity",1);
	setup();
}