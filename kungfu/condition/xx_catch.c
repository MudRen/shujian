//by cool 98.6 for dalijob
// dali_songxin.c
//�ı���caiji@SJ 8/24/2000
#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
      int time;
      time = me->query_temp("xx/catch_time");

        if (duration < 5) tell_object(me, HIY "��ץ���ʱ��쵽�ˣ��Ͻ���ȥ�ѳ��Ӹ������ɣ�\n" NOR);
        if (duration < 1) {

             tell_object(me, HIY "��ʱ���ѵ�������ץ���ӽ�����\n" NOR);
         
              me->delete_temp("xx_zuji",1);
              me->delete_temp("xx_zuji1",1);
              me->clear_condition("xx_catch");
                  return 0;
        }
        if (!duration) return 0;



  if(duration > time/7 && environment(me)->query("short")=="�����" && living(me)
    && duration < time && !me->query_temp("xx_zuji",1) && random(10)>3 &&(interactive(me)))
       {
       tell_object(me, HIY "�������Щ����ƺ���Χ����ʲô���ڣ����˶����ˣ�\n" NOR);
        me->add_busy(1);

       call_out("zuji", 0, me);    
       }

        me->apply_condition("xx_catch", duration - 1);
        return 1;
}


void zuji(object me)
{
          object obj; 
        if (me->query("combat_exp")>100000) {
          obj = new("/d/xingxiu/npc/shashou");
          obj->set("target", me);
          obj->move(environment(me));
          tell_object(me,"����Լ�о�������Χ�˹���....!!! \n");
          me->set_temp("xx_zuji",1);

        if (me->query("combat_exp")>1000000)
         call_out("killer_clone", 2, me);
           } else {

 tell_object(me, RED "��һ���ţ���������͵Ϯ��Զ����������׽�ĳ���С���Ҷ��������һ����ұ���ȥ�ɣ���\n" NOR);

   }
    return;
}
void killer_clone(object me)
{
        object obj;

tell_object(me,"��⣬�ֳ������˸���....!!! \n");
      obj = new("/d/xingxiu/npc/shashou");
obj->set("target", me);
obj->move(environment(me));
return;
}

string query_type(object me)
{
        return "job";
}
