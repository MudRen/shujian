// renmu-daofa ȼľ����
// by snowman@SJ 05/12/1999

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,ap,dp;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("�����ҡ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "blade"
           || me->query_skill_mapped("blade") != "ranmu-daofa")
                return notify_fail("�������޷�ʹ�������ҡ�������\n");

        if (weapon->query("sharpness") > 3)
                return notify_fail("������֮�����Ƿ���֮����ʹ�á����ҡ�����û��ʲô���ã�\n");

        if (weapon->query("unique"))
                return notify_fail("������֮�����Ƿ���֮����ʹ�á����ҡ�����û��ʲô���ã�\n");
                
        if(me->query_skill("ranmu-daofa", 1) < 150 )
                return notify_fail("���ȼľ������򲻹���ʹ���������ҡ�������\n");

        if(me->query_skill("blade", 1) < 150 )
                return notify_fail("��Ļ�������������죬ʹ���������ҡ�������\n");

        if( (int)me->query_skill("yijin-jing", 1) < 120 )
                return notify_fail("����׽�ȼ�������ʹ���������ҡ�������\n");

        if( (int)me->query_str() < 34)
                return notify_fail("�������������ǿ����ʹ���������ҡ�������\n");

        if( (int)me->query_int() < 30)
                return notify_fail("û�д��ǻ۴��������ʹ���������ҡ������ġ�\n");
 
        if ( me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("û���׽��Ϊ���������޷�ʹ�������ҡ������ģ�\n"); 

        if(me->query_temp("ranmu")) 
                return notify_fail("����������ʹ�á����ġ�������\n"); 

        if (me->query_temp("fumo"))
                return notify_fail("����������ʹ�á���շ�ħ���񹦡�\n"); 

        if (me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ������\n");

        if (me->query("neili") < 650)
                return notify_fail("�������������\n");

        if (me->query("jingli") < 200)
                return notify_fail("��ľ���������\n");

        me->add("neili", -600);
        me->add("jingli", -150);        

//fenwo's damage depends on how many times u pfmd       

        i = me->query("fenwo");
        if (i > me->query_skill("blade")) i = me->query_skill("blade");
        ap = me->query_dex(1);
	      dp = target->query_dex(1);
	
//and it will not be over ur enable blade skill

	me->add_temp("apply/damage",i);
	me->add_temp("apply/attack",i/2);//ԭ����/2
        me->set_temp("fenwo_hit", 1);
if(!userp(target))
target->set_temp("must_be_hit",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);   
        	
        if(random( ap + dp ) > dp) { 
        	message_vision(HIC"\n$N����ǿ���ֳöԷ��޻�Ϣ֮�ʣ���ʹ��һ������$n��ֱ����ȥ��\n"NOR,me,weapon);

        	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        	}
target->delete_temp("must_be_hit");
        weapon->add("fenwo", 1);
        if (weapon 
        && !weapon->query("unique")
        && weapon->query("rigidity") < 2
        && weapon->query("fenwo") >= (3+weapon->query("rigidity"))) {
           	message_vision(HIY"\nֻ�������ǡ�������$N���е�$n"HIY"�����ܻ������ѳ�����Ƭ��\n"NOR,me,weapon);
           	weapon->unequip();
           	weapon->move(environment(me));
           	weapon->set("name", "���ѵ�" + weapon->query("name"));
           	weapon->set("value", 49);
           	weapon->set("weapon_prop", 0);
           	me->reset_action();
        }
        me->add_temp("apply/damage", -i);
        me->add_temp("apply/attack", -i/1);//ԭ����/2
        me->delete_temp("fenwo_hit");
        me->start_busy(1);
        me->start_perform(3,"����");
        me->add("fenwo", 1);
        return 1;
}
string perform_name(){ return HIR"����"NOR; }