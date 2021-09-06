// zhenshan-mianzhang.c ��ɽ����
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N�ͺ�һ�������ã���һ�������ݲ������������棬̤��һ��������һ�С����֡�����$n��$l��ȥ",
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "����"
]),
([
	"action" : "$N����һ����һ����ӡ�ơ�����ɽ���Ʒ��Ȼ�縫������$n��$l",
	"damage_type" : "����",
	"lvl" : 10,
	"skill_name" : "ӡ��"
]),
([
	"action" : "$N������ǰ������һ�ơ����Ƽ��ա���һ����ɽ��������������$n��$l",
	"damage_type" : "����",
	"lvl" : 15,
	"skill_name" : "���Ƽ���"
]),
([
	"action" : "$N˫��һ����ʽ������ͻȻ��������ɨ��$n��$l������һ�С����ƶϷ塹",
	"damage_type" : "����",
	"lvl" : 20,
	"skill_name" : "���ƶϷ�"
]),
([
	"action" : "$N����Ϊצ��ץ��$n��$l��һ�С�������ӡ�������$n��������ˤ��",
	"damage_type" : "����",
	"lvl" : 25,
	"skill_name" : "�������"
]),
([
	"action" : "$Nʹ�����������������$n��ǰ����һ����Ż���Ϊָ����ʳ��˫ָ���¶��ϴ���$n���⡸����Ѩ��",
	"damage_type" : "����",
	"lvl" : 30,
	"skill_name" : "�������"
]),
([
	"action" : "$N�������ƣ�һ�С��������¡������󷭹�������ת�˸�СȦ����$n��$l��ȥ",
	"damage_type" : "����",
	"lvl" : 35,
	"skill_name" : "��������"
]),
([
	"action" : "$N��ת���ƣ�������ȭ��һʽ��ѩӵ���ء�����$n��$l�ͻ�",
	"damage_type" : "����",
	"lvl" : 40,
	"skill_name" : "ѩӵ����"
]),
([
	"action" : "$N���̡��̹���񡹣�˫�ַ�ת���������ַ�����$n��$l��ҪѨ����",
	"damage_type" : "����",
	"lvl" : 45,
	"skill_name" : "�̹����"
]),
([
	"action" : "$N���С�ԧ���ȡ�����$n��$l���漴����$n�ؿڵġ�����Ѩ��",
	"damage_type" : "����",
	"lvl" : 50,
	"skill_name" : "ԧ����"
]),
([
	"action" : "$Nһ�С��ɺ����᡹��ٿ��б������$n����󣬻��ֳ��ƣ���$n��$l��",
	"damage_type" : "����",
	"lvl" : 60,
	"skill_name" : "�ɺ�����"
]),
([
	"action" : "$Nʩ������¶�Ὥ���������ͻ����������ܣ�ͻȻ����ץס$n��$l���ͺ�һ������$n�������˳�ȥ",
	"damage_type" : "����",
	"lvl" : 90,
	"skill_name" : "��¶�Ὥ"
]),
([
	"action" : "$N���һ�����ʹܶ����������������$n�����󣬽�������һ�С��׺���ա���ʹ��ȫ����$n��$l��ȥ",
	"damage_type" : "����",
	"lvl" : 120,
	"skill_name" : "�׺����"
]),
([
	"action" : "$N����һ����ʹ��һ�С���ת���ɡ���ת��һ��Ȧ�ӣ�˫��ֱ��$n��$l",
	"damage_type" : "����",
	"lvl" : 150,
	"skill_name" : "��ת����"
]),
([
	"action" : "$N�����ұۣ��������������������һ�У�һ�С���ܽ�����������������$n��$l��ȥ",
	"damage_type" : "����",
	"lvl" : 180,
	"skill_name" : "��ܽ���"
])
});

int valid_enable(string usage) { return (usage == "strike") || (usage == "parry"); }

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("����ɽ���Ʊ�����֡�\n");
	if( (int)me->query_skill("yinyun-ziqi", 1) < 100 )
		return notify_fail("�����������򲻹����޷�ѧϰ��ɽ���ơ�\n");
	if( (int)me->query("max_neili") < 900 )
		return notify_fail("�������̫�����޷�����ɽ���ơ�\n");
	return 1;
}

int practice_skill(object me)
{
	int lvl = me->query_skill("zhenshan-mianzhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if( (int)me->query("jingli") < 40 )
		return notify_fail("��ľ���̫���ˣ��޷���ϰ��ɽ����\n");
	if( (int)me->query("neili") < 20 )
		return notify_fail("���������������ɽ���ơ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
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

	level = (int)me->query_skill("zhenshan-mianzhang", 1);

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if( random(level)/2 > 100
			&& me->query_skill("strike",1) > 200 
			&& me->query("neili") > 1000 
			&& me->query("jingli") > 300 
			&& me->query("jiali") > 5 
			&& !me->query_temp("wd_hkbd")
			&& !random(3) ) {
				me->add("neili", -20);
				return ([
					"action": HIY"$N�������䣬˫����ƮƮ�أ��������޵��Ļ������������䵱��ѧ֮һ����ɽ����"NOR,
					"force": 450,
					"parry": random(30),
					"dodge": random(30),
					"damage_type": "����"
				]);
			}
			if( me->query_temp("wd_hkbd") ) {
				return ([
					"action" : HIC+action[j]["action"]+NOR,
					"force" : 200 + random(300),
					"dodge": random(35),
					"parry": random(35),
					"damage": 40 + random(40),
					"damage_type": "����"
				]);
			}
			return ([
				"action" : action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl":	action[j]["lvl"],
				"force" : 220 + random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

string perform_action_file(string action)
{
	return __DIR__"zhenshan-mianzhang/" + action;
}
