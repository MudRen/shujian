// /d/xiangyang/njie2.c �Ͻ�
// Lklv 2001.9.24

inherit ROOM;
void create()
{
        set("short", "�Ͻ�");
        set("long", @LONG
����������������ͨ�����ŵ�һ����֣�·��ܿ����������������д�
�Ĵ��������������Ŵ�����ʯ��ƽ̹���ࡣ������ȥ����Լ���Կ���������
�ĳ�¥��Ů��ǽ��
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "south" : __DIR__"njie3",
                "north" : __DIR__"njie1",
        ]));

        set("objects", ([
		__DIR__"npc/wanyanping" : 1,
        ]));

        set("incity",1);
	setup();
}
