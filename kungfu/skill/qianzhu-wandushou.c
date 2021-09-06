// qianzhu-wandushouǧ������
// Update By River@SJ 2002.11
// Modified by mxzhao 2005/02/11 �޸ĳ�150���Ͽ�����
// Update by lsxk@hsbbs  �޸���ɫ
// Update by server �޸�û��ǿ���jifa ����ͨ��marry ��ѧϰ

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action": "$N�������������弱�ݶ��ϣ�����ʳָ���죬ֱ��$n��$l",
	"lvl" : 0,
	"poison": 80,
	"damage_type": "����"
]),
([
	"action": "$N����΢�����߳����Ⱥ�ɨ$n������, ͻȻ���ַ���˫������$n��$l",
	"lvl" : 40,
	"poison": 60,
	"damage_type": "����"
]),
([
	"action": "$N����һ����˫����ǰ�趯��ͻȻһ���ھ�˳ָ���ƿն���������$n��$l",
	"lvl" : 80,
	"poison": 40,
	"damage_type": "����"
]),
([
	"action": "$N��������ʮָ�ᵯ��ֻ�������ھ�������ٰ���$n��$l��ȥ",
	"lvl" : 120,
	"poison": 80,
	"damage_type": "����"
]),
([
	"action": "$N����������ʢ��һ�ɺ���˳˫�����ӵ����ۣ�һ�С�������Ѫ����������$n��$l",
	"lvl" : 160,
	"poison": 100,
	"damage_type": "����"
]),
});

string *rcolor = ({HIR,HIB,HIC,HIW,HIM,HIG,HIY,BLU,RED,YEL,CYN,MAG,WHT});

int valid_enable(string usage)
{
   if ( this_player()->query("quest/qianzhu/pass"))
	return usage=="hand" || usage=="parry"; 
}

string query_skill_name(int level)
{
	int i = sizeof(action);

	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

//	HIR"$Nü��������֣����ؽ�ҧ��ͻȻ���һ��������ʮָ�ֿ�����Ȱ����$n����Ѩ"NOR,

mapping query_action(object me,object weapon)
{
	int i, j, level;
	level = me->query_skill("qianzhu-wandushou",1);

	for(i = sizeof(action); i > 0; i--){
		if(level > action[i-1]["lvl"]){
			j = NewRandom(i, 20, level/5);
			if( me->query_temp("qzwd_pfm")) {
				return ([
					"action" :	HIR+action[j]["action"]+NOR,
					"poison":	action[j]["poison"],
					"damage_type":	"����",
					"dodge":	random(35),
					"parry":	random(35),
					"force":	350 + random(300),
                                        "damage":       180 + random(150),
				]);
			}
                   if( me->query_temp("qzwd_pfm2")) {
                           return ([
                                   "action" :      rcolor[random(sizeof(rcolor))]+action[j]["action"]+NOR,
                                   "poison":       action[j]["poison"],
                                   "damage_type":  "����",
                                   "dodge":        random(55),
                                   "parry":        random(55),
                                   "force":        400 + random(350),
                                        "damage":       200 + random(150),
                           ]);
                   }
			return ([
				"action":	action[j]["action"],
				"damage_type":	action[j]["damage_type"],
				"poison":	action[j]["poison"],
				"lvl":		action[j]["lvl"],
				"force":	300 + random(250),
				"dodge":	random(30),
				"parry":	random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	if (me->query_skill("qianzhu-wandushou", 1) < 150)
	{
		return notify_fail("ǧ������ֻ��ͨ����������ߡ�\n");
	}

	if (me->query("jingli") < 50)
	{
		return notify_fail("�������������ϰǧ�����֡�\n");
	}
	
	if (me->query("neili") < 20)
	{
		return notify_fail("�������������ϰǧ�����֡�\n");
	}

	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

int valid_learn(object me)
{
	if (me->query_skill("qianzhu-wandushou", 1) < 150)
	{
		return notify_fail("ǧ������ֻ��ͨ����������ߡ�\n");
	}

	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int i = me->query_skill("qianzhu-wandushou", 1);

	if ( victim->query("job_npc")) return 0;

	if( (random(i) > 150 || me->query_temp("qzwd_pfm")) && me->query("env/ǧ������")) {
		message_vision(HIR"$N����һ���Ӵ���ֻ������һ����¶����֮ɫ�������Ѿ��ж��ˣ�\n"NOR, victim);
		victim->set_temp("qianzhu", 1);
		victim->add_condition("qzhu_poison", random(6)+ i/30);
		if (userp(me)
		 && userp(victim)
		 && !victim->query_temp("kill_other/"+me->query("id"))
		 && !me->query_temp("other_kill/"+victim->query("id"))
		 && ! me->query_temp("revenge/"+victim->query("id"))
               && (!me->query_temp("special_die") || !victim->query_temp("special_die")))
			me->add_condition("killer", 5);
	}
}

string perform_action_file(string action)
{
	return __DIR__"qianzhu-wandushou/" + action;
}
