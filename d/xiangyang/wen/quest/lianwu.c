//by daidai

inherit ROOM;
#include <ansi.h>
#define QUESTJINSHE "quest/���߽���/"

void create()
{
        set("short",HIG "���䳡" NOR);
        set("long", @LONG
�����¼ұ������䳡��һ��յ����ĳ��ء�
LONG);
        set("exits", ([ 
          "out" : "/d/xiangyang/wen/damen",

]));
            set("quest",1);
        setup();
}
void init()
{
  object me,wen1, wen2, wen3, wen4, wen5;
  me = this_player();
  if (me->query_temp(QUESTJINSHE+"start_kill")
         && !me->query_condition("killer")
         && !me->query(QUESTJINSHE+"pass")
         && !me->query(QUESTJINSHE+"over"))
  {
   
     wen1=new(__DIR__"npc/wenfangshan");
     wen1->set("kill_id",me->query("id"));
     wen1->move(environment(me));      
     wen2=new(__DIR__"npc/wenfangwu");
     wen2->set("kill_id",me->query("id"));
     wen2->move(environment(me));        
     wen3=new(__DIR__"npc/wenfangshi");
     wen3->set("kill_id",me->query("id"));
     wen3->move(environment(me));    
     wen4=new(__DIR__"npc/wenfangda");
     wen4->set("kill_id",me->query("id"));
     wen4->move(environment(me));    
     wen5=new(__DIR__"npc/wenfangyi");
     wen5->set("kill_id",me->query("id"));
     wen5->move(environment(me));    
     remove_call_out("killme");
     call_out("killme", 3, me);        
    }      
}
void killme(object me)
{
      if(!me) return;

  if (me->query_temp(QUESTJINSHE+"start_kill")
                 &&!me->query_condition("killer")
                  &&!me->query_temp(QUESTJINSHE+"over") )//����һ����ǣ�ԭ�����е����ˣ�
   
  {

  }  
}
int valid_leave(object me, string dir)
{
       if (me->is_fighting())
                return notify_fail(RED"\n�¼����ϴ����ȵ��������ߡ�һ����ס�㣬�㾹Ȼ�޷��뿪��\n"NOR);
       if (present("heiyi ren",this_object()))
                return notify_fail(RED"\n�¼����ϴ����ȵ��������ߡ�һ����ס�㣬�㾹Ȼ�޷��뿪��\n"NOR);
                if(me->query_condition("killer")) 
                          return notify_fail(RED"\n��ô�����ģ��������wiz�ɡ�\n"NOR);
           if ( me->query_temp(QUESTJINSHE+"kill")
               && me->query_temp(QUESTJINSHE+"have_kill")){
              me->delete_temp(QUESTJINSHE+"start_kill");
              me->delete_temp(QUESTJINSHE+"kill"); 
              me->delete_temp(QUESTJINSHE+"have_kill");              
    
              }
        return ::valid_leave(me, dir);
}


