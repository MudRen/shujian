
// Room: /city/kedian.c
// YZC 1995/12/04 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", CYN"�м��ջ"NOR);
        set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
        );

        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹһ��������\n",
        ]));

        set("exits", ([
                "west" : __DIR__"beidajie1",
                "up" : __DIR__"kedian2",
        ]));
        setup();
}

//�Ǿ���
int is_mirror() { return 1; }
