// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/neijie4.c

inherit ROOM;

void create()
{
        set("short", "�ڽ�");
        set("long", @LONG
�����ǳ����ǵľ�������ס�Ķ���ƽ�����գ����Ժ���Щ��ֱ���������
��Ͳ���ô�����ˡ�����Ҳ����СС���棬���ڶ�������������������������
Ϣ����ȻһƬ�����ľ���������һ���ӻ��̡�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"neijie5",
                "south"  : __DIR__"zahuopu",
                "west"   : __DIR__"neijie3",
                "north"  : __DIR__"minju6",
        ]));

        set("incity",1);
	setup();
}