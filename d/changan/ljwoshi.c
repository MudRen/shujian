// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/ljwoshi.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������Ա�����Ϣ���ڡ�������Ĺ��ߺܰ���������������һ�����˵�
������һ�ſ������Ĵ������ű��죬���˲��������˯��
LONG
        );
        set("sleep_room", 1);
        set("no_fight", 1);
        set("exits", ([
                "east"  : __DIR__"ljzhengting",
        ]));

        set("incity",1);
	setup();
}
