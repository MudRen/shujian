// Write By Yanyang@SJ 2001.9.27
// Room : /d/changan/kezhan2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������ڿ�ջ�������ϣ�������һ��װ�޾����Ŀͷ�����ʱ��˯�����ʵ�
�ÿͽ�����������¥�µ��ƹ񴦸���Ǯ��������˯����
LONG
        );

        set("exits", ([
                "down" : __DIR__"kezhan",
                "north" : __DIR__"kezhan3",
        ]));

        set("incity",1);
	setup();
}
