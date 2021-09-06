#include <ansi.h>

inherit F_SSERVER;
private int remove_effect(object me, int amount);
int perform(object me)
{
        object weapon = me->query_temp("weapon");  
        int skill;
    
        if(!me->is_fighting() )
                return notify_fail("����շ�ħȦ��ֻ����ս����ʹ�á�\n");

        if((int)me->query_skill("yijin-jing", 1) < 150 )
                return notify_fail("����ڹ��ȼ�����������ʹ�á���շ�ħȦ����\n");
    
        if ((int)me->query_skill("riyue-bian", 1) < 150 )
                return notify_fail("������±޷�������죬�����������ӡ���շ�ħȦ����\n");
    
        if (!weapon 
         || weapon->query("skill_type") != "whip"
         || me->query_skill_mapped("whip") != "riyue-bian")
                return notify_fail("�������޷�ʹ�á���շ�ħȦ������߷�������\n");
    
        if ((int)me->query("neili") < 500 )
                return notify_fail("����������̫��������ʹ�á���շ�ħȦ����\n");

        if ((int)me->query("jingli") < 500 )
                return notify_fail("�����ھ���̫�٣�����ʹ�á���շ�ħȦ����\n");

        if ((int)me->query_temp("ryb_yue"))
                return notify_fail("������ʹ�á�������ޡ�������\n"); 

        if( me->query_temp("fumo"))
                return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
    
        if ( (int)me->query_temp("ryb_fumo") ) 
                return notify_fail("������ʹ�á���շ�ħȦ����\n");

      if( me->query_temp("fanzhen")   )
                return notify_fail("���������á���ղ������񹦡���\n");
    
        if (me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("����ڹ������޷�ʹ�á���շ�ħȦ����\n");

        message_vision(HIG "$N��ʱһ���ߺȣ����������Ѫ��ɮ�۶���������������"+weapon->name()+HIG"����ת���������ն̣�\n"+
                           "�����൱���ܡ�"+weapon->name()+HIG"����������������ƻã����۵�����ô�������������Ǳ����˳�ȥ��\n"NOR, me); 
        me->start_busy(1);
        me->start_perform(1,"����շ�ħȦ��");
        me->add("neili", -200);          
        me->add("jingli", -100);
    
        skill = me->query_skill("riyue-bian", 1)/4;
        me->add_temp("apply/armor",  skill*4);
        me->add_temp("apply/parry",  skill*3);
        me->add_temp("apply/dodge",  skill*3);

        me->add_temp("apply/strength",  skill/5);
        me->set_temp("ryb_fumo", 1);

        me->start_call_out( (: call_other, __FILE__, "check_fight", me, skill, weapon :), 1);
        return 1;
}

void check_fight(object me, int amount, object weapon)
{  
        object wep;

        if (!me) return;
        wep = me->query_temp("weapon");  
        if(!me->is_fighting()
         || !living(me)
         || me->is_ghost()
         || !wep
         || weapon != wep )
           remove_effect(me, amount);
        else call_out("check_fight", 1, me, amount, weapon);
}

private int remove_effect(object me, int amount)
{         
        int skill;
        skill = me->query_skill("riyue-bian", 1)/4;
 
        me->add_temp("apply/strength",-skill/5);
        me->add_temp("apply/parry", -skill*3);

        me->add_temp("apply/dodge", -skill*3);
        me->add_temp("apply/armor",  -skill*4);
        me->delete_temp("ryb_fumo");
        if(living(me) && !me->is_ghost())
           message_vision(GRN"���ã�$N��ʹ��շ�ħȦ����������ƽϢ��һ���ָֻ���ԭ״��\n"NOR, me);
        return 0;
}
string perform_name(){ return HIG"��շ�ħȦ"NOR; }
