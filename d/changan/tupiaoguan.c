// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/tupiaoguan.c

inherit ROOM;

void create()
{
        set("short", "���ι�");
        set("long", @LONG
����һ���ª�ģ��������������ĵͰ�С���������ǽ�������ѷ죬����
�Ͻ�һֱ�ѵ���ߵ�ǽ���������һ�ź�������Ϊһ�����������ͷ���ź�
�����ʣ����ϵı���������ģ�����ɢ�������ŵ���ζ��
LONG
        );

        set("exits", ([
                "north" : __DIR__"neijie3",
        ]));
        
        set("objects", ([
                __DIR__"npc/tuchang" : 1,
        ]));
        
        set("incity",1);
	setup();
}