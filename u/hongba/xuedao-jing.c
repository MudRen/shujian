// xuedao-jing.c Ѫ����
// write by iceland
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N���Բ���һ�С�նͷʽ�����ִӱ��������һ����ֱ��$n���",
	"skill_name" : "նͷʽ",
	"lvl" : 0,
	"damage_type" : "����",
]),
([
	"action" : "$NͻȻ�����ڵأ�$nĿ�ɿڴ�֮�ʣ�һ�С����ŵ���������$w���¶���ֱ��$n��С��",
	"skill_name" : "���ŵ�",
	"lvl" : 20,
	"damage_type" : "����",
]),
([
	"action" : "$N���һ�㣬һ������ͷ���ŵأ�һ�С�ȥ��硹��$wһ����������ң����ҵ�������ʮ��",
	"skill_name" : "ȥ���",
	"lvl" : 40,
	"damage_type" : "����",
]),
([
	"action" : "$N�ֽ�һ�������ڿ��У�һ�С����Ǿ��졹������$w���ֶ���������$n��$l",
	"skill_name" : "���Ǿ���",
	"lvl" : 60,
	"damage_type" : "����",
]),
([
	"action" : "$N��ɫ���죬���С��Ǻǡ��ͺ�һ�С����С���$w�鶯�쳣����$n��$l���߹�ȥ",
	"skill_name" : "����",
	"lvl" : 80,
	"damage_type" : "����",
]),
([
	"action" : "$Nһ�С������䡹������$w΢΢һ�����������͡��������죬��$nͷ���ء�����������",
	"skill_name" : "������",
	"lvl" : 100,
	"damage_type" : "����",
]),
([
	"action" : "$Nը�װ���һ����һʽ��ħ����$w��$n§�����б���������������ͣ��Ʋ��ɵ�",
	"skill_name" : "ħ����",
	"lvl" : 120,
	"damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if (me->query("max_neili") < 150)
		return notify_fail("�������������\n");
	if (me->query_skill("longxiang-boruo", 1) < 20)
		return notify_fail("���������������̫ǳ��\n");
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
	level   = (int) me->query_skill("xuedao-jing",1);

for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
if (me->query("quest/ѩɽ/shendao/jidao") ) {
return ([  
				 "action" : HIR+replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR)+NOR,
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":300,
				"dodge":130,
				"damage":180,
				"parry":120,
			]);
	}


	
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
	int lvl = me->query_skill("xuedao-jing", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if (me->query("jingli") < 40)
		return notify_fail("�������������������Ѫ������\n");
	if (me->query("neili") < 20)
		return notify_fail("�������������������Ѫ������\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object target)
{
   int lv = me->query_skill("shenzhao-jing",1);

   if( random(10) > 6 && lv > 250 && !me->query_temp("xdszj") && me->query("quest/ѩɽ/shendao/jidao") && me->query_temp("sjz_power") )
          {
me->set_temp("xdszj",1);
                message_vision(HIW"$N���һ���������չ�������"+me->query_temp("weapon")->query("name")+"֮�ϣ���$n��ȥ��" NOR,me,target);
me->add_temp("apply/attack",  me->query_skill("shenzhao-jing", 1)/3);

if(wizardp(me))  message_vision(HIW "\n$N��xdszj��"+chinese_number(me->query_temp("xdszj"))+"������" NOR,me,target);

                         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(4)?1:3);
target->receive_damage("qi", lv/3, me);

                         me->add_temp("apply/attack", -me->query_skill("shenzhao-jing", 1)/3);
me->delete_temp("xdszj");
if(wizardp(me))  message_vision(HIY "\n$Nɾ��xdszj��"+chinese_number(me->query_temp("xdszj"))+"������\n" NOR,me,target);

         }
     
}







string perform_action_file(string action)
{
	return __DIR__"xuedao-jing/" + action;
}
