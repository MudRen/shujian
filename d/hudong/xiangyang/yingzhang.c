inherit ROOM;

void create()
{
        set("short", "营帐中");
        set("long", @LONG
这是蒙古攻击襄阳的临时军营，营帐中几个披挂着盔甲的将军走来走去正
在和一个看起来样子象谋士的人大声的谈论、争执着什么。营帐外有几个士兵
在巡逻。
LONG
        );
        set("outdoors", "襄阳");
        set("xyjob", 1);
        set("objects", ([
                __DIR__"npc/weishi" : 3,
                __DIR__"npc/mengge" : 1,
        ]));

        set("exits", ([
                "out" : __DIR__"junying",
        ]));

//         set("no_fight",1);

	setup();
}
int valid_leave(object me)
{
    if(me->query_temp("xyjob/mg_attack") 
    && !me->query_temp("xyjob/attack_ready"))
    return notify_fail("攻城时机未到，不要轻举妄动！\n");
    return ::valid_leave(me);
}
