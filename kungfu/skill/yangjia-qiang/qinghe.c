//  lihua.c ������� 
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return HIC"�������"NOR;}

private int remove_effect(object me, int amount);

int perform(object me)
{
        object weapon = me->query_temp("weapon");  
        int skill;
    
        if(!me->is_fighting() )
                return notify_fail("��������ɡ�ֻ����ս����ʹ�á�\n");
    
        if ((int)me->query_skill("yangjia-qiang", 1) < 150 )
                return notify_fail("������ǹ������죬�����������ӡ�������ɡ���������\n");
    
        if((int)me->query_skill("spear", 1) < 150 )
                return notify_fail("��Ļ����ڹ��ȼ�����������ʹ�á�������ɡ���\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "spear" )
                return notify_fail("��������ǹ���������á�������ɡ�����\n");
                                
        if (me->query_skill_mapped("spear") != "yangjia-qiang"
         || me->query_skill_mapped("parry") != "yangjia-qiang")
                return notify_fail("�������޷�ʹ�á�����ǹ�����й�����\n");
    
        if ((int)me->query("max_neili") < 2500 )
                return notify_fail("���������Ϊ̫�ͣ�����ʹ�á�������ɡ���\n");

        if ((int)me->query("neili") < 1000 )
                return notify_fail("����������̫��������ʹ�á�������ɡ���\n");

        if ((int)me->query("jingli") < 500 )
                return notify_fail("�����ھ���̫�٣�����ʹ�á�������ɡ���\n");

        if(me->query_temp("yjq/qinghe"))
                return notify_fail("��������ʹ�á�������ɡ���\n");

        if(me->query_temp("yjq/shenwei"))
                return notify_fail("��������ʹ�á�����ǹ����\n");
                
        if(me->query_temp("yjq/jifeng"))
                return notify_fail("��������ʹ�á�����ǹ����\n");

    message_vision(HIM"$Nʹ�����ǹ����֮��"HIG"�������"HIM"����ֻ��"+weapon->query("name")+HIM"ֻ���о�������ӯƮ�ݣ������ޱȣ�\n"NOR, me);
        me->start_exert(5+random(2),"��������ɡ�");
        me->add("neili", -200);
        me->add("jingli", -500);
        me->start_busy(1+random(2));
    
        skill = me->query_skill("yangjia-qiang", 1);
        me->add_temp("apply/attack",  -skill/5);
        me->add_temp("apply/damage",  -skill/5);
        me->add_temp("apply/parry",  skill/2);
        me->add_temp("apply/dodge",  skill/2);
        me->set_temp("yjq/qinghe", skill);

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
       i = me->query_temp("yjq/qinghe");
        me->add_temp("apply/attack", i/5);
        me->add_temp("apply/damage", i/5);
        me->add_temp("apply/parry",  -i/2);
        me->add_temp("apply/dodge",  -i/2);
           me->delete_temp("yjq/qinghe");
           if(living(me) && !me->is_ghost())
              message_vision(HIW"$Nһ�ס�������ɡ�ʹ�꣬�о�����û�й���Ʈ�ݡ�\n"NOR, me);
           return;
        } 
        call_out("check_fight", 1, me, weapon);
}

int help(object me)
{
   write(YEL"\n���ǹ��"HIG"�������"YEL"����"NOR"\n");
   write(@HELP
   ָ�perform qinghe

   Ҫ�����ǹ150����
         ����ǹ��150����
         ������� 2500 ���ϣ�
         ��ǰ���� 2000 ���ϣ�
         ��ǰ���� 500 ���ϣ�
         �������ǹΪ�мܡ�
HELP
   );
   return 1;
}
