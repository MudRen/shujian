// hanbing-shenzhang.c  ��������
// 6/25/2000 Modifed
// Lklv@SJ 2001.10.22 modified reopen

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "ȴ��$N����һ�����������ֵ��Ƶ����Է������������˺������������֣����ʳ�ж�ָ��$n$l��ȥ",
	"damage_type" : "����",
	"lvl" : 0,
]),
([
	"action" : "$N���Ƶ���$n�����Ƽ����ھ�����$p����ֱ�����£���һ�ƾӸ����£����Ӻ��磬�Ƶ��澢",
        "damage_type" : "����",
	"lvl" : 50,
]),
([
	"action" : "$N����һ�����������Ʒֱ��ĳ�����̬����̫��ȭ��ʮ���֣����漴������ȴ����������ĺ���",
	"damage_type" : "����",
	"lvl" : 100,
]),
([
	"action" : "$N����ȫȻ�����·磬˫�۳��м��̣�������һ�߱㼴���أ�����ֻ�ز�������ͻȻ����һ�죬����$n",
	"damage_type" : "����",
	"lvl" : 150,
]),
([
	"action" : "$N������ָ��ָ���Ƶ�$n������������������ָ��$p��������һ̧����Ȼ����$p$l�������������",
	"damage_type" : "����",
	"lvl" : 180,
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (!me->query("family") || me->query("family/master_id") != "zuo lengchan")
		return notify_fail("��ֻ�ܴ�����������ѧ�ú������ơ�\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if ((int)me->query_skill("hanbing-zhenqi", 1) < 140)
		return notify_fail("��ĺ���������򲻹����޷�ѧ�������ơ�\n");
	if ((int)me->query("max_neili") < 2000)
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
        string msg;
	level = (int)me->query_skill("hanbing-shenzhang", 1);
  
if (random(level) > 200 && random(15)<1 && !me->query_temp("ssj/leiting")){
		return([
			"action": HIB"������$N����һ��һ�գ���$n��û�з�Ӧ����ʱ������ǰ�����𡸺����������������һ�ơ���"NOR,
			"force" : 400 +random(150),
			"dodge" : 20,
			"parry": random(30),
			"damage_type" : "����",
		]);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);


if( me->query_temp("ssj/leiting") ){

msg = HIR"$Nһ�����У������������֣�����"HIW"��������"HIR"���������֣��ͻ�������\n"NOR;
msg += HIR"��һ��������$n������ʮ����ҪѨ��$n�������ܣ���ʱ���ܽ��ˣ�ֻ��Ҳ������ƣ��������ӡ�\n\n"NOR;	
me->delete_temp("ssj/leiting");	
		return ([
                         "action": msg+ action[j]["action"] ,
			"force" :  500 + random(300),
			"dodge":   50,
			"parry":   30,
			"weapon": random(2)==1?"�Ʒ�":"����",
			"damage_type" : "����",
		]);}

 
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 200 +random(350),
				"dodge": random(30)-10,
				"parry": random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("hanbing-shenzhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������������ơ�\n");
	me->receive_damage("jingli", 40);
	me->receive_damage("neili", 15);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	string msg;
	int lvl= me->query_skill("hanbing-shenzhang", 1);
	int j = (lvl - 100) / 5 + 1;
	if ( j > 10 ) j = 10;


	if(random(me->query_skill("hanbing-shenzhang", 1)) > 100
	&& me->query("neili") > 1000
	&& random(me->query("neili")) > victim->query("neili")/2){
		if(victim->query("neili")/2 < me->query("neili"))
			victim->add_condition("cold_poison", 10);
		else
			victim->add_condition("cold_poison", 5);
	}
	if(random(me->query_con(1))>20
	&& lvl >= 100
	&& random(me->query_str(1))>20
	&& me->query_skill_prepared("strike") == "hanbing-shenzhang"
	&& me->query("neili") > 1000
	&& me->query("max_neili") > 1500
	&& me->query("jiali")){
		me->add("neili", -50);
	switch(random(7)){
		case 0 :
			msg = HIB"$N���𺮱���������������һ���������ֵİ�����ʹ�����������еġ�"HIW"�캮�ض� "HIB"����˫��һ�ɸ���֮����$n��ȥ��\n"NOR;
			victim->add_condition("cold_poison", j );
			break;
		case 1 :
			msg =HIB"$N���𺮱���������������һ���������ֵİ�����������ʹ�����������еġ�"HIW"����̹�"HIB"��������Ʈ��������$n��ʱ�о�һ����ɭ֮��ӭ�������\n"NOR;
			victim->receive_damage("qi", lvl*2, me);
			victim->receive_wound("qi", lvl, me);
			break;
		case 2 :
			msg =HIB"$N���ƽ���ʹ�����������еġ�"HIW"����ѩ��"HIB"�������Ʊ��ѩ�ף���$n��ȥ��\n"NOR;
			victim->add("jingli",-lvl);
			break;
		case 3 :
			msg =HIB"$N���𺮱���������������һ���������ֵİ�����ʹ�����������еġ�"HIW"��ѩ����"HIB"����˫�Ʊ��ѩ�ף����һ�ɺ��쳺��֮������$n��ȥ��\n"NOR;
			victim->add("neili", -lvl*3);
			if( victim->query("neili") < 0)
	                	victim->set("neili", 0);
			break;
		case 4 :
			msg =HIB"$N��������ʹ�����������еġ�"HIW"ǧ�����"HIB"����˫����������������һ������֮��ֱ��$n��ȥ��\n"NOR;
			victim->start_busy(2 + random(2));
			break;
		case 5:
			msg =HIB"$N�������˿�����ʹ�����������еġ�"HIW"����ѩƮ"HIB"������$n�ͳ�һ���溮�ޱȵ�������\n"NOR;
			victim->receive_damage("qi", lvl*3, me);
			victim->receive_wound("qi", lvl*2, me);
			break;
		case 6:
			msg =HIB"$N���𺮱���������������һ���������ֵİ�����ʹ����������֮���衸�򺮹�һ��������˫��������������ͬ���ȣ�����$n��\n"NOR;
			victim->apply_condition("no_perform", 1);
			break;
		}
                if (me->query_temp("ss/fw"))
			victim->add_condition("cold_poison", 10);
		msg +=HIW"$nֻ����$N��һ�Ƽ����溮�ޱȵ���������ðٶˣ���������㣬ע��ȫ��Ѩ��, ���ܶ�����\n"NOR;
		message_vision(msg, me, victim);
	}
}

string perform_action_file(string action)
{
	return __DIR__"hanbing-shenzhang/" + action;
}
