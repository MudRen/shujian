// quanzhen-jianfa ȫ�潣��
// Modify By River 99.5.26
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([
	"action" : "$N��Ӱ�ζ���̤���ţ���ƫ�棬һʽ���ֻ���������$w��ֱ����$n��$l",
	"lvl" : 0,
	"skill_name" : "�ֻ�����",
	"damage_type" : "����"
]),
([
	"action" : "$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ������Į����ֱ��$n��$l",
	"lvl" : 10,
	"skill_name" : "����Į��",
	"damage_type" : "����"
]),
([
	"action" : "$N�β�ͦ����һʽ����ɽ������������$w�����ޱȣ���������$n��$l",
	"lvl" : 25,
	"skill_name" : "��ɽ����",
	"damage_type" : "����"
]),
([
	"action" : "$N����΢�࣬$w������һ���һ���󻡣�һʽ��˳ˮ���ۡ���ƽƽ����$n��$l��ȥ",
	"lvl" : 30,
	"skill_name" : "˳ˮ����",
	"damage_type" : "����"
]),
([
	"action" : "$N����š���������鱧��Բ��һʽ�������仨��������$w�й�ֱ��������$n��$l",
	"lvl" : 50,
	"skill_name" : "�����仨",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ������ٵء���$w������������������ֱ����Ю����֮����Ȼն��$n��$l",
	"lvl" : 70,
	"skill_name" : "����ٵ�",
	"damage_type" : "����"
]),
([
	"action" : "$N����ʩ�����׵罻�ӡ���$w�Ƴ�һ��������â��������ƿ�����$n��$l",
	"lvl" : 90,
	"skill_name" : "�׵罻��",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�Ȱ�����ף�һʽ�����񹲷ߡ���$w��������ԲȦ����������������",
	"lvl" : 110,
	"skill_name" : "���񹲷�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "parry"); 
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if( ! me->query_skill("xiantian-gong"))
	if ((int)me->query_skill("yunu-xinjing", 1) < 20)
		return notify_fail("�����Ů�ľ����̫ǳ��\n");
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
	int i, j, level,xtg;
	level = me->query_skill("quanzhen-jianfa",1);
	xtg = me->query_skill("xiantian-gong", 1);

	for(i = sizeof(action); i > 0; i--){
		if(level > action[i-1]["lvl"]){
			j = NewRandom(i, 20, level/5);
			if ( me->query_temp("hebi") && random(2) || me->query_temp("hubo")) { 
				return ([  
                                        "action" :random(2)? HIB + replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIB)+NOR
							   : MAG + replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"MAG)+NOR,
					"force" : 200 + random(350),
					"dodge": random(30),
					"damage": 80 + random(140),
					"parry": random(30),
					"weapon" : random(2)?"����":"����",
					"damage_type" : random(2)?"����":"����",
				]);
			}
                        if( me->query_temp("sanqing")){

				return ([  
                                        "action":HIC+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC), NOR, HIC)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) + xtg/10,
					"dodge": random(20)- 5 +xtg/15,
					"damage": 60 + random(80) + random((level+xtg)/4),
					"parry": random(15)+xtg/10,//ԭ����15
					"weapon" : random(2)?"����":"����",
					"damage_type" : random(2)?"����":"����",
				]);
			}
			if( me->query_temp("qzjf/lian")){
				return ([  
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) + xtg/10,
					"dodge": random(20)- 5 +xtg/15,
                                        "damage": 70 + random(50) + xtg/10,
					"parry": random(15)+xtg/10,//ԭ����15
					"weapon" : random(2)?"����":"����",
					"damage_type" : random(2)?"����":"����",
				]);
			}
						if( me->query_temp("qzjf/jianjue")){
				return ([  
					"action":HIC+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC), NOR, HIC)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) + xtg/10,
					"dodge": random(20)- 5 +xtg/15,
					"damage": 80 + random(100) + random((level+xtg)/5),
					"parry": random(15)+xtg/10,//ԭ����15
					"weapon" : random(2)?"����":"����",
					"damage_type" : random(2)?"����":"����",
				]);
			}
			return ([
				"action": action[j]["action"],
				"force" : 100 +random(250),
				"dodge": random(20)-10,
				"parry": random(10),
				"damage": 80 +random(80),
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
	 || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("�������������ȫ�潣����\n");
	if ((int)me->query("jingli") < 30)
		return notify_fail("�������������ȫ�潣����\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"quanzhen-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
//      ����ȫ�潣�����������������ʺܵ�
        object weapon; 
        int i;
        weapon = me->query_temp("weapon");
        i = me->query_skill("quanzhen-jianfa", 1);

        if( !userp(me) && random(2) ) return 0;
if(me->query_temp("jianjue")) return 0;
        if( !weapon || weapon->query("skill_type") != "sword" ) return 0;
        if( i < 350 ) return 0;
        if( !me->query("quest/qzjf/jianjue")) return 0;
        if( damage_bonus < 100 ) return 0;
        if( !living(victim) ) return 0;

        if( i >= 300 && !random(3)
         && random(me->query_con()) > victim->query_con()/3
         && random(me->query_skill("sword")) > victim->query_skill("parry")/3 )
                         {
                if( me->query_skill_prepared("strike") == "haotian-zhang"
                 && me->query_skill_mapped("strike") == "haotian-zhang"
                 && me->query_skill_mapped("parry") == "quanzhen-jianfa"
                 && me->query_skill_mapped("force") == "xiantian-gong"
                 && me->query_skill_mapped("dodge") == "jinyan-gong"
                 && me->query_skill("haotian-zhang", 1) >= 200 && random(2) ) {
                        message_vision(HIW"$NĬ��ȫ�潣������"HBMAG+HIW"������ָ�����½Դ���������ָ�����½��ġ�"NOR+HIW"�������͵��˽���ת����������ָ��֮��һ��ָ���澢����"NOR, me);
                        weapon->unequip();
                        me->add_temp("apply/attack",  me->query_skill("quanzhen-jianfa", 1)/3);
                        COMBAT_D->do_attack(me, victim, 0, 3);
                        me->add_temp("apply/attack", -me->query_skill("quanzhen-jianfa", 1)/3);
                        weapon->wield();
                } else {
                        message_vision(HIW"$NĬ��ȫ�潣������"HBBLU+HIW"������ָ�����½��������ָ�����½Զ���"NOR+HIW"��������"+weapon->name()+HIW"�͵Ļ�ת�ٴδ̳���"NOR, me);
                        me->set_temp("jianjue", 1);
                        me->add_temp("apply/attack",  me->query_skill("quanzhen-jianfa", 1)/3);
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("quanzhen-jianfa", 1)/3);
                        me->delete_temp("jianjue");
                }
        }
        else if( i >= 400 && random(2)
         && random(me->query("combat_exp")) > victim->query("combat_exp")/3
         && random(me->query_skill("sword")) > victim->query_skill("parry")/3
         && random(me->query_con()) > victim->query_str()/3
         && !victim->query_temp("lost_attack") ) {
                message_vision(HIW"$NĬ��ȫ�潣������"HBRED+HIW"�����ȴӱ��������ɱ�������չ������"NOR+HIW"����ʱ�����ݺᣬ��$n�������ֲ�����\n"NOR, me, victim);
                victim->add_temp("lost_attack", 1+random(3));
                victim->apply_condition("no_perform", 1+random(2));
                return random(me->query_skill("sword"))/3;
        }
        return 0;
}

void check_fight(object me,object victim)
{
	if(!victim) return;
	if( ! me 
         || ! me->query_temp("hebi")){
		victim->delete_temp("lost_attack");
		return;
        }
	call_out("check_fight", 1, me, victim);
}
