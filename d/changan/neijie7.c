// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/neijie7.c

inherit ROOM;

void create()
{
        set("short", "�ڽ�");
        set("long", @LONG
�����ǳ����ǵľ�������ס�Ķ���ƽ�����գ����Ժ���Щ��ֱ���������
��Ͳ���ô�����ˡ�����Ҳ����СС���棬���ڶ�������������������������
Ϣ����ȻһƬ�����ľ�������һ�Ⱥ�����ţ���������һ�����˼ҡ�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "south"  : __DIR__"eastjie4",
                "west"   : __DIR__"lijia",
                "north"  : __DIR__"neijie6",
        ]));

        set("incity",1);
	setup();
}