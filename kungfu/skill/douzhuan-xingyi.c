// douzhuan-xingyi ��ת����
// 1997-2-14

inherit SKILL;

#include <ansi.h>
#include <combat.h>

string *parry_msg = ({
YEL"�����һ��������������$Nһ��һ����$N��������Խ����������һ�ԡ�\n",
HIB"$N����һ����������$l��$n����$N��$l������Ī��������ﻬ��һ�ԡ�\n",
HIW"$N˫��ǰ̽����۴���$n�ұۣ��ұ�ʹ��$n��������$n���л�ȥ��\n",
HIY"$N���ƶ�ת��$n����Ī�����������;ת�˷���ֱ���Լ�Ϯ����\n",
YEL"$N�����Ϲۣ�˫����Է��ཻ���ƣ�̸Ц�侹ʹ��$n�������գ�ʹ��$n��֪����Ǻá�\n",
HIB"$N����������$n�͹����ʹ������������$n�ĳ�����������$n�������������С�\n",
HIW"ֻ��$N����Ʈ�磬ǡ���������ƣ������һʽ��˫�ƶ����޶�����׽��������$n��$l��\n",
HIY"$N����Ʈ�������������ƶ�ת֮�䷴��$n����������$n��ȴ����$n��˼������⡣\n",
});

string *colors = ({YEL,HIB,HIW,HIY,YEL,HIB,HIW,HIY});

int valid_enable(string usage)
{
	return usage == "parry";
}
/*
string query_parry_msg(object weapon)
{
	return parry_msg[random(sizeof(parry_msg))] + "��\n";
}
*/
int valid_learn(object me)
{
	return notify_fail("��ת����ֻ��ͨ����������ߡ�\n");
}

int practice_skill(object me)
{
	return notify_fail("��ת����ֻ��ͨ����������ߣ��޷�ͨ����ϰ����ߡ�\n");
}

int ob_hit(object ob, object me, int damage)
{
	object weapon, weapon1;
	string msg, *limbs, limb, attack_skill, str, str1;
	int ap, dp, skill, size, i;

	if( ob->query("env/invisibility") ) return 0;

	if( me->query_temp("fanzhen")){
		me->delete_temp("fanzhen");
		return 0;
	}

	weapon1 = me->query_temp("weapon");

	if (me->query_skill("douzhuan-xingyi", 1) < 150
	 || me->query_skill_mapped("parry") != "douzhuan-xingyi"
	 || me->query_skill("shenyuan-gong", 1) < 150
	 || me->query("combat_exp") < ob->query("combat_exp")/2 ) 
		return 0;

	skill = me->query_skill("douzhuan-xingyi", 1);
	weapon = ob->query_temp("weapon");

	if ( weapon) str = weapon->query("skill_type");
	if ( weapon1) str1 = weapon1->query("skill_type");
	if ( str != str1 ) return 0;

	if(objectp(weapon))
		msg = weapon->query("skill_type");
	else {
		mapping prepare = ob->query_skill_prepare();
		if (!sizeof(prepare)) msg = "unarmed";
		else msg = keys(prepare)[0];
	}

	if ( me->query("neili") < ob->query("neili")/5 ) return 0;

	if ( weapon ){
		attack_skill = weapon->query("skill_type");
		attack_skill = ob->query_skill_mapped(str);
	}
	else
		attack_skill = ob->query_skill_prepared(msg);

	if (! attack_skill ) return 0;

	ap = COMBAT_D->skill_power(ob, msg, SKILL_USAGE_ATTACK) / 1000;
	if ( weapon ) ap *= 2;
	if ( ob->query("neili") > me->query("neili") * 2 ) ap += ap/2;
	if ( me->is_busy()) ap /= 2;

	dp = COMBAT_D->skill_power(me, "parry", SKILL_USAGE_DEFENSE) / 1000;
	if ( me->query("neili") > ob->query("neili") * 2 ) dp *= 2;
	else if ( me->query("neili") > ob->query("neili") / 2 * 3 ) dp += dp/2;
if(me->query_skill( "douzhuan-xingyi",1)>=451 ) dp *=2;
	ap = ABS(ap);
	dp = ABS(dp);

	if ( wizardp(me)) tell_object(me, sprintf("ap: %d, dp: %d\n", ap ,dp ));

	if ( random(dp + ap) > ap && random(2)) {
		limbs = ob->query("limbs");
		limb = limbs[random(sizeof(limbs))];
		size = sizeof(parry_msg);
		i = random(size);
		msg = parry_msg[i];
		msg += SKILL_D(attack_skill)->query_action(ob, weapon)["action"];
		msg = replace_string( msg, "$l", limb);
		if (weapon1)
			msg = replace_string( msg, "$w", weapon1->name()+colors[i]) + "��\n"NOR;
		else
			msg += "��\n"NOR;
		if (userp(ob) && !userp(me) && damage > 1800)
			damage = 1800 + random (50);
		ob->receive_damage("qi", damage + me->query("jiali")*2, me);
		ob->receive_wound("qi", damage/2, me);
		if (! weapon1)
			msg += COMBAT_D->damage_msg(damage, "����");
		else 
			msg += COMBAT_D->damage_msg(damage, "����");
		msg = replace_string( msg, "$l", limb);
		if (weapon1)
			msg = replace_string( msg, "$w", weapon1->name());
		message_vision(msg, me, ob);
		COMBAT_D->report_status(ob, ob->query("qi") >= 0 || ob->query("eff_qi")+ob->query_temp("apply/qi") < 0);
		me->set_temp("fanzhen", 1);
		return -6000;
	}
	return 0;
}

string perform_action_file(string action)
{
	return __DIR__"douzhuan-xingyi/" + action;
}
