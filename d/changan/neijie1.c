// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/neijie1.c

inherit ROOM;

void create()
{
        set("short", "�ڽ�");
        set("long", @LONG
�����ǳ����ǵľ�������ס�Ķ���ƽ�����գ����Ժ���Щ��ֱ���������
��Ͳ���ô�����ˡ�����Ҳ����СС���棬���ڶ�������������������������
Ϣ����ȻһƬ�����ľ���������һ��С�ƹݡ�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"northjie3",
                "south"  : __DIR__"jiuguan",
                "west"   : __DIR__"shiji",
                "north"  : __DIR__"minju3",
        ]));

        set("incity",1);
	setup();
}