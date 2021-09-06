// lianhuan.c for murong-jianfa
// by snowman@SJ 01/05/1999.
// modify by leontt@SJ 26/09/2000.

#include <ansi.h>

inherit F_SSERVER;
int perform(object me,object target)
{
	object weapon;
	int d=me->query_skill("murong-jianfa",1) /3+ me->query_skill("douzhuan-xingyi",1) /3 + me->query_skill("canhe-zhi",1) /3;
	int i=me->query_skill("shenyuan-gong",1)/2 + me->query_skill("murong-shenfa",1) /2;
         
 if(!userp(me)){ 
             i = i /4; 
             d= d /4;}

	if( !target ) target = offensive_target(me);

		
	         if( !target  
        || !me->is_fighting(target)
        || !objectp(target)
        || environment(target)!= environment(me))
		return notify_fail("�߽�����ָֻ�ܶ�ս���еĶ���ʹ�á�\n");

		
		

	if(me->query_skill_mapped("force") != "shenyuan-gong")
		return notify_fail("����ڹ�������Ԫ�����޷�ʹ���߽�����ָ��\n");

	if( (int)me->query_skill("shenyuan-gong", 1) < 100 )
		return notify_fail("����ڹ���δ���ɣ�����ʹ���߽�����ָ��\n");

	if( (int)me->query_skill("murong-jianfa", 1) < 100 )
		return notify_fail("��Ľ�����δ���ɣ�����ʹ���߽�����ָ��\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| weapon->query("skill_type") != "sword"
	|| me->query_skill_mapped("sword") != "murong-jianfa")
		return notify_fail("������û�н����޷�ʹ���߽�����ָ��\n");

        if((me->query_skill_mapped("parry") != "murong-jianfa")
        &&(me->query_skill_mapped("parry") != "douzhuan-xingyi"))
         return notify_fail("����мܹ��򲻶ԣ��޷�ʹ���߽�����ָ��\n");
	if( (int)me->query_skill("canhe-zhi", 1) < 100 )
		return notify_fail("��Ĳκ�ָ��δ���ɣ�����ʹ���߽�����ָ��\n");
	if((int)me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ����������ʹ���߽�����ָ��\n");
	if((int)me->query("neili") < 800 )
		return notify_fail("�������������㣬����ʹ���߽�����ָ��\n");
	if((int)me->query("jingli") < 500 )
		return notify_fail("�����ھ������㣬����ʹ���߽�����ָ��\n");
	if((int)me->query_temp("lianhuan"))
		return notify_fail("������ʹ���߽�����ָ��\n");
	if(me->query_skill_mapped("finger") != "canhe-zhi"
	 || me->query_skill_prepared("finger") != "canhe-zhi")
		return notify_fail("��û����ָ���޷�ʹ���߽�����ָ��\n");
	if((int)me->query_skill("sword", 1) < 100 )
		return notify_fail("��Ļ�������������죬�����ڽ�����ʹ���߽�����ָ��\n");

	message_vision(MAG"\n$N"MAG"ʹ��Ľ�ݽ���֮���衸�߽�����ָ��������$P����ʳָ��"+weapon->name()+MAG"��һ������������������ӳ��ֱϮ$n"MAG"��\n"NOR, me,target);
	me->set_temp("lianhuan", 7);
	me->receive_damage("neili", 100);
	me->receive_damage("jingli", 100);
if(me->query_skill("murong-jianfa",1) >=450 && !userp(target))
 target->add_busy(2+random(2));
              me->add_temp("apply/attack", i /2);
	me->add_temp("apply/damage", d /3 );
	me->add_temp("apply/sword",d/4);
	me->add_temp("apply/finger",d/4);
	me->add_temp("apply/strength",d/10);
              me->add_temp("apply/dodge", i /3);


	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	me->start_perform(4, "���߽�����ָ��");
	call_out("check_fight", 1, me, 4, i, d);
	return 1;
}

void remove_effect2(object me, int i)
{
	if (me)   me->add_temp("apply/dodge",- i /3);
                          
}

void remove_effect(object me, int i, int d)
{
	if(!me) return;

	me->delete_temp("lianhuan");
  
              me->add_temp("apply/attack",- i /2);
	me->add_temp("apply/damage", -d /3 );
	me->add_temp("apply/sword",-d/4);
	me->add_temp("apply/finger",-d/4);
	me->add_temp("apply/strength",-d/10);

	if (living(me))
		message_vision(HIY"\n$N"HIY"�ġ��߽�����ָ������������ϣ����ص�������չ���\n"NOR, me);
	me->start_perform(2, "���߽�����ָ��");
	d = 1 + random(2);
if(me->query_skill("murong-jianfa",1) <=350 )
        me->add_busy(d);
	call_out("remove_effect2", d+d, me, i);
}

void check_fight(object me, int i, int j, int d)
{
	object weapon, target;

	if (!me ) return;

	target = offensive_target(me);

	if(!i
	|| !living(me)
	|| !target
	|| !me->is_fighting(target)
	|| environment(target)!=environment(me)
	|| !me->query_temp("lianhuan")
	|| me->query("neili") < 200
	|| me->query("jingli") < 200)
		return remove_effect(me, j, d);

	if(me->query_skill_mapped("sword") != "murong-jianfa") {
		tell_object(me, HIR"����ʱ�Ļ���������������ʹ�á��߽�����ָ��������\n");
		remove_effect(me, j, d);
	} else if(me->query_skill_mapped("force") != "shenyuan-gong") {
		tell_object(me, HIR"����ʱ�Ļ��ڹ�����������ʹ�á��߽�����ָ��������\n");
		remove_effect(me, j, d);
   } else if((me->query_skill_mapped("parry") != "murong-jianfa")
       &&(me->query_skill_mapped("parry") != "douzhuan-xingyi")
       &&(me->query_skill_mapped("parry") != "canhe-zhi"))
        {
		tell_object(me, HIR"����ʱ�Ļ��мܣ���������ʹ�á��߽�����ָ��������\n");
		remove_effect(me, j, d);
	} else if(!objectp(weapon = me->query_temp("weapon"))
		|| weapon->query("skill_type") != "sword"){
		tell_object(me, HIR"����ʱ�Ļ���������������ʹ�á��߽�����ָ��������\n");
		remove_effect(me, j, d);
	} else if (me->is_busy())
		call_out("check_fight", 1, me, i, j, d);
	else {
		me->receive_damage("neili", 50);
		me->receive_damage("jingli", 50);
		if (objectp(target) && me->is_fighting(target))
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		call_out("check_fight", 1, me, --i, j, d);
	}
}

string perform_name(){ return MAG"�߽�����ָ"NOR; }
int help(object me)

{
        write(HIG"\nĽ�ݽ���֮���߽�����ָ����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 800 ���ϣ�
                ������� 1000 ���ϣ�
                ��ǰ���� 500 ���ϣ�
                Ľ�ݽ����ȼ� 100 ���ϣ�
                ��Ԫ���ȼ� 100 ���ϣ�
                ���������ȼ� 100 ���ϣ�
                ��������ΪĽ�ݽ�����
                �����м�ΪĽ�ݽ�������ת���ƻ�κ�ָ��
                �����ڹ�Ϊ��Ԫ����
HELP
        );
        return 1;
}
