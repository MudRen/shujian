// ���� huapu1.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "����");
        set("long", @LONG
�����Ǻ����ȵĻ��ԣ��ǡ��������ȡ�����ţ�����ָ��ָ���ҩ�ĵģ���
����������㻨�ݡ�
LONG
        );

        set("outdoors", "������");

        set("exits", ([ 
                "west" : __FILE__,
                "east" : __FILE__,
                "south" : __FILE__,
                "north" : __FILE__,
        ]));

        setup();
}

void init()
{
        object ob;
        int jing, jing_cost;

        ob = this_player();
        jing = ob->query("jing");
        jing_cost = random(ob->query("kar")) * 2 + 10;

        ob->add("jing", -jing_cost);
        if(jing < jing_cost)
         ob->unconcious();
}

int valid_leave(object me, string dir)
{
        if (random(10) > 5)
              me->add_temp("mark/steps",1);
        if (random(10) < 5)
              me->add_temp("mark/steps",-1); 
        
        if (me->query_temp("mark/steps") >= 5){
            me->move(__DIR__"caojing");
            me->delete_temp("mark/steps");
              return notify_fail("������һ������Ȼ��ǰһ��������һ���ݾ���\n");
        }  
        if (me->query_temp("mark/steps") <= 0){
            me->move(__DIR__"niupeng");
            me->delete_temp("mark/steps");
              return notify_fail("���۵ð�����ȴ��Ȼ�������߻���ţ�\n");
        }      
        return ::valid_leave(me, dir);
}
