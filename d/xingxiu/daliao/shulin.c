// by tangfeng 8/2004

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��С���֣����ߺܰ��������ƺ���һЩ���������ĺۼ���
LONG);
        set("exits", ([
                "east" : __FILE__,
                "south" : __FILE__,
                "west" : __FILE__,
                "north" : __FILE__,
        ]));
   set("quest", 1);
   setup();

}

int valid_leave(object me, string dir)
{
        if ( dir == "north")
              if(userp(me)) me->add_temp("daliao/north",1);
        if ( dir == "south")
              if(userp(me)) me->add_temp("daliao/south",1);         

        if (me->query_temp("daliao/north") >= 10)
         {
            me->move(__DIR__"shanlu1");
            me->delete_temp("daliao/north");
            me->delete_temp("daliao/south");
            tell_room(environment(me), me->name()+"���ϱߵ��������˹�����\n", ({ me }));
            return notify_fail("���۵ð���������߳������֡�\n");
          }
          
        if (me->query_temp("daliao/south") >= 10)
         {
            me->move("/d/xingxiu/silk3");
            me->delete_temp("daliao/north");
            me->delete_temp("daliao/south");
            tell_room(environment(me), me->name()+"�ӱ��ߵ��������˹�����\n", ({ me }));
            return notify_fail("���۵ð���������߳������֡�\n");
          }
          
        return ::valid_leave(me,dir);
}