//  shandian-daofa���絶��

inherit SKILL;

mapping *action = ({
([
	"action" : "$N��Ӱ��˫�����⸡����ת���������ŵ�����$n��$l��ȥ",
	"lvl" : 0,
	"skill_name" : "���絶��",
	"damage_type" : "����"
]),
([
	"action" : "$N����ﵶ����$n���ߣ�����֮�죬������˼������$w�Ѹ���$n���������",
	"lvl" : 50,
	"skill_name" : "���絶��",
	"damage_type" : "����"
]),
([
	"action" : "$N����$w����һ�٣����������ǻ��գ�����������ˢ��һ�����϶�����$n����",
	"lvl" : 100,
	"skill_name" : "���絶��",
	"damage_type" : "����"
]),
([
	"action" : "$N���ַ�ִ�������ᵶһն��$wֱ��$n�ľ��л�ȥ",
	"lvl" : 150,
	"skill_name" : "���絶��",
	"damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level   = (int) me->query_skill("shandian-daofa",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	150+random(300),
				"dodge":	random(30),
				"parry":	random(30),
				"damage":	60 + random(100),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 40)
		return notify_fail("����������������絶����\n");
	if ( me->query("neili") < 20)
		return notify_fail("����������������絶����\n");
        me->receive_damage("jingli", 30);
	me->add("neili", -10);
        return 1;
}

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	return 1;
}
