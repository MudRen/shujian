#include <ansi.h>
inherit ROOM;

int do_pi(string arg);



void create()
{
    set("short", "�˵�");
       set("long", @LONG
һ�������͵Ĳ˵أ����˲����߲ˣ�������׳�ɳ�����
�ڲ�����ʳ����˾���ɮ���ǾͲ���õ�ʳ���ˡ��˵ر���
��һ����أ�������ֻ��Ͱ��
LONG
       );
       
       set("exits", ([
       "east"      : __DIR__"gchangw",
]) );
    //   set("no_fight",1);
       set("outdoors","����");
             set("objects", ([
                "/d/shaolin/npc/yuan-gen.c" : 1,
       ]));

       set("coor/x",30);
  set("coor/y",200);
   set("coor/z",110);
   setup();

}

void init()
{
        add_action("do_jiao", "jiao");
        add_action("do_jiao", "��");

        
}
int do_jiao(string arg)
{   
 object me;
        int costj, costq,times;
        me = this_player();
        if (me->is_busy())
         {write("��������æ����!\n");return 1;}
        if (me->is_fighting())
         {write("������ս����,�޷�ר�ĸɻ�!\n");return 1;}
        if ( !arg || arg != "��" )
            {    message_vision("$NҪ��ʲô��\n",me);
                 return 1;
             }
        costj = random((int)me->query("con")/3);
        costq = random((int)me->query("str")/3);

        times=20+random(50);
        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq)
       {
        message_vision("$N����һ�������������\n",me);
        me->unconcious();
        return 1;
        }
        
        me->receive_damage("jingli", costj);
        me->add("qi", -costq);       
        if (((int)me->query_temp("mark/��")>times)&&(present("yuangen", environment(me))))
           {
              me->set_temp("mark/����",1);
               return notify_fail(RED "Ե��˵��������ģ���ξ��������´��ٽ�ѵ�㣬����ȥ������(task ok)!!!"NOR);
            }  
        message_vision("$N�����Ͱ�˾���Ͱ�еĳ�����ȵ�����ÿ����ߵĸ��������ѽ��\n", me);
        me->add_temp("mark/��",1);
        
       if ( (int)me->query_skill("staff", 1) < 20 && random(10)>6 )
                {  write(HIM"���ڽ����ж����ȵ��÷���Щ���!\n"NOR);
                   me->improve_skill("staff", (int)(me->query_skill("buddhism",1) / 5));
                }
          return 1;

}
