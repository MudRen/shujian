// ss5.c By River 98/08
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{ 
       set("short",HIB"ʯ��"NOR);
       set("long", @LONG
�������ǰһ����ǰ��ʯ��͸����һ˿΢���Ĺ⣬������һ˿ϣ��������
��ֻ����ԶԶ������Ų��Ļ������յ����ĸо�ʹ������ֻ�п־壬��������
�¶���������˼�Ȼ������ֻ�ܿ�����ǰ�С�
LONG
     );
    
        set("exits", ([
                "enter" : __DIR__"lingshi",
                "west" : __DIR__"ss4",
        ]));

        setup();
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me,string dir)
{          
       object *inv = deep_inventory(me);
       object *obj;   
       if((int)me->query_skill("yunu-xinjing",1) < 101 && !me->query("gmpass") && dir == "enter")
            return notify_fail(HIR"\t\t��Ĺ�صأ�һ����Ӳ������ڡ�\n"NOR);  
       obj = filter_array(inv,(:get_object:));
       if( sizeof(obj) && dir =="enter")
         return notify_fail (HIR"\t\t��Ĺ�صأ�������������˽��룡\n"NOR);
         return ::valid_leave(me, dir);
}
