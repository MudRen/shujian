// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastjl2.c

inherit ROOM;

void create()
{
        set("short", "��¥");
        set("long", @LONG
�������ฺ�𱣻����ŵľ��±��ݣ����м�ĳ�¥��ͬ��ɶ������š���
������ڵ������⣬�����ϡ����඼����������������Ϊ�س�ʱ��������
�ף������ڹ۲���飬��սʱ��������ɱ�С�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "south" : __DIR__"eastchq3",
                "north" : __DIR__"eastchl",
        ]));

        set("incity",1);
	setup();
}

