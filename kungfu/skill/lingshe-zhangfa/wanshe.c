//wanshe.c ��������             
#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name() {return HIB"��������"NOR;}

int perform(object me,object target)
{
    object weapon;
    
    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if((int)me->query_skill("staff", 1) < 300 )
                return notify_fail("��Ļ����ȷ�������죬����ʹ���������塣\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "staff"
        || me->query_skill_mapped("staff") != "lingshe-zhangfa")
                return notify_fail("���������ȣ����ʹ���������壿\n");
    if (me->query_skill("lingshe-zhangfa", 1) < 300 )
		            return notify_fail("��������ȷ���������죬ʹ�����������������\n");
	  if (me->query_skill("hamagong", 1) < 300 )
		            return notify_fail("��ĸ�󡹦�ȼ����㣬�޷�ʹ���������塣\n");
	  if (me->query_skill("force") < 300 )
		            return notify_fail("����ڹ��ȼ�������ʹ�����������������\n");
	  if (me->query_str(1) < 60)
		            return notify_fail("�������������ǿ����ʹ�����������������\n");
	  if (me->query_skill_mapped("force") != "hamagong")
		            return notify_fail("���������塹��Ҫ�ø�󡹦Ϊ������\n");
    if (me->query("oyf/hamagong") < 3 )         
                return notify_fail("���������塹��Ҫ�ڻ�ɽ֮�۵õ�ŷ����ָ��ſ�ѧϰʹ�á�\n");
	  if (me->query_skill_mapped("staff") != "lingshe-zhangfa"
)
		            return notify_fail("�����ڵ�״̬���޷�ʹ�����������塹������\n");                
    if((int)me->query("max_neili") < 1500 )
                return notify_fail("���������Ϊ����������ʹ���������壡\n");
    if((int)me->query("neili") < 1000 )
                return notify_fail("�������������㣬����ʹ���������壡\n");
                
        message_vision(HIR"\n$N����󡹦��������Ѩ�����з�����������������������������������������\n"+
        ""HIB"ͻȻֻ��$Nʹ�������ȷ����һ�С�"HIM"��������"NOR"��"HIB"������"+weapon->name()+HIB"����ֶ�ȥ��\n"+
        ""HIG"������ŷ�����ڻ�ɽ֮��Ϊ�˴򹷰���������֮�����޹����龫���ǣ��ľ���Ѫ����������һ�������Ǻ��߹�������Ҳ�øʰ��·磡\n"NOR,me,target);
    me->start_perform(5,"���������塹");
    me->set_temp("lszf/wanshe",1);
    me->add("neili", -500);
    me->add_temp("apply/attack",  me->query_skill("lingshe-zhangfa", 1)/2);
    me->add_temp("apply/damage",  me->query_skill("lingshe-zhangfa", 1)/2);

target->start_busy(3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);


    me->delete_temp("lszf/wanshe");
     if (me->is_fighting(target)
     	&&  random(me->query_con()) > target->query_con()/3) {
     	message_vision(HBRED"\nͻ��"+weapon->name()+HBRED"���ٵ���ת�������������߽������з��ٲ�ס��$n���壡��������Ѹ���ϴ���\n"NOR,me,target);
     	target->start_busy(4+random(2));
     	message_vision(HBRED"��������$n�ʺ�ҧȥ�����ȵ�����ҧס����$nҪ����$n���������߶��ˣ�\n"NOR,me,target);
     	target->add_condition("snake_poison",5+random(5));
     	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    };
     	    if (me->is_fighting(target))
     	message_vision(HIY"\n$N������"+weapon->name()+HIY"ֱͦ�����۹�����"+weapon->name()+HIY"�ϣ��������Ʈ�ڣ����ȼ�������籩��Ҳ���ƶ���\n"+
					           HIY"����ֱָ$n�Ŀڣ����Ǵ򹷰�����ʮ��·������"HIG"�����޹�"NOR"��"HIY"�ĵ�����İ������ڣ�\n"NOR, me, target);
					                             COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
					                      
					if ( me->is_fighting(target)&&me->query_temp("hmg_nizhuan"))
						message_vision(HIB"\n������ת֮���ڻ�ɽ֮���ٵ�ŷ����ָ��֮������֮����ʤ��ǰ��$N���������������"+weapon->name()+HIB"\n$N�����۸��֮���ھ���������ʹ��ʹ����������ǧ���������̾۳�һ����$n�ؿ��ػ���ȥ��\n"NOR,me,target);
						COMBAT_D->do_attack(me, target, me->query_temp("weapon"),4);
						
    me->add_temp("apply/attack",  -me->query_skill("lingshe-zhangfa", 1)/2);
    me->add_temp("apply/damage",  -me->query_skill("lingshe-zhangfa", 1)/2);     	
     	
    return 1;
}


