// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/changjie2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ߵ��˳��ֵľ�ͷ��������һƬï�ܵİ����֣�������ɭɭ�ġ��ϱ�
�ɿ�����Ժ����Լһ����Ӱ�����º�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"baishulin2",
           "southeast"   : __DIR__"ciensi",
                "west"   : __DIR__"changjie1",
           "northeast"   : __DIR__"baishulin1",
        ]));

        set("incity",1);
	setup();
}