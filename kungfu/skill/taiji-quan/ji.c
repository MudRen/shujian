// zhen.c ̫��ȭ�������־�
// snowman
#include <ansi.h>

inherit F_SSERVER;
string *taiji_msg = ({"��ȸβ","����","��������","�׺�����","§ϥ����","��������","��̽��",
"����ʽ","������","�𼦶���","��Ů����","��������","�乭�仢","������ɽ",});

string perform_name(){ return HIR"���־�"NOR; }

int perform(object me, object target)
{
	int damage, force, ap, dp;
	string msg, *limbs;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target))
		return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( userp(me) 
	&&( me->query_skill_mapped("parry") != "taiji-quan"
	&& me->query_skill_mapped("parry") != "taiji-jian") )
		return notify_fail("�����־�����������̫��ȭ��̫���������мܵ�����²���ʹ�á�\n");

	if( userp(me) && (me->query_skill_mapped("force") != "yinyun-ziqi"
	|| me->query_skill_prepared("cuff") != "taiji-quan") )
		return notify_fail("����ڹ���ȭ�����ԣ��������ܷ��ӳ������־��������ơ�\n");  

	if( !me->query_temp("tj/̫��") && me->query_skill("taiji-quan", 1) < 300 )
		return notify_fail("̫��ȭҪּ�����ɷ��ɣ���û�����á�̫�������������ʹ�á������־���\n");

	if( (int)me->query("neili", 1) < 500 )
		return notify_fail("����������������ǿ��ʹ�á������Ƿ��Ӳ������������ģ�\n");

	if( (int)me->query("jingli", 1) < 100 )
		return notify_fail("�����ھ���������ǿ��ʹ�á������Ƿ��Ӳ������������ģ�\n");                     

	if( me->query_temp("weapon"))
		return notify_fail("���ȷ������е�������˵�ɣ���\n");     

	limbs = target->query("limbs");

	msg = CYN "\n$Nʹһ��̫��ȭ��"+taiji_msg[random(sizeof(taiji_msg))]+"�����ҽ�ʵ������飬����"RED"������"CYN"�־���ճ��ճ�棬�����Ѵ�ס$p"+limbs[random(sizeof(limbs))]+"��\n"NOR;
        
	force = me->query_skill("force") + target->query_skill("force");

	ap = me->query("combat_exp", 1) /1000 * me->query_skill("force");
	dp = target->query("combat_exp",1 )/ 1000 * target->query_skill("parry");
if(me->query("quest/wdjiuyang/pass") )  ap =ap * 2;
	if( random(ap + dp) > dp ){
		if(!target->is_busy()) target->start_busy(random(2));
		damage = (me->query_skill("force")+ me->query_skill("wudang-jiuyang",1) )*2;                
		if(me->query("neili") > target->query("neili")*2) 
			damage *= 2;
		else if(me->query("neili") > target->query("neili")*3/2) 
			damage += random(damage);
		else if(me->query("neili")*2 < target->query("neili")) 
			damage /= 2;
		else if(me->query("neili") < target->query("neili")) 
			damage -= random(damage/2);
		else damage = damage/2 + random(damage);
                
		if(damage> 2400) damage = 2400; 
		target->receive_damage("jingli", damage);
		target->receive_damage("neili", damage);
	      target->receive_wound("jing", damage, me);
		me->add("neili", -300);
		me->add("jingli", -100);
		msg += HIR"����$P�ᾢ������$p����ôһ�������ӱ��Լ��ľ������ò���������ǰһ�壬���������\n"NOR;       
	}
	else{
		me->add("jingli", -25);
		me->add("neili", -100);
		msg += HIY"$p�����龰��һ�����棬��æ�ջ��Լ��ľ�����������ã�\n"NOR;
	}
	me->start_busy(random(2));
	me->start_perform(2, "������"); 
	message_vision(msg, me, target);
	return 1;
}

int help(object me)
{
	write(WHT"\n̫�������־�����"NOR"\n");
	write(@HELP
	Ҫ��	���� 500 ���ϣ�      
		���� 200 ���ϣ�      
		����̫��ȭ�������ޱ�����
HELP
	);
	return 1;
}
