// tangfeng@SJ 2004

#include <ansi.h>
#include <room.h>

inherit ROOM;
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"

void create()
{
	set("short", "����");
	set("long", @LONG
˭���ϵ�����Ӫ�ؾ������������һ�����ң���֪��ƽʱ�����ô���
LONG
	);
           set("quest",1);
	setup();
}
void init()
{
  object me,obj;
  me = this_player();
  me->start_busy(1);
  if (me->query(QUESTDIR4+"start")
     &&me->query_temp(QUESTDIR4+"kill")
     &&!me->query_temp(QUESTDIR4+"breakmen")
     &&!me->query(QUESTDIR4+"over"))
  {
     obj=new("/d/nanyang/npc/xiaofeng");
     if(!present("xiao feng", environment(me)))
                 obj->move(environment(me));     
     me->set_temp(QUESTDIR4+"breakmen",1);   
  }      
    add_action("do_push", "push");
}

int do_push(string arg)
{
        if( arg == "wall" || arg == "ǽ" || arg == "ǽ��")
        {
        message_vision("$N�ƿ����ǽ���򿪳��ڡ�\n", this_player());
        if( !query("exits/east") ) {
       set("exits/south", __DIR__"zuotang");
        remove_call_out("close_path");
        call_out("close_path", 15);
        }
        return 1;
        }
}
void close_path()
{
        if( !query("exits/east") ) return;
        message("vision","һ��ᣬ�̵�һ����ǽ�ָֻ�ԭ����\n", this_object() );
        delete("exits/east");
}
