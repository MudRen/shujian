// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/neijie5.c

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
                "south"  : __DIR__"neijie6",
                "west"   : __DIR__"neijie4",
                "north"  : __DIR__"minju7",
        ]));

        set("incity",1);
	setup();

}