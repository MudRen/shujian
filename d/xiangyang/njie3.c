// /d/xiangyang/njie3.c �Ͻ�
// Lklv 2001.9.24

inherit ROOM;
void create()
{
        set("short", "�Ͻ�");
        set("long", @LONG
����������������ͨ�����ŵ�һ����֣�·��ܿ����������������д�
�Ĵ��������������Ŵ�����ʯ��ƽ̹���ࡣ������ȥ����Լ���Կ���������
�ĳ�¥��Ů��ǽ��·������һ�����ӿ����ţ����ϻ���һ���ܴ��ͭǮ������
��Ǯׯ��
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "south" : __DIR__"zqmnj",
                "west" : __DIR__"bank",
                "east" : __DIR__"ncx1",
                "north" : __DIR__"njie2",
        ]));

        set("incity",1);
	setup();
}
