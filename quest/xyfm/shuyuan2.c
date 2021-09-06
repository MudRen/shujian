// Room: /d/city/shuyuan2.c
// This is a room made by roommaker. write by Fan. :)
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "无名寝室");
	set("long", @LONG
这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
	);
    set("objects", ([
]));

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shuyuan",
]));
	setup();

}
  void init() 
  { 
       add_action("no_action", "shot");
       add_action("no_action", "array");
 } 
 int no_action(string str) 
{
       write(HIY"别乱来！！！ \n"NOR); 
       return 1; 
} 
//是镜像
int is_mirror() { return 1; }
