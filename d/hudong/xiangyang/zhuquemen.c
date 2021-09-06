// /d/xiangyang/zhuquemen.c

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
        set("short", YEL"朱雀门"NOR);
        set("long", @LONG
这里是军事重镇襄阳城的南门，因为这边离战场较远，所以显得繁华热闹
得多。向南出城可以去湖南。城外由于连年的战争，百姓流离失所，造成了大片的荒
地，人烟稀少。城门紧紧地关着，用冲车冲开(chong chengmen)倒不失是个好办法。

LONG
        );
set("no_save", 1);
        set("outdoors", "襄阳");
                set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

        set("exits", ([
                "north" : __DIR__"zqmnj",
                "south" : __DIR__"outsroad1",
        ]));

        set("objects", ([
          "d/hudong/xiangyang/obj/doorzq" : 1,
            //    NPC_D("guanfu/bing") : 2,
        ]));


	set("incity",1);
	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n襄阳安抚使\n吕文德\n";
}
void init()
{
object env = this_object();
object me = this_player();
int i;
object ob;
add_action( "do_back", "goback" );
if (ob = present("zhuque chengmen", env)){
 this_object()->set("no_fight",1);
return ;
}
else 
{
this_object()->delete("no_fight");
return ;
}
 if(wizardp(me)) message_vision(HIG"同志们，杀呀！测试一下\n"NOR, me);
    
   
}


int valid_leave(object me, string dir)
{
object ob;
object env = this_object();
        if (dir == "south"){
                if ( me->query_temp("互动任务/襄阳大战/阵营"))
                        return notify_fail("你正处在互动任务襄阳大战不能离开战场。\n");
        }


if (dir == "north"){
if ( me->query_temp("互动任务/襄阳大战/阵营") == 2 && ob = present("zhuque chengmen", env) )

                        return notify_fail("城门还未攻破，不能进入。\n");
        }



        return ::valid_leave(me, dir);
}
int do_back(string arg)
{
	object me = this_player();

	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");

	if(!arg || arg == "" || arg != "营帐外")	
return notify_fail("你想去哪里？\n");
if(arg == "营帐外")
{
if ( me->query_temp("互动任务/襄阳大战/阵营") == 2)
{
message_vision("$N见此处防守甚严，只好先撤回再图打算。\n", me);
me->move("/d/hudong/xiangyang/zhangwai");
return 1;
}
if ( me->query_temp("互动任务/襄阳大战/阵营") == 1)
{
return notify_fail("你是守军，还往哪里撤？\n");

}
else
return notify_fail("你是哪部分的？？？\n");

}
return 1;
}

