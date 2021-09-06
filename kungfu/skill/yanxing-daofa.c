// yanxing-daofa.c ���е���

inherit SKILL;
#include  <ansi.h>
mapping *action = ({
([
	"action" : "$NĬ����־�����Ѹ������$n�Ĺ��ƣ�$wͬʱ������$n��ǰ�ػӳ���",
	"lvl" : 0,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([
	"action" : "$N�������ã�һ�С����־���������$wֱ�������䲻��ش���$n�ĺ󱳣�",
	"lvl" : 30,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([
	"action" : "$N��ʾ������һ�С����־�������$n����Ϊ��ʱ���͵ػӶ�$w��$n���ҽ�նȥ��",
	"lvl" : 60,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([
	"action" : "$N�������־������������ã�������ߣ���$n׷�������䲻������ͻ���",
	"lvl" : 80,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([
	"action" : "$N���氵�գ�һ�С����־���������էչ��ָ�ϴ��£�ָ��������ɱ�����ޣ�",
	"lvl" : 100,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([
	"action" : "$NӰ���ء����־������������������д��ң�$n��ʱ����ʧ�룬���ִ��У�",
	"lvl" : 120,
	"skill_name" : "���־�",
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
	if ( me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ( me->query_skill("linji-zhuang", 1) < 30)
		return notify_fail("����ټ�ʮ��ׯ���̫ǳ���޷�ѧϰ���е�����\n");
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
	level   = (int) me->query_skill("yanxing-daofa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":150+random(300),
				"dodge":random(30),
				"damage":60+random(100),
				"parry":random(30),
			]);
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("yanxing-daofa", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40)
		return notify_fail("����������������е�����\n");
	if (me->query("neili") < 20)
		return notify_fail("����������������е�����\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yanxing-daofa/" + action;
}

void huanying(object me, object victim)
{
	if (!me || !victim || !me->is_fighting(victim))
		return;

	if( me->query_temp("��Ӱ")
	 && !me->query_temp("huanying_hit")){
		me->set_temp("huanying_hit", 1);
		me->set_temp("apply/name", ({ me->query("name")+"��"HIY"��Ӱ"NOR }));
		COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(3)?1:3);
		me->delete_temp("apply/name");
		me->delete_temp("huanying_hit");
	}

}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	call_out((: huanying :), 1, me, victim);
}
