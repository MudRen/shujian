// liaoyuan.c ��ԭ�ٻ�

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
		return notify_fail("��ԭ�ٻ�ֻ����ս���жԶ���ʹ�á�\n");

	if (!weapon
	 || weapon->query("skill_type") != "sword"
	 || me->query_skill_mapped("sword") != "huifeng-jian")
		return notify_fail("������û�н����޷�ʹ����ԭ�ٻ���\n");             

	if( (int)me->query_skill("huifeng-jian",1) < 120 )
		return notify_fail("��Ļط������������죬����ʹ����ԭ�ٻ���\n");
      
	if( (int)me->query_skill("sword",1) < 120 )
		return notify_fail("��Ļ��������ȼ�����������ʹ����ԭ�ٻ���\n");  

	if( (int)me->query_skill("jieshou-jiushi", 1) < 120 )
		return notify_fail("��Ľ��־�ʽ�ȼ�����������ʹ����ԭ�ٻ���\n");
      
	if( (int)me->query_skill("linji-zhuang", 1) < 120 )
		return notify_fail("����ټ�ʮ��ׯ�ȼ�����������ʹ����ԭ�ٻ���\n");

	if (me->query_skill_mapped("force") != "linji-zhuang")
		return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("�������̫��������ʹ����ԭ�ٻ���\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������̫���ˣ��޷�ʹ�ó���ԭ�ٻ���\n");

	if (me->query_skill_prepared("hand") != "jieshou-jiushi"
	 || me->query_skill_mapped("hand") != "jieshou-jiushi")
		return notify_fail("�㲻����־�ʽ�������޷�ʹ����ԭ�ٻ����й�����\n");

	skill = me->query_skill("huifeng-jian", 1);
	skill1 = me->query_skill("jieshou-jiushi", 1);

        lvl = (skill + skill1) /8; 
	jiali = me->query("jiali");

	message_vision(HIW"\n$N��Хһ�����������߿���ȥ���պ���ס$n��������"+name+HIW"ɲ�Ǽ������ռ䡣\n"NOR, me,target);
	message_vision(HIW"����ʹ�����־�ʽ����������С������������Ȼ��ǿ��\n"NOR, me,target);
	me->add("neili", -350); 
	me->add("jingli", -100); 

	if ( skill > 350)
                lvl = to_int((skill+skill1)/6.0* skill/350.0);

	if ( jiali > 100) {
		me->set("jiali", 100);
		me->set_temp("lyjiali", 1);
	}
        if(!userp(me)) lvl = lvl / 3;
 if(me->query("env/���־�ʽ")   &&  me->query("emei/jianjue")) 
          target->add_busy(1+random(2));
	 me->set_temp("liaoyuan", 1);
        me->add_temp("apply/attack", lvl  );
        me->add_temp("apply/damage", lvl );
        me->add_temp("apply/sword" , lvl  );
        me->add_temp("apply/dexerity",lvl /8);
	 me->add_temp("apply/hand", lvl);

         	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if ( me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);//��ǰ��random(4) by lsxk@hsbbs
                	
   if ( me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);//��ǰ��random(4) by lsxk@hsbbs
   
   weapon->unequip(); 
	if ( me->is_fighting(target) && me->query_skill("jieshou-jiushi",1) > 150)

{                if(me->query("env/���־�ʽ")   &&  me->query("emei/jianjue")     ) {
                  target->set_temp("must_be_hit",1);
                COMBAT_D->do_attack(me, target, 0, 3); //��ǰ��random(4)?1:3  by lsxk@hsbbs
                  target->delete_temp("must_be_hit",1) ; }

               COMBAT_D->do_attack(me, target, 0, 3); //��ǰ��random(4)?1:3  by lsxk@hsbbs

                                        
}
	if ( me->is_fighting(target) && me->query_skill("jieshou-jiushi", 1) > 200)
{
              if(me->query("env/���־�ʽ")   &&  me->query("emei/jianjue")   ) { 
                  target->set_temp("must_be_hit",1);
                COMBAT_D->do_attack(me, target, 0, 3); 
                  target->delete_temp("must_be_hit",1) ; }

                COMBAT_D->do_attack(me, target, 0, 3); 

}


	          weapon->wield();
 
	if ( me->query_temp("lyjiali")){
 		me->set("jiali", jiali);
		me->delete_temp("lyjiali");
                                	}

        me->add_temp("apply/attack", -lvl  );
	 me->add_temp("apply/sword", -lvl);
        me->add_temp("apply/damage", -lvl);
        me->add_temp("apply/dexerity", -lvl /8);
	 me->add_temp("apply/hand", -lvl);
        me->start_busy(1);
	me->delete_temp("liaoyuan");
        me->start_perform(4, "��ԭ�ٻ�");
	return 1;
}

string perform_name(){ return HIW"��ԭ�ٻ�"NOR; }

int help(object me)
{
	write(HIW"\n�ط������֮����ԭ�ٻ�����"NOR"\n\n");
	write(@HELP
	Ҫ��	��ǰ���� 500 ���ϣ�
		������� 1000 ���ϣ�
		��ǰ���� 300 ���ϣ�
		�ط�������ȼ� 120 ���ϣ�
		���־�ʽ�ȼ� 120 ���ϣ�
		�ټ�ʮ��ׯ�ȼ� 120 ���ϣ�
		���������ȼ� 120 ���ϣ�
		�����ڹ�Ϊ�ټ�ʮ��ׯ��
		��������Ϊ�ط��������
		�����ַ�Ϊ���־�ʽ��
		���ַ�Ϊ���־�ʽ��
		���ֱֳ�����

HELP
        );
        return 1;
}
