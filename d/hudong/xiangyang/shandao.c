inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "ɽ��");
        set("long",@LONG
�����Ѿ������������ˣ�������ȥ�������������۵�ɽ��������е�
�˴������󶼿�ʼ��Щ����������
LONG
);
        set("outdoors", "xiangyang");
        set("no_fly",1);

        set("exits", ([
                "east"  : __DIR__"shandao",
                "west"  : __DIR__"shandao",
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
          
 if(!( room = find_object(__DIR__"baihumen")) )
                room = load_object(__DIR__"baihumen");
        if(objectp(room)){
                set("exits/eastup", __DIR__"baihumen");

}
      // me->move("d/hudong/xiangyang/baihumen");

         me->delete_temp("yidao");
         tell_object(me,YEL"һ·�糾����֮�󣬰׻����Ѿ�������ǰ��......\n"NOR);
         return;
        } 

        if( me->query_temp("yidao/mark_steps") < -20 )
        {

if(!( room = find_object(__DIR__"zhangwai")) )
                room = load_object(__DIR__"zhangwai");
        if(objectp(room)){
                set("exits/westup", __DIR__"zhangwai");

}

       //  me->move("d/hudong/xiangyang/zhangwai");

         me->delete_temp("yidao");
         tell_object(me,YEL"һ·�糾����֮���ɹž�Ӫ�Ѿ�������ǰ��......\n"NOR); 
         return;
        }

        tell_object(me,YEL"��ָ���Ŵ�����н������۵�ɽ����......\n"NOR); 
}

int valid_leave(object me,string dir)
{
       if( dir == "west" )
       me->add_temp("yidao/mark_steps",-random(2));
       if(  dir == "east" )
       me->add_temp("yidao/mark_steps",random(2));
       return ::valid_leave(me,dir);
}

