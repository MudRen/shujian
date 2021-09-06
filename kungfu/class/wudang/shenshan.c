#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "深山");
        set("long", @LONG
三人直奔出数十里外，方才止步，只见所到
处是一座深山之中。暮霭四合，归鸦阵阵。
想要离开就赶紧离开(leave)吧。
LONG
        );

 set("outdoors", "shaolin");    
set("no_fight", 1);
   set("exits", ([
                 "leave" : "/d/wudang/houyuan",
]));
   setup();
}
void init()
{
        object me = this_player(), ob;

       

        add_action("do_look", "xun");
       add_action("do_fire", "shi");

        if (me->query_temp("wdjiuyang2"))
        {
		
                tell_object(me, HIG "那老僧内力虽强，这一阵舍命急驰，却也已筋疲力竭，\n"
                                    "一时之间，再也无力将铁桶卸下肩来。\n"NOR);

        }
        return 0;
}
int do_look(string arg)
{
object me = this_player();
if (!me->query_temp("wdjiuyang2"))
 return notify_fail("你是怎么来的？\n");
if (arg != "caomei" )
return notify_fail("你要干什么？\n");
 if (me->is_busy() || me->is_fighting())
return notify_fail("你正忙着呢。\n");
 if ( (int)me->query("jingli")<400)
             {
                     write("你现在太累了，休息一下吧！\n");
             return 1;
             } 

        if(random(10) > 3)
             {
             me->add("jingli",-random(300));
             return notify_fail("但眼见四下里长草齐膝，在这荒野山地，哪里有甚吃的。\n"); 
}
 message_vision(HIG"$N去了半日，只采得一大把草莓来。三人胡乱吃了，倚石休息。\n"NOR, me);
 me->start_busy(random(5));
me->delete_temp("wdjiuyang2");
me->set_temp("wdjiuyang3",1);
return 1;
	
}
int do_fire(string arg)
{
object me = this_player();
if (!me->query_temp("wdjiuyang3"))
return notify_fail("你是怎么来的？\n");
if (arg != "kuchai" )
return notify_fail("你要干什么？\n");
 if (me->is_busy() || me->is_fighting())
return notify_fail("你正忙着呢。\n");
message_vision(RED"$N拾些枯柴，生了个火，烤干少女和自己身上的衣服。三人便在大树之下睡了。
\n"NOR, me);
me->delete_temp("wdjiuyang3");
remove_call_out("meet");
        call_out("meet", 2, me);
        return 1;
}
int meet(object me)
{
me = this_player();
tell_object(me,HIG"\n睡到半夜，忽听得老僧喃喃自语，似在念经，当即从朦胧中醒来，只听他念道：“……\n"NOR);  
tell_object(me,HIG"：……彼之力方碍我之皮毛，我之意已入彼骨里。两手支撑，一气贯通。\n"
                     "左重则左虚，而右已去，右重则右虚。而左已去……”\n"NOR);  
tell_object(me,HIG"\n只听他顿一顿，又念道：\n"
                     "有不相随处，身便散乱，其病于腰腿求之……”\n"NOR);
                  
tell_object(me,HIR"\n你心中一凛，他念诵的莫非就是张真人口中常提到的......\n"NOR);  
tell_object(me,HIW"\n正在胡思乱想，忽然一个嘴巴把你打醒，你揉揉眼睛，原来还是在张真人身边。\n"NOR); 
me->set_temp("wdjiuyang4",1);
me->move("/d/wudang/houyuan");

        return 1;
}
