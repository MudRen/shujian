// /d/xingxiu/mogaoku.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"Ī�߿�"NOR);
        set("long", @LONG
�����Ƕػ�Ī�߿ߣ�����ǽ���ϻ�����������صĻ��棬����Ů���죬
���з������á����л��кܶ����;��顣�㱻��Щ�������Ļ�֮�������ˡ�
LONG);
        set("exits", ([ 
             "out" : __DIR__"silk3c",
        ]));

         set("objects", ([
                "/d/shaolin/obj/fojing11" : 1,
                "/d/shaolin/obj/fojing20" : 1,
                "/d/shaolin/obj/fojing21" : 1,
        ]));

        setup();
}

