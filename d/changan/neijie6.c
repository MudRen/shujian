// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/neijie6.c

inherit ROOM;

void create()
{
        set("short", "�ڽ�");
        set("long", @LONG
�����ǳ����ǵľ�������ס�Ķ���ƽ�����գ����Ժ���Щ��ֱ���������
��Ͳ���ô�����ˡ�����Ҳ����СС���棬���ڶ�������������������������
Ϣ����ȻһƬ�����ľ���
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "south"  : __DIR__"neijie7",
                "north"  : __DIR__"neijie5",
        ]));

        set("objects", ([
                __DIR__"npc/fenggou" : 1,
        ]));

        set("incity",1);
	setup();
}