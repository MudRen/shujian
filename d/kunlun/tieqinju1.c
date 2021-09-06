// tieqinju.c 铁琴居

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short",MAG"铁琴居二楼"NOR);
        set("long",@long
这儿便是“铁琴先生”何太冲的居处二楼。房间陈设颇为精巧，物品与中土所
见别是不同。窗外苍松碧雪，甚是葱茏。
long);

        set("objects",([
           CLASS_D("kunlun")+ "/hetaichong.c" :   1,
           CLASS_D("kunlun")+ "/xihuazi.c" :   1,
           __DIR__"npc/kl-dizi2.c" :   1,
           __DIR__"npc/kl-dizi4.c" :   1,
        ]));

        set("exits", ([
             "down" : __DIR__"tieqinju", ]));

        set("no_clean_up", 0);
        setup();
}
