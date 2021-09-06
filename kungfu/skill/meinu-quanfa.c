// meinu-quan ��Ůȭ��
// Modify By River
// Modified by darken@SJ

#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([
	"action" : "$Nʹһ�С��������¡�������һ�ӣ���$n��$l��ȥ����Ե��$n��$lһն",
	"skill_name" : "��������",
	"lvl" : 0,
	"damage_type" : "����"
]),
([
	"action" : "$N˫ȭ���أ���������ʹһ�С���ʩ���ġ�����$n��$l��ȥ",
	"skill_name" : "��ʩ����",
	"lvl" : 10,
	"damage_type" : "����"
]),
([
	"action" : "$N������ָ���𣬷��Ƶ�ϰ����һ�㣬һ�С��Ѿ���������ָ�ַ���$n��ȥ", 
	"skill_name" : "�Ѿ�����",
	"lvl" : 20,
	"damage_type" : "����"
]),
([
	"action" : "$N����һ����˫�ֺ�ȭ����̧ȥ��һ�С�������١�����$n��$l",
	"skill_name" : "�������",
	"lvl" : 30,
	"damage_type" : "����"
]),
([
	"action" : "$Nʩ������Ů֯�󡹣����ֻ�����Ͷ��֯��֮״��һ��һ�ͣ�����$n��$l",
	"skill_name" : "��Ů֯��",
	"lvl" : 50,
	"damage_type" : "����"
]),
([
	"action" : "$Nʩ�������촹����������ǰ�ˣ�˫���Դ���֮������������ն��$n��$l",
	"skill_name" : "���촹��",
	"lvl" : 70,
	"damage_type" : "����"
]),
([
	"action" : "$N��¶΢Ц��������ͷ��һ�ᣬ��ָ�硸������ױ��������ӽ���ȥ������$n��$l",
	"skill_name" : "������ױ",
	"lvl" : 90,
	"damage_type" : "����"
]),
([
	"action" : "$N˫�ֻ��ģ�����������ٲȻһ�С�������ġ����ַ�����$n$l",
	"skill_name" : "�������",
	"lvl" : 110,
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С�Ū�����һָ���죬һָ�Եأ���Ŀ���ף����������������$n��$l",
	"skill_name" : "Ū����",
	"lvl" : 120,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���ַ�����ϰ��Ůȭ����\n");
	if ( me->query_skill("yunu-xinjing", 1) < 10)
		return notify_fail("��Ů�ľ����򲻹����޷���ϰ��Ůȭ����\n");
	if ( me->query_skill("dodge", 1) < 20)
		return notify_fail("����Ṧ̫��޷�����Ůȭ����\n");
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
	int i, j, level, flag = (me->query("gender") == "Ů��");
	string msg;

	level = (int) me->query_skill("meinu-quanfa",1);         

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if ( me->query_temp("mnqf")){
				msg = MAG"$N��������������֧�ã���������ӳ�����̾һ�������ּ���֮�⣬$n���ɵô��ˣ��ó�����Ľ�ĵ��۹⿴��$N"NOR;
				me->delete_temp("mnqf");
				return ([
					"action" : msg,
					"force" : flag?250+random(350):180+random(300),
					"dodge": flag?random(30)-5:random(25),
					"parry": flag?random(30):random(35),
					"lvl" : action[j]["lvl"],
					"damage_type" : action[j]["damage_type"],
				]);
			}
			if ( me->query_temp("mnq_shexin")) {
				return ([
					"action" : action[j]["action"],
					"force" : flag?250+random(350):200+random(300),
					"dodge": flag?random(30):random(35),
					"parry": flag?random(30):random(35),
					"lvl" : action[j]["lvl"],
					"damage_type" : action[j]["damage_type"],
				]);
			}
			return ([
				"action" : action[j]["action"],
				"force" : flag?200+random(350):150+random(300),
				"dodge": flag?random(30)-10:random(30),
				"parry": flag?random(20):random(30),
				"lvl" : action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
			]);
		}
	}
}

string perform_action_file(string action)
{
	return __DIR__"meinu-quanfa/" + action;
}

int practice_skill(object me)
{
	if (me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if (me->query("neili") < 20)
		return notify_fail("���������������Ůȭ���ˡ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int extra, level, i, per, g = 2;
	if ( damage_bonus < 100 ) return 0;

	extra = (me->query("gender") == "Ů��"? 2:1);
	level = me->query_skill("meinu-quanfa",1);
	per = me->query("per");

	if( !userp(me) ) per -= 4;

	i = random(3) + 1;

	if( !userp(me) && userp(victim) ) g = 1;

	if( per > 24
	 && random(10) > 5
	 && level > 120
	 && random(me->query("combat_exp", 1)) > victim->query("combat_exp", 1)/g
	 && me->query("neili") > 500
	 && !victim->query_temp("mnq")
	 && !victim->query_temp("shexin")
	 && !victim->is_busy()
	 && random(me->query_per()*extra) > victim->query_per()/2 ){
		victim->add_temp("apply/parry", -level/5);
		victim->add_temp("apply/defense", -level/5);
		victim->add_temp("apply/dodge", -level/5);
		victim->set_temp("mnq", level/5);
		victim->add_busy(i);
		me->add("neili", -50);
		me->set_temp("mnqf", 1);
		call_out("reset_temp", 1, me, victim, i*2+1);
		return damage_bonus/2;
	}
	return 0;
}

void reset_temp(object me,object victim, int count)
{
	int skill;
	if (me)
		me->delete_temp("mnqf");
	if (!victim) return;
	if (!me
	|| !me->is_fighting(victim)
	|| count -- < 0) {
		skill = victim->query_temp("mnq");
		victim->add_temp("apply/parry", skill);
		victim->add_temp("apply/defense", skill);
		victim->add_temp("apply/dodge", skill);
		victim->delete_temp("mnq");
		if (me && living(victim) && ! victim->is_ghost())
			message_vision(HIW"\n$n�����״��˸���ս������Ϊ֮һ�塣\n"NOR, me, victim);
		return;
	}
	call_out("reset_temp", 1, me, victim, count);
}

int help(object me)
{
        write(WHT"\n��Ůȭ����"NOR"\n\n");
        write(@HELP
	�书���ƣ�
	        ��Ůȭ��(meinu-quanfa)
             
	���⹥����   
	        ���ľ���(perform shexin)��
        
HELP
        );
        return 1;
}
