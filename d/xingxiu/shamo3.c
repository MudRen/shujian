// /d/xingxiu/shamo1.c
// Jay 3/17/96
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","��ɳĮ");
       set("long", @LONG
����һƬһ���޼ʵĴ�ɳĮ����һ��������ʧ�˷���
����Ҫ�߳����ɳĮ�������¡�
LONG);
        set("outdoors", "shamo");
        set("exits", ([
                "east" : __DIR__"shamo"+(1+random(4)),
                "west" : __DIR__"shamo"+(1+random(4)),
                "south" : __DIR__"shamo"+(1+random(4)),
                "north" : __DIR__"shamo"+(1+random(4)),
        ]));             
        set("coor/x",-310);
  set("coor/y",110);
   set("coor/z",0);
   set("coor/x",-310);
  set("coor/y",110);
   set("coor/z",0);
   set("coor/x",-310);
 set("coor/y",110);
   set("coor/z",0);
   setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "west") me->add_temp("mark/steps",1);
        if ( dir == "east") me->add_temp("mark/steps",-1);

     if (me->query_temp("mark/steps") == 5){
         me->move("/d/hj/caoyuan");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"�Ӷ��ߵĴ�ɳĮ���˹�����\n", ({ me }));
         return notify_fail("���۵ð���������߳���ɳĮ��\n");
         }  
     if (me->query_temp("mark/steps") == -5){  
         me->move(__DIR__"silk9");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"�����ߵĴ�ɳĮ���˹�����\n", ({ me }));
         return notify_fail("���۵ð���������߳���ɳĮ��\n");
         }
        return ::valid_leave(me,dir);
}
