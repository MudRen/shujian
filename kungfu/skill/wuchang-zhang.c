// wuchang-zhang.c �޳��ȷ�

inherit SKILL;

mapping *action = ({
([
	"action":"$N΢һ����һ�С�ӹ�����š���$w���Ŵ̶���֨֨��������ɨ��$n�Ľ���",
	"lvl" : 0,
	"skill_name" : "ӹ������",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С�����Ƿǡ���������ס�ȶˣ����ƾ���һ��������ƾ���Ե���$n�ļ�ͷ",
	"lvl" : 20,
	"skill_name" : "����Ƿ�",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С����񲻰���������$wƹƹ���ҵ��������ã���$n�����ұܣ��Ǳ�����",
	"lvl" : 40,
	"skill_name" : "���񲻰�",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С�������ɫ��������$w�������ض���һ�ᣬͻȻ�͵�һ�ȴ���$n��$l",
	"lvl" : 50,
	"skill_name" : "������ɫ",
	"damage_type":"����"
]),
([
	"action":"$N��$w��ס�Լ������ţ�һ��ָ��$n��һ�С��ľ��������������к��ų���$n",
	"lvl" : 60,
	"skill_name" : "�ľ�����",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С���ʬ���⡹��ȫ��ֱ�������ų���ǰ�У��䲻������������$n��ȥ",
	"lvl" : 80,
	"skill_name" : "��ʬ����",
	"damage_type":"����"
]),
([
	"action":"$N�����ɫ��һ�С���������������$n˵���䣬һ����$n�Ŵ�����ͱ�˹�ȥ",
	"lvl" : 90,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С��������ġ������⽫$wˤ����ϣ���$n������һ�Ź��𣬻���$n��$l",
	"lvl" : 100,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([
	"action":"$N����װ����һ�С���;û·����һ������������$w��������������$n���ɲ�",
	"lvl" : 110,
	"skill_name" : "��;û·",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С�����ľ�������������Ų��ƣ�$wȴֱ�ɰ�գ���ƫ���е�����$n��$l",
	"lvl" : 120,
	"skill_name" : "����ľ��",
	"damage_type":"����"
]),
([
	"action":"$N�߾�$w��һ�С��˹���;������������Ȱ�Ʈ������׼$n�������һ�ȴ���",
	"lvl" : 130,
	"skill_name" : "�˹���;",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С���������������ȶ�����$w���ǧ�ٸ����ƣ���������$nȫ�����Ҫ��",
	"lvl" : 150,
	"skill_name" : "�������",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ( me->query("max_neili") < 800)
		return notify_fail("�������������\n");
	if ( me->query_skill("yijin-jing", 1) < 80)
		return notify_fail("����׽�ڹ����̫ǳ��\n");
	if ( me->query_skill("pudu-zhang",1) <=100)
		return notify_fail("����ն��ȷ��Ļ�����Ƿ�ѣ��޷�ѧϰ�޳��ȷ���\n");
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
	level   = (int) me->query_skill("wuchang-zhang",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 150 + random(300),
				"dodge": random(30),
				"damage": 60 + random(100),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("wuchang-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40 || me->query("neili") < 20)
		return notify_fail("��������������޳��ȷ���\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}
