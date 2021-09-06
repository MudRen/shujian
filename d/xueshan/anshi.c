// Room: fatang2.c
// tangfeng@SJ 2004

#include <ansi.h>
#include <room.h>

inherit ROOM;
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"

void create()
{
	set("short", "����");
	set("long", @LONG
˭���ϵ����������ž������������һ�����ң���֪��ƽʱ�����ô���
LONG
	);
	//set("exits", (["south" : __DIR__"fatang2",]));
	setup();
}
void init()
{
  object me,obj;
  me = this_player();
  me->start_busy(1);
  if (me->query(QUESTDIR2+"start")
     &&me->query_temp(QUESTDIR2+"askzhi")
     &&!me->query_temp(QUESTDIR2+"pushdown")
     &&!me->query(QUESTDIR2+"over"))
  {
     obj=new("/d/dali/wuliang/npc/dy");
     if(!present("qingnian nanzi", environment(me)) && !present("duan yu", environment(me)))
		 obj->move(environment(me));     
	 me->set_temp(QUESTDIR2+"pushdown",1);  

    }      
    add_action("do_push", "push");
}

int do_push(string arg)
{
        if( arg == "wall" || arg == "ǽ" || arg == "ǽ��")
        {
        message_vision("$N�ƿ����ǽ���򿪳��ڡ�\n", this_player());
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"fatang2");
        remove_call_out("close_path");
        call_out("close_path", 15);
        }
        return 1;
        }
}
void close_path()
{
        if( !query("exits/south") ) return;
        message("vision","һ��ᣬ�̵�һ����ǽ�ָֻ�ԭ����\n", this_object() );
        delete("exits/south");
}
