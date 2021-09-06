//    /kungfu/skill/suixing-tui.c ��Ӱ������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N������ǰ����Ȼ������ȣ�һʽ������ִ�ԡ���ֱ��$n��ͷ��",
	"lvl" : 0,
	"skill_name" : "����ִ��",
	"damage_type" : "����"
]),
([
	"action" : "$N����һ����˫���أ�һʽ�����ǰ��¡����ڿ��������߽ţ�ֱ��$n��ͷ���ء���",
	"lvl" : 40,
	"skill_name" : "���ǰ���",
	"damage_type" : "����"
]),
([
	"action" : "$N����ǰ�㣬��Ż�Բ������ʹ��һʽ������ޱߡ���ɨ��$n������",
	"lvl" : 80,
	"skill_name" : "����ޱ�",
	"damage_type" : "����"
]),
([
	"action" : "$N����ٿ�ص������������ȣ�����$n��ͷ�����ز����ɲ�������һʽ��ת���ֻء�",
	"lvl" : 120,
	"skill_name" : "ת���ֻ�",
	"damage_type" : "����"
]),
([
	"action" : "$N������������������η�ת��ɨ��һ�С����켫�֡�������$n��$l",
	"lvl" : 150,
	"skill_name" : "���켫��",
	"damage_type" : "����"
]),
([
	"action" : "$NԾ���ڰ�գ�˫������������磬һʽ������ȱ���Ѹ�����׵ؾ���$n",
	"lvl" : 180,
	"skill_name" : "����ȱ�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"; }

int valid_combine(string combo) 
{
	object me;
	me = this_player(); 

	if ((int)me->query_int(1) > 40)
		return combo=="qianye-shou"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ѧ��Ӱ������ʱ���ﲻ����������\n");
	if ( me->query_skill("yijin-jing", 1) < 60)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧ��Ӱ�����ȡ�\n");
	if ( me->query_int(1) > 30)
		return 1;
	else {
		if ( me->query_skill("banruo-zhang", 1)
		 && me->query_skill("yizhi-chan", 1)
		 && me->query_skill("jingang-quan", 1)
		 && me->query_skill("nianhua-zhi", 1)
		 && me->query_skill("qianye-shou", 1)
		 && me->query_skill("longzhua-gong", 1)
		 && me->query_skill("sanhua-zhang", 1))
			return notify_fail("��Ĺ����������޷�ͬʱѧϰ�������ϵ��ϳ˹���\n");
	}

	if ((int)me->query("max_neili") < 600)
		return notify_fail("�������̫�����޷�����Ӱ�����ȡ�\n");
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
	string msg;
	level   = (int) me->query_skill("ruying-suixingtui",1);
        
	if (me->query_temp("sl_rysxt")){
		switch(me->query_temp("sl_rysxt")){
			case 5: msg = HIY"$N��ȻԾ�����һ��һ������ʱ֮���߳�һ�С��硹�־��Ĵ����ȣ�ֱϮ$nǰ��"NOR; break;
			case 4: msg = HIY"������$N���ȹ��أ�������һŤ�������ȵ�һ�С�Ӱ���־���������������$n"NOR; break;
			case 3: msg = HIY"ֻ��$N�ҽž���δ���������һת������˳��ɨ��һ�С��桹�־�����Ӱ����"NOR; break;
			case 2: msg = HIY"�����$N��δ�󳷣��Ѿ������Ρ��־����ھ�ֱ͸�ż⣬��$n�ظ�����������ʮ��"NOR; break;
			case 1: msg = HIR"��ʱ$N˫��չ��������һ��ǿ�ҵ����磬˫����ʱ�벢������Ӱ���Ρ�һ�����ں���$n����֮��"NOR; break;
		}
		me->add_temp("sl_rysxt", -1);                  
		return([
			"action": msg,
			"force" : 300+random(200),
			"dodge" : random(35),
			"parry" : random(35),
                        "damage": 140 + random(140),
			"damage_type" : me->query_temp("sl_rysxt")?"����":"����",
		]);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 150 + random(300),
                                "dodge": random(30),
                         "damage": 140 + random(140),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("ruying-suixingtui", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������Ӱ�����ȡ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"ruying-suixingtui/" + action;
}

