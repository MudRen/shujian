#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", YEL"营帐外"NOR);
        set("long", "这里是襄阳不远处蒙古军营大帐以外：\n"+
"向西走可到达：「"+HIG"青龙门"NOR+"」。\n"+
"向东走可到达：「"+HIW"白虎门"NOR+"」。\n"+
"向北走可到达：「"+HIR"朱雀门"NOR+"」。\n"+
"向南走可到达：「"+CYN"宣武门"NOR+"」。\n"
        );

        set("no_save", 1);
        set("outdoors", "襄阳");
        

        set("exits", ([
"east" : "d/hudong/xiangyang/shandao",
"west" : "d/hudong/xiangyang/shandao1",
"north" : "d/hudong/xiangyang/shandao2",
"south" : "d/hudong/xiangyang/shandao3",
                
        ]));
       
        set("incity",1);
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "west" || dir == "east" || dir == "north" ||dir == "south"  ){
if ( !me->query_temp("cart"))
                        return notify_fail("领了冲车再走。\n");
        }
return ::valid_leave(me, dir);

}
void init()
{
	add_action("do_get","ling");
	
}
int do_get(string arg)
{
	object me = this_player();
object obj;
if(!arg || arg == "" || arg != "冲车")	
return notify_fail("你想领什么？\n");
if(me->query_temp("cart"))
return notify_fail("你已经领过了。\n");
if(arg == "冲车")
{
obj =new("d/hudong/xiangyang/obj/cart");
message_vision(CYN"$N一辆冲车轰隆隆地驶了出来。\n"NOR, me);
me->set_temp("cart",1);  // 领取一辆冲车
obj->move(this_object());
obj->set("name",obj->query("name")+(me->query("id")));
obj->set("long", obj->query("long")+"这两冲车是由"+me->query("name")+"负责操纵的。\n");
obj->set("make",me->query("id"));
return 1;
}
}

