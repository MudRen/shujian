// Room: /d/putian/mtd2.c
// Lklv 2001.9.10

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����һ��Ƭ����أ��������ż�����ͷ���Ա���һ�ѵ�����������Ҳݣ�����
���п�С���ϴ���һ���·��������˺���û��Զ��
LONG
        );

        set("exits", ([
                "north" : __DIR__"xl8",
                "southdown" : __DIR__"mtd1",
        ]));
        set("outdoors", "����");
        setup();
}

