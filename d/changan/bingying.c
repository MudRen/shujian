// Write By Yanyang@SJ 2001.9.28
// ROOM : /d/changan/bingying.c

inherit ROOM;

void create()
{
        set("short", "��Ӫ����");
        set("long", @LONG
�����ǳ������ٽֶ����ı�Ӫ�����볤���Ķ�����ֻ�м���֮ң����Ӫ��
�����Ʈ����ŵı�ʿ������ɫ��Ѱ�������ܡ���Ӫ���浽�����йٱ�����
�߶����������佫����ָ��ʿ����������ʱ�ش����ź������ϰ����ǲ�������
�˹ۿ��ģ�����øϿ��߿���
LONG
        );

        set("exits", ([
                "south" : __DIR__"bingying2",
                "north" : __DIR__"eastjie4",
        ]));

        set("objects", ([
        __DIR__"npc/bing" : 2,
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
                dir == "south")
                return notify_fail("�ٱ���ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}