// Room: /d/huashan/yanshi.c
// by daidai 

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIG"��ʯ"NOR);
        set("long", @LONG
���ǻ�ɽɽ����һ��޴���ʯ�Ķ������������ܸߣ�վ�ڴ˴����Կ���
��Զ�ĵط�����Χ����������û������ʱ������һ��ӥ����
LONG    );
        set("exits", ([ 
        "down" :   __DIR__"shentan"
        ]));
        set("outdoors", "��ɽ");
        set("no_fight", 1);
        set("coor/x",30);
  set("coor/y",70);
   set("coor/z",-10);
   setup();
}

void init()
{
     object me = this_player();
       
        if(me->query_temp("quest/��ɽ��/ӥ��������/start2")){       
          me->start_busy(5);
          write(HIC"\n�����²t����ͻȻ����Զ��ɽ�����̾���һ���޴�����ߣ���ͷ�������ϣ�\n"NOR);
          write(HIC"�������²������������졣��̧ͷ�����������һͷ��ӥ�������¡�\n"NOR);
          call_out("do_wait", 4, me);
          } else 
          {   write(HIY"ͻȻһ�����������վ�����ȵ�������ʯ��\n"NOR);  
              me->move("/d/huashan/shentan"); // ����Ī�� by daidai
          }                           
}
void do_wait()
{
        object me = this_player();
         if(environment(me) && me->query_temp("quest/��ɽ��/ӥ��������/start2")){
      if(me->query_temp("quest/��ɽ��/ӥ��������/thinking")<(5+random(5))){
           me->start_busy(5);
          if(random(2)) {
          write(HIW"\n�㿴���Ǿ�ӥ�ڰ��������ͻȻ���һ��������£�ӥצ�����ץ�����ߣ������ޱȡ�\n"NOR);
     if ( random((int)me->query("kar")) > 18) {
          write(HIG"\n������һ�����ƺ������������в��Ծ��ĳ�ӥצ֮״�Ȼ��˼��¡�\n"NOR);
             me->add_temp("quest/��ɽ��/ӥ��������/mingwu", 1);
               }
       } else {
          write(HIC"\n�㿴���Ǿ������������ͷҡ�ڲ�������ʱ���������صĵ�ˮ��©���ְ��ط���֮�ࡣ\n"NOR);
     if ( random((int)me->query("kar")) > 18) {
          write(HIG"\n������һ�����ƺ������������ֲ��Ծ��ľ�ָ������֮�ˣ��Ȼ��˼��¡�\n"NOR);
             me->add_temp("quest/��ɽ��/ӥ��������/mingwu", 1);
               }
      }
             me->add_temp("quest/��ɽ��/ӥ��������/thinking", 1);
                call_out("do_wait", 4+random(2), me);
  }
   else {
          write(HIW"\n��ۿ���Զ��ӥ��������������Լ�������򣬵���������׽�����ƺ���һ�㱡������ǰ��\n"NOR);
          write(HIW"��е�ֻҪ������㱡��������ѧ�����ض���������½���üͷ���˼����\n"NOR);
             me->delete_temp("quest/��ɽ��/ӥ��������/thinking");
          call_out("do_wait2", 4, me);     
          }
    }
}
void do_wait2()
{
        object me = this_player();
        int i,l,j;
        i= me->query("quest/��ɽ��/ӥ��������/fail");
        l=500+random(300);
        j=10+random(20); 
         if(environment(me) && me->query_temp("quest/��ɽ��/ӥ��������/start2")
           && me->query_temp("quest/��ɽ��/ӥ��������/mingwu")+random((int)me->query("kar")) > 23){
           me->start_busy(2);
          write(HIG"\n������һ����վ��������˫��ģ��ӥ���භ֮�˱Ȼ��š���˫���趯�������ҽ��ɹ��ɣ���Լ\n"NOR);
          write(HIG"�γ���һЩ��ª����ʽ����Ȼ�һ�󣬸о��Լ���Ϊ��Ϊ����������ʱ�վͿ�ƾ������������\n"NOR);
          write(HIG"һ�ž���ľ�ѧ������������������ѧ�б�����Լ����а�����\n"NOR); 
          me->set("quest/��ɽ��/ӥ��������/over",1);
          me->delete_temp("quest/��ɽ��/ӥ��������/start2");
          me->add("combat_exp", l);
          me->add("max_neili", j); 
 tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"�ۿ�ӥ���භ�����ĵã���ѧ��Ϊ���������"+l+"�㾭�齱����"+j+"�����������\n"NOR);
 log_file("quest/hsys", sprintf("%s(%s) ʧ��%d�κ�ۿ�ӥ���භ�����ĵã���ѧ��Ϊ������������%d�㾭�飬%d�����������\n", me->name(1),me->query("id"), i,l,j ) );
     
          }
         else {
          write(HIR"\n���˼ڤ�룬��Ȼ�����ջ�ֻ�ó�̾һ��վ��������\n"NOR);
          me->delete_temp("quest/��ɽ��/ӥ��������/start2");
          me->add("quest/��ɽ��/ӥ��������/fail",1);
     log_file("quest/hsys", sprintf("%s(%s) ��%d�ιۿ�ӥ���භһ������\n", me->name(1),me->query("id"), i));
}
             me->delete_temp("quest/��ɽ��/ӥ��������/mingwu");
}
