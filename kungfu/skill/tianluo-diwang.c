// tianluo-diwang ���޵�����
// By River
// Modified by darken@SJ

#include <ansi.h>;
inherit SKILL;
mapping *action = ({
([
	"action" : "$N���ƻ�һ��Բ�����ƻ�����һ��Բ���ʺ�£֮�ƣ�����$n����ǰ��Ѩ",
	"lvl" : 0,
	"damage_type" : "����",
]),
([
	"action" : "$N���ƻ��أ���ȭ�����󷢣�����һ��������������$n��$l",
	"lvl" : 20,
	"damage_type" : "����",
]),
([
	"action" : "$N������ǰ��ȥ��һ�¼��弲�����������۽���δ��֮�ʣ�˫�ֱ���$n��$l",
	"lvl" : 30,
	"damage_type" : "����"
]),
([
	"action" : "$N�������»��أ�����ͻȻһ�䣬��Ȼ��Ϊ�������꣬����$n��$l",
	"damage_type" : "����",
	"lvl" : 50,     
]),
([
	"action" : "$N����Ӵ�����������˳���$nֻ�����ܲ�͸�磬��������ӡ����ôҲ���㲻��",
	"lvl" : 70,        
	"damage_type" : "����"
]),
([
	"action" : "$N˫�۷��裬˫�����ƻ�����ǧ��ǧ�ƣ���$n���Ծ�����㣬ʼ���Ӳ�����Χ��ȦȦ",
	"lvl" : 90,
	"damage_type" : "����"
]), 
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���ַ�����ϰ���޵����ơ�\n");
	if ( me->query_skill("yunu-xinjing", 1) < 10 )
		return notify_fail("�����Ů�ľ����򲻹����޷���ϰ���޵����ơ�\n");
	if ( me->query_skill("hand", 1) < 20)
		return notify_fail("��Ļ����ַ�̫��޷���ϰ���޵����ơ�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, j, level;
	level = (int)me->query_skill("tianluo-diwang", 1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action" : action[j]["action"],
				"force" : 100+random(250),
				"dodge": random(20)-10,
				"parry": random(10),
				"lvl" : action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
			]);
		}
	}
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 30)
		return notify_fail("����������������޵������ˡ�\n");
	if ( me->query("neili") < 10)
		return notify_fail("����������������޵������ˡ�\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lvl = me->query_skill("hand");

	if( random(lvl) > 300 && !victim->is_lost() && random(2)) {
		message_vision(HIW"$Nһ����ܵĹ����£�$n˿���޷�׼ȷ�Ĺ���$N��\n"NOR, me, victim);
		victim->start_lost(1+random(2));
	}
}
