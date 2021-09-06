//tangfeng@SJ 2004
//������̨�Ĺ���
// /d/shaolin/shifang_copy.c
// �����������һս��û������Σ�գ����ѶȺܴ�

#include <ansi.h>
inherit ROOM;
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"

void create()
{
    set("short", BLU"ʯ��"NOR);
    set("long", 
"һ���޴���Ʒ��������Ƭɽ��֮�䣬�Ʒ����Ϸ�������������Ľ��֣�\n"
"\n\t\t\t��"HIY"���µ�һ��ɲ"NOR"��\n\n"+
"�ּ���Щ���䣬����ȥ�����Ϊ��Զ�ˡ�ǰ����һƫ�ܴ�Ĺ㳡��վ����ǰ��\n"+
"�������ͺ�һЩ�����ϵĺ�ʿ�������������µ�ɽ�ŵ�ʹ����ڹ㳡����\n"+
"һ�ࡣ\n"
    );

	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"shijie11",
	]));

	set("outdoors", "shaolin");
  set("no_death", 1);
  set("no_get_from", 1); 
  set("no_sleep_room", 1);
  setup();
}
void init()
{
	object me,ob,obj;
	me = this_player();
	ob = this_object();
	if (!userp(me)) return;
  if(!me->query(QUESTDIR3+"bad") || !me->query_temp(QUESTDIR5+"zhangxing")||me->query_temp(QUESTDIR5+"zhenfa")||ob->query("busy"))
  {
   if(wizardp(me)) tell_object(me,HIR"���ԡ�\n");
  	me->move("/d/shaolin/shifang");
    return;
  }
  if(!present("xiao feng",ob))
  {
  	obj=new("/d/shaolin/npc/tlbb_npc");
  	obj->set("party","gb");
  	obj->set("fight_id",me->query("id"));
  	obj->move(ob);
  	obj->kill_ob(me);
  }
  if(!present("wuming laoseng",ob))
  {
  	obj=new("/d/shaolin/npc/tlbb_npc");
  	obj->set("party","sl");
  	obj->set("fight_id",me->query("id"));
  	obj->move(ob);
  	obj->kill_ob(me);
  }
  ob->set("busy",me->query("id"));
  remove_call_out("check");
  remove_call_out("busy_pass");
  call_out("busy_pass",600); 
  call_out("check",1,me);
}

void pass_busy()
{
	object me,ob = this_object();
  if(ob->query("busy"))
  {
	  if(userp(me = present(ob->query("busy"),ob)) ) 
	  {
       if(!me->query(QUESTDIR3+"bad") || !me->query_temp(QUESTDIR5+"zhangxing"))
       {
  	     me->move("/d/shaolin/shifang");
         return;
       }      
	  }
             ob->delete("busy");
	}
	return;
}
void check(object me)
{
        object ob;
	if(!me || !living(me)||!present(me,this_object())||me->query("qi")<=1||me->query("jing")<=1)  
	{
		remove_call_out("check");
		if((ob=present("xiao feng",this_object())))
		{
	  	 message_vision(HIW"\n$N��Цһ����һ���߰�����̬��������˭��С��ؤ���������\n"NOR, ob);
       destruct(ob);
    }
		if((ob=present("wuming laoseng",this_object())))
		{
	  	 message_vision(HIW"\n$N�����ص�������š�\n"NOR, ob);
       destruct(ob);
    }
    if(userp(me))
    { 
    	if(present(me,this_object()))
    	{
       	me->remove_all_killer();   	
    		me->reincarnate();
	  	  message_vision(HIW"\nͻȻһ�����������$N��$N�ľ�����Ȼȫ���ָ��ˣ�\n"NOR, me);
        me->move("/d/shaolin/shifang");
    		tell_object(me,HIR"\n���ǹԹԴ�������Ǳ�޷����ˣ�\n"NOR);
    		message_vision("$N����ææ��������"+environment(me)->query("short")+"��\n", me);
    	}
   	  me->delete_temp(QUESTDIR5+"zhenfa");
      log_file("quest/TLBB", sprintf("%s(%s)�����������һսʧ�ܡ����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );                  
    }
   	remove_call_out("busy_pass");
    this_object()->delete("busy");
	  return;
	}
	if (!present("xiao feng",this_object())&&!present("wuming laoseng",this_object()))
	{
		  remove_call_out("check");
		  me->remove_all_killer(); 

    	me->reincarnate();
	  	message_vision(HIW"\nͻȻһ�����������$N��$N�ľ�����Ȼȫ���ָ��ˣ�\n\n"NOR, me);
		me->move("/d/shaolin/shifang");
		message_vision("$N����ææ��������"+environment(me)->query("short")+"��\n", me);
		me->set_temp(QUESTDIR5+"zhenfa",1);
		this_object()->delete("busy");
		log_file("quest/TLBB", sprintf("%s(%s)�����������һս�ɹ������飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );                  
    	return;
	}
  call_out("check",1,me);
}
int valid_leave(object me, string dir)
{
   return notify_fail(HIR"���޷��뿪���\n"NOR);
}
