// sl3.c
// Modify By River 98/09
inherit ROOM;
#include <ansi.h>
void create()
{ 
       set("short",HIB"����"NOR);
       set("long", @LONG
����������ľ���ڱ��˴󲿷��չ⣬���ϻ��˺�����Ҷ��ľ����֮��
��С�����ʬ�壬������͸�����������ơ����������ţ�����ʧ�˵�·��
LONG
     );
    
        set("exits", ([
                "east" : __FILE__,
                "west" : __FILE__,
                "south" : __DIR__"sl1",
                "north" : __DIR__"sl2",
        ]));
        set("outdoors","��Ĺ");
        set("coor/x",10);
  set("coor/y",-20);
   set("coor/z",60);
   setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "east")
            me->add_temp("mark/steps",1);
        if ( dir == "west")
            me->add_temp("mark/steps",-1);
        if (me->query_temp("mark/steps") == 6){
            me->move(__DIR__"shulin2");
            me->delete_temp("mark/steps");
            return notify_fail("�㾫ƣ����������߳��˺��֡�\n");
        }  
        if (me->query_temp("mark/steps") == -6){  
            me->move(__DIR__"shulin1");
            me->delete_temp("mark/steps");
            return notify_fail("���۵ð�����ȴ���ǻص�ԭ�ء�\n");
        }
        return ::valid_leave(me,dir);
}
