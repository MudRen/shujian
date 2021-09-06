// by tangfeng 8/2004

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "�ܶ�");
        set("long", @LONG
��������ޱȣ������Ѳ⡣��һ�߽������㷢�����в涴�����Թ�������
Ī�⣬�ƺ�����޵ס�
LONG);
        set("exits", ([
                "east" : __FILE__,
                "south" : __FILE__,
                "west" : __FILE__,
                "north" : __FILE__,
        ]));
   set("quest", 1);
   set("baozang",1);
   setup();

}
void init()
{
   add_action("do_use", "use");
}
int do_use(string arg)
{
   object ob, me;
   me = this_player();
   if(!living(me) ) return 0;
   if (me->is_busy() || me->is_fighting())
      return notify_fail("����æ���ģ�\n");
   if(!objectp(ob = present("fire", me)))
      return notify_fail("������û�л��ۡ�\n");
   if( !arg || arg=="" ) return 0;
   if( arg == "fire" ) {
      message_vision(BLU"$N��ȼ���ۣ��Ѷ���������һЩ��΢���Ļ��һ��һ���ġ�\n"NOR, me);
      message_vision(BLU"$N�ƺ������ܶ���һЩ�ŵ���\n"NOR, me);
      me->set_temp("baozang/north_",2+random(8));//��
      me->set_temp("baozang/south_",2+random(8));//��
      me->set_temp("baozang/east_",2+random(8));//��
      me->set_temp("baozang/west_",2+random(8));//��
      tell_object(me,HIY"���ְ�������һ����ԭ����ˣ�����"+chinese_number(me->query_temp("baozang/east_"))+"��������"+chinese_number(me->query_temp("baozang/west_"))
                        +"������"+chinese_number(me->query_temp("baozang/north_"))+"���ϻ�"+chinese_number(me->query_temp("baozang/south_"))+"���ɣ�\n"NOR);
      return 1; 
   }
}
int valid_leave(object me, string dir)
{
        if ( dir == "north")
              if(userp(me)) me->add_temp("baozang/north",1);
        if ( dir == "south")
              if(userp(me)) me->add_temp("baozang/south",1);         
        if ( dir == "east")
              if(userp(me)) me->add_temp("baozang/east",1);
        if ( dir == "west")
              if(userp(me)) me->add_temp("baozang/west",1);         

        if (me->query_temp("baozang/north") >= 13||me->query_temp("baozang/south") >= 13
           ||me->query_temp("baozang/east") >= 13||me->query_temp("baozang/west") >= 13)
        {
         	  message_vision(HIG"$N��ûͷ��Ӭһ���ڶ���Ϲ�꣬���һͷײ�ڶ����ϡ���������κ����ģ��ƺ�ײɵ�ˡ�\n"NOR, me);
            me->delete_temp("baozang/north");
            me->delete_temp("baozang/south");
            me->delete_temp("baozang/east");
            me->delete_temp("baozang/west");
            me->start_busy(1);
            return notify_fail(HIB"��Ծ��ط��֣������ڵ�λ�þ�Ȼ���������λ�á�\n"NOR);
        }  
        if (me->query_temp("baozang/north") == 10 && me->query_temp("baozang/south") == 10
          && me->query_temp("baozang/east") == 10 && me->query_temp("baozang/west") == 10)
        {
         	  message_vision(HIC"$N��ûͷ��Ӭһ���ڶ���Ϲ�꣬���һͷײ�ڶ����ϡ���������κ����ģ��ƺ�ײɵ�ˡ�\n"NOR, me);
            me->delete_temp("baozang/north");
            me->delete_temp("baozang/south");
            me->delete_temp("baozang/east");
            me->delete_temp("baozang/west");
            me->delete_temp("baozang/north_");
            me->delete_temp("baozang/south_");
            me->delete_temp("baozang/east_");
            me->delete_temp("baozang/west_");
            me->move(__DIR__"jinku");
            tell_room(environment(me), me->name()+"�����ߵ��ܶ����˹�����\n", ({ me }));
            return notify_fail(HIB"��Ծ��ط��֣��������߳����ܶ���\n"NOR);
        } 
        if (me->query_temp("baozang/north_") 
            && me->query_temp("baozang/north") == me->query_temp("baozang/north_") 
            && me->query_temp("baozang/south") == me->query_temp("baozang/south_") 
            && me->query_temp("baozang/east") == me->query_temp("baozang/east_") 
            && me->query_temp("baozang/west") == me->query_temp("baozang/west_") )
        {
            me->delete_temp("baozang/north");
            me->delete_temp("baozang/south");
            me->delete_temp("baozang/east");
            me->delete_temp("baozang/west");
            me->delete_temp("baozang/north_");
            me->delete_temp("baozang/south_");
            me->delete_temp("baozang/east_");
            me->delete_temp("baozang/west_");
            me->move(__DIR__"jinku");
            tell_room(environment(me), me->name()+"�����ߵ��ܶ����˹�����\n", ({ me }));
            return notify_fail(HIC"���۵ð���������߳����ܶ���\n"NOR);
        }                          
        return ::valid_leave(me,dir);
}
 
