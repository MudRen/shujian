// lieyan-dao.c ���浶

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһ�С�����������$w����һ��������$n���������Σ�����������仯����",
	"lvl" : 0,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С���ˮǧɽ����������һǰһ��$w����������$n��$lնȥ",
	"lvl" : 10,
	"skill_name" : "��ˮǧɽ",
	"damage_type" : "����"
]),
([
	"action" : "$N����Ծ�䣬һ�С���ɨǧ���$w���ż������һ������$n��ɨ��ȥ",
	"lvl" : 20,
	"skill_name" : "��ɨǧ��",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С����ҿ�������$w�󿪴��أ����Ҳ�������һ������һ����$n�����翳��",
	"lvl" : 30,
	"skill_name" : "���ҿ���",
	"damage_type" : "����"
]),
([
	"action" : "$N����$w���϶��£�һ�С����ɷ��١���������к����һƬѩ���ٲ�����$n��ͷ��",
	"lvl" : 40,
	"skill_name" : "���ɷ���",
	"damage_type" : "����"
]),
([
	"action" : "$N����$w��ʹ��һ�С�ֱ���������������ã����ҿ�����ǧ�����������$n",
	"lvl" : 50,
	"skill_name" : "ֱ������",
	"damage_type" : "����"
]),
([
	"action" : "$N���õ��羢����һ�С�����������һ����ת������������$n��$l����ȥ",
	"lvl" : 60,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$N��ǰһ��������һ�С��ϲ���ɽ����$wֱֱ��������һƬ�����ĵ�Ӱ��$n��ȫ����ȥ",
	"lvl" : 70,
	"skill_name" : "�ϲ���ɽ",
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
	if (me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ( !me->query_skill("jiuyang-shengong", 1))
	if (me->query_skill("shenghuo-shengong", 1) < 20)
		return notify_fail("���ʥ���񹦻��̫ǳ��\n");
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
	level   = (int) me->query_skill("lieyan-dao",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 100 +random(250),
				"dodge": random(20)-10,
				"parry": random(10),
				"damage": 40 + random(60),
			]);
		}
	}
}

int practice_skill(object me)
{
        int lvl = me->query_skill("lieyan-dao", 1);
        int i = sizeof(action);
        while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 30 || me->query("neili") < 10 )
                  return notify_fail("����������������浶��\n");
        me->receive_damage("jingli", 20);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
	return __DIR__"lieyan-dao/" + action;
}
