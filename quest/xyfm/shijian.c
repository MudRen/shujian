// #include <room.h>

inherit ROOM;

void create()
{
        set("short", "试剑厅");
        set("long", @LONG
这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
        );

        set("exits", ([
                 "south": __DIR__"wumiao",
]));
set("item_desc", ([
                "sign": @TEXT
   虹台论剑
天下归心
TEXT
        ]) );


        setup();
}
//是镜像
int is_mirror() { return 1; }