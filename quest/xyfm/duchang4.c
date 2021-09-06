// Room: /d/city/duchang4.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "无主之地");
	set("long", @LONG
这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"duchang",
]));
    
	setup();
}
//是镜像
int is_mirror() { return 1; }