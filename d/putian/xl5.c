// Room: /d/putian/xl5.c
// Lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
����һ��С·��·��һ���Ǹ߸ߵ�ǽ�ڣ�������һ���˺�������ȥ������
��ǽ����������ż����������Զ��������ɮ���������������·�Կ���һ��
Ұ������ɫ�ʺ죬���Ǻÿ���
LONG
        );

        set("exits", ([
                "west" : __DIR__"xl3",
                "eastdown" : __DIR__"xl7",
        ]));

        set("outdoors", "����");
        setup();
}

