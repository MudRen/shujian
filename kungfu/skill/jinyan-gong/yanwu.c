// Modified by action@SJ 2008/09/15

#include <ansi.h>

inherit F_SSERVER;
void remove_effect(object me, int count);
string perform_name() {return HIR"ӥ"HIC"��"HIW"��"HIM"��"NOR;}
int perform(object me, object target)
{
        string msg;
        int i;
        
        if (! me->is_fighting())
                return notify_fail("��ֻ����ս����ʹ�á�ӥ�����衹��\n");

        if ((int)me->query_skill("xiantian-gong", 1) < 100)
                return notify_fail("������칦���������ʹ������ӥ�����衹��\n");  

        if ((int)me->query_skill("jinyan-gong", 1) < 100)
                return notify_fail("��Ľ��㹦���������ʹ������ӥ�����衹��\n");  

        if ((int)me->query("jing", 1) < 500)
                return notify_fail("�����ھ�������\n");

        if ((int)me->query("neili", 1) < 500)
                return notify_fail("����������������\n");

        if (me->query_temp("quanzhen/parry"))
                return notify_fail("������ʹ�á�ӥ�����衹��\n");

        msg = HIC "�㳤Хһ��������Ȼ�ӿ죬����ӥ�����ա�����Ⱥ����裬�����ۻ����ң�ɷ�Ǻÿ���\n\n" NOR; 

        me->add("neili", -200 + random(100));
        me->recieve_damage("jing", 50);
        
        tell_object(me,msg);
        
        i = me->query_skill("xiantian-gong", 1) / 6;

        me->add_temp("apply/dodge", i);
        me->add_temp("apply/parry", i);
        me->set_temp("quanzhen/parry", i);
        
    //    remove_call_out("remove_effect");
        call_out("remove_effect", 1, me, (int)me->query_skill("force",1) / 3);
        return 1;
}

void remove_effect(object me, int count)
{
	   int i;
	   if(!me) return;
     if ( objectp(me) && me->query_temp("quanzhen/parry") ) {
     	 if(count-->0) {
           call_out("remove_effect", 1, me, count);
                      return;
                                     }
        i = me->query_temp("quanzhen/parry",1);
         me->add_temp("apply/dodge", -i);
         me->add_temp("apply/parry", -i);
         me->delete_temp("quanzhen/parry");
       tell_object(me, HIC "�����ν�ͣ������һ�������ջ��ˡ�ӥ�����衹�Ṧ������\n" NOR);
            return;
       }
}


