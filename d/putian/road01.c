// Room: /d/putian/road01.c
// Lklv 2001.9.11

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����������ڣ�ֻ����ɽ�컨���������衣·������һƬƬ����ï�ܵ���
�֣�����׺����಻֪����Ұ�����ϱ�ԶԶ�ĺ�������������ǳء�
LONG
        );

        set("exits", ([
                "northwest" : "/d/fuzhou/road2",
                "south" : __DIR__"road02",
        ]));

        set("outdoors", "����");
        setup();
}

