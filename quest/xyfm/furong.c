// 芙蓉宴会厅.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
// amount: 单位是gold

void create()
{
        set("short", HIY"破旧酒楼"NOR);
        set("long", @LONG
这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"zxlpath",
        ]));

        set("item_desc", ([
                "menu": @TEXT
承办各式酒席, 欢迎惠顾：

        order birthday: 祝寿宴        (400两黄金)

        order marry:    订婚宴        (800两黄金)

        order player:   群豪宴        (1000两黄金)

        order end:      结  束

TEXT
        ]) );

        setup();
}
//是镜像
int is_mirror() { return 1; }