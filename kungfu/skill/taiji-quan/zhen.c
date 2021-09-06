// zhen.c ̫��ȭ�����־�
// snowman
#include <ansi.h>

inherit F_SSERVER;

string *taiji_msg = ({"ʮ����","����Ʊ�","������","Ұ�����","б����","����","����","��ͨ��"});

string perform_name(){ return HIR"���־�"NOR; }

int perform(object me, object target)
{
	int damage, p, m, force, ap ,dp;
	float at;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target) )
		return notify_fail("�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( userp(me) && !me->query_temp("tj/̫��") && me->query_skill("taiji-quan", 1) < 300 )
		return notify_fail("̫��ȭ���������ⲻ�ϣ���û�����á�̫�������������ʹ�á����־���\n");

	if( userp(me) && (me->query_skill_mapped("force") != "yinyun-ziqi"
	 || me->query_skill_prepared("cuff") != "taiji-quan") )
		return notify_fail("����ڹ���ȭ�����ԣ��������ʹ�á����־���\n");

	if( (int)me->query("neili", 1) < 1000 )
		return notify_fail("����������������ǿ��ʹ�á����־�ֻ���˵����Լ���\n");

	if( me->query_temp("weapon") )
		return notify_fail("���ȷ������е�������˵�ɣ���\n");

	msg = CYN "\nͻȻ��$Nһ�С�"+taiji_msg[random(sizeof(taiji_msg))]+"����˫������������һ��ԲȦ�ѽ�$n��ס��̫��ȭ��"RED"����"CYN"�־��漴ʹ����\n"NOR;

	force = me->query_skill("force") + target->query_skill("force");

	ap = me->query("combat_exp", 1)/ 1000 * me->query_skill("force");
if(me->query_skill("wudang-jiuyang") ) ap =ap *2;
	dp = target->query("combat_exp", 1)/1000 * target->query_skill("force");

	if( random( ap + dp) > dp ){
			if( me->query("neili") < target->query("neili")*3/2 ) {
				me->start_busy(2);
				target->add_busy(2);
				me->add("jingli", -force/10);
				me->add("neili", -force/2);
                       	target->add("jingli", -force/10);
                       	target->add("neili", -force/2);
				msg += HIY"ֻ����ž����һ����$p��$P����������ƴ�������������˼�����\n"NOR;
				me->start_perform(2, "����");
				message_vision(msg, me, target);
				return 1;
			}
			me->start_busy(random(2));

			damage = (int)me->query_skill("force") * 4;

if( me->query_skill("wudang-jiuyang") )  damage = damage + me->query_skill("wudang-jiuyang",1) * 4;

			at = me->query("neili") / (target->query("neili")+1);
                
			if( at < 1 ) {
				if(at < 0.5) damage /= 2;
				damage /= 2;
			}
			else damage = to_int(damage * at);


			if( me->query_skill("taiji-quan", 1) > 300 ) 
			m = 4000 + ( me->query_skill("taiji-quan", 1) - 300 ) * 10 + random(200);
			else m = 4000;

			if( !userp(me) ) m = 4000;

			if( damage > m ) damage = m + (damage-m)/20;
			if( damage > 8000 ) damage = 10000 + (p-8000)/50;
			if( wizardp(me) ) tell_object(me, "��ġ�"RED"���־�"NOR"������Ϊ�� "+damage+"��\n"NOR);

			if( wizardp(me) && (string)me->query("env/combat")=="verbose")
			tell_object(me, "M_neili = "+me->query("neili")+ " T_neili = "+target->query("neili")+" Damage = "+damage+"\n");

			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/(2+random(2)), me);
			target->receive_damage("neili", damage/(2+random(2)), me);
                    target->add("jing",-(me->query_int(1)+ me->query_con(1))* 3 );

			me->add("neili", -400);
			me->add("jingli", -150);
			me->start_perform(3, "����");

			if( damage >= me->query_skill("taiji-quan", 1) * 10 )
				msg += "̫��֮�����಻�ϣ�������ȥ�пգ�һ��ԲȦδ�꣬�ڶ���ԲȦ����������һ�죬$pһ����ͷ���ʶϣ�\n";
			if( damage >= me->query_skill("taiji-quan", 1) * 12 ){
				msg += "$N���������������־�ʹ��ʱ���಻�ϣ����ſ�����������$pȫ�������ͷҲ��һһ�ʶϣ�\n";
			       target->receive_wound("jing", damage/(2+random(2)), me);}
			p = (int)target->query("eff_qi")*100/(int)target->query("max_qi");

			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
	else{
		msg += HIY"$pһ�����ԣ�����һ�󼱹���$P��ʱ��æ���ң���Ҳ���������У�\n"NOR;
		me->start_busy(random(2));
		me->add("jingli", -50);
		me->add("neili", -150);
		me->start_perform(2, "����");
	}
	message_vision(msg, me, target);
	return 1;
}

int help(object me)
{
	write(WHT"\n̫�������־�����"NOR"\n");
	write(@HELP
	Ҫ��	���� 1000 ���ϣ�      
		���� 200 ���ϣ�      
		����̫��ȭ�������ޱ�����
HELP
	);
	return 1;
}
