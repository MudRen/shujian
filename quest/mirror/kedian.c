
// Room: /city/kedian.c
// YZC 1995/12/04 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", CYN"有间客栈"NOR);
        set("long", @LONG
这是扬州城本地一家价钱低廉的客栈，生意非常兴隆。外地游客多
选择这里落脚，你可以在这里打听到当地的风土人情。店小二里里外外
忙得团团转，接待着南腔北调的客人。角落里几位江湖人物打扮的大汉
正围着一张桌子不知道在商量什么,客店的主人从不露面，他究竟是谁，
有各种各样的猜测。墙上挂着一个牌子(paizi)。
LONG
        );

        set("item_desc", ([
                "paizi" : "楼上雅房，每夜一两白银。\n",
        ]));

        set("exits", ([
                "west" : __DIR__"beidajie1",
                "up" : __DIR__"kedian2",
        ]));
        setup();
}

//是镜像
int is_mirror() { return 1; }
