// ������ huacong1.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "������");
        set("long", @LONG
������Χ�����̺���ϵ��ʻ��������滨��ݣ�������㡣��ǰ��һ��С
���������ʻ����С�
LONG
        );

        set("outdoors", "������");

        set("exits", ([ 
            "north" : __DIR__"xiaojing",
            "out" : __DIR__"shanbi",
        ]));

        setup();
}
