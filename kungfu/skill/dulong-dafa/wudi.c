// wudi.c 
// by fengyue

#include <ansi.h>
inherit F_CLEAN_UP;

string exert_name() {return HIR"�޵д�"NOR;}

void remove_effect(object me, int amount);
void remove_effect2(object me, int amount);

int exert(object me)
{
        int i;
        string s;

        if((int)me->query_skill("dulong-dafa",1) < 100  )
                return notify_fail("��Ķ����󷨹����������޷�ʩ�á��޵С��󷨡�\n");
        
        if((int)me->query("max_neili") < 500 )
                return notify_fail("��������������޷�ʹ�á��޵С��󷨡�\n");
 
        if((int)me->query("eff_qi") < me->query("max_qi")/3 )
            return notify_fail("���������˹��أ�����ʹ�á��޵С��󷨡�\n");

        if( me->query_temp("sld/wudi") && environment(me)->query("no_death"))
               return notify_fail("û��Ҫ�����ಫ�ɡ�\n");

        if( (int)me->query_temp("sld/wudi2") )
                return notify_fail("���Ѿ�������������Ǳ����\n");

        if((int)me->query("neili") < 400  )
                return notify_fail("��������������޷�ʹ�á��޵С��󷨡�\n");

        i = me->query_skill("dulong-dafa", 1);
      
 //  if( me->query_temp("sld/wudi") && me->query("eff_qi") < me->query("max_qi") && me->query_temp("sld/wudi1") && !me->query_temp("sld/wudi2") )
     
     if( me->query_temp("sld/wudi") && me->query("eff_qi") < me->query("max_qi") && me->query_temp("sld/wudi1") && !me->query_temp("sld/wudi2") )
     
  {
           if( me->is_fighting() )
          {   
                s=RED"\n$N�����Ľе������������ͨ���ӣ��ڵ��������ٱ�����һ���٣��԰ٵ���\n"+
                "�������Ŀ��磬�����ķ����ҵ���ɱ�л��̣�������׼���Σ�����ʥְ��\n"+ 
                "�ҽ̵��ӻ��̶�����ͬ�����ã�����ͻȻ���һ����Ѫ���ƺ��Ѿ���������ʹ��\n\n"NOR;

            //    me->delete_temp("sld/wudi");
                me->add("max_neili", -2); // ����max neili��Ϊ���۵õ��߹�����
                me->add_temp("apply/strength", i/20);
                me->reincarnate();
                me->set("neili", me->query("max_neili")*2);
                me->set("jingli", me->query("eff_jingli")*2);
                me->set_temp("double_attack",1);
                me->add_temp("apply/attack", i/3);
                me->set_temp("sld/wudi2", i);

       call_out("remove_effect2", 1, me, i/5);

                me->start_exert(1,"���޵С�");
                message_vision(s, me);
                return 1;
          }
      return notify_fail("����û��ս�����õ�����ôƴ��ô��\n");

        }
           

 
  if( !me->query_temp("sld/wudi2") && !me->query_temp("sld/wudi") && !me->query_temp("sld/wudi1") )
        {  
                me->add("neili", - 200);
                s=HIR"\n$N�����е������������ͨ����ҽ�ս�޲�ʤ�����޲��ˣ��޼᲻�ݣ��޵в��ƣ�\n"+
                "�����������ң���֮زز������˫��ͻȻð��һ˿��⣬�ƺ�ͻȻ�����˹�����\n\n"NOR;
                 
                 me->add_temp("apply/attack", i/4);
                 me->add_temp("apply/strength", i/20);
                 me->set_temp("sld/wudi", i);
                 me->set_temp("sld/wudi1",i);
                 

           call_out("remove_effect", 1, me, i/3);
          
                me->start_exert(1,"���޵С�");
                message_vision(s, me);
                return 1;
       }

     return notify_fail("�����ڲ���Ҫʹ�á��޵С��󷨡�\n");
}

void remove_effect(object me, int count)
{
        int i;
        if( objectp(me) && me->query_temp("sld/wudi1") ) 
            {
               if( count-- > 0 ) { 
                      call_out("remove_effect", 1, me, count);
                     return;
                                 }
           i = me->query_temp("sld/wudi1");
           me->add_temp("apply/strength", -i/20);
           me->add_temp("apply/attack", -i/4);
           me->delete_temp("sld/wudi");
           me->delete_temp("sld/wudi1"); 
    message_vision(HIR"\n$N����������һ����ͻȻ����������\n\n"NOR,me);
            }
}

void remove_effect2(object me, int count)
{
        int i;
        if( objectp(me) && me->query_temp("sld/wudi2") ) 
            {
               if( count-- > 0 ) { 
                      call_out("remove_effect2", 1, me, count);
                     return;
                                 }
       
        i = me->query_temp("sld/wudi2");
        me->add_temp("apply/strength", -i/20);              
        me->add_temp("apply/attack", -i/3);
        me->delete_temp("double_attack");
        me->delete_temp("sld/wudi2");
        message_vision(RED"\n$N����һ�ɣ���Ҳ֧�ֲ�����\n"NOR,me);   
     // me->unconcious();

          }
}
