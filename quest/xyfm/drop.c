inherit ROOM;
int do_drop(object me, object obj);
string money_str(int count);
void create()
{
        set("short", "瓦砾场");
        set("long", @LONG

你眼前出现一座硕大的垃圾堆。堆积如山的是无数的尸体。

LONG
        );
        set("exits", ([
                 "up" : __DIR__"guangchang",
        ]));

        setup();
}
//是镜像
int is_mirror() { return 1; }