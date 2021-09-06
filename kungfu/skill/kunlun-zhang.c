// ���� pfm ��������Ч�� by Lane@SJ
// kunlun-zhang.c ������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N�Ʒ缤����˫�ƴ��䣬���������޷���һ�С������ɽ��������$n��$l",
	"lvl" : 0,
	"skill_name" : "�����ɽ",
	"damage_type" : "����"
]),
([
	"action" : "$N˫������һ�С������Ƶ�����һ�ƻ���$n���ţ���һ��ȴ����$nС��",
	"lvl" : 30,
	"skill_name" : "�����Ƶ�",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�ƻ������Ī�⣬һ�С���粻������ǰ�����ң�˲Ϣ֮����$n����������һʮ����",
	"lvl" : 60,
	"skill_name" : "��粻��",
	"damage_type" : "����",
]),
([
	"action" : "$Nһ����Х������һ�ƣ�һ�С�ɽ��·ת��������ת׾��ȴ��ȥ����죬��$n��$l�ͻ���ȥ",
	"lvl" : 100,
	"skill_name" : "ɽ��·ת",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�ƽ����������ޣ�һ�С������޷졹������$n��$l",
	"lvl" : 120,
	"skill_name" : "�����޷�",
        "damage_type" : "����"
]),
([
	"action" : "$Nһ�С���ɽ�Ϻӡ�������һȭ���������ƽ���������ȭ��һ����˫������������$n��$l",
	"lvl" : 140,
	"skill_name" : "��ɽ�Ϻ�",
	"damage_type" : "����"
]),
([
	"action" : "$N˫���뻮������˫�����ƣ�һ�С������ء���һ����ɽ������������ֱ��$n����",
	"lvl" : 160,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" : "$NͻȻ�������ת��һ�С���ɽѩƮ������Ӱ���裬��ʱ֮�佫$n����˷�����ס��",
	"lvl" : 180,
	"skill_name" : "��ɽѩƮ",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	mapping fam  = me->query("family");
	if (fam["family_name"] != "������" || fam["generation"] != 2)
		return notify_fail("������ֻ�ܴӺ������ѧ����\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ( me->query_skill("xuantian-wuji", 1) < 120)
		return notify_fail("��������޼�����򲻹����޷��������ơ�\n");
	if(me->query("gender") != "Ů��"){
		if ( me->query_skill("zhentian-quan", 1) < 80 && !me->query_skill("kunlun-zhang", 1))
			return notify_fail("�������ȭ���ڰ�ʮ�����޷��������ơ�\n");
	}
	else {
		if ( me->query_skill("chuanyun-tui", 1) < 80 && !me->query_skill("kunlun-zhang", 1))
			return notify_fail("��Ĵ�����С�ڰ�ʮ�����޷��������ơ�\n");
	}
	if ( me->query("max_neili") < 800)
		return notify_fail("���������Ϊ�������޷��������ơ�\n");
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
	level = (int) me->query_skill("kunlun-zhang",1);

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if( me->query_temp("diezhang1") ) {
				me->delete_temp("diezhang1");
				return ([
					"action": HIR"$N˫��ƽƽ�Ƴ������ƻ���֮����������������ʵ�ھ�ǰ����̣�����ɱ�У�"NOR,
					"lvl": action[j]["lvl"],
					"damage_type": action[j]["damage_type"],
					"force": 200 + random(500),
					"dodge": random(30)-10,
					"parry": random(20),
				]);
			}
			else if( me->query_temp("diezhang2") > 0 ) {
				return ([
					"action": YEL+action[j]["action"]+NOR,
					"lvl": action[j]["lvl"],
					"damage_type": action[j]["damage_type"],
					"force": 200 +random(350),
					"dodge": random(30),
					"parry": random(10),
				]);
			} else
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 200 +random(350),
				"dodge": random(30)-10,
				"parry": random(20),
			]);

		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("kunlun-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"kunlun-zhang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( victim->query("qi") < 0 ) return;

	if( me->query_temp("diezhang2") > 1 ) {
		me->add_temp("diezhang2", -1);
		COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(2)?1:3);
	}
}
