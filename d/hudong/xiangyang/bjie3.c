// /d/xiangyang/bjie3.c ����
// Lklv 2001.9.24

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����ɱ���ͨ�������ĵĽֵ���·��ܿ����������������ֵ���������
�����������֡���Ⱥ��������в����������ˣ�ż���м�����ñ���ʵ�����
��ǣ���鴩���ж�����վ��������������ȥ�����Կ���һ����¥��������һ
����ʯ·��ͨ��������
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "south" : __DIR__"dpailou",
                "north" : __DIR__"bjie2",
                "west" : __DIR__"cross1",
        ]));

        set("incity",1);
	setup();
}
