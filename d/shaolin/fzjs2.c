#include <ansi.h>
inherit ROOM;
void create()
{
       set("short", "������");
       set("long", @LONG
�����ҳ����࣬����һ����һ���ţ�һ����������ǽ��д�Ŵ���һ
���������֡�һλ��ü��Ŀ�Ļ�����ɮ�������������ϴ�����
LONG
       );

       set("exits", ([
               "south" : __DIR__"fzjs1",
       ]));

       set("objects",([
               CLASS_D("shaolin") + "/xuan-ci" : 1,
       ]));
       setup();
}
void init()
{
        add_action("do_massage", "massage");
        add_action("do_massage", "��Ħ");
}
int do_massage(string arg)
{      
//    mapping fam;
    object me;
        int costj, costq,times;
        me = this_player();
        if(me->query_temp("job_name")!="�������ȷ���") 
            return notify_fail("��ʲô�Ұ��⵱��ĦԺ����! \n");
        if (me->is_busy())
         {write("��������æ����!\n");return 1;}
        if (me->is_fighting())
         {write("������ս����,�޷�ר�ĸɻ�!\n");return 1;}
        if ( !arg || arg != "����" )
            {   
                 message_vision("$NҪ��˭��Ħ��\n",me);
                 return 1;
             }
        costj = random((int)me->query("con")/3);
        costq = random((int)me->query("str")/3);
        times=20+random(50);
        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq)
       {
        message_vision("$N��æ���ң�����һ��ˤ���ڵء�\n",me);
        me->unconcious();
        return 1;
        }
        
        me->receive_damage("jingli", costj);
        me->add("qi", -costq);       
        if (((int)me->query_temp("mark/��Ħ")>times)&&(present("xuanci", environment(me))))
           {
              me->set_temp("mark/��Ħ��",1);
               return notify_fail(RED "���ȷ���˵����лл���������ң����ȥ��Ϣ��(task ok)!!!"NOR);
            }  
        message_vision("$N��ϥ���£�������Ħ����ȫ��������Ū��ˬˬ�ġ�\n", me);
        me->add_temp("mark/��Ħ",1);
        
       if ( (int)me->query_skill("buddhism", 1) < 50 && random(10)>6 )
                {  write(HIM"�㾲�����������о����������ķ���Щ����!\n"NOR);
                   me->improve_skill("buddhism", (int)(me->query_skill("force",1) / 5));
                  }
          return 1;
}
