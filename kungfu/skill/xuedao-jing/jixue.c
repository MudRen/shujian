// jixue.c  Ѫ���� [��Ѫ��]
// coded by emnil@sj	2/5/2000

#include <ansi.h>
#include <skill.h>
#include <combat.h>
#include <weapon.h>
inherit F_SSERVER;

string perform_name(){ return HIR"��Ѫ��"NOR; }

void jixue(object me,object target,int times,int now);
 
int perform(object me, object target)
{
	object ob,weapon;
	string msg;
	int lvl,times;
    
	if( !me->is_fighting() )
		return notify_fail("����Ѫ�񵶡�ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
 
	if((int)me->query_skill("xuedao-jing",1) < 120)
		return notify_fail("��ĵ�����Ϊ������ Ŀǰ����ʹ�á���Ѫ�񵶡�! \n");

	if(me->query_temp("xs/jixue"))
		return notify_fail("������ʹ�á���Ѫ�񵶡�! \n");

	if((int)me->query_skill("longxiang-boruo",1) < 120)
		return notify_fail("��������������Ϊ������ Ŀǰ����ʹ�á���Ѫ�񵶡�! \n");

	if( me->query_skill_mapped("blade") != "xuedao-jing")
		return notify_fail("�����ʹ��Ѫ����������ʹ�á��񵶴��ġ��ľ�����\n");

	if( me->query_skill_mapped("force") != "longxiang-boruo")
		return notify_fail("��������ʹ�õ��ڹ�ͬ���������������ִ�������ʹ������Ѫ�񵶡��ľ�����\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("���������Ϊ������\n");
	if((int)me->query("neili")<500)
		return notify_fail("�������������\n"); 
	if((int)me->query("jingli")<300)
		return notify_fail("��ľ���������\n"); 

	ob = me->select_opponent();
	lvl = me->query_skill("xuedao-jing",1);
	me->set_temp("xs/jixue",1);
	times = me->query("env/jixue");
	if(times < 1) times = 1;
	if(times > lvl/40) times = lvl/40;
	if(times > 6) times = 6;

	msg = HIR"\n$N��ɫ��Ȼһ�䣬���������дʣ�ͬʱ��ת���У���֪��Ҫ��ʲô��\n\n"NOR;
	message_vision(msg, me);
	me->add("neili", -100);
	me->start_perform(10,"��Ѫ��");

	call_out("jixue",0,me,ob,times,0);

	return 1;
}

void jixue(object me,object target,int times,int now)
{
	string msg,weaname;
	object weapon;
	int lvl,force,damage,attack,qi;

	if( !objectp(me) ) return;
	if( !objectp(target) || !me->is_fighting(target) || (now >= times) || (me->query("neili")<200) || 
	  (!objectp(weapon = me->query_temp("weapon"))) || ((string)weapon->query("skill_type")!="blade") ) {
		me->set_temp("xs/jixue",0);
		me->start_perform(1,"��Ѫ��");
		if(living(me))
			message_vision(HIC"\n$N�����ջ��ھ�������Ҳ�ƺ�����Ѫɫ��\n"NOR, me);
		return;
	}

	weapon = me->query_temp("weapon");
	weaname = weapon->query("name");
	lvl = me->query_skill("xuedao-jing",1);
	force = me->query_skill("longxiang-boruo",1);

	now++;
	if(now <= 1)
		msg = HIR"\n$N��Хһ�����Ա����Կ��ֱۣ���ʱһ���Ѫ�ɽ���"NOR+weaname+HIR"֮�ϣ�"NOR+weaname+HIR"��������һ��Ѫɫ��";
	else
	if(now <= 3)
		msg = HIR"\n$N��Хһ�����Ա����Կ����ţ���ʱһǻ��Ѫ�ɽ���"+weaname+HIR"֮�ϣ�"NOR+weaname+HIR"����һ��Ѫɫ��";
	else
		msg = RED"\n$N��Хһ������ͷ�����Լ�һ������ʱһ����Ѫ�ɽ���"+weaname+RED"֮�ϣ�"NOR+weaname+RED"�������ͨ�죡����";
	
	attack = 7-now;
	damage = 8-now;
	if(me->query_temp("xs/longxiang")) {
		damage--;
		if(damage<2) damage=2;
		msg += "$N���������ھ����ڱ���֮�ϣ�";
	}
	msg += "\n"NOR;
	message_vision(msg, me);
	if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("damage:%d , attack:%d , qi:%d \n",force/damage,lvl/attack,-50*now));

	me->add_temp("apply/damage", force/damage);
	me->add_temp("apply/attack", lvl/attack);

	if (present(target,environment(me)) && me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	if (present(target,environment(me)) && me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	me->add_temp("apply/damage", -force/damage );
	me->add_temp("apply/attack", -lvl/attack);

	if(me->query("qi") < (60*now)) 
		qi = me->query("qi")-10;
	else
		qi = 60*now;
	if(qi<0) qi = 0;

	me->receive_damage("qi", qi);
	me->receive_wound("qi", qi/2);

	me->add("neili", -50*now);
	if(me->query("neili") < 0)	me->set("neili",0);

	call_out("jixue",2+random(3),me,target,times,now);
}
