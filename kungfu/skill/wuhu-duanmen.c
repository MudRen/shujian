//Cracked by Roath
// wuhu-duanmen. �廢���ŵ�
// kane

inherit SKILL;

mapping *action = ({
([	"action" : "$N�յ��뻳��һ�С��׻�����������շ���һ����Ծ�������Ի�����$n��$lֱ�����",
	"force" : 210,
      "dodge" : 10,
	"damage" : 20,
	"lvl" : 0,
	"skill_name" : "�׻�����",
	"damage_type" : "����"
]),
([	"action" : "$N����Ȧת��һ�С��������硹�����ⲻס�������������ع��ˣ���$n������ס",
	"force" : 210,
      "dodge" : 10,
	"damage" : 30,
	"lvl" : 8,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ����ȣ�����˶��ġ����ˡ����죬˳��һ��ն�£���δ�������ȵ�������һ�С�һХ���硹��",
	"force" : 210,
      "dodge" : 5,
	"damage" : 30,
	"lvl" : 16,
	"skill_name" : "һХ����",
	"damage_type" : "����"
]),
([	"action" : "$N���ֱ�����һ�С����Ӷɺӡ�������$wת����Բ�����һƬ������סȫ�������$n��$lֱ���ȥ",
	"force" : 240,
      "dodge" : 15,
	"parry" : 15,
	"damage" : 40,
	"lvl" : 24,
	"skill_name" : "���Ӷɺ�",
	"damage_type" : "����"
]),
([	"action" : "$N�յ����ƣ�ʹһ�С��ؽ����塹�����治���������ߣ������Դ���$nȫ����Ŷ���$N��������֮��",
	"force" : 240,
      "dodge" : 20,
	"parry" : 20,
	"damage" : 40,
	"lvl" : 33,
	"skill_name" : "�ؽ�����",
	"damage_type" : "����"
]),
([	"action" : "$N����һ��������������һ�������������ĵ��������������޼᲻�ݣ������廢���ŵ��������͵ġ������ĵ���",
	"force" : 300,
      "dodge" : 5,
	"damage" : 60,
	"lvl" : 42,
	"skill_name" : "�����ĵ�",
	"damage_type" : "����"
]),
([	"action" : "$N���������һ�С��۰�Ⱥɽ�������ưԵ��Ѽ����������磬���쵶����$nϯ���ȥ",
	"force" : 300,
      "dodge" : 25,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "�۰�Ⱥɽ",
	"damage_type" : "����"
]),
([	"action" : "$N˫Ŀ�������������м��ƣ�����һ�С�����ʤʨ�����ƻ�$nǰ�أ�����$n$l������������ŭ�����࣬��ӿ����Ϯ��$n",
	"force" : 300,
      "dodge" : 30,
	"damage" : 50,
	"lvl" : 60,
	"skill_name" : "����ʤʨ",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
/*
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
*/
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
	int i, level;
	level   = (int) me->query_skill("wuhu-duanmen",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ����������廢���ŵ���\n");
	me->receive_damage("jingli", 25);
	return 1;
}
