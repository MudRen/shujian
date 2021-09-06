//fogang.c �������
// by snowman@SJ

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, ap, dp, p, lvl;
	float at;
	string msg, dodge_skill;
 
	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target)
	 || !living(target))
		return notify_fail("��������ա�ֻ����ս����ʹ�á�\n");

	if(objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á�������ա���\n");

	if( me->query_skill("linji-zhuang", 1) < 150 && !wizardp(me))
		return notify_fail("����ټ�ʮ��ׯδ�ɣ�����ʹ�á�������ա���\n");

	if((int)me->query("max_neili") < 2000 )
		return notify_fail("���������Ϊ���㣬����ʹ�á�������ա���\n"); 

	if((int)me->query("neili") < 1000 )
		return notify_fail("�������������㣬����ʹ�á�������ա���\n"); 

	if((int)me->query_skill("jieshou-jiushi", 1) < 150 )
		return notify_fail("��Ľ��־�ʽ������죬����ʹ�á�������ա���\n");

	if((int)me->query_str(1) < 25)
		return notify_fail("����������㣬�޷����ӡ�������ա������ơ�\n");

	if((int)me->query_con(1) < 25)
		return notify_fail("��ĸ���Ƿ�ѣ��޷�ʹ�á�������ա���\n");

	if(me->query_skill_prepared("hand") != "jieshou-jiushi"
	|| me->query_skill_mapped("hand") != "jieshou-jiushi"
	|| me->query_skill_mapped("parry") != "jieshou-jiushi")
		return notify_fail("�����ȫ�����ý��־�ʽ������ʹ�á�������ա���\n");

	if(me->query_skill_mapped("force") != "linji-zhuang" && !wizardp(me))
		return notify_fail("�㲻ʹ���ټ�ʮ��ׯ����ô��ʹ�á�������ա���\n");

	if(me->query_temp("huanying")) 
		return notify_fail("������ʹ�����λ�Ӱ��������ʹ�á�������ա���\n");

	if(me->query_temp("shuangdao_hebi")) 
		return notify_fail("������ʹ�á�˫����赡����޷�ʹ�á�������ա���\n");

	msg = MAG "\nֻ��$N����ׯ�ϣ�ͻȻ��ȫ������з����������ĵ���΢����֮�����������\n"+
		"����δ����һʽ��"HIY"�������"MAG"������һ��������Ʈ����ϣ���������ƽ���һ\n"+
		"���ھ����������ˣ������������Ƶ磬��һ���ĳ�����ʽƽƽ������һ��\n"+
		"���䣬����$n����ȴ���޿ɵ������޿ɱܣ�\n"NOR;
 lvl = me->query_skill("hand") + me->query_skill("force");
	ap = me->query("combat_exp")/ 1000 * me->query_skill("jieshou-jiushi",1) * me->query_str(1) / 200;;
	dp = target->query("combat_exp")/ 1000 * target->query_skill("force", 1) * target->query_con(1)/ 200;

	if ( target->is_busy())
		dp -= dp/3;

if(me->query("max_pot")<=450 ) ap = ap*2;

	if(random( ap + dp ) > dp) {
		target->add_busy(random(2));
		damage = me->query_skill("hand") + me->query_skill("force");
		damage += me->query("jiali") * 15;
             damage = damage + random(damage/2);
		if(target->query("neili") < 10) at = 8;
		else at = me->query("neili") / (target->query("neili")+1);
		if(at < 1){
			if(at < 0.5) damage /= 2;
			else damage /= 1;
		}
		else if (at < 2 ) at = 2;

		else damage = to_int(damage*at);

		damage = random(damage) + damage/2;
		if (target->query_skill_mapped("force") == "jiuyang-shengong"
		&& target->query_skill("jiuyang-shengong", 1) > 100 && userp(target)){
			tell_object(me, HIY"\n��֪��һ�ƴ���"+target->name(1)+"���ϣ�ȴ���罭���뺣������ˮ�齻�ڣ�������ʱ��Ӱ���٣�\n"NOR);
			msg += "��������Ȼһ�����죬$N�Ѵ�����$n�ؿڣ�ֻ��$p��Ȼȫ��������顣��֪һ�ƹ�ȥ��\n"+
				"$n��¶��ɫ�����ö˶˵�վ�ţ�$Nȴ���������ң�����΢΢������\n";
			target->add_busy(2);
			message_vision(msg, me, target);
			me->add("neili", -500);
			me->add("jingli", -100);
			me->start_perform(2, "��������ա�");
			return 1;
		}
		if((target->query_skill_mapped("force") == "yijin-jing"
		|| target->query_skill_mapped("force") == "yinyun-ziqi")
		&& target->query_temp("fanzhen")) 
			damage /= 2;
		else
			damage *= 2;

    //          	if (damage > 5000) damage = 5000 + (damage-5000)/100;
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", random(damage), me);
		target->receive_damage("neili", damage/4);
		me->receive_damage("neili", 500);
		if(damage >= 4000)
			msg += HBCYN"��һ������ʹ����ȫ����˿��������أ�$n����������������������֮�䣡\n"NOR;
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += COMBAT_D->damage_msg(damage, "����");
		msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		message_vision(msg, me, target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;

	 if(!userp(target) && (random(2)|| p < 30) )  target->unconcious();
     
		me->start_perform(4, "��������ա�");
	}
        else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		msg += MAG"\n$N��һ�����У������ڿ��л���һ�����ߣ�����˳�ֳ�$n�ٹ��˼��У�\n"NOR;
		message_vision(msg, me, target);
    
      me->add_temp("apply/damage",  lvl/6);
      me->add_temp("apply/attack",     lvl/6);

		COMBAT_D->do_attack(me, target, 0, 3);
		COMBAT_D->do_attack(me, target, 0, 3);
		COMBAT_D->do_attack(me, target, 0, 3);
	   
	    me->add_temp("apply/damage",  -lvl/6);
       me->add_temp("apply/attack",     -lvl/6);		
		me->add("neili", -200);
		me->start_perform(3, "��������ա�");
	}
	me->add("jingli", -100);
	me->start_busy(random(2));
	return 1;
}

string perform_name(){ return MAG"�������"NOR; }

int help(object me)
{
	write(MAG"\n���־�ʽ֮��������ա���"NOR"\n\n");
	write(@HELP
	Ҫ��	��ǰ���� 1000 ���ϣ�
		������� 2000 ���ϣ�
		���־�ʽ�ȼ� 150 ���ϣ�
		�ټ�ʮ��ׯ�ȼ� 150 ���ϣ�
		�������� 25 ���ϣ�
		������� 25 ���ϣ�
		�����ַ�Ϊ���־�ʽ��
		�����м�Ϊ���־�ʽ��
		�����ұ����־�ʽ��

HELP
        );
        return 1;
}
