// Write By Yanyang@SJ 2001.9.27
// Room : /d/changan/kezhan3.c

inherit ROOM;

void create()
{
        set("short", "�ͷ�");
        set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ֻ�������ǽ���˼��Ŵ󴲣������Ǹ��Ŵ�
����˯�����㣬�����Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ���������ŵ�
���˹�ȥ��
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);
        set("hotel",1);

        set("exits", ([
        "south" : __DIR__"kezhan2",
        ]));

        set("incity",1);
	setup();
}
