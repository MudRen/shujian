// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/juhao.c

inherit ROOM;

void create()
{
        set("short", "�ۺ���¥");
        set("long", @LONG
�����ǳ��������ľ�¥�������ǳ��е��׸���Ա�⡣��Ա��Ϊ�˺�ˬ��
�㽻���º��ܣ���¥��˵�����¥�����У�����һ�������ĺ��ң��������
�������֡��ۺ���¥�������ԡ���������ɣ������۾������ư��硣
LONG
        );

        set("exits", ([
                "up"   : __DIR__"juhao2",
                "west" : __DIR__"northjie1",
        ]));

	set("objects", ([
		__DIR__"npc/zhanggui" : 1,
]));

        set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
        if( dir=="up" && me->query_temp("getout")>0 )
                return notify_fail("���Ѿ����˼Ҹϳ����ˣ����ǲ���ӭ���ٸ����ˣ�\n");
        return ::valid_leave(me,dir);
}