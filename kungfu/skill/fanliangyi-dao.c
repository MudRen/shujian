// fanliangyi-dao.c �����ǵ�

inherit SKILL;

mapping *action = ({
([
	"action" : "$N������������桱λ���������ַ��������»��������������������������$n���������ƣ�",
	"lvl" : 0,
	"skill_name" : "���»���",
	"damage_type" : "����"
]),
([
	"action" : "$N��̤���Ƿ�λ�������ߣ�һ�С���ٲ���������������$w����̹Ǻ��磬��$n���뵶���������У�",
	"lvl" : 15,
	"skill_name" : "��ٲ���",
	"damage_type" : "����"
]),
([
	"action" : "$Nʹ������ɫ���ࡹ���������á������ƾ�������ֱ�Ķ���������$wȴ������Ϣ����$n��$l��",
	"lvl" : 35,
	"skill_name" : "��ɫ����",
	"damage_type" : "����"
]),
([
	"action" : "$N��������������ġ���$wһʽ��̫�����ȡ���������ٱ�ض�׼$n��$l������ȥ��",
	"lvl" : 50,
	"skill_name" : "̫������",
	"damage_type" : "����"
]),
([
	"action" : "$N��ǰ����һ�����Ⱦݡ�������ʹ�������Ǻϵ¡����Ӷ�$w��$n�����������ն������",
	"lvl" : 65,
	"skill_name" : "���Ǻϵ�",
	"damage_type" : "����"
]),
([
	"action" : "$Nš��תʩչ������һ�ơ�����Ȼ�ӵ��ӱ��󷴻��˸����Σ�����������ն��$n$l��",
	"lvl" : 80,
	"skill_name" : "����һ��",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zixia-gong", 1) < 10)
		return notify_fail("�����ϼ�񹦻��̫ǳ��\n");
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
	level   = (int) me->query_skill("fanliangyi-dao",1);
	for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	150+random(300),
				"dodge":	random(30),
				"damage":	160 + random(100),
				"parry":	random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("fanliangyi-dao", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40)
		return notify_fail("��ľ��������������ǵ���\n");
	if ((int)me->query("jingli") < 20)
		return notify_fail("������������������ǵ���\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"fanliangyi-dao/" + action;
}
