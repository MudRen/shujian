// 牡丹宴会厅.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

// amount: 单位是gold

void create()
{
        set("short", HIR"点将台"NOR);
        set("long", @LONG
这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG );
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"zxlpath",
        ]));

        

        setup();
}
//是镜像
int is_mirror() { return 1; }