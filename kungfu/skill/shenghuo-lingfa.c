// shenghuo-lingfa ʥ���
// 1997-5-14
inherit SKILL;
#include <ansi.h>
string  *msgl = ({
"$Nһʽ���������󡹺��ط��֣�$w��β�����ϵ��������벻����λ������$n��ȥ",
"$Nƽƽһ�������һʽ�����·ת����$w�ڰ�չŹŹֵֹ�ת�˸��䣬����$n��$l",
"$NͻȻһ����Х��˫��һ�С�������ʵ������ʵʵ�����Ƕ��ǵĻ���$n��$l",
"$N��Ȼ��ͷ��һʽ��ͷͷ�ǵ�����һ��ͷ����$nײȥ������$wȴ���е���$n��$l��ȥ",
"$NͻȻ�������һʽ�����������������������Ľ���׹������$w��$n��$l��ȥ",
"$N���ش��أ�һʽ������������������صĿ޺ţ�ͻȻ����߷�ɳ�����$w��$n����",
"$NĬ��ھ���$wһ�С�Ӧ����󡹣���ָǰ�أ�ͻ��һת�䣬��$n�ı��Ĵ�Ѩ��ȥ",
"$Nʹ������ʥ�����е�һ�С�������ǰ����������$n�ұۣ�$wȴ��Է���ǰ��Ѩ��ȥ",
"$Nһ�С��������С�����֪��Σ������Ѿ����$w������һ�ڣ������ޱȵĴ���$n��$l",
"$N���е�$w����һ������Ȧ�ӣ����С��췽��԰��һ������ʱ����$n�ۻ����ң���֪����"
});
string  *msgc = ({
"$N����Ϊ����һ�С�������ʤ��������б�ɣ���������$n�߳��Ľ�",
"$Nһʽ��������ȫ���������ڵ���һ�������ֱ���$n��$l�����ֻ����ж���Ѩ",
"$NͻȻ��һʽ���Խ�Ϊ�ˡ���������ǰһ�����Ľ��������£�˫����$n$l��ȥ",
"$N����һ����һʽ��������ա��������շ��˼������Ľ�������$n��$lץȥ",
"$Nһ�����һʽ���������ڡ������ڰ�գ�����ʱ�ҽŵ�ϥ����$n�ض�һ��",
"$N��ǰһ����һʽ��Ͷ���ͱ�����ײ��$n�Ļ��У�˫����$n$l��Ѩ��ײȥ",
"$N���ش��أ�һʽ����ɳ��ʯ�����������صĿ޺ţ�ͻȻ����߷�ɳ��������$n����"
});

string  *msg2 = ({
HIW"$Nֱ����ǰ������һ�٣���Ȼһ���ˤ�˹�ȥ��˫��$w"HIW"ȴ����$n�ؿ����˹�ȥ"NOR,
HIR"$Nƽƽһ�������$w"HIR"�ڰ�;�ŹŹֵֹ�ת�˸��䣬�ĵ�һ�죬����$n��$l"NOR,
MAG"$N��$w"MAG"���뻳�У�����һ̽����ץס$n��ţ�Ӳ������$n�ڰ�������˻���"NOR,
HIY"$N˫��$w"HIY"���Ӻ�ɨ��$n����һת������ܿ��������ĵ�һ�죬$l�ѱ�$w"HIY"����"NOR,
YEL"$n����ٿ��ץס��$N���ֵ�$w"YEL"����֪��$w"YEL"β�����ϵ����ĵ�һ�죬���ô���$n����"NOR,
GRN"$N�����ڵأ�˫ȭ�ʹ��Լ����ţ���$n����ͻȻ����߷�ɳ�����$w"GRN"��$n��$l����"NOR,
HIG"$N����΢б���ұ������$w"HIG"��Ī������ķ�λת�˹������ĵ�һ������$n��$l���ش�ȥ"NOR
});

int valid_enable(string usage)
{
        return usage == "dagger" || usage== "cuff" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
	string msg;

	if(me->query_temp("tisha")){
		switch(me->query_temp("tisha")) {
			case 4: msg = HBBLU+HIW"$Nֱ����ǰ������һ�٣���Ȼһ���ˤ�˹�ȥ��˫������$n�ؿ����˹�ȥ"NOR; break;
			case 3: msg = HBBLU+HIC"$N�����ڵأ�˫ȭ�ʹ��Լ����ţ���$n����ͻȻ����߷�ɳ�����$w"HBBLU+HIC"��$n��$l����"NOR;break;
			case 2: msg = HBBLU+HIM"$n����ʱ֮�䣬������ѩ���棬˫�۲��ܼ��ãȻ��֪���룬$N������"YEL"�粿"HBBLU+HIM"�ӱ�����$nײȥ"NOR; break;
			case 1: msg = HBBLU+HIR"$N����$n��ȥʽ������"HIR"Ǭ����Ų����"HBBLU+HIR"���굽$n����ǰ��������$w"HBBLU+HIR"��$n��$l��ȥ"NOR;break;
			default: msg = HBBLU+HIW"$Nֱ����ǰ������һ�٣���Ȼһ���ˤ�˹�ȥ��˫������$n�ؿ����˹�ȥ"NOR; break;
		}  
		me->add_temp("tisha", -1);
		return ([
			"action": msg,
			"force" : 250 + random(350),
			"dodge": random(30),
			"parry": random(30),
			"damage": me->query_temp("type")? 50+random(50):130 + random(140),
			"damage_type" : me->query_temp("type")? "����":"����",
		]);
	}
	if (!weapon)
		return ([
			"action":msgc[random(sizeof(msgc))],
			"damage_type":"����",
			"dodge":random(30),
			"parry":random(30),
			"force":random(300)+ 150,
		]);
	if( me->query_temp("ling") && random(2))
		return ([
			"action" :msg2[random(sizeof(msg2))],
			"force" : random(350) + 300,
			"dodge": random(30),
			"parry": random(30),
			"damage": 180+ random(90),
			"damage_type":random(2)?"����":"����",
		]);
	return ([
		"action":msgl[random(sizeof(msgl))],
		"damage": 80 + random(140),
		"damage_type":random(2)?"����":"����",
		"dodge": random(30)-10,
		"force": random(350)+200,
		"parry": random(20),
		"post_action": (: call_other, WEAPON_D, "bash_weapon" :)
	]);
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 50)
		return notify_fail("�������������ʥ�����\n");         
	if ((int)me->query("neili") < 10)
		return notify_fail("�������������ʥ�����\n");
	me->receive_damage("jingli", 40);
	me->receive_damage("neili", 15);
	return 1;
}

int valid_learn(object me)
{
	object weapon = me->query_temp("weapon");
	int skill = me->query_skill("shenghuo-lingfa", 1);
       
	if (!weapon || weapon->query("skill_type") != "dagger")
		return notify_fail("��û��ʹ�õ�������\n");

	if (me->query("max_neili") < 1000)
		return notify_fail("�������������\n");
	if (!me->query_skill("jiuyang-shengong"))
	if (me->query_skill("shenghuo-shengong", 1) < (skill-10)
	&& me->query_skill("shenghuo-shengong", 1) < 200)
		return notify_fail("���ʥ���񹦻��̫ǳ��\n");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"shenghuo-lingfa/" + action;
}
