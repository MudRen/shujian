// /d/xiangyang/bjie1.c ����
// Lklv 2001.9.24

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��������������ͨ�������ĵĽֵ���·��ܿ����������������ֵ�����
���������������֡���������ñ���ʵ����꣬�������Ŷ�ȥ��������һ����
��ҵ��Ķĳ����ſڹ���һ���죬���滭��˶������ӡ�
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "south" : __DIR__"bjie2",
                "north" : __DIR__"nroad1",
                "west" : __DIR__"bcx1",
                "east" : __DIR__"duchang",
        ]));

        set("incity",1);
	setup();
}
