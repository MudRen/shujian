#include <ansi.h>

inherit F_SSERVER;
void remove_effect(object me, string id);

string exert_name() {return HIR"����"NOR;}

int exert(object me, object target)
{
        int skill;

        if(!objectp(target) || !living(target)) return notify_fail("��Ҫ������˭��\n"); 
        if(target == me)
                return notify_fail("��Ҫ������˭��\n");              
        if((int)me->query("neili") < 500  ) 
                return notify_fail("�������������\n");
        if((int)target->query_temp("yinfeng/time") > 1) 
                return notify_fail("�Է��Ѿ������ٳ��ܸ���Ĺ����ˡ�\n");
        if((int)me->query_temp("chuangong"))
                return notify_fail("���Ѿ������ô����ˡ�\n");
        if((int)me->query_skill("force") < 150 )
                return notify_fail("����ڹ��ȼ������������ܴ��������ˡ�\n");
        if((int)me->query_skill("shenghuo-shengong", 1) < 100 )
                return notify_fail("���ʥ���񹦵ȼ������������ܴ��������ˡ�\n");
        if((int)me->query("max_neili") < 1500 )
                return notify_fail("�������������ǿ�������ܴ��������ˡ�\n");
        if((int)me->query("neili") < me->query("max_neili")/3 )
                return notify_fail("������������ˣ����ܴ��������ˡ�\n");
        if(me->query("family") && me->query("family/master_name") != "���޼�")
                return notify_fail("�㲻�ǽ����״����ӣ��Դ���һ˵ֻ�ж��ţ�δ���׼�����\n");
        if((int)target->query_skill("shenghuo-shengong", 1) < 130 )
                return notify_fail("�Է���ʥ���񹦵ȼ����������ܽ����������Ĺ�����\n");
        if((int)target->query_temp("yinfeng/"+me->query("id")))
                return notify_fail("�Է������Ѿ����������Ĺ����ˡ�\n");
                
        skill = me->query_skill("force")/3;
        me->receive_damage("neili", me->query("max_neili")/3);
        me->receive_damage("qi", 150);
        me->receive_damage("jing", 150);
        me->receive_damage("jingli", 150);
        message_vision(HIR"\n$N����������$n���Ĵ�Ѩ�ϣ�����"RED"���"HIR"ʱ��ʱ�ԣ�����������$n��\n\n"NOR, me, target);
        target->add_temp("yinfeng/time", 1);
        target->set_temp("yinfeng/"+me->query("id") , 1);
        tell_object(target, YEL+me->name()+"�Ĺ���������������ڣ����ÿ���������ǿ���絶��������\n"NOR);
        call_out("remove_effect", skill, target, me->query("id"));              
        if(userp(me))
            me->start_busy(10);
        else me->start_busy(5);
        return 1;
}

void remove_effect(object me, string id)
{        
	if(!me) return;

        me->add_temp("yinfeng/time", -1);
        me->delete_temp("yinfeng/"+id);
        tell_object(me, YEL"\n�����ڱ��˵Ĺ����Ѿ����꣬���絶�����ָֻ��ˣ�\n"NOR);
}
