// Room: /d/city/duchang4.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "残破赌场");
	set("long", @LONG
这里原先是一处赌场，专供兵士聚赌之用，如今哪里还有人在。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"chatroom",
  "west" : __DIR__"chat-dc3",
  "east" : __DIR__"chat-dc4",
]));

    set("item_desc", ([
                "paper": @TEXT
    骰子的赌法：
    bet <种类> <数量> <货币名称>
    种类：０、１、２、３到１８
    ０：　      赌小    （  ３－１０）  一赔一
    １：        赌大    （１１－１８）  一赔一
    ２：　      赌围骰  （三粒骰子同点）一赔三十六
    ３－１８    赌单点                  一赔四
    例子：
    bet 0 50 silver  压五十两银子在小上
TEXT
        ]) );

	setup();
}
//是镜像
int is_mirror() { return 1; }