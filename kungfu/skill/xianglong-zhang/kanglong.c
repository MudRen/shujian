// �����л�
// by snowman@SJ 16/10/99
// modify by looklove 2001.10.04
// Modify by lsxk@hsbbs 2007/7/2
// By Spiderii@ty �жϾ���������,�Ҹ���!
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HIY"�����л�"NOR; }
int kanglong_attack(object me, int flag);

int perform(object me, object target)
{
   int tmp,damage,lvl,j;
   string msg;

   if( !target ) target = offensive_target(me);

        if( !objectp(target)
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
               return notify_fail("�������лڡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á������лڡ���\n");

	if( (int)me->query_skill("xianglong-zhang", 1) < 200 )
		return notify_fail("��Ľ���ʮ���ƻ�������죬ʹ�����������лڡ�������\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 180 )
		return notify_fail("��Ļ��������ȼ���������ʹ�����������лڡ�������\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("�����õ��ڹ����ԣ�ʹ�����������лڡ�������\n");

	if( (int)me->query_skill("force") < 270 )
		return notify_fail("����ڹ��ȼ�����������ʹ�á������лڡ���\n");

	if( (int)me->query_str(1) < 40 )
		return notify_fail("�������������ǿ����ʹ�����������лڡ�������\n");

	if( me->query_skill_prepared("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("parry") != "xianglong-zhang")
		return notify_fail("�������޷�ʹ�á������лڡ���\n");

	if( (int)me->query("max_neili") < 4000 )
		return notify_fail("����������̫����ʹ�����������лڡ���\n");

	if( (int)me->query("neili") < 1500 )
		return notify_fail("����������̫����ʹ�����������лڡ���\n");

	if( (int)me->query("jingli") < 1000 )
		return notify_fail("��ľ����������޷�ʹ�á������лڡ�������\n");
/*
	if( (int)me->query_temp("xlz/xiao") )
		return notify_fail("���Ѿ���ʼ�ˡ�����Х����\n");
*/
	if( !me->query("xlz/hang") )
		return notify_fail("�㻹û���򵽡������лڡ��ľ��裬�޷�ʹ�ô�����������\n");

   lvl = (int)me->query_skill("xianglong-zhang",1);
   tmp = 1 + (lvl-200)/10;
   if(tmp>18) tmp = 18;

   message_vision(HIY"\n$N�е��������У�������΢�������ƻ��˸�ԲȦ��ƽ�Ƴ�ȥ�����ǽ���ʮ�����еġ������лڡ���\n"+
   "���Ƴ�ȥ�������赭д����һ��������ɲʱ֮������"+ chinese_number(tmp)+ "���ᾢ��һ��ǿ��һ�������ص�����\n"+
   "ֱ���޼᲻�ݣ���ǿ���ƣ�\n"NOR,me);

   me->start_perform(3+random(3), "�������лڡ�");
 me->receive_damage("neili", 1000+random(500));
 me->receive_damage("jingli", 100+random(200));
   if(((int)me->query("pur")>28 && random(3))
     ||random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2
     ||random((int)me->query_con()) > target->query_con()/2
     ||random((int)me->query_skill("xianglong-zhang",1)) > (int)target->query_skill("parry",1)/2
     ||target->is_busy() ) {
       damage = lvl*(tmp + (int)me->query("str")/10)/2;
       if(me->query("gender")!="����" || !userp(me)) damage = damage/2;
       if(wizardp(me)) write("damage is "+ damage + "!\n");
       target->receive_damage("qi", damage, me );
       target->receive_wound("qi", damage/2 , me);
       target->set_temp("xlz/kanglong1",1);
       msg = HIR"$nֱ����һ�ƱƵ����޿��ˣ����޿��ã����صر������ؿڣ�������Ѫ���磡\n"NOR;
       msg += COMBAT_D->damage_msg(damage,"����");
       message_vision(msg,me,target);
       COMBAT_D->report_status(target, 0);
   }
   else{
       message_vision(HIC"$n���������˸��͵��Ʒ�����æ�͵�һ����ԶԶ�Ķ��˿�ȥ��ֻ�ŵ���ð�亹��\n"NOR,me,target);
       target->add_busy(1+random(2));
       target->delete_temp("xlz/kanglong1");
       me->start_perform(3, "�������лڡ�");
   }
   if(userp(me) && lvl>=250 && target->query_temp("xlz/kanglong1") && me->query("combat_exp") > target->query("combat_exp")/2)
       if(random((int)me->query_con()) > target->query_con()/2 || target->is_busy()){
         msg = HIW"�⡸�����лڡ�֮��Ҫ���ڡ������ֶ��ڡ��ڡ��֣�$N��"+ chinese_number(tmp)+ "���ᾢ�շ��������������˻�����\n"+
               "$nȴ����֪����ֻ����$N����һ����������ʶ�߶�ȫ���ھ���֮���⣬����"+ chinese_number(tmp)+ "���ᾢȴͻȻƾ\n"+
               "����ʧ��$n������ɿ����ھ�ȴ�޷��ջأ���ʱ�㱻�Լ�������ھ������ǰһ�ڣ�������������ը��\n"+
               "һ�����ܣ���Ҳ֧�ֲ�ס�ˣ�\n"NOR;
         message_vision(msg,me,target);

j = target->query("str");
if (j < 50) j =  target->query("con");
if (j < 50) j =  target->query("dex");
if (j < 50) j =  target->query("int");

         if( j <50 )
         if( (int)target->query("con")<15 
             ||( random(me->query("str")) > target->query("con")*2/3
             && random(me->query("combat_exp")) > target->query("combat_exp")*2/3)){
               target->set("eff_qi",-1);
               target->delete_temp("xlz/kanglong1");
               COMBAT_D->report_status(target,1);
               return 1;
         }
       damage = lvl*(tmp + 4 - (int)target->query("con")/10 + (int)me->query("str")/10)/2;
       if(me->query("gender")!="����") damage = damage/2;
       if(wizardp(me)) write("damage is "+ damage +"!\n");
       target->receive_damage("qi", damage, me );
       target->receive_wound("qi", damage , me);
       message_vision(COMBAT_D->damage_msg(damage,"����"),me,target);
       COMBAT_D->report_status(target, 0);
       target->delete_temp("xlz/kanglong1");
       return 1;
   }
   target->delete_temp("xlz/kanglong1");
   return 1;
}

/*
	tell_object(me, HIC"\n�㻺����˫���ᵽ��ǰ����Ϣ������������ת��Խ��Խ�죬������ȴ�������κζ���...\n\n"NOR);
	me->set_temp("no_fight", 1);
	me->start_busy(random(2));
	me->start_perform(10, "�������лڡ�");
	me->start_call_out( (: call_other, __FILE__, "kanglong_attack", me , 1 :), i);
	return 1;
}
*/
int kanglong_attack(object me, int flag)
{
	object target;
	int i;

	if( !me ) return 0;

	me->delete_temp("no_fight");

	if( !living(me) || me->is_ghost() ) return 0;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !living(target)
	 || !me->is_fighting(target)
	 || environment(target) != environment(me) ) {
		tell_object(me,"�������лڡ�ֻ����ս���жԶ���ʹ�á�\n"); 
		return 1;
	}

	if( me->query_skill_prepared("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("parry") != "xianglong-zhang"
	 || me->query_temp("weapon")){
 		tell_object(me,"�������޷�ʹ�á������лڡ���\n"); 
		return 1;
	}

	if( me->query_skill_mapped("force") != "huntian-qigong" ) {
 		tell_object(me,"�����õ��ڹ����ԣ��޷�ʹ���������лڡ���\n"); 
		return 1;
	}

	if( objectp(me->query_temp("weapon")) ) {
 		tell_object(me,"�������޷�ʹ�á������лڡ���\n"); 
		return 1;
	}

	if( (int)me->query("neili") < 1500 ) {
		tell_object(me,"�������������㣬ʹ�����������лڡ���\n");
		return 1;
	}

	if( (int)me->query("jingli") < 1000 ) {
		tell_object(me,"�����ھ���������ʹ�����������лڡ���\n");
		return 1;
	}

	if( (int)me->query_temp("xlz/xiao") ) {
		tell_object(me,"���Ѿ���ʼ�ˡ�����Х����\n");
		return 1;
	}

	if( me->is_busy() ) {
		call_out("kanglong_attack", 1, me, 1);
		me->set_temp("no_fight", 1);
		if( wizardp(me) ) tell_object(me,"����æ�����Թ˲�Ͼ���ȴ���...\n");
		return 1;
	}

	i = me->query_skill("xianglong-zhang", 1) + random(me->query_str(1));

	if( userp(target) ) i = i*2/3;

//	�жϿ����������ȼ�
	if( !flag ) flag = 1;
	i /= flag;

	if( me->query_temp("bishen_target") )
		target->set_temp("xlz/hanglong",1);
	else
		me->set_temp("xlz/hanglong", 1);

	me->add_temp("apply/attack", i);
	me->add_temp("apply/strength", i);
	me->add_temp("apply/damage", i/2);
	me->add_temp("apply/strike", i/2);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

	me->add_temp("apply/attack", -i);
	me->add_temp("apply/strength", -i);
	me->add_temp("apply/damage", -i/2);
	me->add_temp("apply/strike", -i/2);

	me->delete_temp("xlz/hanglong");
	me->receive_damage("neili", 1000+random(500));
	me->receive_damage("jingli", 200);
	me->start_perform(3+random(2),"�������лڡ�");
	return 1;
}

int help(object me)
{
	write(YEL"\n����ʮ����֮�������лڡ���"NOR"\n");
	write(@HELP
	�������ֽ���ʮ������ƥ�������������ҡ�
	�������������Ʊ��߶�������Ǵ˾��С�

	Ҫ��	��ǰ���� 1500 ���ϣ�
		������� 4000 ���ϣ�
		��ǰ���� 1000���ϣ�
		�����Ƶȼ� 200 ���ϣ�
		���������ȼ� 180 ���ϣ�
		�ڹ���Ч�ȼ� 270 ���ϣ�
		���� 40 ���ϣ�
		�����м�Ϊ�����ƣ�
		�����߹�ָ��󷽿�ʹ�á�
HELP
	);
	return 1;
}
