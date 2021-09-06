//�μҽ���
//cool@SJ,990528
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N�������˸�����������$wƽƽ�ݳ���һʽ�������Ͻ�ֱ��$n��ǰ��",
	"damage_type" : "����",
	"lvl": 0,
]),
([
	"action" : "$N������ǰ��$w��һ���벻���ĽǶ�ͻȻ������һʽ���̼�������ֱ��$n������",
	"damage_type" : "����",
	"lvl": 20,
]),
([
	"action" : "$Nһ�С������ڿա�������Ծ�ڰ�գ�$w����������ֱ��$n��ͷ��",
	"damage_type" : "����",
	"lvl": 40,
]),
([
	"action" : "$N����б�ӣ�����ָ��$n�ĸ�����һ�С���Ԩ���ԡ������¶�������$n",
	"damage_type" : "����",
	"lvl": 60,
]),
([
	"action" : "$N˫����أ�б�ɶ�����$w����$n��$l����һ�С�Цָ���ϡ�",
	"damage_type" : "����",
	"lvl": 80,
]),
([ 
	"action" : "$N��Хһ�����ὣ�������͸������֮�⣬���ǶμҲ���֮�ء���¹��ԭ����������ס$n��ȫ��",
	"damage_type" : "����",
	"lvl": 100,
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if (me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ( ! me->query_skill("kurong-changong", 1))
	if (me->query_skill("qiantian-yiyang", 1) < 20)
		return notify_fail("���Ǭ��һ�����̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	string msg;
	level   = (int) me->query_skill("duanjia-jianfa",1);

	if(me->query_temp("fenglei")){
		switch(me->query_temp("fenglei")){
			case 4: msg = HIW"$Nʩչ���������裢��һ��Ծ���ڿ��У�����Χ����$n��ͣ��ת���������ĸ���λ��$n�̳��Ľ�������ޱ�" NOR;break;
			case 3: msg = HIW"$N����$n�ľ����ڿ���һ����˫���ս���һ���̳�������ӥ�����գ����ˣ���һ����������һ����������$n" NOR;break;
			case 2: msg = HIW"$N���ƻ��Ļ���������$n��ע�⣬���ֽ�ת���Σ���������������������һ�����ģ���������Ϯ��$n��ȫ��" NOR; break;
			case 1: msg = HIW"$N�����³���ͻȻ����һ������ĳ���ͷ�½��ϣ����ӽ������������һƮ�����ǿ����ޱȵĴ̳�������ֱ��$n"NOR;break;
			default: msg = HIW"$N�����³���ͻȻ����һ������ĳ���ͷ�½��ϣ����ӽ������������һƮ�����ǿ����ޱȵĴ̳�������ֱ��$n" NOR; break;
		}
		me->add_temp("fenglei", -1);
		return ([
			"action":msg,
			"damage": me->query("class") =="bonze"?80 +random(100):130+random(140), 
			"damage_type": "����",
			"dodge": random(35), 
			"force": me->query("class")=="bonze"?180+random(300):250+random(300),
			"parry": random(35),
			"skill_name" : "��������",
		]);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			return ([
				"action":action[NewRandom(i, 20, level/5)]["action"],
				"damage": me->query("class")=="bonze"? 60+random(100):80+random(140),
				"damage_type": action[NewRandom(i, 20, level/5)]["damage_type"],
				"dodge": me->query("class")=="bonze"? random(30):random(30)-10,
				"force": me->query("class")=="bonze"? 150+random(300):200+random(350),
				"parry": me->query("class")=="bonze"? random(30):random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("duanjia-jianfa", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("��������������μҽ�����\n");
	if((int)me->query("neili") < 20)
		return notify_fail("��������������μҽ�����\n");
	if ( me->query("class") == "bonze") {
		me->receive_damage("jingli", 30);
		me->add("neili", -10);
	}
	else {
		me->receive_damage("jingli", 40);
		me->add("neili", -15);
	}
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"duanjia-jianfa/" + action;
}
