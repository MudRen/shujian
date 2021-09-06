// qianye-shou.c -����ǧҶ��
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһʽ���Ϻ���𡹣�������Σ���������ͻȻ����$n�ı����Ѩ",
	"lvl" : 0,
	"skill_name" : "�Ϻ����",
	"damage_type" : "����"
]),
([
	"action" : "$N����һ�Σ�һʽ����������������������$n�ļ�ͷ����ȭ����$n��$l",
	"lvl" : 20,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ�����������������ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
	"lvl" : 40,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$N�������У�����ֱ����һʽ�������Ӱ������Ʈ��������$n��$l",
	"lvl" : 60,
	"skill_name" : "�����Ӱ",
	"damage_type" : "����"
]),
([
	"action" : "$Nʹһʽ��ˮ��׽�¡�����ȭ�ϸ�����̽��ͻ����ץ��$n��$l",
	"lvl" : 80,
	"skill_name" : "ˮ��׽��",
	"damage_type" : "����"
]),
([
	"action" : "$N˫ȭ���裬һʽ������ȥ���������ֻ��ۣ�£��Ȧ״���ͻ�$n��$l",
	"lvl" : 100,
	"skill_name" : "����ȥ��",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ��ˮ�ݳ�û����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"lvl" : 120,
	"skill_name" : "ˮ�ݳ�û",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�ֱ�ȭ��һʽ����������������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
	"lvl" : 150,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ������տա���ȭ���������֣��������ޣ�����������$n�ĵ���",
	"lvl" : 180,
	"skill_name" : "����տ�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) 
{
	object me;
	me = this_player(); 

	if (me->query_int(1) > 40)
		return combo=="ruying-suixingtui"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ǧҶ�ֱ�����֡�\n");
	if ((int)me->query_skill("yijin-jing", 1) < 60)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧ����ǧҶ�֡�\n");
	if ((int)me->query_int(1)>30) {
		return 1;
	}
	else {
		if ( me->query_skill("banruo-zhang", 1)
		 && me->query_skill("yizhi-chan", 1)
		 && me->query_skill("jingang-quan", 1)
		 && me->query_skill("nianhua-zhi", 1)
		 && me->query_skill("longzhua-gong", 1)
		 && me->query_skill("ruying-suixingtui", 1)
		 && me->query_skill("sanhua-zhang", 1))
			return notify_fail("��Ĺ����������޷�ͬʱѧϰ�������ϵ��ϳ˹���\n");
        }

	if ((int)me->query("max_neili") < 600)
		return notify_fail("�������̫�����޷�������ǧҶ�֡�\n");
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
	level   = (int) me->query_skill("qianye-shou",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 150 + random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("qianye-shou", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ǧҶ�֡�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object target,int damage_bonus)
{
	int j = me->query_skill("qianye-shou", 1);

	if( !random(3)
	&& !target->is_busy()
	&& j >= random(150)
	&& me->query_skill("buddhism",1) >= random(180)
	&& me->query("neili") >= 1000 
	&& me->query("max_neili") >= 2500 
	&& me->query("combat_exp")/2 > random(target->query("combat_exp"))){
		message_vision(CYN"�Ƶ���;����Ȼ΢΢ҡ�Σ���ʱһ�Ʊ����ƣ����Ʊ����ƣ����Ʊ���ƣ����$n�ٵ���̣�\n"
			"$N����Ʊ�ʮ���ƣ������û�Ϊ��ʮ���ƣ�$n����������������Ӱ���ں��ġ�\n"NOR, me, target);
		return damage_bonus*(j/10+random(j))/400;
	}
	return 0;
}

string perform_action_file(string action)
{
	return __DIR__"qianye-shou/" + action;
}
