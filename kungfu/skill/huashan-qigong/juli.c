// juli.c ��������  By lsxk@hsbbs 2007/7/22
// ����Ϊ�����Ӻ������Ͷ�����  By lsxk@hsbbs

#include <ansi.h>

inherit F_SSERVER;

string exert_name() {return HIW"��������"NOR;}

private int remove_effect(object me, int amount);
int exert(object me)
{
        object weapon = me->query_temp("weapon");  
        int skill;
    
        if(!me->is_fighting() )
                return notify_fail("������������ֻ����ս����ʹ�á�\n");

        if((int)me->query_skill("huashan-qigong", 1) < 100 )
                return notify_fail("��Ļ�ɽ�����ȼ�����������ʹ�á�������������\n");
    
        if ((int)me->query_skill("huashan-jianfa", 1) < 100 )
                return notify_fail("��Ļ�ɽ����������죬�����������ӡ�������������������\n");
    
        if (!weapon 
         || weapon->query("skill_type") != "sword"
         ||( me->query_skill_mapped("parry") != "huashan-jianfa" &&  me->query_skill_mapped("parry") != "dugu-jiujian")
         ||( me->query_skill_mapped("sword") != "huashan-jianfa" &&  me->query_skill_mapped("sword") != "dugu-jiujian") )
                return notify_fail("�������޷�ʹ�á�������������\n");
    
        if ((int)me->query("neili") < 500 )
                return notify_fail("����������̫��������ʹ�á�������������\n");

        if ((int)me->query("jingli") < 500 )
                return notify_fail("�����ھ���̫�٣�����ʹ�á�������������\n");

        if(me->query_temp("hsqg/juli"))
                return notify_fail("��������ʹ�á�������������\n");

        if(me->query_temp("hsqg/yjs"))
                return notify_fail("��������ʹ�á�Ԧ��ʽ����\n");                


        if (me->query_skill_mapped("force") != "huashan-qigong")
                return notify_fail("����ڹ������޷�ʹ�á�������������\n");

    message_vision(HIY"$N����һ��������������ȫ����ת���ս�֮�֣���ʱ$N�Ľ��б���޷���ĥ!\n"NOR, me);
        me->start_exert(1+random(2),"������������");

        me->add("neili", -200);          
        me->add("jingli", -100);
    
        skill = me->query_skill("huashan-jianfa", 1)/6;
        me->add_temp("apply/dexerity",  skill);

            me->add_temp("apply/damage",skill);
        me->set_temp("hsqg/juli", skill);

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
         || !wep
         || weapon != wep ){
       i = me->query_temp("hsqg/juli");
           me->add_temp("apply/dexerity", -i);

               me->add_temp("apply/damage",-i);
           me->delete_temp("hsqg/juli");
           if(living(me) && !me->is_ghost())
              message_vision(HIY"$N����������֧�������غ��˿����������ָֻ���ƽ����\n"NOR, me);
           return;
        } 
        call_out("check_fight", 1, me, weapon);
}

int help(object me)
{
    write(YEL"\n��ɽ������"HIY"��������"YEL"����"NOR"\n");
   write(@HELP
   ��ɽ�����˻�ɽһ�ɻ����ڹ����䲻��������ϼ�񹦾����������
   ���Ҳ����ͬС�ɣ��ˡ��������������������ھ�����֫�������
   �������ʵս���Ͷ�������ϻ�ɽ����������ӯ���ɡ�����ɽ�ɽ�
   ��ʹ�ã���������������
   ָ�exert juli

   Ҫ�󣺻�ɽ����100����
         ��ɽ����100����
         ��ǰ���� 500 ���ϣ�
         ��ǰ���� 500 ���ϣ�
         ������ɽ����Ϊ�мܡ�
HELP
   );
   return 1;
}
