// Room: /d/huashan/ys_houshan.c
//by daidai 

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ɽ");
        set("long", @LONG
���ǻ�ɽ��ɽ���һ��ɽ�ȣ������Ƕ��͹⻬��ɽ�ڡ��ȵ�������ʪ��
�ƺ����ʺ����ද�����������ʵ��ͱ���ż����������ӥ����
LONG    );      set("outdoors", "��ɽ");
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
          write(HIC"\n���ߵ��˴�ͻȻ����Զ����Լ����һ��ӥ����\n"NOR);
          write(HIC"������һ��������ͣ���������ϸ������\n"NOR);
          call_out("do_wait", 4+random(4), me);
          }                               
}
void do_wait()
{
        object me = this_player();
         if(environment(me) && me->query_temp("quest/��ɽ��/ӥ��������/start2")){
          write(HIW"\nͻȻ���ִ���һ��ӥ��������ϸ�����ƺ��ǴӶ����������ġ�\n"NOR);
          write(HIY"\n�㲻���ӳ٣����϶��������һ����ʯ�����²t����\n"NOR);       
           me->move("/d/huashan/yanshi");      
          }
}
