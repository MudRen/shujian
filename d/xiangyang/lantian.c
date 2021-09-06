// /d/xiangyang/lantian.c

inherit ROOM;

void create()
{
        set("short", "蓝田");
        set("long", @LONG
蓝田自古出产美玉，不仅玉质好，也可已入药。这里已是长安附近，东南
边是去湖北的正路。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
            "southeast" : __DIR__"shanxiroad2",
                "north" : "/d/changan/southroad3",
        ]));

        setup();
}


void init() 
 {
           add_action("do_push", "huigong");
 }
 int do_push()
 {
           object me = this_player();
           if (me->is_busy() || me->is_fighting())
                  return notify_fail("你正忙着呢。\n");
if(me->query("family") && me->query("family/family_name")!="灵鹫宫")
                    return notify_fail("什么?\n");

       message_vision("$N早听说蓝田玉暖，有心寻觅，竟从乡村走夫手中获得极品美玉一方，欣喜之余，急着赶路，前往灵鹫，秀玉诸姝。\n", me);
           me->receive_damage("jing", 30);
           me->start_busy(random(3));
         message_vision("$N当下匆匆赶路，日转月轮，不多日已是到了飘渺峰。\n", me);
  me->move("/d/tianshan/pmfeng");
           return 1;
 }

