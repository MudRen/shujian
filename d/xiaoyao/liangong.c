// liangong.c

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
这是树林中的一间石屋，屋内显得什么清净和简朴，房间中并没有什么
特别的摆设在这里，不会受到任何东西的骚扰，是个修炼内功的好地方。
后面好像有个木门(door)，通往一条不知道什么去处的小路。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"xiaodao4",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
void init()
{
         add_action("do_push", "push");
}

int do_push(string arg)
{
         object me = this_player();
         if (arg != "door")
                 return notify_fail("你要推什么?\n");
         if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");

     message_vision("$N轻轻的推开木门，原来却是一条蜿蜒的小路，貌似可以直达青城。\n", me);
         me->receive_damage("jing", 30);
         me->move("/d/zhiye/gaoshan0");
         message_vision("$N满头大汗的从青城山一条羊肠小路走了过来。\n", me);
         me->start_busy(random(2));
         return 1;
}










