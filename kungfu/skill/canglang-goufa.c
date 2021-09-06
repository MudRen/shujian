// canglang-goufa.c ���˹���
// by aug   99.9.10

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([
	"action" : "$N˫�Ų�������������һ�С���Ҷ���ҡ���$w��ǰƽ��$n�ĵ���",
	"lvl" : 0,
	"skill_name" : "��Ҷ����",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С�Ⱥħ���衹��$w�趯��סȫ����$nײȥ",
	"lvl" : 40,
	"skill_name" : "Ⱥħ����",
	"damage_type" : "����"
]),
([
	"action" : "$Nʹһ�С�������թ�����ҽ����س���$w�������Һ󳷣�ͻȻ����ǰ������$n������",
	"lvl" : 80,
	"skill_name" : "������թ",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С���·ͬ�项��$w�й�ֱ����һ��һ�´���$n���Ҽ�",
	"lvl" : 100,
	"skill_name" : "��·ͬ��",
	"damage_type" : "����"
]),
([
	"action" : "$N����$w��󳷣�����ǰƽƽ����һ�С�����������$n������",
	"lvl" : 140,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([
	"action" : "$Nһת��$w���б����һ�С��ɺ�λ���������$n�����",
	"lvl" : 160,
	"skill_name" : "�ɺ�λ�",
	"damage_type" : "����"
]),
([
	"action" : "$N�ҽ���ǰһ������ϥ����һ�С�������������$w��ǰ�Ϸ�����$n�ĺ���",
	"lvl" : 180,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ����ʹһ�С��������ơ���$w����һ�е�����$n������",
	"lvl" : 200,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "hook" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hook")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 10)
		return notify_fail("��Ķ����󷨻��̫ǳ���޷�ѧϰ���˹�����\n");
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
	int i,level,temp,j;
	object target;
	object *enemy;
        level = me->query_skill("canglang-goufa",1);

	enemy = me->query_enemy();
	if(sizeof(enemy) > 0) {
		target = enemy[random(sizeof(enemy))];
		temp = target->query_skill("dodge");
		if (!temp) temp=1;

		i = me->query_skill("hook")*100 / temp;
		if( i > 200) i=200;
		if( i < 50) i=50;
		if ( random(300) < (50+i) && me->query("neili") > 500 && !random(4))
			if ( me->query_skill_prepared("leg")=="shenlong-tuifa"
			 && me->query_skill("dulong-dafa",1) > 100 
			 && me->query_skill("canglang-goufa",1) > 100 
			 && me->query_skill("shenlong-tuifa",1) > 100 
			 && me->query_skill_mapped("force")=="dulong-dafa" )
				call_out("autopfm",1,me,target);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 150 +random(300),
				"dodge": random(30),
				"parry": random(30),
				"damage": 60 + random(100),
			]);
		}
	}
}

void autopfm(object me,object target)
{
	object weapon;
	int i;

	if(!me || !target ) return;
	weapon = me->query_temp("weapon");      
	if(!weapon) return;
	if ( me->add("neili",-75) <0 ) me->set("neili",0);

	i = me->query_skill("canglang-goufa", 1);
	me->add_temp("apply/attack",i/4);
	if(target->query_temp("weapon")) {
		message_vision(HIC"\n$N����"+weapon->query("name")+HIC"�������ġ�������У�$nһ��û����͸���ס�˱�����\n$N�˻������������ȣ�"NOR,me,target);
		weapon->unequip(); 
		if (me->is_fighting(target)) COMBAT_D->do_attack(me, target, 0, 1);
		if (me->is_fighting(target)) COMBAT_D->do_attack(me, target, 0, 1);
		if (me->is_fighting(target) && random(2)==1) COMBAT_D->do_attack(me, target, 0, 3);
		weapon->wield(); 
	}
	else {
                message_vision(HIC"\n$N����"+weapon->query("name")+HIC"�������ġ�������У�$nһ��û����͸�$N��ס���ֽţ�\n$N�˻���������$n���ţ�"NOR,me,target);
		weapon->unequip(); 
		if (me->is_fighting(target)) COMBAT_D->do_attack(me, target, 0, 1);
		if (me->is_fighting(target) && random(2)==1) COMBAT_D->do_attack(me, target, 0, 3);
		weapon->wield(); 
	}
	me->add_temp("apply/attack",-i/4);
}

int practice_skill(object me)
{
	int lvl = me->query_skill("canglang-goufa", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("jingli") < 40)
                return notify_fail("����������������˹�����\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("����������������˹�����\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
	return __DIR__"canglang-goufa/" + action;
}
