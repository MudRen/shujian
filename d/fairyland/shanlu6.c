// Room: shanlu3.c
// By River@SJ
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"���"NOR);
        set("long", @LONG
����ǰ�Ǹ����Ž��صĴ�ȣ��컨������������ӳ������̤�ŵ�������ϸ
�ݣ������ŵ��������Ļ��㣬���ݼ�أ��ʹ���֦�����ɵ��Ŀ�������
LONG    );
        set("exits", ([
                "south" : __DIR__"shanlu5",
                "north" : __DIR__"cuigu1",
        ]));
        set("objects",([
		__DIR__"npc/monkey" : 1,
        ]));

        set("outdoors", "���ش��");
        set("no_clean_up", 0);

        setup();
}
