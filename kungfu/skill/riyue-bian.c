// riyue-bian.c ���±޷�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([
	"action": "$N����������һʽ�������ɴ̡���������̧��$w�������裬���������Ҳ���ǰ�����ƣ�����մճ��ɢ",
	"lvl" : 0,
	"skill_name" : "�����ɴ�",
	"damage_type":  "����"
]),
([
	"action": "$Nһʽ��Ŀ�����̡�������$w�ж��ñ�ֱ�������ڡ�������$n���̶�������Ю��������$nһ������",
	"lvl" : 30,
	"skill_name" : "Ŀ������",
	"damage_type":  "����"
]),
([
	"action": "$N�ھ���������$w����ת������ԲȦ��һʽ��������̡���Ծ��Ӱ������$n$l����",
	"lvl" : 60,
	"skill_name" : "�������",
	"damage_type":  "����"
]),
([
	"action": "$N����������һʽ����¥�Ǵ̡���$w��$n��ǰ��Ȧ�¹���������ת��������������ʽ����Ȼ��$n$l����������",
	"lvl" : 90,
	"skill_name" : "��¥�Ǵ�",
	"damage_type":  "����"
]),
([
	"action": "$Nһ���ߺȣ�����������һʽ�������Ӵ̡���$w����ת������Ӱ�ݺᣬֱ����Բ��Բ����ֱ�������ƻã�����$n",
	"lvl" : 120,
	"skill_name" : "�����Ӵ�",
	"damage_type":  "����"
]),
([
	"action": "$N���ذα�������׹�⣬һʽ�������̡ܴ��������鶯���ͣ���ʵ����������������˷���$n��ѹ��ȥ",
	"lvl" : 150,
	"skill_name" : "�����ܴ�",
	"damage_type":  "����"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if(!me->query("family") || me->query("family/family_name")!="������" )
		return notify_fail("�㲻�����ֵ��ӣ�������������±޷���\n");

	if ( me->query_skill("ranmu-daofa",1)
	 || me->query_skill("weituo-chu",1) 
	 || me->query("pass_xin"))
		return notify_fail("������д�Ħ�������Ϊ������ͬʱѧϰ������������\n");

	if ( me->query("max_neili") < 1500 )
		return notify_fail("���������Ϊ���㣬û�а취�����±޷���\n");

	if ((int)me->query_skill("yijin-jing", 1) < 130)
		return notify_fail("����׽�񹦻��̫ǳ��\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
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

mapping query_action(object me, object target)
{
	int i, level, j;
     
	if(me->query_temp("ryb_riyue"))
		return ([
//                         "action":HIB+action[random(sizeof(action))]["action"]+NOR,
  "action":BLU+replace_string(replace_string(action[random(sizeof(action))]["action"], "$w", "$W"), "$W", "$w"BLU)+NOR,
			"damage": 130 + random(140),
                        "dodge":  20+random(30),
                        "force": 350 + random(250),
                        "parry": 20+random(30),
			"damage_type":"����",
		]);

	if(me->query("env/���±޷�") 
	&& me->query_skill("parry",1) > 120 
	&& me->query("neili") > 1000 
	&& me->query("jingli") > 300 
	&& me->query("jiali") > 5
	&& random(me->query_str(1)) >= 40 
	&& random(me->query_skill("riyue-bian",1)) > 140){
		me->add("neili", -10);
		if (random(me->query_str(1)) >= 45 
		&& me->query_skill("riyue-bian",1)> 200) {           
			me->add("neili", -10);
			return ([
 "action": HIR "$N������$w"HIR"������Ȧ������$nԽתԽ����ԽתԽ�죬$p��ʱ�����������׵���ת�˼����ۿ���Ҫˤ����"NOR,
				"force": 400 + random(300),
				"dodge": 30,
				"parry": 30,
				"damage" : 200 + random(100),
				"damage_type": "ˤ��"
			]);
		}
		return ([
   "action": HIR "$N����һ�������������$w"HIR"������º�$n����һ��һ����ɽ�������ھ�����Ϣ����$n�ؿ�ײȥ��"NOR, 
			"force": 300 + random(350),
			"dodge": 30,
			"parry": 30,
			"damage" : 130 + random(140),
			"damage_type": "����"
		]);
	}
	level   = (int) me->query_skill("riyue-bian",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 200 + random(350),
				"dodge": random(30)-10,
				"damage": 80 + random(140),
				"parry": random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("riyue-bian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("����������������±޷���\n");

	if ((int)me->query("neili") < 20 )
		return notify_fail("����������������±޷���\n");
                
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}
/*
mixed hit_ob(object me, object victim, int damage)
{
	object weapon, weapon1;    
	int ap , dp;

	weapon=me->query_temp("weapon");
	weapon1=victim->query_temp("weapon");

	if(objectp(weapon) && objectp(weapon1)){
		if (random(me->query_skill("riyue-bian",1)) <100) return 0;
		if (random(10)>4 ) return 0;

		ap = me->query("combat_exp") /1000 * me->query("str");
		dp = victim->query("combat_exp")/ 1000 * victim->query("str");

		if( random(ap + dp ) > dp && weapon1->query("imbued") < 3 && weapon1->query("rigidity") < 5){
			message_vision(HIY"ֻ������ৡ���һ�����죬$N���е�"+weapon1->name()+HIY"�Ѿ���"+weapon->name()+HIY"��Ϊ���أ�\n"NOR, victim );
			weapon1->broken("�ϵ���");
			return 0;
		}
		else if ( weapon1->query("rigidity") < 5 )  {
			ap = me->query_str(1)+ me->query("jiali") +  me->query_skill("parry")/3;         
			dp = victim->query_str(1)+ victim->query("jiali") + victim->query_skill("parry")/3;
			ap *= me->query("combat_exp") /1000;
			dp *= victim->query("combat_exp")/1000;
			if (random(ap + dp) > dp ) {
				message_vision(HIY "ֻ�������������죬$N���е�"+weapon1->name()+HIY"�Ѿ���"+weapon->name()+"����һ���ѳֲ������ַɳ���\n"NOR, victim );
				victim->add_busy(random(2)+ 2);
				weapon1->move(environment(victim));
				victim->reset_action();
			}
		}
	}
	return 0;
}
*/
string perform_action_file(string action)
{
	return __DIR__"riyue-bian/" + action;
}
