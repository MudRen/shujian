inherit ROOM;
void create()
{
        set("short", "大榕树上");
        set("long", @LONG
人说大树底下好乘凉，没想到大树上更凉快。这棵大榕树真不愧为千年神木，
至今仍绿叶繁茂。据说这里的时间是冻结的，因此便成为许多玩家聊天的地方。
这里摆着几张用榕树根做的椅子，中间用几根榕树枝搭在一起，算是一个茶几了。
当你抬头往上看的时候似乎有个影在树梢之间移动，不过也许是风吹动所造成的
错觉。
LONG);
        set("exits", ([
        "down": __DIR__"guangchang",
        ]));
        setup();
}

void init()
{
    add_action("do_jump","tiao");
}
int do_jump(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("你要往哪跳？\n");
      if (me->is_fighting() || me->is_busy() )  return notify_fail("你正忙着呢！\n");
        message("vision",
                me->name() + "犹豫了一下，鼓起勇气，跳了下去。\n“嘭”的一巨响，似乎听到"+me->name()+"惨嚎了一声!\n",
                environment(me), ({me}) );
                me->move(__DIR__"guangchang");
        message("vision",
                me->name() + "惨嚎一声，从树上掉了下来。\n",
                environment(me), ({me}) );
        return 1;
}
//是镜像
int is_mirror() { return 1; }