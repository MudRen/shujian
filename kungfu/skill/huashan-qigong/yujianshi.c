// yujianshi.c Ԧ��ʽ  By lsxk@hsbbs 2007/7/24
// ����Ϊ���������к�set_temp("double_attack")��  By lsxk@hsbbs

#include <ansi.h>

inherit F_SSERVER;

string exert_name() {return HIG"Ԧ��ʽ"NOR;}

private int remove_effect(object me, int amount);
int exert(object me)
{
        object weapon = me->query_temp("weapon");  
        int skill;
    
        if(!me->is_fighting() )
                return notify_fail("��Ԧ��ʽ��ֻ����ս����ʹ�á�\n");

        if((int)me->query_skill("huashan-qigong", 1) < 250 )
                return notify_fail("��Ļ�ɽ�����ȼ�����������ʹ�á�Ԧ��ʽ����\n");
    
        if ((int)me->query_skill("huashan-jianfa", 1) < 250 )
                return notify_fail("��Ļ�ɽ����������죬�����������ӡ�Ԧ��ʽ����������\n");
    
        if((int)me->query_skill("force", 1) < 250 )
                return notify_fail("��Ļ����ڹ��ȼ�����������ʹ�á�Ԧ��ʽ����\n");

        if (!weapon 
         || weapon->query("skill_type") != "sword"
         ||( me->query_skill_mapped("parry") != "huashan-jianfa" &&  me->query_skill_mapped("parry") != "dugu-jiujian")
         ||( me->query_skill_mapped("sword") != "huashan-jianfa" &&  me->query_skill_mapped("sword") != "dugu-jiujian") )
                return notify_fail("�������޷�ʹ�á�Ԧ��ʽ����\n");
    
        if ((int)me->query("max_neili") < 3500 )
                return notify_fail("���������Ϊ̫�ͣ�����ʹ�á�Ԧ��ʽ����\n");

        if ((int)me->query("neili") < 1500 )
                return notify_fail("����������̫��������ʹ�á�Ԧ��ʽ����\n");

        if ((int)me->query("jingli") < 800 )
                return notify_fail("�����ھ���̫�٣�����ʹ�á�Ԧ��ʽ����\n");

        if(me->query_temp("hsqg/yjs"))
                return notify_fail("��������ʹ�á�Ԧ��ʽ����\n");

        if(me->query_temp("hsqg/juli"))
                return notify_fail("��������ʹ�á�������������\n");
/*
        if ((int)me->query_temp("hsj_junzi"))
                return notify_fail("������ʹ�á����ӽ�����������\n"); 

        if ((int)me->query_temp("hsj_shunv"))
                return notify_fail("������ʹ�á���Ů������������\n"); 
    
        if ( (int)me->query_temp("hsj_xiyi") ) 
                return notify_fail("������ʹ�á���Ů��������\n");

        if ( me->query_temp("zxg/jianyi") ) 
                return notify_fail("������ʹ�á���ϼ���⡹��\n");
*/
        if (me->query_skill_mapped("force") != "huashan-qigong")
                return notify_fail("����ڹ������޷�ʹ�á�Ԧ��ʽ����\n");

    message_vision(HIM"$N�������У����±�ʹ����ɽ���ھ�ѧ֮��"HIR"Ԧ��ʽ"HIM"����ֻ��$N����"+weapon->query("name")+HIM"�����趯�������ɳ��ʯһ�㣬���н�������!\n"NOR, me);
        me->start_exert(1+random(2),"��Ԧ��ʽ��");
        me->add("neili", -500);
        me->add("jingli", -300);
if(me->query_skill("huashan-qigong")<=300 )
        me->start_busy(1);
    
        skill = me->query_skill("huashan-jianfa", 1);
        me->add_temp("apply/attack",  skill/2);
        if(me->query("quest/huashan")=="����")
        me->set_temp("double_attack",1);
        me->set_temp("hsqg/yjs", skill);

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
         || me->query_skill_mapped("force") != "huashan-qigong"
         ||(me->query_skill_mapped("sword") != "huashan-jianfa" &&
            me->query_skill_mapped("sword") != "dugu-jiujian")
         ||(me->query_skill_mapped("parry") != "huashan-jianfa" &&
            me->query_skill_mapped("parry") != "dugu-jiujian")
         || !wep
         || weapon != wep ){
       i = me->query_temp("hsqg/yjs");
           me->add_temp("apply/attack", -i/2);
           if(me->query("quest/huashan")=="����")
               me->delete_temp("double_attack");
           me->delete_temp("hsqg/yjs");
           if(living(me) && !me->is_ghost())
              message_vision(HIG"$Nһ�ס�Ԧ��ʽ��ʹ�꣬΢΢һЦ?�����������\n"NOR, me);
           return;
        } 
        call_out("check_fight", 1, me, weapon);
}

int help(object me)
{
   write(YEL"\n��ɽ������"HIG"Ԧ��ʽ"YEL"����"NOR"\n");
   write(@HELP
   ��ɽ�����˻�ɽһ�ɻ����ڹ����䲻��������ϼ�񹦾����������
   ���Ҳ����ͬС�ɣ��ˡ�Ԧ��ʽ���������ǽ��ڲ�����ѧ���ٵж�
   ��ʱ�����������Լ������С���ɽ���ڵ���Խ���������Խ����
   ��Ӧ�֣�����֮���˹������������ࡣ
   ָ�exert yujianshi

   Ҫ�󣺻�ɽ����250����
         ��ɽ����250����
         �����ڹ�250����
         ������� 3500 ���ϣ�
         ��ǰ���� 1500 ���ϣ�
         ��ǰ���� 800 ���ϣ�
         ������ɽ����Ϊ�мܡ�
HELP
   );
   return 1;
}
