// Room: /d/system_3/postoffice.c
inherit ROOM;
void create()
{
        set("short", "荒废驿站");
        set("long", @LONG
这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
        );
        
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"beimen",
        ]));

        setup();
}

//是镜像
int is_mirror() { return 1; }