// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/neijie2.c

inherit ROOM;

void create()
{
        set("short", "�ڽ�");
        set("long", @LONG
�����ǳ����ǵľ�������ס�Ķ���ƽ�����գ����Ժ���Щ��ֱ���������
��Ͳ���ô�����ˡ�����Ҳ����СС���棬���ڶ�������������������������
Ϣ����ȻһƬ�����ľ���������һ��ϷԺ��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"neijie3",
                "south"  : __DIR__"xiyuan",
                "west"   : __DIR__"northjie3",
                "north"  : __DIR__"minju4",
        ]));

        set("incity",1);
	setup();
}