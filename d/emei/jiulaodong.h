// jiulaodong.h
// ���϶�
#include <ansi.h>
void init()
{
        add_action("do_use", "use");
        add_action("do_leave", "leave");
}

int do_use(string arg)
{
    object room, ob, me;
   me = this_player();
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");

        if(!objectp(ob = present("fire", me)))
        return notify_fail("������û�л��ۣ���ô�ܽ�����ɽ����\n");

	if( !arg || arg=="" ) return 0;

	if( arg == "fire" ) {
        message_vision(BLU"$N��ȼ���ۣ��Ѷ���������һЩ��
��������һЩ��΢���Ļ��һ��һ���ġ�\n"NOR, me);
        destruct(ob);
        if(!(room = find_object(__DIR__"jiulaodong1")))
            room = load_object(__DIR__"jiulaodong1");
            set("exits/north", __DIR__"jiulaodong1");
            set("exits/south", __DIR__"jiulaodong1");
            set("exits/west", __DIR__"jiulaodong1");
            set("exits/east", __DIR__"jiulaodong1");
            set("exits/southwest", __DIR__"jiulaodong1");
            set("exits/southeast", __DIR__"jiulaodong1");
            set("exits/northwest", __DIR__"jiulaodong1");
            set("exits/northeast", __DIR__"jiulaodong1");
            call_out("delete_exit", 4, room); 	
            return 1; }
}
void delete_exit(object room)
{       
        delete("exits/south");
        delete("exits/north");
        delete("exits/west");
        delete("exits/east");
        delete("exits/northwest");
        delete("exits/northeast");
        delete("exits/southwest");
        delete("exits/southeast");
}

int do_leave()
{
        object me = this_player();

        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");
        
        if(present("fire", me) )
        return notify_fail("�����ﻹ�л��ۣ�Ϊʲô����������·��\n");

        if(!present("fire", me) ){
        if(random(30) >= 20) {
        write("��ת��תȥ������ת���˶��ڡ�\n", me);
        me->move(__DIR__"dongkou");
        message_vision("$N�Ӿ���ͭ�����˳�����\n", me);
	return 1;
        }
        else {
        message_vision("$N��ûͷ��Ӭһ���ڶ���Ϲ�꣬���һͷײ�ڶ����ϡ�
��������κ����ģ��ƺ�ײɵ�ˡ�\n", me);
        me->move(__DIR__"jiulaodong1");
        me->receive_damage("jingli", 20);
        me->delete_temp("marks/east");
        me->delete_temp("marks/west");
        me->delete_temp("marks/north");
        me->delete_temp("marks/south");
        me->delete_temp("marks/northwest");
        me->delete_temp("marks/northeast");
        me->delete_temp("marks/southwest");
        me->delete_temp("marks/southeast");
        return 1; }
     }
}

int valid_leave(object me, string dir)
{
	object room;
       if (dir == "north")
          me->add_temp("marks/north",1);
       if (dir == "south")
          me->add_temp("marks/south",1); 
       if (dir == "east")
          me->add_temp("marks/east", 1); 
       if (dir == "west")
          me->add_temp("marks/west", 1); 
       if (dir == "northeast")
          me->add_temp("marks/northeast",1);
       if (dir == "southeast")
          me->add_temp("marks/southeast",1); 
       if (dir == "southwest")
          me->add_temp("marks/southwest", 1); 
       if (dir == "northwest")
          me->add_temp("marks/northwest", 1); 

       if (me->query_temp("marks/east") == 1 && 
           me->query_temp("marks/west") == 1 &&
           me->query_temp("marks/northwest") == 1 &&
           me->query_temp("marks/southwest") == 1 &&
           me->query_temp("marks/north") == 1 &&
           me->query_temp("marks/northeast") == 1 &&
           me->query_temp("marks/south") == 1 &&
           me->query_temp("marks/southeast") == 1) {
       if(!(room = find_object(__DIR__"jiulaodong1")))
           room = load_object(__DIR__"jiulaodong1");
           set("exits/out", __DIR__"shanpo");
        me->delete_temp("marks/east");
        me->delete_temp("marks/west");
        me->delete_temp("marks/north");
        me->delete_temp("marks/south");
        me->delete_temp("marks/northwest");
        me->delete_temp("marks/northeast");
        me->delete_temp("marks/southwest");
        me->delete_temp("marks/southeast");
	call_out("delete_exits_1", 3, room);
	return 1; }
        return ::valid_leave(me,dir);

}
void delete_exits_1(object room)
{       
        delete("exits/out");
}