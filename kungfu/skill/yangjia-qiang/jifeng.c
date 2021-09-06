//  lihua.c ����ǹ 
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return MAG"����ǹ"NOR;}

private int remove_effect(object me, int amount);

int perform(object me)
{
        object weapon = me->query_temp("weapon");  
        int skill;
    
        if(!me->is_fighting() )
                return notify_fail("������ǹ��ֻ����ս����ʹ�á�\n");
    
        if ((int)me->query_skill("yangjia-qiang", 1) < 350 )
                return notify_fail("������ǹ������죬�����������ӡ�����ǹ����������\n");
    
        if((int)me->query_skill("spear", 1) < 350 )
                return notify_fail("��Ļ����ڹ��ȼ�����������ʹ�á�����ǹ����\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "spear" )
                return notify_fail("��������ǹ���������á�����ǹ������\n");
                                
        if (me->query_skill_mapped("spear") != "yangjia-qiang"
         || me->query_skill_mapped("parry") != "yangjia-qiang")
                return notify_fail("�������޷�ʹ�á�����ǹ�����й�����\n");
    
        if ((int)me->query("max_neili") < 6000 )
                return notify_fail("���������Ϊ̫�ͣ�����ʹ�á�����ǹ����\n");

        if ((int)me->query("neili") < 3000 )
                return notify_fail("����������̫��������ʹ�á�����ǹ����\n");

        if ((int)me->query("jingli") < 2000 )
                return notify_fail("�����ھ���̫�٣�����ʹ�á�����ǹ����\n");

        if(me->query_temp("yjq/jifeng"))
                return notify_fail("��������ʹ�á�����ǹ����\n");

        if(me->query_temp("yjq/shenwei"))
                return notify_fail("��������ʹ�á�����ǹ����\n");
                
        if(me->query_temp("yjq/qinghe"))
                return notify_fail("��������ʹ�á�������ɡ���\n");

    message_vision(HIC"$N�ںϹ�ͨ��ѧ��ʹ�����ǹ����֮��"MAG"����ǹ"HIC"����ֻ��"+weapon->query("name")+HIC"�������������������Ӱ�㳯��Ϧ����\n"NOR, me);
        me->start_exert(2+random(2),"������ǹ��");
        me->add("neili", -500);
        me->add("jingli", -300);
        me->start_busy(1+random(2));
    
        skill = me->query_skill("yangjia-qiang", 1);
        skill = skill /3;
        me->add_temp("apply/attack",  skill);
        me->set_temp("double_attack",1);
        me->set_temp("yjq/jifeng", skill);

        call_out("check_fight", 1, me, weapon);
        return 1;
}

void check_fight(object me, object weapon)
{  
        object wep;
        int i;

        if (!me) return;
        wep = me->query_temp("weapon");  
        if( !me->is_fighting()
         || !living(me)
         || me->is_ghost()
         || me->query_skill_mapped("spear") != "yangjia-qiang" 
         || me->query_skill_mapped("parry") != "yangjia-qiang" 
         || !wep
         || weapon != wep ){
       i = me->query_temp("yjq/jifeng");
           me->add_temp("apply/attack", -i);
           me->delete_temp("double_attack");
           me->delete_temp("yjq/jifeng");
           if(living(me) && !me->is_ghost())
              message_vision(HIW"$Nһ�ס�����ǹ��ʹ�꣬���ϲ���͹��һ�ɺ�����\n"NOR, me);
           return;
        } 
        call_out("check_fight", 1, me, weapon);
}

int help(object me)
{
   write(YEL"\n���ǹ��"HIG"����ǹ"YEL"����"NOR"\n");
   write(@HELP
   ָ�perform jifeng
   
   �����߹����ٶȡ�

   Ҫ�����ǹ350����
         ����ǹ��350����
         ������� 5000 ���ϣ�
         ��ǰ���� 3000 ���ϣ�
         ��ǰ���� 2000 ���ϣ�
         �������ǹΪ�мܡ�
HELP
   );
   return 1;
}
