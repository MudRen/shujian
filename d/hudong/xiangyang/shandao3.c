inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "山道");
         set("long",@LONG
这里已经看不到襄阳了，满眼望去，尽是曲曲折折的山道，大军行到
此处，人畜都开始有些吃力起来。
LONG
);
        set("outdoors", "xiangyang");
        set("no_fly",1);

        set("exits", ([
                "south"  : __DIR__"shandao3",
                "north"  : __DIR__"shandao3",
        ]));

        setup();
}

void init()
{
object room;
        object me=this_player();

        me->start_busy(1+random(2));


        if( me->query_temp("yidao/mark_steps") > 20 )
        {

if(!( room = find_object(__DIR__"xuanwumen")) )
                room = load_object(__DIR__"xuanwumen");
        if(objectp(room)){
                set("exits/southup", __DIR__"xuanwumen");

}
        // me->move("d/hudong/xiangyang/xuanwumen");
         me->delete_temp("yidao");
         tell_object(me,YEL"一路风尘仆仆之后，玄武门已经近在眼前了......\n"NOR);
         return;
        } 

        if( me->query_temp("yidao/mark_steps") < -20 )
        {

if(!( room = find_object(__DIR__"xuanwumen")) )
                room = load_object(__DIR__"xuanwumen");
        if(objectp(room)){
                set("exits/northup", __DIR__"xuanwumen");

}
       //  me->move("d/hudong/xiangyang/zhangwai");
         me->delete_temp("yidao");
         tell_object(me,YEL"一路风尘仆仆之后，蒙古军营已经近在眼前了......\n"NOR); 
         return;
        }

        tell_object(me,YEL"你指挥着大军，行进在曲折的山道上......\n"NOR); 
}

int valid_leave(object me,string dir)
{
       if( dir == "north" )
       me->add_temp("yidao/mark_steps",-random(2));
       if(  dir == "south" )
       me->add_temp("yidao/mark_steps",random(2));
       return ::valid_leave(me,dir);
}

