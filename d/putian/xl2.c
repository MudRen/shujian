// Room: /d/putian/xl2.c
// Lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
����һ��С·��·��һ���Ǹ߸ߵ�ǽ�ڣ�������һ���˺�������ȥ������
��ǽ�������������ǿ�������Զ��������ɮ���������������·�Կ���һ��
Ұ������ɫ�ʺ죬���Ǻÿ���
LONG
        );

        set("exits", ([
                "east" : __DIR__"shanmen",
                "west" : __DIR__"xl4",
        ]));

        set("outdoors", "����");
        setup();
}

