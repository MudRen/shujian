// Room: /d/xingxiu/xxh5.c
// Modify by Lklv 2001.10.16

inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
����������޺��ľ�ͷ�ˡ���Ŀң��, ��Χ���޼ʵĺ������������ǻ�
��, Ȼ������ʪ, ���深ֳ���������޵��ӳ����˲�׽����,�Ա�����֮�á�
LONG
        );
	set("outdoors", "����");
        set("exits", ([
             "southeast" : __DIR__"xxh3",
             "southwest" : __DIR__"xxh4",
        ]));
        set("objects", ([
                __DIR__"npc/xxdizi.c"  : 1,
        ]));
        setup();
}