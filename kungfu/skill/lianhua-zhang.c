// lianhua-zhang.c ������
// By Looklove 2000/10/18
// Modify by Looklove 2001.4.4
// Modify by Looklove 2001.4.6
// update 2001.10.4

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$Nʹ�������������ơ�С�������������ƻ��أ����ƻ�������$n��$l",
	"lvl" : 0,
	"damage_type" : "����",
	"skill_name" : "С������"
]),
([
	"action" : "$N��¶΢Ц��һ�С�Ҷ����ɡ�����һ�ڣ����ƻ���һ������Ļ��ߣ�ֱ��$n��$l",
	"lvl" : 10,
        "damage_type" : "����",
	"skill_name" : "Ҷ�����"
]),
([
	"action" : "$N˫��΢�Ż���ǰ̽��˫����ֱ��ͻȻ�仯Ϊ�ƣ�һʽ�����ط��ۡ�����$n��$l",
	"lvl" : 20,
	"damage_type" : "����",
	"skill_name" : "���ط���"
]),
([
	"action" : "ֻ��$Nʹһ�С�ź��˿���������ƻζ���ƽ�٣�����ҡ�ڲ����л���ԲȦ����$n",
	"lvl" : 30,
	"damage_type" : "����",
	"skill_name" : "ź��˿��"
]),
([
	"action" : "$N����һ�������ֻ��أ�����һ�ǡ�ǧҶ����������һ���Ʒ磬ֱ��$n��$l",
	"lvl" : 40,
	"damage_type" : "����",
	"skill_name" : "ǧҶ����"
]),
([	"action" : "$Nʹ����˫�����ޡ���˫�Ʒɿ��趯����$nȦ���Ʒ�֮�ڣ����ۻ����Ҽ���Ȼ�ĳ�",
	"lvl" : 50,
        "damage_type" : "����",
	"skill_name" : "˫������"
]),
([
	"action" : "$Nһʽ���������������Ծ��ֱ��$n��˫�ƻû�����ʮ����Ӱ������������$n",
	"lvl" : 60,
        "damage_type" : "����",
	"skill_name" : "�������"
]),
([
	"action" : "$N���ƻ��أ���������ǰһ�Σ�ͻ�ش�Ҹ�´�����һʽ����ź������ֱ��$n����",
	"lvl" : 80,
        "damage_type" : "����",
	"skill_name" : "��ź����"
]),
([	"action" : "$N����$n�������ߣ�ʹ������Ұ���㡹�����紩�����������·��裬����$n��$l",
	"lvl" : 100,
        "damage_type" : "����",
	"skill_name" : "��Ұ����"
]),
([
	"action" : "ɲ�Ǽ�$N�������ͻȻʹ��һ�С��������������һ�Ʊ���$n��$l��ȥ",
	"lvl" : 120,
        "damage_type" : "����",
	"skill_name" : "�������"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�������Ʊ�����֡�\n");
	if( (int)me->query_skill("huntian-qigong", 1) < 30 )
		return notify_fail("��Ļ���������򲻹����޷�ѧϰ�����ơ�\n");
	if( (int)me->query("max_neili") < 150 )
		return notify_fail("�������̫�����޷��������ơ�\n");
	return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);
        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me,object weapon)
{
	int i, j, p, level, neili, strike;
	string msg;

	neili = (int)me->query("neili");
	level = (int)me->query_skill("lianhua-zhang", 1);
	strike = (int)me->query_skill("strike", 1);
	p = me->query_int()+me->query("dex");

	if( me->query_temp("lhz/bdlh") ) {
		switch(me->query_temp("lhz/bdlh")) {
			case 2: msg = HIG"$N˫����Σ������ں��������һ�����ԲȦ��ͻȻ��$n��$l"NOR; break;
			case 1: msg = HIG"$N��������һ�գ����ں����������Ȼ������һ������$n��$l"NOR; break;
			default: msg= HIG"$N˫����Σ������ں��������һ�����ԲȦ��ͻȻ��$n��$l"NOR; break;
		}
		me->add_temp("lhz/bdlh", -1);
		return ([
			"action": msg,
			"dodge": random(35),
			"parry": random(35),
			"force": 180+random(300),
			"damage_type": "����"
		]);
	}
	if( me->query_temp("shuangjue/lhz") ) {
		switch(me->query_temp("shuangjue/lhz")) {
			case 2: msg = HIR"ֻ��$N��һ��������ǰ��������ͻȻ���У��������Ю���Ʒ���$n��$l��ȥ"NOR; break;
//			case 1: msg = HIM"��Ӱһ�գ�$nֻ�����ۻ����ң�ֻ��$Nһ����ȣ����������ģ�����"NOR; break;
			case 1: msg = HIY"$N���Ȱ������ϣ������ϲ������һ������Ȼһ���ĳ����˵��Ǹɾ�����"NOR;break;
			default: msg = HIR"ֻ��$N��һ��������ǰ��������ͻȻ���У��������Ю���Ʒ���$n��$l��ȥ"NOR; break;
		}
		me->add_temp("shuangjue/lhz", -1);
		return ([
			"action": msg,
			"dodge": random(30),
			"parry": random(30),
			"damage": 50 +random(50),
			"force": 200+random(300),
			"damage_type": "����"
		]);
	}
	if( random(level) > 100
	 && strike > 80
	 && neili > 800
	 && random(p) > 24
	 && random(3) ) {
		me->add("neili", -60);
		return ([
			"action":HIM"ɲ�Ǽ䣬$N�������һ�С��������������һ�Ʊ���$n��$l��ȥ"NOR,
			"weapon" :"�Ʒ�",
			"force": 420,
			"dodge": 25,
			"parry": 20,
			"damage_type": "����"
		]);
	}
	for ( i = sizeof(action); i > 0; i--){
		if(level > action[i-1]["lvl"]){
			j = NewRandom(i, 20, level/5);
			return ([
				"action" : action[j]["action"],
				"dodge": random(30),
				"parry": random(30),
				"force" : 150+random(300),
				"lvl" : action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("lianhua-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 40)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("jingli", 30);
	me->receive_damage("neili", 10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"lianhua-zhang/" + action;
}

mixed hit_ob(object me, object target)
{
	string msg;
	int j, p;
	object wp = me->query_temp("weapon");

	p = me->query_int()+me->query("dex");
	j = me->query_skill("lianhua-zhang", 1);

	if( random(p) > 40 && !target->is_busy() && random(j) > 100
	 && me->query("neili") > random(target->query("neili")/2)
	 && random(me->query("neili")) > 500
	 && me->query("max_neili") > 1500
	 && !objectp(wp)
	 && random(j+p) > random(target->query_skill("dodge",1) )
	 && !me->query_temp("lhz/bdlh")
	 && !me->query_temp("shuangjue/lhz") ) {
		switch(random(2)) {
			case 0 :
				msg = "������$N��ʹ����˫�����ޡ���˫�Ƴ��ְ�ӳ�����$nȦ���Ʒ�֮�ڣ�";
				msg += "$n��ǰһ������ʧȥ��$N����Ӱ��\n";
				target->add_busy(1+random(2));
				break;
			case 1 :
				msg = "������$N��һʽ����Ұ���㡹����ֻ�����紩�����������·��衣\n";
				msg += "$nֻ�����ۻ����ң��ֲ���������ʵ�������顣\n";
				target->add_busy(1+random(2));
				break;
		}
		message_vision(msg, me, target);
	}
}

int help(object me)
{
	write(HIM"\n�����ƣ�"NOR"\n");
	write(@HELP
	ؤ������������һ�ſ������Ź��򡣳����ŵĵ��ӣ���ѧ�����ơ�
        ���ż������ߣ�������������ǿ��

	ѧϰҪ�󣺻�����������30����������150 ��
	�Զ����������������
	���Դ���24�����������������Ʒ���������ȫ������80��
	�������� 800 ��ս�������������
HELP
        );
        return 1;
}
