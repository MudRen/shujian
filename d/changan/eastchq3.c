// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastchq3.c

inherit ROOM;

void create()
{
        set("short", "����ǽ");
        set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���������ǽ����ʯ�ҡ�����
Ŵ��֭������ɣ��������沼���˶�������������֮�á���ǽ�ϣ���������
��ǽ�⻤�ǺӶ����һ��һ����
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "south" : __DIR__"eastchq4",
                "north" : __DIR__"eastjl2",
        ]));

        set("incity",1);
	setup();
}

