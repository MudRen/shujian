// Room: /d/putian/xl8.c
// Lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
����һ��С·��·��һ���Ǹ߸ߵ�ǽ�ڡ���һ����ǽͷ���˼���ש������
���Եø��ӹ��ӡ�ż����������Զ��������ɮ���������������·�Կ���һ��
Ұ������ɫ�ʺ죬���Ǻÿ���
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"xl6",
                "south" : __DIR__"mtd2",
        ]));

        set("outdoors", "����");
        setup();
}

