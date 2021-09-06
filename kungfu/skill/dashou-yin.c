// dashou-yin.c ���ڴ���ӡ
//  by iceland

inherit SKILL;
mapping *action = ({
([
	"action" : "$Nʹ��һ�С���������ӡ����˫�ƺ�ʮ��ֱֱײ��$n��ǰ��",
	"skill_name" : "��������ӡ",
	"lvl" : 0,
	"damage_type" : "����",
]),
([
	"action" : "$Nʹ��һ�С����ƹ���ӡ��������Ծ��˫���繴��ץ��$n��$l",
	"skill_name" : "���ƹ���ӡ",
	"lvl" : 10,
	"damage_type" : "����",
]),
([
	"action" : "$Nʹ��һ�С�׼���ĸӡ����������ָ��ֱȡ$n��$l",
	"skill_name" : "׼���ĸӡ",
	"lvl" : 20,
	"damage_type" : "����",
]),
([
	"action" : "$Nʹ��һ�С���������ӡ����ŭ��һ����һ�Ƶ�ͷ����$n��$l",
	"skill_name" : "��������ӡ",
	"lvl" : 30,
	"damage_type" : "����",
]),
([
	"action" : "$Nʹ��һ�С�ҩʦ�����ӡ�����ͳ���ǰ�����������㹥��$n",
	"skill_name" : "ҩʦ�����ӡ",
	"lvl" : 40,
	"damage_type" : "����",
]),
([
	"action" : "$Nʹ��һ�С����½��ӡ������������˫������ɨ��$n��$l",
	"skill_name" : "���½��ӡ",
	"lvl" : 50,
	"damage_type" : "����",
]),
([
	"action" : "$Nʹ��һ�С����ֽ��ӡ���������Ծ��˫��ǰ�������ץ��$n���ʺ�",
	"skill_name" : "���ֽ��ӡ",
	"lvl" : 60,
	"damage_type" : "����",
]),
([
	"action" : "$Nʹ��һ�С������ǻ�ӡ������ʱ��������������г���������Ӱ����$n��$l",
	"skill_name" : "�����ǻ�ӡ",
	"lvl" : 70,
	"damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ڴ���ӡ������֡�\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("�������̫���ˣ����������ڴ���ӡ��\n");
	if ( me->query_skill("longxiang-boruo", 1) < 20)
		return notify_fail("���������������̫ǳ������ѧ���ڴ���ӡ��\n");
	if ( me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ������ѧ���ڴ���ӡ��\n");
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
	level   = (int) me->query_skill("dashou-yin",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"weapon": action[j]["weapon"],
				"force":100+random(250),
				"dodge":random(20)-10,
				"parry":random(10),
			]);
		}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("dashou-yin", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 30)
		return notify_fail("����������������������ڴ���ӡ��\n");
	if ( me->query("neili") < 10)
		return notify_fail("����������������������ڴ���ӡ��\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"dashou-yin/" + action;
}
