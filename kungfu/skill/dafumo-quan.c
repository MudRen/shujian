// dafumo-quan.c
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : HIY"$N˫��һ�֣�����$n����ǰ��ͻȻʹ������ӳ��ա���˫ȭϮ��$n"NOR,
	"lvl" : 0,
	"skill_name" : "��ӳ���",
	"damage_type" : "����"
]),
([
	"action" : HIG"$Nʹ���������쿪������ȭΪ�ƣ�˫�Ʋ�������$n"NOR,
	"lvl" : 7,
	"skill_name" : "�����쿪",
	"damage_type" : "����"
]),
([
	"action" : HIR"$NһԾ��$n��ǰ�����綯��ͥ����һȭ����$n"NOR,
	"lvl" : 15,
	"skill_name" : "�綯��ͥ",
	"damage_type" : "����"
]),
([
	"action" : HIB"$Nֻ�����أ��Ż��󿪣�һ�С���Ŀ����������$n"NOR,
	"lvl" : 28,
	"skill_name" : "��Ŀ����",
	"damage_type" : "����"
]),
([
	"action" : HIW"$N˫ȭ�趯��ɣ�һʽ���������ɨ��$n������"NOR,
	"lvl" : 45,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : HIC"$N���ΰ������ն��£���ȭ�Ӻ�ա�����$n"NOR,
	"lvl" : 60,
	"skill_name" : "ȭ�Ӻ��",
	"damage_type" : "����"
]),
([
	"action" : HIM"$N������������վ����˫ȭ��ӣ�һ�С���ɽ�ƺ���Ϯ��$n"NOR,
	"lvl" : 65,
	"skill_name" : "��ɽ�ƺ�",
	"damage_type" : "����"
]),
([
	"action" : MAG"$N���ƻ��˸�ȦȦ�������ɨҶ������ȭ���������$n"NOR,
	"lvl" : 70,
	"skill_name" : "���ɨҶ",
	"damage_type" : "����"
]),
([
	"action" : YEL"$N�󿪴�ϣ�ʩչ�����ຣ�Ⱥ�����˫ȭײ��$n��ǰ��"NOR,
	"lvl" : 80,
	"skill_name" : "�ຣ�Ⱥ�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jiuyin-shenzhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ѧ���ħȭ��������֡�\n");
	if ((int)me->query_skill("jiuyin-zhengong", 1) <= (int)me->query_skill("dafumo-quan", 1))
		return notify_fail("��ľ����湦��򲻹����޷�ѧ���ħȭ����\n");
	if ( me->query_skill("dafumo-quan", 1) < 150 )
		return notify_fail("��Ĵ��ħȭ�ȼ���������ϰ��\n");
	if (me->query_skill_mapped("force") != "jiuyin-zhengong")
		return notify_fail("��ϰ���ħȭ�������о����湦��ϡ�\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������̫�����޷������ħȭ����\n");
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
	level   = (int) me->query_skill("dafumo-quan",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level >= action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	300 + random(350),
				"dodge":	random(30),
				"parry":	random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("����������������ħȭ����\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"dafumo-quan/" + action;
}
/*
int hit_ob(object me, object ob, int damage)
{
	int i;
	i=me->query_skill("jiuyin-shenzhang")*(me->query_skill("jiuyin-shenzhang")/100+1);
	if(i>3000) i=3000+random(i-3000)/2;
	if(damage>i)
		damage=i;//�޸�damage by tangfeng
	message_vision(HIR"$N����������һ����Ϣ���ң�\n"NOR,ob);
	ob->add("neili",-random(damage));
	return 0;
}
*/
int hit_ob(object me, object ob, int damage)
{
        message_vision(HIR"$N����������һ����Ϣ���ң�\n"NOR,ob);
        ob->add("neili",-random(damage/2));
        ob->start_busy(2);
        return 0;
}

