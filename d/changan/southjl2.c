// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/southjl2.c

inherit ROOM;

void create()
{
        set("short", "��¥");
        set("long", @LONG
�������ฺ�𱣻����ŵľ��±��ݣ����м�ĳ�¥��ͬ����������š���
������ڵı����⣬�����ϡ����඼����������������Ϊ�س�ʱ��������
�ף������ڹ۲���飬��սʱ��������ɱ�С�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
               "east" : __DIR__"southchq4",
               "west" : __DIR__"southchl",
        ]));

        set("incity",1);
	setup();
}

