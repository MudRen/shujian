
// feilong.c ����������֮����������
// Build by fengyue@CB 2008-10-20
// ������� zaqz,howkjie,axj@CB


#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int lvl, skill, skill1,jiali;
	object weapon;
	string name;

	weapon = me->query_temp("weapon");
	if (weapon) name = weapon->query("name");

	if( !target ) target = offensive_target(me);
     
	if( !objectp(target)
	 || !me->is_fighting(target) )
		return notify_fail("����������ֻ����ս���жԶ���ʹ�á�\n");

	if (!weapon
	 || weapon->query("skill_type") != "whip"
	 || me->query_skill_mapped("whip") != "yinlong-bian")
		return notify_fail("�㲻�ñ�����ôʹ�á�����������\n");             

	if( (int)me->query_skill("yinlong-bian",1) < 150 )
		return notify_fail("��ľ��������޲�����죬����ʹ�á�����������\n");
      
	if( (int)me->query_skill("whip",1) < 150 )
		return notify_fail("��Ļ����޷��ȼ�����������ʹ�á�����������\n");  
/*
	if( (int)me->query_skill("claw", 1) < 150 )
		return notify_fail("���צ���ȼ�����������ʹ�á�����������\n");
*/  
	if( (int)me->query_skill("force", 1) < 200 )
		return notify_fail("����ڹ��ȼ�����������ʹ�á�����������\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("�������̫��������ʹ�á�����������\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������̫���ˣ��޷�ʹ�ó�������������\n");

	if( (int)me->query("jingli") < 500 )

		return notify_fail("��ľ���̫���ˣ��޷�ʹ�ó�������������\n");
/*
����ж��������д�����jifa claw ���� jybgz,���߲���9ysz ...
��ôִ���������ǲ��Եġ�
	if (me->query_skill_mapped("claw") != "jiuyin-baiguzhua"
	 && me->query_skill_mapped("claw") != "jiuyin-shenzhua")
		return notify_fail("��û�м��������׹�צ�������޷�ʹ�á������������й�����\n");
*/
	skill = me->query_skill("yinlong-bian", 1);
	skill1 = me->query_skill("claw", 1);
        lvl =  skill / 4;
        lvl += skill1 / 4;
	jiali = me->query("jiali");


	message_vision(HIW"\n$N����һ��һ�Σ�"+name+HIW"�͵�˦������������������ʸ�ö�����\n"NOR, me,target);
	message_vision(HIB"������$N����ʳ�ж�ָ����צ״����$n������ȥ��һ����צ��ȫ�Ƕ���ͷ����ǰ����Ѩ��\n"NOR, me,target);
	me->add("neili", -350); 
	me->add("jingli", -100); 
target->add_busy(2);
	if ( skill > 200)
		lvl = to_int((skill+skill1)/8.0* skill/200.0);

	if ( jiali > 100) {
		me->set("jiali", 100);
		me->set_temp("lyjiali", 1);
	}

	me->set_temp("feilong", 1);
	me->add_temp("apply/attack", lvl);
	me->add_temp("apply/damage", lvl/2);
	me->add_temp("apply/claw", lvl);
	me->add_temp("apply/whip", lvl);


COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);


	if ( me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);

         	weapon->unequip(); 

// ��һ��������ж�9ybgz�������ж���û��9yzg֧�֡�Ϊ�˷�ֹ��Ҽ�����Ŀ��֡�

if( me->is_fighting(target) && me->query_skill_prepared("claw") == "jiuyin-baiguzhua" && me->query_skill_mapped("claw") == "jiuyin-baiguzhua" ){

         if( me->query_skill("jiuyin-zhengong",1) >= 120 )
              {
              	message_vision(HIM"\n$Nָצ�Ӷ����������˻˻���죬����������������������������ޱȣ�\n"NOR, me,target);
                        target->set_temp("must_be_hit",1);
                        target->start_busy(3);
                        COMBAT_D->do_attack(me, target, 0, 3);
                  target->delete_temp("must_be_hit",1) ;
              }

        COMBAT_D->do_attack(me, target, 0, 3); 
}

// ��2��������жϼ���9����צ�;����湦��

if( me->is_fighting(target) && me->query_skill_prepared("claw") == "jiuyin-shenzhua" && me->query_skill_mapped("claw") == "jiuyin-shenzhua" ){

         if( me->query_skill("jiuyin-zhengong",1) >= 120 )
              {
              	message_vision(HIM"\n$Nצ���þ�������֧�֣�����Զ�Ǿ����׹�צ�ɱȣ�����������ף������ޱȣ�\n"NOR, me,target);
                        target->set_temp("must_be_hit",1);
                        target->start_busy(5);
                        COMBAT_D->do_attack(me, target, 0, 3);
                  target->delete_temp("must_be_hit",1) ;
              }

        COMBAT_D->do_attack(me, target, 0,3); 
}


//���е�һ����� 
if( me->is_fighting(target) && me->query_skill_prepared("claw") == "jiuyin-baiguzhua" && me->query_skill_mapped("claw") == "jiuyin-baiguzhua" ){

          if( me->query_skill("jiuyin-shenzhua",1) >= 120 ) 
                 {
               	message_vision(HIM"\n$N���ָ���ǰ̽����ָ��ץ��$n�ؿ�,�ۼ���һץ֮�£���ʱ���ǿ�������֮����\n"NOR, me,target);
                        target->set_temp("must_be_hit",1);
                        COMBAT_D->do_attack(me, target, 0, 3);
                        target->delete_temp("must_be_hit",1) ; 
               }

               COMBAT_D->do_attack(me, target, 0, 3); 
}


//���еڶ������ 
if( me->is_fighting(target) && me->query_skill_prepared("claw") == "jiuyin-shenzhua" && me->query_skill_mapped("claw") == "jiuyin-shenzhua" ){

          if( me->query_skill("jiuyin-shenzhua",1) >= 120 ) 
                 {
               	message_vision(HIM"\n$N���ָ���ǰ̽����ָ��ץ��$n�ؿ�,�ۼ���һץ��������ʱ���ǿ�������֮����\n"NOR, me,target);
                        target->set_temp("must_be_hit",1);
                        COMBAT_D->do_attack(me, target, 0, 3);
                        target->delete_temp("must_be_hit",1) ; 
               }

               COMBAT_D->do_attack(me, target, 0, 3); 
}

        weapon->wield();
 
	if ( me->query_temp("lyjiali")){
 		me->set("jiali", jiali);
		me->delete_temp("lyjiali");
                                	}

	me->add_temp("apply/attack", -lvl);
	me->add_temp("apply/whip", -lvl);
	me->add_temp("apply/damage", -lvl/2);
	me->add_temp("apply/claw", -lvl);
        me->start_busy(1);
	me->delete_temp("feilong");
	me->start_perform(3, "����������");
	return 1;
}

string perform_name(){ return HIW"����������"NOR; }

int help(object me)
{
	write(HIW"\n����������֮������������"NOR"\n\n");
	write(@HELP
	Ҫ��	��ǰ���� 500 ���ϣ�
		������� 1000 ���ϣ�
		��ǰ���� 500 ���ϣ�
		���������޵ȼ� 150 ���ϣ�
                �����޷�,�м�Ϊ���������ޣ�
                ���ֱֳ�����

      ����������¼��ܣ��������벻����Ч��Ч��        
		����צ��Ϊ�����׹�צ�������צ���ұ�צ����
                �����湦�ȼ� 120 ����(���輤��)��		

		

HELP
        );
        return 1;
}
