// Room: /d/putian/xl7.c
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
                "westup" : __DIR__"xl5",
                "north" : __DIR__"youcaidi",
        ]));
        set("objects",([
                __DIR__"npc/jinsq" : 2,
        ]));
        set("outdoors", "����");
        setup();
}

