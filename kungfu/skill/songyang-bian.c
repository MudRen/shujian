// songyang-bian.c ������
// Created by Numa 1999-11-22
// Modified by Numa 2000-1-25

#include <ansi.h>
inherit SKILL;

string  *msg2 = ({
HIY"\n$N��$n���г�����ǿ����������һ��������$n��\n"NOR,
HIR"\n$n���мȳ��������ջ����ǲ��ܣ���ǿ������$N���ѽ�$w����$n�Ĵ�ҪѨ��\n"NOR,
HIG"\n$N���Լ��������𽥻��ң��鼱֮�£�������շɳ���$w��ĩ��ȴ��ɨ��$n������Ѩ��\n"NOR,
HIB"\n$N���һ����������·��ֻ��ƴ��һ����������ˣ�$w���ƶ�Ȼ������$n�����м�֮����\n"NOR,
HIW"\n$n��$N������Ȼ���������а����кã�����һԽ�����������ϵ��������ű�Ӱ��ʹ$n�޴����Σ�\n"NOR,
});


mapping *action = ({
([
	"action": "$N����$w������һת��$w����һ�����ߴ�Խ��������ֱ����$n",
	"lvl" : 0,
	"damage_type":  "����"
]),
([
	"action": "$N������������$w��˫�ֲ����趯��$n����ȫ�����������Ӱ֮�У�˿���޻���֮��",
	"lvl" : 30,
	"damage_type":  "����"
]),
([
	"action": "$N�����ھ�����ע��$w֮�ϣ��漴������������ԲȦ���⻷֮��һ����Ӱֱ�ܶ�������ճ���$n",
	"lvl" : 45,
	"damage_type":  "����"
]),
([
	"action": "$N��������һ�٣������Ͼ٣���Ҫ������������$wȴ��һ�����ߴ�����$n��ȥ",
	"lvl" : 70,
	"damage_type":  "����"
]),
([
	"action": "$N�粿һ�ʣ�����$w��ǰ������$wĩ���ڵ��ϻ��������ڡ��ı��죬�ͻ���$n",
	"lvl" : 90,
	"damage_type":  "����"
]),
([
	"action": "$N�����Ȼһ�������˸�ת��˫���Բ��϶���$w��������ҵ���������$n",
	"lvl" : 110,
	"damage_type":  "����"
]),
([
	"action": "$N������$w��ջ��˸���Ȧ������Χ��$n���ߣ�$n��ȫ���Ѩ����������$w֮��",
	"lvl" : 125,
	"damage_type":  "����"
]),
([
	"action": "$N��Хһ��������������ɽ�ڹ����̶����̤��$w����ˮ���߰㻮��$n�ĸ���ҪѨ",
	"lvl" : 140,
	"damage_type":  "����"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if ((int)me->query("max_neili") < 500 )
		return notify_fail("���������Ϊ���㣬û�а취�������ޡ�\n");
	if ((int)me->query_skill("hanbing-zhenqi", 1) < 50)
		return notify_fail("��ĺ����������̫ǳ����ʮ���Ժ�ſ��ԡ�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	 ||( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me,object weapon)
{
	int i, level, j;

	level = (int) me->query_skill("songyang-bian",1);
	if (level>200) level=200+(level-200)/10;
	if( me->query_temp("ss_luan")&& !random(4)){
		return ([
			"action":	msg2[random(sizeof(msg2))],
			"force":	200+random(300),
			"dodge":	random(35),
			"damage":	250 + random(90),
			"damage_type":	random(2)?"����":"����",
			"parry":	random(35),
		]);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	150+random(300),
				"dodge":	random(30),
				"parry":	random(30),
				"damage":	60 + random(100),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("songyang-bian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40)
		return notify_fail("������������������ޡ�\n");
	if ((int)me->query("neili") < 20 )
		return notify_fail("������������������ޡ�\n");

	me->receive_damage("jingli",30);
	me->receive_damage("neili",10);
	return 1;
}

mixed hit_ob(object me, object target, int damage)
{
	object weapon;

	if (me->query("env/songyang_auto")
	&& objectp(weapon = me->query_temp("weapon"))
	&& weapon->query("skill_type") == "whip"
	&& me->query_skill("parry",1) > 160
	&& me->query("neili") > 1500
	&& me->query("jingli") > 500
	&& me->query_skill("songyang-bian",1) > 180
	&& me->query_skill("songyang-shou",1) > 160
	&& me->query_skill_mapped("hand") == "songyang-shou"
	&& me->query_skill_prepared("hand") == "songyang-shou"
	&& me->query_temp("ss_luan")
	&& random(me->query("combat_exp")) > target->query("combat_exp")/4) {
		me->add("neili", -50);
		message_vision(HIY"\n$N�������������"+weapon->name()+HIY"һ���������ֱ���һ�Ǵ������֣�\n"NOR,me);
		damage = me->query_skill("songyang-bian", 1)/3 + random(me->query_skill("songyang-bian", 1)/4);
		me->add_temp("apply/damage", damage);
		weapon->unequip();
target->set("must_be_hit",1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		weapon->wield();
		message_vision(HIC"\n$Nһ��δ�ϣ��ּ�������������"+weapon->name()+HIC"һ�����ھ�˳��"+weapon->name()+HIC"���������㳯��$nֱ�ƶ�ȥ��\n"NOR,me,target);
		me->add_temp("apply/damage", - damage);
target->delete("must_be_hit");
	//	me->start_busy(1 + random(2));
	}
	return 0;
}

string perform_action_file(string action)
{
	return __DIR__"songyang-bian/" + action;
}
