// qiankun-nuoyi.c Ǭ����Ų��
// 1998-4-7
// snowman 1998-3-16

#include <ansi.h>
inherit SKILL;

string  *msg_weapon = ({
YEL"$N����һ�ӣ�����б$w"YEL"���ƣ����ϵ���ô����һ��֮�����ػ�����������˴�����Ѱ����\n"NOR,
RED"��֪$N��$W"RED"΢ת��ƽƽ�Ĵ���$w"RED"֮�ϣ�һ����͵ľ����ͳ�����$w"RED"ֱ���˿�ȥ��\n"NOR,
HIY"$N����̤������������$W"HIY"�ӳ���һ�ɾ�������$n�ĺ��ģ���λʱ�������ǡ���ô���\n"NOR,
HIC"$n��������һ�У�ԭ�Ǽ�����������������$N��ָһ����������ббж�˿�ȥ��\n"NOR,
BLU"$N��$n��$w"BLU"��Ҫ�����Ŀ�ʱ������ͻȻ�߳���ѹ��$w"BLU"��һ����˳��̤�䣡\n"NOR,
HIB"$N˫��ͬʱʩչŲ��Ǭ���ķ���һ����Х����������ڰ��������һ��ת�ۣ�ƮȻ����$n���ԣ�\n"NOR,
HIW"$n�书��ߣ�����$N��������Ϯ�����������$w"HIW"��Ҳ���Բ��$N��$W"HIW"��ʽ��\n"NOR,
YEL"$N������ָ���縧�ٹ�ɪ�������������������������㲻����Ƭ�̼佫$n����������ж�ˣ�\n"NOR,
GRN"$N�Ҵ��һ��̩ɽ������������Ȫ��������ȴ��ʹ��Ǭ����Ų�Ƶ��ַ�������$n����$w"GRN"��\n"NOR,
CYN"$N����$W"CYN"������$n$w"CYN"���ϣ�����������Ǭ����Ų���ķ���΢һ�˾����㽫$n�ľ��������ƿ��ˣ�\n"NOR,
});

string  *msg_unarmed = ({
HIC"һɲ�Ǽ�$N����Ϊ��ļ���ת�ۣ���ʹ����Ǭ����Ų���ķ��ĵ��߲��񹦣�\n"NOR,
HIW"$N��Ҳ����������������ǰ��Ǭ����Ų������б������������Ų����ж�˿�ȥ��\n"NOR,
GRN"��֪�ո��ഥ��ͻȻһ�ɾ�����$N���Ϸ�������ס��$n�ľ�����$N������ָ˳�ư���$n���ؿڣ�\n"NOR,
RED"���$Nʹ��Ǭ����Ų���ķ������Ű��Է�λ��������$n���е�ȥ�ơ�\n"NOR,
CYN"$N��ʹǬ����Ų�ƣ�Խ��Խ�죬�����������Ƶ磬���������ǰ������̽��ץ��$n��\n"NOR,
BLU"$N��ʱ����������ת��һ����������Ȼ��Ȼ������������֮$n�����������ִ�ö��ˣ�\n"NOR,
BLU"$n����һָ����$N��ͷ��ȴ��֪��α�����һ�����۵�һ�죬���������Լ��ֱۣ�ֻʹ����ǰ����ֱð��\n"NOR,
YEL"���������Ա���һ��������������$n������һ������$N����бб������\n"NOR,
YEL"$N����Ǳ��Ǭ����Ų���ķ���ʹ$n����$N��һ��Ī��������ﻬ��һ�ԡ�\n"NOR,
HIR"$N��ʹŲ��Ǭ���ķ���һǣһ�����е�һ�죬��$n��������ƫ��\n"NOR,
YEL"$N������ָ���縧�ٹ�ɪ�����������������Σ������㲻������$n���л������Σ�\n"NOR,
WHT"$N����Ǭ����Ų���ķ���ʹ$n����Ī�����������;ת�˷��������������Σ�\n"NOR,
CYN"Ǭ����Ų���񹦱�ã��εȰ�����$N��ָ�������ѵ�����$n˫��Ѩ����\n"NOR,
GRN"$Nʹ��Ų�ƴ�Ǭ����$n����Ī�����������;ת�˷��򣬴�����������Լ����˻�����\n"NOR,
});
int valid_enable(string usage){ return usage == "parry";}

int valid_learn(object me)
{
	if(me->query_skill("qiankun-danuoyi", 1) < 210)
		return notify_fail("Ǭ����Ų��ֻ��ͨ����ϰ��Ǭ����Ų���ķ�������������ߡ�\n");
	return 1;
}

int practice_skill(object me)
{
	if( me->query_skill("qiankun-danuoyi", 1) < 210 )
		return notify_fail("�㻹û�е��ܶ�����ϰǬ����Ų�Ƶľ��硣\n");
	if( me->query("neili") < 50 )
		return notify_fail("������������ˡ�\n");
	if( (int)me->query("jingli") < 80 )
		return notify_fail("������������ˡ�\n");
	me->receive_damage("jingli", 70);
	me->receive_damage("neili", 30);
	return 1;
}

void skill_improved(object me)
{
	int skill, lit, med;
	skill = me->query_skill("qiankun-danuoyi", 1);
	lit = me->query_skill("literate", 1);
	med = me->query_skill("medicine", 1);

	if(skill = 50 && !me->query("qkdny") && lit > 50){
		tell_object(me, HIY"�㰴����Ƥ�����飬�������С��ƹ�ʹ�������Ǻ��������ı������ˡ�\n"NOR);
		me->add("max_neili", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill = 80 && me->query("qkdny") == 1 && lit > 80){
		tell_object(me, HIM"�������ڶ����ķ�������ʩΪ��Ƭ��������ͨ��ֻ��ʮ����ָ֮�У��ƺ���˿˿���������\n"NOR);
		me->add("max_jingli", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill = 100 && me->query("qkdny") == 2 && lit > 100){
		tell_object(me, CYN"�㰴����Ƥ�����飬�߶�����������Ϊ֮����\n"NOR);
		me->add("max_neili", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill = 130 && me->query("qkdny") == 3 && lit > 120){
		message_vision(RED"$N��������͵�Ѫ�죬�������ȴ�����࣬���������㣬˫�۾��⾼���������ް���\n"NOR, me);
		me->add("max_jingli", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill = 150 && me->query("qkdny") == 4 && lit > 140){
		message_vision(HIW"$N���Ϻ�����죬������ʱ����΢������麮�������Ϻ�ʱ��ͷ�������¡�\n"NOR, me);
		me->add("max_neili", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill = 170 && me->query("qkdny") == 5 && lit > 160){
		tell_object(me, MAG"���������Ǳ������ɽ��ͻ������ȻĪ֮������ԭ����Ǭ����Ų���ķ��������㱾�������е�Ǳ����\n"NOR);
		me->add("max_neili", 20+random(30));
		me->add("qkdny", 1);
	}
	if(skill = 190 && me->query("qkdny") == 6 && lit > 180){
		tell_object(me, MAG"���͵�����Ѫ��ӿ�������ӿ죬����������Ǭ����Ų���񹦣�\n");
		me->add("max_neili", 50+random(30));
		me->add("qkdny", 1);
	}
}

string perform_action_file(string action)
{
	return __DIR__"qiankun-danuoyi/" + action;
}

int ob_hit(object ob, object me, int damage)
{
	object wp,wp1, target;
	string msg;
	int p, j, skill, neili, neili1, exp, exp1, xu, qi_wound;

	if( userp(me) && me->query("family/family_name") != "����" ) return 0;

	wp = me->query_temp("weapon");
	wp1 = ob->query_temp("weapon");
	skill = me->query_skill("qiankun-danuoyi", 1);
	neili = me->query("neili");
	neili1 = ob->query("neili");
	exp = me->query("combat_exp");
	exp1 = ob->query("combat_exp");
	if( wizardp(me) ) tell_object(me,sprintf("damage = %O\n",damage));

// hua
	if( me->query_temp("qkdny/hua") && living(me) && !me->is_busy() ) {
		if( me->query("jing") < damage/10 || me->query("jingli") < damage/10 ) {
			message_vision(HIW"$N��Ҫ��$n�Ĺ��ƻ��⣬�ķ�ȴ���������������󣡽��$N���һ�С�\n"NOR,me, ob);
			me->start_busy(1+random(2));
			return random(damage/5);
		}
		if( random(me->query_int(1)) > ob->query_int(1)/4
		 && random(me->query("combat_exp")) > ob->query("combat_exp")/3 ) {
			message_vision(HIW"$Nʹ��������ǧ��֮��������Ļ�����$n�Ĺ��ơ�\n"NOR,me,ob);
			me->add("jing",-damage/10);
			me->add("jingli",-damage/10);
			return -damage;
		}
		else {
			message_vision(HIW"$Nʹ��������ǧ��֮����������$n�Ĵ�빥�ơ�\n"NOR,me,ob);
			me->add("jing",-damage/20);
			me->add("jingli",-damage/20);
			return -damage/2;
		}
	}

// yin
	if( me->query_temp("qkdny/yin") && living(me) && !me->is_busy() ) {
		if( me->query("jing") < damage/10
		 || me->query("jingli") < damage/10
		 || me->query("neili") < damage/10 ) {
			message_vision(HIG"$N��Ҫǣ��$n�Ĺ��ƣ��ķ�ȴ�������������������󣡽��$N���һ�С�\n"NOR,me, ob);
			me->start_busy(1+random(2));
			return random(damage/5);
		}
		if( random(me->query_int(1)) > ob->query_int(1)/4
		 && random(me->query("combat_exp")) > ob->query("combat_exp")/3) {
			message_vision(HIG"$N����Ǭ����Ų�����־���$n�Ĺ��Ʋ�֪��ι�����$n�Լ���\n"NOR,me,ob);
			me->add("jing",-damage/10);
			me->add("jingli",-damage/10);
			me->add("neili",-damage/10);
			ob->receive_damage("qi",damage*2/3, ob);
			ob->receive_wound("qi",damage/5, ob);
			p = ob->query("qi")*100/ob->query("max_qi");
			msg = "( $N"+COMBAT_D->eff_status_msg(p)+" )\n";
			message_vision(msg,ob);
			return -damage;
		}
		else {
			message_vision(HIG"$N����Ǭ����Ų�����־���ǣ������$n�Ĵ�빥�ơ�\n"NOR,me,ob);
			me->add("jing",-damage/20);
			me->add("jingli",-damage/20);
			me->add("neili",-damage/20);
			return -damage/2;
		}
	}

// yi
	if( me->query_temp("qkdny/yi") && living(me) && !me->is_busy() ) {
		if( !objectp(target = me->query_temp("qkdny/yi"))
		|| environment(me) != environment(target) ) {
			me->delete_temp("qkdny/yi");
			tell_object(me, HIY"�㷢������Ų�Ƶ�Ŀ������Ѿ����������ˡ�\n"NOR);
			return 0;
		}
		me->delete_temp("qkdny/yi");

		if( !living(target) ) {
			tell_object(me, HIY"�㷢������Ų�Ƶ�Ŀ������Ѿ����Բ����ˡ�\n"NOR);
			return 0;
		}
		if( neili < 800 ) {
			tell_object(me, HIY"����ҪŲ�ƣ�ȴ�����Լ������������ˣ�\n"NOR);
			return 0;
		}

		message_vision(WHT"$NͻȻ˫�ֻζ�������������������Ҵ�Ҫ��$n���������Ա�����ǣ����\n"NOR,me, ob);
		if( exp < exp1/2 || random(neili) < neili1/2 ) {
			me->add("jingli", -25);
			me->add("neili", -125);
			message_vision(HIY"���$n��û���ܵ����ţ�����˳������$N�Ĳ��棬����ǿ����һ����\n"NOR,me, ob);
			return random(damage);
		}
		me->add("neili", -250);
		me->add("jingli", -50);
		tell_room(environment(me), "�������"+ob->name()+"������ֱ��"+target->name()+"�����ȥ��\n",({ target,ob }));
		tell_object(target, HIR"����㷢��"+ob->name()+"������ֱ���Լ����������\n"NOR);
		tell_object(ob, HIR"����㷢���Լ�������ֱ��"+target->name()+"�����ȥ��\n"NOR);
		if(target->query_skill("dodge") >= damage)
			msg = HIY"���$nû���ܵ��κ��˺���\n"NOR;

		else{
			target->receive_damage("qi", damage, ob);
			p = target->query("qi")*100/target->query("max_qi");
			msg = COMBAT_D->damage_msg(damage, "�˺�");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		if( target->query("shen") < -1000 && !target->is_killing(ob->query("id")) ) {
			if( random(target->query_int()) < 20 )
				target->kill_ob(ob);
			else if( random(target->query_int()) > 30 )
				target->fight_ob(me);
		}
		if( target->query("shen") > -1000 && !target->is_killing(ob->query("id")) ) {
			if( random(target->query_int()) < 20 )
				target->fight_ob(ob);
			else if( random(target->query_int()) > 30 )
				target->fight_ob(me);
		}
		message_vision(msg, me, target);
		return -8000;
	}

// xu
	if( me->query_temp("qkdny/xu") ) {
		if( me->query_temp("qkdny/xu") > 1000
		 || me->query_temp("qkdny/xu") > me->query("neili")/4 ) {
			msg = "\nǬ����Ų�ơ���־����������������˾�����\n";
			tell_object(me, msg);
			msg = HIY"$NͻȻ����һ�������������ʮ���Ƶ������鲢��Ϊһ��Ѹ������$n��\n"+
				"����һ�������ɽ�鱬��ʱ�����˺�ˮ���͵�����̱�������ˮ�������������\n"+
				"ԭ����˴�����$p������ʵ�ˣ�������ʱ��ǡ��۹ǡ���ǡ��߹�һ���۶ϣ���\n"+
				"ѪҲ�粻������������Ϊһ��Ѫ��ģ�������òҲ����ԣ�\n"NOR;
			qi_wound = me->query_temp("qkdny/xu") * (4+random(3));
			ob->receive_damage("qi", qi_wound, me);
			ob->receive_wound("qi", qi_wound/3*2+random(qi_wound/3), me);
			if( random(2) ) {
				p = (ob->query("eff_qi")+ob->query_temp("apply/qi"))*100/(ob->query("max_qi")+ob->query_temp("apply/qi"));
				msg += COMBAT_D->damage_msg(damage, "����");
				msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
			}
			else {
				p = ob->query("qi")*100/(ob->query("max_qi")+ob->query_temp("apply/qi"));
				msg += COMBAT_D->damage_msg(damage, "����");
				msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
			}
			me->delete_temp("qkdny/xu");
			message_vision(msg, me, ob);
			return -8000;
		}
		else {
			msg = "Ǭ����Ų�ơ���־���Ȼ���𣬽�������������������\n";
			tell_object(me, msg);
			xu = ob->query("jiali");
			xu += ob->query_skill("force")/8;
			if( me->query_skill("jiuyang-shengong", 1) )
				xu *= 2;
			if( me->is_busy() ) xu /= 2;
			me->add_temp("qkdny/xu", xu);
		}

		if( wizardp(me) )
			tell_object(me, "Qkdny/xu = "+me->query_temp("qkdny/xu")+"\n");

		if( damage/2 > me->query("neili") ) {
			tell_object(me, HIR"����Է�������̫����һ��С�ı���ɢ�˻����������\n"NOR);
			me->delete_temp("qkdny/xu");
			return damage/4;
		}
		ob->add_busy(random(2));
		if( !me->is_busy() )
			me->start_busy(random(2));
		return -damage/3;
	}

	if( me->query_temp("fanzhen") ) {
		me->delete_temp("fanzhen");
		return 1;
	}

	if( me->query("jiali")
	 && living(me)
	 && random(skill) + 20 > ob->query_skill("force", 1)/3
	 && random(exp) > exp1/4
	 && skill > 100 
	 && neili > 500 
	 && living(ob)
         && userp(me)
	 && !ob->query("env/invisibility") ) {
		if( random(2) ) me->add_temp("fanzhen", 1);
		me->add("neili",  -(random(10)));
		if( wp && wp1 ) {
			msg = msg_weapon[random(sizeof(msg_weapon))];
			msg = replace_string(msg, "$W", wp->name());
			msg = replace_string(msg, "$w", wp1->name());
			if( neili >= neili1 ) {
				if( random(me->query_str(1)) > ob->query_str(1)/3 && skill > 150 ) {
					msg += HIW"���$nһ���ֵ���ס������"+wp1->name()+HIW"������ַɳ���\n"NOR,
					me->add("neili", -50);
					ob->add_busy(2+random(2));
					j = -8000;
				}
				else {
					j = damage/2;
					if( j < skill*3/2 ) j = skill*3/2;
					ob->receive_damage("qi", j/6, me);
					ob->receive_wound("qi", j/9, me);
					p = ob->query("qi")*100/ob->query("max_qi");
					msg += COMBAT_D->damage_msg(j, "�˺�");
					msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
					j = -5000;
				}
			}
			else if( neili >= random(neili1)*2/3 ) {
				msg += "���������ж����$n��������\n";
				j = -5000;
			}
			else{
				j = damage/2+random(damage/2);
				if( me->is_busy() ) j = j/2;
				if( j < damage/2 ) msg += "���ж����һЩ$n��������\n";
				else msg += "���ж����$n����������\n";
				j = -j;
			}
			message_vision(msg, me, ob);
			return j;
		}
		else{
			msg = msg_unarmed[random(sizeof(msg_unarmed))];
			if( neili >= neili1 ) {
				j = damage/2;
				if( j < skill*3/2 ) j = skill*3/2;
				ob->receive_damage("qi", j/6, me);
				ob->receive_wound("qi", j/9, me);
				p = ob->query("qi")*100/ob->query("max_qi");
				msg += COMBAT_D->damage_msg(j, "����") + "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
				j = -8000;
			}
			else if( neili >= random(neili1)*2/3 ){
				msg += "���������ж����$n��������\n";
				j = -5000;
			}
			else {
				j = damage/2+random(damage/2);
				if( me->is_busy() ) j = j/2;
				if( j < damage/2 ) msg += "���ж����һЩ$n��������\n";
				else msg += "���ж����$nһ���������\n";
				j = -j;
			}
			message_vision(msg, me, ob);
			return j;
		}
	}
}
