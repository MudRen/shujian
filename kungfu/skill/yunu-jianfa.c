// yunu-jiafa ��Ů���Ľ�
// by xdd and shang 97/6
// Modify By River 98/10
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([
	"action" : "$N���߶��£�һʽ������б�����������»���$wֱ��$n��$l",
	"lvl" : 0,
	"skill_name" : "����б��",
	"damage_type" : "����"
]),
([
	"action" : "$N̤ǰ����������ңָ������$wʹһʽ���˼����ġ�ֱ��$n��$l",
	"lvl" : 10,
	"skill_name" : "�˼�����",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С���ǰ���¡���$w�������ʻ���չ���У����ػ���$n��$l",
	"lvl" : 20,
	"skill_name" : "��ǰ����",
	"damage_type" : "����"
]),
([
	"action" : "$N�����Ϸ���$wָ���Լ���ӣ����һ�С�����С�á��������ٱ�����һ�㣬��ɨ$n��$l",
	"lvl" : 30,
	"skill_name" : "����С��",
	"damage_type" : "����"
]),
([
	"action" : "$Nʹ�������ٰ����$w�Ժ���ǰ��������״���漴�����й���ƽ��$n��$l",
	"lvl" : 40,
	"skill_name" : "���ٰ���",
	"damage_type" : "����"
]),
([
	"action" : "$N����һ�С��ʱʻ�ü��������������ױ֮״��һ�����ߣ�$wȴδ��ͣ��������$n��$l",
	"lvl" : 50,
	"skill_name" : "�ʱʻ�ü",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С��ٰ���ü����˫�����ս������ٽ�������$wֱ��$n��$l",
	"lvl" : 70,
	"skill_name" : "�ٰ���ü",
	"damage_type" : "����"
]),
([
	"action" : "$N��ǰ����������һ�С�ľ�����䡹�������ͦ�������򱳺�̳���$wֱ��$n��$l",
	"lvl" : 90,
	"skill_name" : "ľ������",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С��ֻ���������$w����ʵ�ң�����ʵ����ʵĪ�磬����$n�ĺ�ͷ",
	"lvl" : 110,
	"skill_name" : "�ֻ�����",
	"damage_type" : "����"
]),
([
	"action" : "$N�۽Ǿ���Ц�⣬üĿ���飬һ�С���Ӱ���桹��$w��$n��������ƮƮ�н����������ԣ�",
	"lvl" : 130,
	"skill_name" : "��Ӱ����",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ( me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ( me->query_skill("yunu-xinjing", 1) < 20)
		return notify_fail("�����Ů�ľ�����������\n");
	return 1;
}

string query_skill_name(int level)
{
	int i = sizeof(action);

	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, j, level;
	string msg;

	level =  me->query_skill("yunu-jianfa",1);

	for(i = sizeof(action); i > 0; i--){
		if(level > action[i-1]["lvl"]){
			j = NewRandom(i, 20, level/5);
			if ( me->query_temp("hebi") && me->query_temp("double_attack")  ) {
			 	if (random(2) && me->query_skill("quanzhen-jianfa", 1) > 0) {
					msg = SKILL_D("quanzhen-jianfa")->query_action(me, me->query_temp("weapon"))["action"];
					return ([  
						"action" :random(2)? HIW + msg +NOR : HIY + msg +NOR,
						"force" : 200 + random(350),
						"dodge": random(30),
						"damage": 80 +random(140),
						"lvl" : action[j]["lvl"],
						"parry": random(20),
						"weapon" : random(2)?"����":"����",
						"damage_type" : random(2)?"����":"����",
					]);
				}
				return ([  
					"action" :random(2)? HIC + replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC)+NOR
							: HIR + replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR)+NOR,
					"force" : 200 + random(350),
					"dodge": random(30),
					"damage": 80 + random(140),
					"lvl" : action[j]["lvl"],
					"parry": random(20),
					"weapon" : random(2)?"����":"����",
					"damage_type" : random(2)?"����":"����",
				]);
			}
			if ( me->query_temp("hebi") && random(2) || me->query_temp("hubo")){ 
				return ([  
					"action" :random(2)? HIC + replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC)+NOR
							: HIR + replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR)+NOR,
					"force" : 200 + random(350),
					"dodge": random(30),
					"damage": 180 + random(140),
					"lvl" : action[j]["lvl"],
					"parry": random(20),
					"weapon" : random(2)?"����":"����",
					"damage_type" : random(2)?"����":"����",
				]);
			}
			if( me->query_temp("juan")){ 
				return ([  
					"action" : CYN + replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"CYN)+NOR,
					"force" : 150 +random(300),
					"dodge": random(30),
					"damage": 60 + random(100),
					"lvl" : action[j]["lvl"],
					"parry": random(30),
					"weapon" : random(2)?"����":"����",
					"damage_type" : random(2)?"����":"����",
				]);
			}

			return ([
				"action": action[j]["action"],
				"force" : 100 +random(250),
				"dodge": random(20)-10,
				"parry": random(10),
				"damage": 40 +random(100),
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
			]);
		}
	}
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if (me->query("jingli") < 30)
		return notify_fail("���������������Ů���Ľ���\n");
	if (me->query("neili") < 20)
		return notify_fail("���������������Ů���Ľ���\n");
	me->add("jingli", -20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunu-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int skill = me->query_skill("yunu-jianfa", 1);
	if(random(skill) > 60
	 && me->query_temp("hebi")
	 && me->query("combat_exp") > victim->query("combat_exp")/(3+random(2))) {
		victim->add_temp("lost_attack", random(skill/50) + 2);
		call_out("check_fight", 1, me, victim);
	}
}

void check_fight(object me,object victim)
{
	if(!victim) return;
	if( ! me 
	 || ! me->query_temp("hebi")) {
		victim->delete_temp("lost_attack");
		return;
        }
	call_out("check_fight", 1, me, victim);
}
