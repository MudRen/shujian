// weituo-gun.c -Τ�ӹ�

inherit SKILL;

mapping *action = ({
([
	"action":"$Nһ�С���ʯ���ġ�������$w�����ѵ�ˮ�㣬������$n������Ҫ����ȥ",
	"lvl" : 0,
	"skill_name" : "��ʯ����",
	"damage_type":"����"
]),
([
	"action":"$N��$wƽ���ؿڣ�һš��һ�С�����ͣ�桹��$w�͵�����$n�ľ���",
	"lvl" : 8,
	"skill_name" : "����ͣ��",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С�ƽ�����ɡ���ȫ���������ڵ��ϴ����ת���ٹ���$n���ظ����ȥ",
	"lvl" : 16,
	"skill_name" : "ƽ������",
	"damage_type":"����"
]),
([
	"action":"$N����һ��������һ�С��������硹��$wЮ��������Ѹ��ɨ��$n������",
	"lvl" : 25,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С����Ǹ��¡��������һ�����˱Ƴ�һ��ֱ�ߣ����ǰ�����$n��$l",
	"lvl" : 35,
	"skill_name" : "���Ǹ���",
	"damage_type":"����"
]),
([
	"action":"$N˫�ֳֹ����˸���ش�Ȧ��һ�С���ϼ���ա���һ����Բ�����л�����ײ��$n���ؿ�",
	"lvl" : 44,
	"skill_name" : "��ϼ����",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С�Ͷ�޶�������$w�߾٣����������֮�ƶ�׼$n�����鵱ͷ����",
	"lvl" : 52,
	"skill_name" : "Ͷ�޶���",
	"damage_type":"����"
]),
([
	"action":"$NǱ��������һ�С������麣����$w��ʱ�������ɣ�������ֱ��$n���ؿ�",
	"lvl" : 60,
	"skill_name" : "�����麣",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return  (usage == "club") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("yijin-jing", 1) < 20)
		return notify_fail("����׽�ڹ����̫ǳ��\n");
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
	level   = (int) me->query_skill("weituo-gun",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 100 + random(250),
				"dodge": random(20)-10,
				"damage": 40 + random(60),
				"parry": random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("weituo-gun", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("�������������Τ�ӹ���\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}
