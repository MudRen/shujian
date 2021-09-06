//tangfeng@SJ 2004
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @long
��������Ժ��Ӫ���ڶ����;��²�����������еģ��������ĺ�
�ĵش������ر����ء�
long);
	set("exits", ([
                "east" : __DIR__"zhongying",
	]));
   set("outdoors", "����");
   set("quest",1);
   setup();
}
void init()
{
  object me,obj1,obj2;
  me = this_player();
 if(me->query_condition("killer"))
  {
   message_vision(HIC"\nͻȻ$N�ƺ���Ѫ��Щ��˳������һ����������ȥ��\n"NOR,me); 
   tell_object(me,HIR"��ͻȻ�е�һ�������������㣬˲����ʧȥ֪����\n"NOR);
   tell_room(environment(me),HIR"\nֻ��������ͻȻ����һ���Ѷ���"+ me->name()+ "һͷ������ȥ��˲����ʧ��\n"NOR, ({  }));
   me->move(__DIR__"shanlu1"); 
   tell_room(environment(me), HIR"\n����У��ƺ�һ���˵����������㶨��һ����Ȼ��"+ me->name()+ "��\n"NOR, ({  }));
   me->unconcious();
   return;
  }
  if(!me->query("quest/�����˲�/���ɾ�Ԯƪ/start")) return;
   if(me->query("quest/�����˲�/���ɾ�Ԯƪ/over")) return; 
  if(!me->query_temp("quest/�����˲�/���ɾ�Ԯƪ/godaliao")) return; 
 
  obj1=new(__DIR__"npc/liaobing");
  obj1->set("teamleader",1);
  obj1->set("fight_id",me->query("id"));
  obj1->move(environment(me)); 
  if(obj1->query_skill("wuxing-zhen")<200)
     obj1->set_skill("wuxing-zhen",200);
  obj1->command("lineup form wuxing-zhen");

  obj2=new(__DIR__"npc/liaobing");
  obj2->set("party","sl");
  obj2->set("fight_id",me->query("id"));
  obj2->move(environment(me)); 
  if(obj2->query_skill("wuxing-zhen")<200)
     obj2->set_skill("wuxing-zhen",200);
  obj1->command("lineup with "+obj2->query("id"));
  obj2->command("lineup with "+obj1->query("id"));  
  add_action("do_push","push");

}

int do_push(string arg)
{
  object me,obj;
  int skill;
  me = this_player();
  skill = me->query_skill("force");
  if ( arg != "anshi" && arg != "anmen" ) return 0;
  if (me->is_fighting())return 0;
  if (skill<100)
  {
	  message_vision("$N����һ���������������ư��ң�������Ȼ��˿��������������Ҫ���������С�\n", me);
	  return 1;
  }
  if(!me->query_temp("quest/�����˲�/���ɾ�Ԯƪ/dianhuo"))
  {
	  obj=new(__DIR__"npc/liaobing");
	  obj->set("teamleader",1);
	  obj->set("fight_id",me->query("id"));
	  obj->move(environment(me)); 
	  tell_object(me,HIR"\n����֮�⣬��Ӫ�ױ�������Χ�����Ҫ�ƿ����ң�����������һ���ɱ���\n"NOR);
	  return 1;
  }
  if(present("liao bing",this_object()))
  {
	  tell_object(me,HIR"\n�����Ƚ���ɱ����������ⰵ�ҡ�\n"NOR);
	  return 1;
  }
  if( !query("exits/west") ) {
 	   message_vision("$N����һ���������������ư��ң���Ȼ��һ��ͨ���ҵ�ͨ����\n", me);
	   log_file("quest/TLBB", sprintf("%s(%s)�ҵ����ң��ش˼�¼�����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) ); 
     set("exits/west", __DIR__"anshi");
     remove_call_out("close_path");
     call_out("close_path", 15);
  }	
  return 1;
}	
void close_path()
{
        if(!query("exits/west")) return;
        message("vision","һ��ᣬ�̵�һ����ǽ�ָֻ�ԭ����\n", this_object() );
        delete("exits/west");      
}

int valid_leave(object me, string dir)
{
  if(present("liao bing",environment(me)))  return notify_fail("�ɱ�һ�ѽ�����ס�������ܣ�\n" );
  return ::valid_leave(me, dir);
}
