// Room: /d/tianshan/pmfeng.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "缥缈峰");
	set("long", @LONG
这里是天山绝峰，山峰终年云封雾锁，非天即海，茫茫一片，险峻之极，
远远望去，若有若无，因此叫作缥缈峰。
LONG);
	 set("exits", ([
                "northdown" : __DIR__"dadao1",
		"southdown" : __DIR__"shanjin6",
        ]));        

	set("outdoors", "天山");
	setup();
}


void init()
{
          add_action("do_push", "leave");
}

int do_push()
{
          object me = this_player();
          if (me->is_busy() || me->is_fighting())
                 return notify_fail("你正忙着呢。\n");
if(me->query("family") && me->query("family/family_name")!="灵鹫宫")
                   return notify_fail("什么?\n");
      message_vision("这飘渺峰险峻无比，无路可攀，但$N身在灵鹫宫，自然摸索出了一条蜿蜒小路，可以直达山下。\n", me);
          me->receive_damage("jing", 30);
          me->start_busy(random(2));
        message_vision("$N行了半响，已到山脚。但见树木葱茏，放眼望去，良田沃野。\n", me);
 me->move("/d/gumu/xiaolu1");
          return 1;
}
