// Room: /d/putian/nuange.c ů��
// Lklv 2001.9.12

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"ů��"NOR);
        set("long", @LONG
������һ��ů�󣬶�ǽ�ĵط��ڷ��źܶ��ľ���Ӻʹ�ľ�����涼����
�������������汣��Ķ���Щ����Ҫ�Ķ�����ů������˼������������
�Ե������������Ī�⡣
LONG
        );

        set("exits", ([
                "west" : __DIR__"changlang3",
        ]));

        setup();
}
