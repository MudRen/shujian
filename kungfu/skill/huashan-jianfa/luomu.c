// luomu.c �ޱ���ľ Create By lsxk@hsbbs 2007/7/25
/* �ǵ�ȥ�����£�ʦ������ѩ���裬�������ߣ��ۼ���һ�ڵ��ӽ�
   �۽��������ʩչ�����С��ޱ���ľ��������������һ������һ
   ����ÿһ���������˰����Ʈ������һ��ѩ������ʦ�ﶼ���ƺ�
   �ʣ�˵������ʦ�磬��һ���ҿɷ����ˣ���ɽ��ȷ������������
   �ˡ���
*/

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name() {return HIC"�ޱ���ľ"NOR;}

int perform(object me,object target)
{
    object weapon;
    
    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("���ޱ���ľ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if(me->query_skill_mapped("force") != "zixia-gong"
	&&me->query_skill_mapped("force") != "huashan-qigong")
                return notify_fail("����ڹ������޷�ʹ�á��ޱ���ľ����\n");

    if( (int)me->query_skill("zixia-gong", 1) < 350
	&&(int)me->query_skill("huashan-qigong", 1) < 350 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ�á��ޱ���ľ����\n");

    if((int)me->query_skill("force", 1) < 350 )
                return notify_fail("��Ļ����ڹ�������죬�޷�֧�֡��ޱ���ľ����\n");

    if( (int)me->query_skill("huashan-jianfa", 1) < 350 ) 
                return notify_fail("��Ľ�����δ���ɣ�����ʹ�á��ޱ���ľ����\n");

    if( (int)me->query_skill("huashan-shenfa", 1) < 350 ) 
                return notify_fail("��Ļ�ɽ����δ���ɣ�����ʹ�á��ޱ���ľ����\n");

    if((int)me->query_skill("sword", 1) < 350 )
                return notify_fail("��Ļ�������������죬�����ڽ�����ʹ�á��ޱ���ľ����\n");

    if((int)me->query_skill("dodge", 1) < 350 )
                return notify_fail("��Ļ����Ṧ������죬����ʹ�á��ޱ���ľ����\n");

    if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "sword"
         || me->query_skill_mapped("parry") != "huashan-jianfa")
                return notify_fail("�������޽������ʹ�á��ޱ���ľ����\n");
 
       if( me->query_skill_mapped("sword") != "huashan-jianfa")
             if(me->query_skill_mapped("sword") != "dugu-jiujian")
                    return notify_fail("�㲻ʹ�û�ɽ���������ʹ�á��ޱ���ľ����\n");
               
    if((int)me->query("max_neili") < 8000 )
                return notify_fail("���������Ϊ����������ʹ�á��ޱ���ľ����\n");

    if((int)me->query("neili") < 2000 )
                return notify_fail("�������������㣬����ʹ�á��ޱ���ľ����\n");

    if((int)me->query("jingli") < 1000 )
                return notify_fail("������̫���ˣ�����ʹ�á��ޱ���ľ����\n");

        message_vision(HIC"\n$N��Хһ��,��ʹ�����ޱ���ľ������!����$Nһ������һ����ÿһ�����ڰ���м���һ������,�����¼���\n"NOR, me,target);

    me->start_perform(4,"���ޱ���ľ��");
    me->add("neili", -800);
    me->add("jingli",-500);
    me->set_temp("hsjf/luomu",1);

    me->add_temp("apply/attack",  (int)me->query_skill("huashan-jianfa", 1)/4);

    if(me->query_temp("zxg")){
   message_vision(HIM"$N������ϼ�񹦷��ӵ����쾡��,����"+weapon->query("name")+HIM"�������������ˡ�֮����\n"NOR, me);
   me->add_temp("apply/damage", (int)me->query_skill("huashan-jianfa",1)/3);
	target->set_temp("must_be_hit",1);
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
 if(objectp(target))  target->delete_temp("must_be_hit");
   me->add_temp("apply/damage", -(int)me->query_skill("huashan-jianfa",1)/3);
    }
    else{
	me->add_temp("apply/damage", (int)me->query_skill("huashan-jianfa",1)/5);
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
	me->add_temp("apply/damage", -(int)me->query_skill("huashan-jianfa",1)/5);
    }

    me->add_temp("apply/attack", -(int)me->query_skill("huashan-jianfa", 1)/4);
    me->delete_temp("hsjf/luomu");
    me->start_busy(1);
    target->start_busy(1);
    return 1;
}

int help(object me)
{
   write(WHT"\n��ɽ������"HIC"�ޱ���ľ"WHT"����"NOR"\n");
   write(@HELP
    ���С��ޱ���ľ�����ǻ�ɽ�������裬�Ǿ�ͨ��ɽ�������޷�ʹ�ã�
    ����һ��ʹ����������һ������һ����˲������ֻ�������������
    ��Ľ��У�

    ������ϼ����ϣ����������л������������������������ߣ�

    ָ�perform luomu

    Ҫ�󣺻�ɽ���� ���� ��ϼ��350��
          ��ɽ����350����
          ��ɽ��350����
          �����ڹ�350����
          ��������350����
          �����Ṧ350����
          ��ǰ����2000���ϣ�
          ��ǰ����1000���ϣ�
          �������8000���ϡ�

HELP
   );
   return 1;
}

