// qiaobi.c 
// By River 98.08.28
int get_object(object ob);
inherit ROOM;
#include <ansi.h>
void create()
{
       set("short", HIY"�ͱ�"NOR);
       set("long", @LONG
���ͱڱ���һ����������磬��������ͱ��в����Լ��ʮ���ɴ�����
��һ�������ɼ����Ĵ�ʯ������һ��ƽ̨��ʯ�������̵����֡���Ŀ��������
����ǡ���ڣ���������֡�
LONG
        );

       set("exits", ([ 
           "southdown"  : __DIR__"shanlu8",
       ]));
   
       set("outdoors", "����");

       setup();
}

void init()
{
        add_action("do_look", "kan");
        add_action("do_look", "look");
        add_action("do_mo", "mo");
        add_action("do_cuan", "cuan");              
}

int do_look(string arg)
{
        object me;
        me = this_player();
 
        if(!arg) return 0;
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( me->query_temp("shibi1") >= 1)
        return notify_fail("�㻹û�п�����\n");
        if(arg == "shibi"){
        if( me->query_temp("shibi") >= 10)
           {
            write(HIY"\n����������һ��ͻ���ͱ���ÿ�����߱�����һ����̦����ʮ�Ա�ֱ���ж��ϡ�\n"NOR);            
            me->add_temp("shibi1",1);
            me->start_busy(2);
            return 1;
            }
            message_vision("$N������ʯ����ϸ���о��š�\n", me);                    
            write(HIG"����ʯ�ڲ�ľ��������ͺͺ��ʵ�޿�������֮������֪�������������Ԯ��ȥ��\n"NOR);
            me->add_temp("shibi", 1);
            return 1;
        }             
}         

int do_mo(string arg)
{         
         object me;
         me = this_player();
         
         if (!arg && arg != "qingtai")
             return 0;
         if (me->is_busy() || me->is_fighting())
             return notify_fail("����æ���ģ�\n");
         if (me->query_temp("shibi1"))
          write(HIG"������һ�����ֵ����һ����̦����ȥ��ץ��һ�Ѻ��࣬��Ȼ�Ǹ�СС��Ѩ��\n"NOR);
          me->delete_temp("shibi");
          me->delete_temp("shibi1");
          me->set_temp("shibi2", 1);
          return 1;
}   

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int do_cuan(string arg)
{
          object me= this_player();
          object *inv = deep_inventory(me);
	object *obj;

          if ( !arg ) return 0;
          if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
          if (me->query_temp("shibi2")){
          if ( arg =="up"){
          if (me->query_skill("dodge", 1) < 120 
           && me->query("neili") < 1500)
           return notify_fail(HIM"���һ������������һ�������ܸ����ߣ�����̤�ڵ�һ��С��֮�У���������\n"+
                                 "�����׼�ڶ�����̦���˽�ȥ������ų�������ֻ����ʮ���ɣ���Ȼ�������ӣ�\n"+
                                 "������������������\n"NOR);
          obj = filter_array(inv,(:get_object:));
          if(sizeof(obj)){
          write(HIR"���һ������������һ�������ܸ����ߣ�����̤�ڵ�һ��С��֮�У���������\n"+
                   "�����׼�ڶ�����̦���˽�ȥ������ų�������ֻ����ʮ���ɣ�ͻȻ���ָ���\n"+
                   "���ߣ���Ȼ�۵�������������Ȼһ���Ӹߴ�ˤ�¡�\n"NOR);     
          me->unconcious();
          me->move(__DIR__"qiaobi");
          return 1;
          }
          write(HIG"���һ������������һ�������ܸ����ߣ�����̤�ڵ�һ��С��֮�У���������\n"+
                   "�����׼�ڶ�����̦���˽�ȥ��շת��Ų֮�ʣ�һ����������ƽ̨��\n"NOR); 
          tell_room(environment(me),HIG + me->name() + "���ͱ����˹���Ϣ������������շת��Ų֮�ʣ�һ����������ƽ̨��\n"NOR, ({ me }));
          me->delete_temp("shibi2"); 
          me->move(__DIR__"pingtai");
          me->receive_damage("jingli", 300);
	  me->receive_damage("qi", 300); 
          me->start_busy(2);  
          tell_room(environment(me), me->name() + "���ͱ��´���������\n", ({ me }));  
          return 1; 
         }
      }
}
