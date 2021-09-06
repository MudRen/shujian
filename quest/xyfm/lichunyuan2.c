// Room: /city/lichunyuan2.c
// Dec.12 1997 by Venus
inherit ROOM;
void create()
{
        set("short", "土妓院");
        set("long", @LONG
这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG);
        set("exits", ([
            "down" : __DIR__"lichunyuan",
        ]));

        setup();
}

//是镜像
int is_mirror() { return 1; }