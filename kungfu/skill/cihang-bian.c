//�Ⱥ���,
//ȡ��������ʦ<��ţͼ��>
//cool@SJ,990420

#include <ansi.h>

inherit SKILL;

string *body_name = ({ 
"������","��첲","����","ͷ��","����","����","С��","��Ž���","������","�Ҹ첲","����","�ҽŽ���",}); 

mapping *action = ({
([
	"action": "$N˫�ֺ�ʲ��������ע, һʽ��δ����������$w�������ԣ�����һת������$n��$l",
	"skill_name" : "δ��",
	"lvl": 0,
	"damage_type":  "����",
]),
([
	"action": "$N���绬��������$wһ����һʽ����������Ѹ���ޱȵطִ��������࣬$n��ʱ����֧穣������ֽ�",
	"skill_name" : "����",
	"lvl": 20,
	"damage_type":  "����"
]),
([
	"action": "$N������ע��$w�����ʹ��һʽ�����ơ���$w��ز���裬ֱ�������ƿ�һ�����$n",
	"skill_name" : "����",
	"lvl": 40,
	"damage_type":  "����"
]),
([
	"action": "$Nһ����Х������$wһ�С����ס������������Ӱ����ǵص���$n�������Ƶ�����֮��",
	"skill_name" : "����",
	"lvl": 60,
	"damage_type":  "����"
]),
([
	"action": "$N������������$w��һʽ��ѱ�������ӳ�������ת������$n��ȥ ",
	"skill_name" : "ѱ��",
	"lvl": 80,
	"damage_type":  "����"
]),
([
	"action": "$N������շ������ִ����ӳ�$w��һʽ���ް�����һ����ɽ�����ı޷�ֱ����$n",
	"skill_name" : "�ް�",
	"lvl": 100,
	"damage_type":  "����"
]),
([
	"action": "$N��¶΢Ц��ǰһ��������$w���ʹ��һʽ�����ˡ�������ƽ������������˿������",
	"skill_name" : "����",
	"lvl": 120,
	"damage_type":  "����"
]),
([
	"action": "$N��ǰ������˫����ס$w������ʹ��һʽ�������������Ƴ���, һ�ɾ����ƿն���",
	"skill_name" : "����",
	"lvl": 140,
	"damage_type":  "����"
]),
([
	"action": "$N��������$w��һʽ�����ա�����������, ��������",
	"skill_name" : "����",
	"lvl": 160,
	"damage_type":  "����"
]),
([
	"action": "$N�����������裬����$wͻȻ�ӳ���ʹ��һʽ��˫����������������������,���ƾ���",
	"skill_name" : "˫��",
	"lvl": 180,
	"damage_type":  "����"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 800 )
		return notify_fail("����������㣬û�а취��ϰ�޷�, ����Щ���������ɡ�\n");

	if ((int)me->query_skill("kurong-changong", 1) < 100)
		return notify_fail("��Ŀ���������Ϊ������\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	 ||( string)weapon->query("skill_type") != "whip" )
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

mapping query_action(object me, object weapon)
{
	int i, level, j;
	string msg;
	level = (int) me->query_skill("cihang-bian",1);

	if(me->query_temp("chb")){
		switch(me->query_temp("chb")){
			case 3: 
				         msg =HIY"$N�����������ӷ𣡡���ʹ�����ȱ����־������г���һ���$n���ʺ��ȥ��\n";
                       msg +="��ͷδ����������Ю����������յ��գ���Է�һ�����ϣ�ֻ������žž���������죬\n";
                       msg +="��ͷ���𣬱���һ�������Ķ��ߺ��ط��ɻӶ�������������ɳ����Х������"NOR;
				break;
		  case 2:         msg =HIW"$N�������ҷ�ȱ���������ʹ�����ȱ����־����������տ�����������������¶��ǣ�\n";
                             msg +="���г����趯ʱ�Ʋ������Ӱ��������Ϣ���ƻ�ʵ����ȴ�ִ󿪴�����������˵������Ī����"NOR;

				break;
			
			
			case 1: msg = HIW"$N�������ҷ�ȱ����������ˣ�����ʹ�����ȱ��������������տ������������������г���һ�����������ɳ����Х������"NOR; break;
			
			
			default: msg = HIW"$N�������ҷ�ȱ����������ˣ�����ʹ�����ȱ��������������տ������������������г���һ�����������ɳ����Х������"NOR; break;
		}
		me->add_temp("chb", -1);
		return ([
			"action":	msg,
			"damage_type": 	"����",
			"damage": 	130 +random(140),
			"dodge": 	random(30), 
			"parry": 	random(30),
			"force": 	250 + random(350),
		]);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action":	action[j]["action"],
				"damage_type": 	action[j]["damage_type"],
				"skill_name" : 	action[j]["skill_name"],
				"lvl":		action[j]["lvl"],
				"damage": 	80 + random(140),
				"dodge": 	random(30)-10,
				"force": 	200 + random(350),
				"parry":	random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("cihang-bian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 50)
		return notify_fail("��������������Ⱥ��޷���\n");
	if ( me->query("neili") < 20)
		return notify_fail("��������������Ⱥ��޷���\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weap,weap1;
        
	weap = victim->query_temp("weapon");
	weap1 = me->query_temp("weapon");

	if( random(me->query_skill("cihang-bian", 1)) > 150
	 && me->query("neili") > 100
	 && random(10) > 7 
	 && !me->query_temp("chb")){
		if ( weap ){
			message_vision(HIY "ֻ��$N���ٻ���" + weap1->name() + HIY"��ת����������СȦ�ӣ�������֮����ס�Է���" + weap->name() +HIY"��\n" NOR, me );
			if (random(me->query_skill("parry", 1)) > victim->query_skill("parry", 1)/2 ) {
				message_vision(HIY "$N�����ֱ�����һק��" + weap->name() + HIY"ȴ�޷���"+weap1->name()+HIY"�Ĳ������ѿ����鼱֮��ֻ�÷��������еı��С�\n" NOR, victim );
				weap->unequip();
				weap->move(environment(me));
				victim->reset_action();
			}
			else {
				message_vision(HIY "$N�����ɾ���" + weap->name()+ HIY"˳�ŷ��������ת���£��⿪��"+weap1->name()+HIY"�Ĳ��ơ�\n" NOR, victim );
				victim->add("neili",-20);
			}
			me->add("neili", -30);
		}
		else {
			if ( random(me->query_skill("parry", 1)) > victim->query_skill("parry", 1)/2 
			&& !random(5) 
			&& !victim->is_busy() ) {
				victim->start_busy(random(3)+ 1);
				me->add("neili",-80);
				victim->receive_damage("qi", damage_bonus/2, me);
				victim->receive_wound("qi", damage_bonus/4, me);     
				message_vision(HIY"ֻ��$N�ı�ʽ�鶯�쳣��"+ weap1->name() + HIY"ת����������СȦ�ӣ�������֮����ס�˶Է���"
					+ body_name[random(sizeof(body_name))] +"��\n" NOR, me);
	               		message_vision(HIR"$N����һ��,�ƺ����˵��ˡ�\n" NOR, victim );    
	           	}
	        }
	}
	return 0;
}

string perform_action_file(string action)
{
	return __DIR__"cihang-bian/" + action;
}
