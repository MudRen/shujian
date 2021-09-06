// ruyi-dao.c ���⵶��
// modified by xjqx@SJ 2009/1/3
//modified by zhuifeng@SJFY 2010/07/20

inherit SKILL;
#include <combat.h>
#include <ansi.h>
mapping *action = ({
([ "action" : "$Nһ�ĵ�����һ�С��������������͵�һ��ת������$wֱ��$n���ؿ�ͻȻնȥ",
   "lvl" : 0,
	"skill_name" : "��������",
	"parry":0,
	"damage_type" : "����"
]),
([      "action" : "$N�����е�$wһ�һ�С����·ת�������еĵ�һ����ת��ֱ����$n��$l",
        "lvl" : 10,
	"skill_name" : "���·ת",
	"parry":10,
	"damage_type" : "����" 
]),
([      "action" : "$N���ζ�Ȼ�������ߣ�һ�С�������С���������磬����$wն��$n��$l",
        "lvl" : 30,
	"skill_name" : "�������",
	"parry":10,
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С��������ơ���������Ȼ�θ����ߣ�����$wһ��ƽ����$n��$l��ȥ",
       "lvl" : 50,
	"skill_name" : "��������",
	"parry":0,
	"damage_type" : "����"
]),
([      "action" : "$N����ͻȻһԾ������$wһ�С����к�ء���ƮƮ����$n��$lҪ����ȥ",
       "lvl" : 80,
	"skill_name" : "���к��",
	"parry":30,
	"damage_type" : "����"
]),
([      "action" : "$N����$w����һ�֣���������� һ�С�����������������$n$l��ȥ",
       "lvl" : 110,
	"skill_name" : "��������",
	"parry":20,
	"damage_type" : "����"
]),
([      "action" : "$N�ᵶ��ǰ������һת������$wʹһ�С��չ���硹����һ���⻡ն��$n��$l",
       "lvl" : 140,
	"skill_name" : "�չ����",
	"parry":30,
	"damage_type" : "����"
]),
([      "action" : "$nֻ����ǰһ����$Nһ�С�������������$wЮ��������Ѹ�Ϳ���$n��$l",
        "lvl" : 180,
	"skill_name" : "��������",
	"parry":40,
	"damage_type" : "����"
]),
([      "action" : "$N��$w����һȦ��һ�С������ϡ���$nֻ����ȫ��������һ�ŵ���֮��",
       "lvl" : 240,
	"skill_name" : "������",
	"parry":40,
	"damage_type" : "����"
]),
([      "action" : "$N����һת��һ�С���ң���ڡ��� $w���ⲻ���� ���п���$n��$lҪ��",
"lvl" : 300,
	"skill_name" : "��ң����",
	"parry":40,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ( me->query("max_neili", 1) < 100)
		return notify_fail("�������������\n"); 
		
		

	if (!me->query_skill("bahuang-gong", 1) )
    if ( me->query_skill("beiming-shengong", 1) < 30 )
		return notify_fail("��ı�ڤ�񹦻��̫ǳ��\n");
        if ( me->query_skill("blade", 1) < 30 )
		return notify_fail("��Ļ���������������죬�޷�ѧϰ���⵶����\n");
	if ( me->query_skill("liuyang-zhang", 1) < 30)
		return notify_fail("�����ɽ������̫�����޷�ѧϰ�����⵶���ľ��衣\n");
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
	int i, j, level;

	level = (int) me->query_skill("ruyi-dao",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
					
			if ( me->query_temp("ryd/ruyi")){
				return ([
					"action":WHT+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"WHT), NOR, WHT)+NOR,
          "damage": 220+random(150),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			if ( me->query_temp("ryd/xiaoyao")||me->query_temp("xiaoyao_jianwu")){
				return ([
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
          "damage": 230+random(190),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
				"dodge" : random(25)+25,
				"parry": 20-random(10),
        "damage" : 120 + random(120),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
		}
	}
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 50)
		return notify_fail("����������������⵶����\n");         
	if ((int)me->query("neili") < 10)
		return notify_fail("����������������⵶����\n");
	me->receive_damage("jingli", 40);
	me->receive_damage("neili", 15);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"ruyi-dao/" + action;
}




mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon, weapon1;
        int i;
        weapon = me->query_temp("weapon");
        weapon1= victim->query_temp("weapon");

        if( !objectp(weapon) ) return;

        i = me->query_skill("ruyi-dao", 1);



   if(i>=350){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_condition("no_fight")){
            message_vision(HIR"$N�����ݺᣬѸ����磬$n�����м�,���Ǻ��޻���֮����\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }

        if( weapon1 && i > 200 && living(victim)
         && me->query_skill_mapped("force") == "beiming-shengong"
         && random(me->query("combat_exp")) > victim->query("combat_exp")/2 ) {
                message_vision(HIM"��ڤ�񹦺ε����棬$N���������˵�"+weapon->name()+HIM"�ϣ�����������ƥ���ݿ����࣬�޿�ƥ�У�\n"NOR, 

me,victim);
                if( random(me->query("str")) > victim->query("dex")/3 ) {
                        me->add("neili", -50);
                   victim->add_busy(1+random(2));
                        message_vision(HIR"$Nֻ��һ�ɴ���Ϯ�����۰��ʹ������"+weapon1->name()+HIR"��Ҳ����ס�����ֶ�����\n"NOR, victim);
                        weapon1->unequip();
                        weapon1->move(environment(victim));
                }
        }
     
}

