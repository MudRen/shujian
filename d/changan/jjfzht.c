// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/jjfzht.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ����������������ſڹ���һ����ң����顸������˽���ĸ�����
�����������������飬���պ������ࡣ����ǽ�Ϲ���һ���޴�Ĺ��ʻ�������
һ����ǣ�ɽ��ˮ�ƣ�����׺��̨ͤ¥��԰����������ǽ��ϵ�һ�����ǡ�
�������ڼң����ȥ����Ѳ���ˡ����ڵĹܼ�һ����������������
LONG
        );
        set("exits", ([
                "east"  : __DIR__"jjfyt",
                "south" : __DIR__"jjfhm",
                "west"  : __DIR__"jjfws",
                "north" : __DIR__"jiangjunfu",
        ]));

        set("objects", ([
                __DIR__"npc/guanjia" : 1,
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("guan jia", environment(me))) && (dir == "east" || dir== "west" ||dir=="south"))
                return notify_fail("�ܼ���ס��˵���������ǽ��������ɲ�Ҫ�Ҵ�����\n");
        return ::valid_leave(me, dir);
}