#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : HIB"$Nʹһ�С�������ӿ����˫��Ʈ�Ʋ�������$n$l"NOR,
	"skill_name" : "������ӿ",
	"lvl" : 10,
	"damage_type" : "����"
]),
([
	"action" : HIW"$Nٿ������$n��ǰ��һ�С��ﲨ���ˡ�ֱ��$n��$l"NOR,
	"skill_name" : "�ﲨ����",
	"lvl" : 30,
	"damage_type" : "����"
]),
([
	"action" :HIY "$N������$nһת��һ�С����ײ�����$n$l��������"NOR,
	"skill_name" : "���ײ���",
	"lvl" : 50,
	"damage_type" : "����"
]),
([
	"action" : HIR"$N���ΰ����ڰ��һ�С����羪�ס������ͻ�$n��$l"NOR,
	"skill_name" : "���羪��",
	"lvl" : 90,
	"damage_type" : "����"
]),
([
	"action" : HIC"$Nʹһ�С���ɳ��Ӱ������������ֱ��$n��$l"NOR,
	"skill_name" : "��ɳ��Ӱ",
	"lvl" : 120,
	"damage_type" : "����"
]),
([
	"action" : HIG"$Nһ�����ʹ�������Ǵ��ġ����ó�������Ӱ�����Ʋ���$n��$l"NOR,
	"skill_name" : "���Ǵ���",
	"lvl" : 150,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if ((int)me->query_skill("jiuyin-zhengong",1) < 50)
		return notify_fail("��ľ����湦��������޷����������ơ�\n");
	if ((int)me->query_skill("cuixin-zhang",1) > 1)
		return notify_fail("��ѧ�˴����ƣ��޷����������ơ�\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������̫�����޷����������ơ�\n");
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
	level = (int) me->query_skill("jiuyin-shenzhang",1);
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
		return notify_fail("������������������ơ�\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -20);
	return 1;
}

int valid_combine(string combo){return combo=="dafumo-quan";}

string perform_action_file(string action)
{
	return __DIR__"jiuyin-shenzhang/" + action;
}
/*
int hit_ob(object me, object ob, int damage)
{
	int i;
	i=me->query_skill("jiuyin-shenzhang")*(me->query_skill("jiuyin-shenzhang")/100+1);
	if(i>3000) i=3000+random(i-3000)/2;
	message_vision(HIR"$N����������һ�𣬷�����ң�\n"NOR,ob);
	if(damage>i)
		damage=i;//�޸�damage by tangfeng
	ob->add("jingli",-random(damage));
	ob->set("jiali",0);
	return 0;
}
*/
int hit_ob(object me, object ob, int damage)
{
        message_vision(HIR"$N����������һ�𣬷�����ң�\n"NOR,ob);
//        ob->add("jingli",-random(200));
        ob->set("jiali",0);
        return 0;
}

