// wuhu-duanmendao.c �廢���ŵ�
// Modified By Numa@SJ 2000.7

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N������$w����һ�����漴��������һ�ݣ��ԡ��ͻ���ɽ��֮������$n",
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "�ͻ���ɽ"
]),
([
	"action" : "$Nһ�С����絹��������$w��������ֱֱ����$nС��",
	"damage_type" : "����",
	"lvl" : 40,
	"skill_name" : "���絹��"
]),
([
	"action" : "$N��������������תһ�ܣ�����$w����һ�С���ɳ��ʯ������$n",
	"damage_type" : "����",
	"lvl" : 80,
	"skill_name" : "��ɳ��ʯ"
]),
([
	"action" : "$Nȫ������һԾ��ԼĪ�����ʱ�����´ܣ�һ�С����ذ���ֱȡ$n����",
	"damage_type" : "����",
	"lvl" : 120,
	"skill_name" : "���ذ�"
]),
([
	"action" : "$N����һ����������������$w֮�ϣ���һ�С���ɨ���¡�ֱ��$n˫ϥ",
	"damage_type" : "����",
	"lvl" : 150,
	"skill_name" : "��ɨ����"
]),
([
	"action" : "$N����ͻȻ���ȣ����ֻ��˸�ԲȦ�������Ե�����ס���ƣ�һ�С�����ɽ�ӡ���$n��ѹ��ȥ",
	"damage_type" : "����",
	"lvl" : 200,
	"skill_name" : "����ɽ��"
]),
});

int valid_enable(string usage) {return (usage == "blade") || (usage == "parry");}

int valid_learn(object me)
{
	object weapon;

	if ( me->query_skill("wuhu-duanmendao", 1) < 150)
		return notify_fail("���廢���ŵ�����ѧֻ�ܴ��ؼ�������\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("blade", 1) < 30)
		return notify_fail("��Ļ���������򲻹���\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level   = (int) me->query_skill("wuhu-duanmendao",1);

	if( random(10) > 5
	&& me->query_skill("blade", 1) >= 120
	&& level >= 120
	&& me->query_skill("force") >= 150
	&& me->query("neili") >= 500
	&& random(level) >= 100 ) {
		me->add("neili", -25);
		if (me->query("mao18/pass2")) {
			if (me->query("mao18/pass3"))
				switch (random(6)) {
					case 0 :
					case 2 :
					case 4 :
						return ([
							"action":	HIY"$N�������أ�����$w"HIY"����$n���裬��һʽ��"HIR"�廢����"HIY"����ѧ�ٽ�$nΧ�ڵ���֮��"NOR,
                                                        "damage":	250,
							"force":	550,
							"dodge":	random(20),
							"parry":	random(20),
							"damage_type":	"����"
						]);
						break;
					case 1 :
					case 3 :
						return ([
							"action":	HIR"$N˫�ֽ�߬����$w"HIR"������Բ���Ȼһʽ���ͻ���ɽ����ݺݵ�����$n"NOR,
							"damage":	200,
							"force":	500,
							"dodge":	random(20),
							"parry":	random(20),
							"damage_type":	"����"
						]);
						break;
					case 5 :
						return ([
							"action":	HIC"$NĿ¶�׹⣬��$n̤��ǰʱ��һʽ��������ʳ��������$w"HIC"��$n���迪ȥ"NOR,
							"damage":	160,
							"force":	450,
							"dodge":	random(20),
							"parry":	random(20),
							"damage_type":	"����"
						]);
						break;
				}
			else
				switch (random(3)) {
					case 0 :
					case 2 :
						return ([
							"action":	HIR"$N˫�ֽ�߬����$w"HIR"������Բ���Ȼһʽ���ͻ���ɽ����ݺݵ�����$n"NOR,
							"damage":	200,
							"force":	500,
							"dodge":	random(20),
							"parry":	random(20),
							"damage_type":	"����"
						]);
						break;
					case 1 :
						return ([
							"action":	HIC"$NĿ¶�׹⣬��$n̤��ǰʱ��һʽ��������ʳ��������$w"HIC"��$n���迪ȥ"NOR,
							"damage":	160,
							"force":	450,
							"dodge":	random(20),
							"parry":	random(20),
							"damage_type":	"����"
						]);
						break;
				}
		}
		else
			return ([
				"action":	HIC"$NĿ¶�׹⣬��$n̤��ǰʱ��һʽ��������ʳ��������$w"HIC"��$n���迪ȥ"NOR,
				"damage":	160,
				"force":	450,
				"dodge":	random(30),
				"parry":	random(30),
				"damage_type":	"����"
			]);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action":	action[j]["action"],
				"damage_type":	action[j]["damage_type"],
				"lvl":		action[j]["lvl"],
				"force":	200 + random(350),
				"damage":	80 + random(140),
				"dodge":	random(30)-10,
				"parry":	random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 50)
		return notify_fail("��������������廢���ŵ�����\n");
	if ( me->query("neili") < 20)
		return notify_fail("��������������廢���ŵ�����\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wuhu-duanmendao/" + action;
}
