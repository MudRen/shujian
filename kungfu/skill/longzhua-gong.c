// longzhua-gong.c -��צ��

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "ֻ�����ꡱ��һ�������������$Nʹһ�С�����ʽ����������Ȼ̽����ȥ����������",
	"lvl"   : 0,
	"skill_name" : "����ʽ" ,               
	"damage_type" : "ץ��"
]),
([
	"action" : "$N������𣬶������糤�羪�죬һ�С�׽Ӱʽ������ʸӦ��������Ͼ��",
	"lvl"   : 10,
	"skill_name" : "׽Ӱʽ" ,               
	"damage_type" : "ץ��"
]),
([
	"action" : "$N����һ����ʹ��������ʽ����ʮָ΢΢���¶����������ཻ�ġ����ڡ�����ʱ���緱�Ҽ���һ��",
	"lvl"   : 20,
	"skill_name" : "����ʽ" ,               
	"damage_type" : "ץ��"
]),
([
	"action" : "$N�߶�������˫צ����ʹ������ɪʽ�����������಻��������������ˮһ��",
	"lvl"   : 40,
	"skill_name" : "��ɪʽ" ,               
	"damage_type" : "ץ��"
]),
([
	"action" : "$Nʹһ�С�����ʽ���������ݺῪ�أ��������ۣ��͵ػ���$n��$l",
	"lvl"   : 60,
	"skill_name" : "����ʽ" ,               
	"damage_type" : "ץ��"
]),
([
	"action" : "$N��շ������ִ�������������һ�С�����ʽ������$n��$l",
	"lvl"   : 80,
	"skill_name" : "����ʽ" ,               
	"damage_type" : "ץ��"
]),
([ 
	"action" : "$N���н��ƣ�һ�С�����ʽ����ֱȡ$n$l��ÿһצ����ʯ���쾪���������֮��",
	"lvl"   : 100,
	"skill_name" : "����ʽ" ,               
	"damage_type" : "ץ��"
]),
([
	"action" : "$N������ת�����������צ��һ�С�����ʽ�����ƿ�֮����������",
	"lvl"   : 120,
	"skill_name" : "����ʽ" ,               
	"damage_type" : "ץ��"
]),
([
	"action" : "$N�ǽڡ���������һ���죬�ֱ�ͽ����ߣ�һ�С�����ʽ������ָ��Ȼ����$n��ǰ��Ѩ",
	"lvl"   : 150,
	"skill_name" : "����ʽ" ,               
	"damage_type" : "ץ��"
]),
([ 
	"action" : "$N�͵�һ�����ƣ�צ�����䣬һ�С���ȱʽ�������滺��������ȴ����ǿ��",
	"lvl"   : 180,
	"skill_name" : "��ȱʽ" ,               
	"damage_type" : "ץ��"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_combine(string combo) 
{
	object me;
	me = this_player(); 

	if ( me->query_int(1) > 40)
		return combo=="yizhi-chan"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����צ��������֡�\n");
	if ((int)me->query_skill("yijin-jing", 1) < 60)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧ��צ����\n");
	if ((int)me->query_int(1) > 30) {
		return 1;
	}
	else {
		if ( me->query_skill("banruo-zhang", 1)
		 && me->query_skill("yizhi-chan", 1)
		 && me->query_skill("jingang-quan", 1)
		 && me->query_skill("nianhua-zhi", 1)
		 && me->query_skill("qianye-shou", 1)
		 && me->query_skill("ruying-suixingtui", 1)
		 && me->query_skill("sanhua-zhang", 1))
			return notify_fail("��Ĺ����������޷�ͬʱѧϰ�������ϵ��ϳ˹���\n");
	}
	if ((int)me->query("max_neili") < 600)
		return notify_fail("�������̫�����޷�����צ����\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, j, level;
	string msg;
	
	level = (int) me->query_skill("longzhua-gong",1);
	for(i = sizeof(action); i > 0; i--) 	{
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if(me->query_temp("baocan")) {
				switch(me->query_temp("baocan")) {
					case 2: msg = HIY"$N����������ɽ���ƺ����������ٳ�����æ���ң���ʵ����ʵ����������׾��ÿһ�������ж������������ޱȵ����塣"NOR; break;
					case 1: msg = HIR"$N�ۼ��Է���������Χ����Ҳ����ȫ����ˣ�����˫�ƻػ�����ȻȦת������һ�죬��$n�����ϻ�����ȥ��"NOR; break;
					default: msg = HIY"$N����������ɽ���ƺ����������ٳ�����æ���ң���ʵ����ʵ����������׾��ÿһ�������ж������������ޱȵ����塣"NOR;break;
				}
				me->add_temp("baocan", -1);      
				return ([
					"action": msg, 
					"force" : 200 + random(300),
					"dodge": random(35),
					"parry": random(35),
					"damage": 40 + random(50),
					"damage_type" : "ץ��",
				]);
			}

			if( me->query_temp("lzg/lianhuan")){
				return ([  
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) ,
					"dodge": random(20)- 5 ,
					"damage":40 + random(50) + random((level*2)/4),
					"parry": random(15)+level/10,//ԭ����15
					"weapon" : random(2)?"�Ʒ�":"����",
					"damage_type" : random(2)?"����":"����",
				]);
			}
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 150 + random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("longzhua-gong", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������צ����\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"longzhua-gong/" + action;
}
