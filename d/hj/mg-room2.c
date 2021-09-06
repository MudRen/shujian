// mg-room2.c �Թ�����
#include <ansi.h>
#include <command.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", CYN "�Թ�����" NOR);                      
        set("long", "��һ�������й����Ǻ�����������д���ǡ�"HIY"�����ʥ��ʦ����λ"NOR"������
����һ�����ˣ����Ҹ�����ʮ�ˣ��ֱ�д�����ջء�������·�������ӹ�����
�����ġ��������š������֡����������������˽�����\n");

        set("no_sleep_room", 1);
        set("exits", ([
              "south" : __DIR__"mg-room1",                     
        ]));

        setup(); 
        set("tie_count", 1);
}

void init()
{
       this_player()->set_temp("ketou_times", 50);
       add_action("do_ketou", "ketou");
}

int do_ketou()
{
       int i;
       object me, ob, *inv;
       me = this_player();
       if(!userp(me) || me->is_busy() || me->is_fighting()) return notify_fail("����æ���أ�\n");               
       if(random(me->query_temp("ketou_times")) == 0 ) {
         me->set_temp("ketou_times", 50);
         message_vision(BLU"ͻȻһ�Ű�ɫ���´Ӻڰ���Ѹ���쳣�ĳ������嵽��$NԼĪһ��֮�����͵�\n"+
                           "ֱ������������ȥ��ϡ�Ǹ����Σ����ӳ���£�ֻ������������ɫ���ۣ�\n"+
                           "����������Ѫ��������Ҳ��Ѫ�����죬���θߴ�֮�������ٱȳ��˸�����ߡ�\n"+
                           "��ҹ�������ֲ��ޱȡ��ǹ�ֶ�Ȼ��˫��ǰ�죬ʮ��ָ�ױ���ָ����������\n"+
                           "Ҳ������Ѫ��\n"NOR, me);
         message_vision(HIB"�ǹ�������Ц�����������������Թ�����ס��һǧ�꣬����˭�����ţ�\n"+
                           "˭�����������󵨣����ǹ������ת��˫�ֶ���$N���е���������������\n"NOR, me);
         me->start_busy(2);
         if(random(20)>18){
            tell_object(me, HIR "��о���֫һ�飬���ã�\n" NOR );
            tell_room(environment(me), HIR +"ֻ��"+me->name()+"˫ϥ�򵹣�Ȼ����°�Į���������ˣ�\n" NOR, ({ me }));    
              inv = all_inventory(me);
            for (i = 0; i < sizeof(inv); i++)
               DROP_CMD->do_drop(me, inv[i]);
            me->unconcious();
            message_vision("�������ֻع�������ץ��$N���۶�ȥ��Ƭ�̼��ߵ���Ӱ���٣�\n", me);            
            me->move(__DIR__"shulin1");
            return 1;
         }
         tell_object(me, HIR"������һ�����������Ծ����Զ��\n" NOR );
         message_vision(CYN"�������ֻع����������۶�ȥ��Ƭ�̼��ߵ���Ӱ���٣�\n"NOR, me);            
       }
       me->add_temp("ketou_times", -1);        
       message_vision("$N���������ڿ�����ǰ����һ��ͷ��\n", me);
       if(random(160-(int)me->query_temp("ketou_times")) == 30 
        && !present("kuaixueshiqing tie", me)
        && query("tie_count") >= 1){
          add("tie_count", -1);
          ob = unew(__DIR__"obj/tie");
          if (!clonep(ob)){
             ob = new("/clone/money/coin")->move(environment(me));
             message_vision("\nͻȻž��һ������һöͭǮ������$N����ǰ��\n\n", me);
             return 1;
          }
          if( clonep(ob) && ob->violate_unique()){
             destruct(ob);
             ob = new("/clone/money/coin")->move(environment(me));
             message_vision("\nͻȻž��һ������һöͭǮ������$N����ǰ��\n\n", me);
             return 1;
          }           
          ob->move(environment(me));
          message_vision("\nͻȻž��һ������һ��ֽ������$N����ǰ��\n\n", me);
       }       
       return 1;
}

int valid_leave(object me, string dir)
{
      me->delete_temp("ketou_times");
      return ::valid_leave( me,dir);
} 

int clean_up()
{
        return 0;
}

int count = 40;
void reset()
{
    if (--count == 0) {count = 40; set("tie_count", 1); ::reset();}
}
