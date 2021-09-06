// modified by darken@SJ

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int focus, i, j;
	string str;

	focus = me->query_temp("ss/focus");

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target) 
	|| !living(target))
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_skill("songshan-jian", 1) < 100 )
		return notify_fail("�����ɽ��������̫ǳ���޷�ʹ�÷��蹥����\n");

	if( me->query_skill("sword", 1) < 100 )
		return notify_fail("��Ļ�����������̫ǳ���޷�ʹ�÷��蹥����\n");

	if( me->query_skill("hanbing-zhenqi", 1) < 100 )
		return notify_fail("����ڹ�����̫ǳ���޷�ʹ�÷��蹥����\n");
                
	if( me->query("max_neili") < 1200 )
		return notify_fail("�������̫ǳ���޷�ʹ�÷��蹥����\n");

	if( me->query("neili") < 800 )
		return notify_fail("����������㣬�޷�ʹ�÷��蹥����\n");

	if (me->query_skill_mapped("force") != "hanbing-zhenqi")
		return notify_fail("����ʲôΪ������ʹ��ɽ������ô?\n");

	if (!objectp(weapon = me->query_temp("weapon")) 
	|| weapon->query("skill_type") != "sword"
	|| me->query_skill_mapped("sword") != "songshan-jian"
	|| me->query_skill_mapped("parry") != "songshan-jian" )
		return notify_fail("��ʹ������ɽ������ô?\n");

	i = me->query_skill("songshan-jian", 1);

	message_vision(HIB"\n$N��Хһ�����ٽ�ͦ�̣��ڰ���л����������⣬����������������������$n��Ϯ��ȥ��\n" NOR,me,target);
  if(me->query_temp("ss/hb"))
	message_vision(HIB"\n$N�����������������ӵ����쾡�£����ܺ����ʢ��\n" NOR,me,target);

	j = i / 4;
        if ( i > 250 )  	j = to_int(i/ 4.0 * i/ 250.0);
        if ( focus > 15 ) focus = 15;
                                   	j += 5 * focus;

if(!userp(me)) j = j /4;
	me->add_temp("apply/attack", j /2);
	me->add_temp("apply/sword",  j );
  	me->add_temp("apply/damage", j );
	if(me->query_temp("ss/hb"))
        	me->add_temp("apply/damage", j);
me->set_temp("ss/fw",1);
if(!userp(target)) target->add_busy(2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if(me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

   if(me->is_fighting(target) && (int)me->query_skill("songshan-jian", 1) > 150 )
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if(me->is_fighting(target)) {
			weapon->unequip(); 
                   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
			weapon->wield();
		}  
		
		
	if(me->query_temp("ss/hb"))
		    me->add_temp("apply/damage", -j);
	       me->add_temp("apply/attack",-j/2);
	       me->add_temp("apply/sword",  -j );
       	me->add_temp("apply/damage", -j );
me->delete_temp("ss/fw");
	      me->add("neili", -350);
	      me->add("jingli", -150);
       	me->start_busy(random(2));
	     me->start_perform(3+random(2), HIB"����"NOR);
	return 1;
}

string perform_name(){ return HIB"����"NOR; }

int help(object me)
{
        write(HIB"\n��ɽ����֮�����衹��"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 800 ���ϣ�
                ������� 1200 ���ϣ�
                ��ǰ���� 500 ���ϣ�
                ��ɽ�����ȼ� 100 ���ϣ�
                ���������ȼ� 100 ���ϣ�
                ���������ȼ� 100 ���ϣ�
                ��������Ϊ��ɽ������
                �����м�Ϊ��ɽ������
                �����ڹ�Ϊ����������
                ���ֱֳ�����

HELP
        );
        return 1;
}
