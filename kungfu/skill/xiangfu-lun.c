// /kungfu/skill/xiangfu-lun.c
// xiangfu-lun.c ������
// dubei
// snowman(98,12,22)
// iceland(99.8.3)
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһ�С�����̾�����ơ����������ƻ��أ����ֵ�������$w�����ؿ���$n��$l",
	"skill_name" : "����̾������",
	"lvl" : 0,
	"damage_type" : "����",
]),
([
	"action" : "$N������$w���ϰ�գ�Ծ��һ������$w�ϣ����С�����������ơ���������׹�أ�ֱ��$n",
	"skill_name" : "�����������",
	"lvl" : 20,
	"damage_type" : "����",
]),
([
	"action" : "ƾ������һ��ѩ�׵Ĺ�Ļ�������˸��$wЮ���󹦵¹����ơ������Ͼ�������$N���зɳ�����$n��$l",
	"skill_name" : "�󹦵¹�����",
	"lvl" : 40,
	"damage_type" : "����",
]),
([
	"action" : "$N˫�ۿıգ�ȫ������ȴ���ھ��ĵ�������������$w���⡸���ֹ����ơ����ƶ��£���$n����ѹȥ",
	"skill_name" : "���ֹ�����",
	"lvl" : 60,
	"damage_type" : "����",
]),
([
	"action" : "$N˫��ԽתԽ������Ļٲ��һ�����£���$n���֣��⡸��������ơ��ľ�������$w����ɽ����֮�Ʒ�������",
	"skill_name" : "���������",
	"lvl" : 80,
	"damage_type" : "����",
]),
([
	"action" : "$N���и߳�����ħ�䡹��һ�С������������ơ��ӳ���$w�û����������Ӱ����������ˮ��ӿ��$n",
	"skill_name" : "������������",
	"lvl" : 100,
	"damage_type" : "����",
]),
([
	"action" : "$N���������������Ͻ�ħ�󷨴߶�������������ơ���$w����Ĺ��������ƽ�$n��",
	"skill_name" : "�����������",
	"lvl" : 120,
	"damage_type" : "����",
]),
([
	"action" : "$N��һ������������$w���·��ɣ��ַ��ҳ����⡸���ǻ۹����ơ���$n��ǰ��Ӱ���裬Ӧ�Ӳ�Ͼ��",
	"skill_name" : "���ǻ۹�����",
	"lvl" : 140,
	"damage_type" : "����",
]),
([
	"action" : "$N���΢Ц����¶�ȹ⣬ȫ����ɢ�����ġ���ȱ������ơ��������羪�κ��ˣ�$wһ����һ����ӿ��$n",
	"skill_name" : "��ȱ�������",
	"lvl" : 160,
	"damage_type" : "����",
]),
([
	"action" : "$N˫�ָ߾�$w�����һ��ʹ������Բ�������ơ����϶���ն��$n�������ޱȣ�������ӿ���Ѵ�Բ��֮��",
	"skill_name" : "��Բ��������",
	"lvl" : 180,
	"damage_type" : "����",
]),
});

string *wushuai_msg = ({
HIR"$N���ִ��ڷ�������б��һ���������ڿ��л���һ�����ߣ���$n��ȥ��������ţ��"NOR,
HIR"$N����������أ�����ǰ���һ��һ�ͣ����ֶ�Ȼ���𣬴Ӳ���˼��ĽǶ�ײ��$n"NOR,
HIR"$N����������˫�����ƣ�����ȥ�ƾ������ص�һ������$n��"NOR,
HIR"$N˫�ֻ��ţ�����$n��ǰ�������ڿ�����ת���أ�Ϯ��$n�ĺ��ԡ�"NOR,
HIR"$N������һ���Ϻȣ�����ȭӲ�������ڷ����ϣ����ַ����͵�һת��ֱ׷��$n��"NOR,
HIR"$N����Ȧת���������������ɽ������У����������󼱷�������ƽ�ƣ���������$n��$l��"NOR,
HIR"$Nƾ���������ֶ����������ϼ������۹�ɨ��$n�����ֽ����ŷ��˹�ȥ��"NOR,
HIR"$NԾ���գ�˫�����϶����Ƴ�������ƾ�ռ��٣����ƾ��ˡ�"NOR,
HIR"$N��ǰ����������һת�������ͳ����֣������$n���ļ��ƣ���ס��$n����·��"NOR,
});

string *parry_msg = ({
HIC"$n���㲻�ܣ����з��ְڿ�����$N��ǰ�γ���һ����Ļ��$N���и����޷��ݳ���\n"NOR,
HIM"ȴ��$n̤ǰһ�������з��ַ��ɣ��������ͣ�$N�������ӣ�������ˡ�\n"NOR,
HIY"$n�ַ�ͻ�䣬���ִ��ŷ��������ȥ������������$N��û����ʱ������$N��������\n"NOR,
MAG"����$n����˫�ۣ��ٷ���Ӳ�ܣ�ƹ��һ�������������ڵ�$N��\n"NOR,
MAG"$n��׼���ƣ����ְڸ�����ƣ���$N��·������$N����ֻ����һ��͹�����ȥ�ˡ�\n"NOR,
MAG"$Nһ�����㣬�ŷ���$n���з���ָ���Լ���$l�����Ǵ��еĿ��ţ���æ�������ܡ�\n"NOR,
});

string  *msg = ({
CYN"$w"CYN"���ݷ�û�����ǧ��������費Ϣ���������Ӱ�γ���һ������ε�ͼ����ÿһ�ֵĹ��������������������"NOR,
HIY"�����Ǽ�ֻ���ֶԻ����������������Ʋ���������$nһ��֮�ʣ����ַ����˳�ȥ��"NOR,
YEL"���������У�������ת������ײ��$n����$p��Ҫ����ʱ��ȴ�ƹ����ɵ�������"NOR,
YEL"$w"YEL"�������������������ɻأ�����$n����Ȧ�ӣ����ߺ��ͣ�������б����������Ҳ���������죬�Թ����˾����ŵ��ۻ����ң����񲻶�"NOR,
YEL"һ����С���ˣ�������Ȼ�䷨�ֺ����һ��������$nײȥ��������ţ���������ɵ�"NOR,
HIC"���$n��ǰ���ɷ�Բ������һ������ķ籩���⻪��Ȼ�У����ַ��������������������"NOR,
HIG"��Щ$w"HIG"���Ʊ˱�������һ��ľ�������$n��ǰ�����ݺᣬ�ۼ���˸����������֮�䣬��ȫ��������������"NOR,
MAG"ֻ��$w"MAG"������������������$n���·��ɣ��Ƶ����������絶���Ҫ��$n��������"NOR,
YEL"ͻȻ����������������$w"YEL"������ײ�����ֹ�һ���ϲ�����$n��ȥ"NOR,
HIM"�����ٴκ�Χ���ϵ羫âΧ��$n�������������䣬ǧ����Ӱ��ӳ��һ��������ѣĿ��ͼ������ͼ�������ˣ�����һƬ����ε���ɫѩ����"NOR,
YEL"������$n��ǰ���ģ��͵���$pӭͷ���£������ַ���һ�֣�һ��һ�ͣ��������죬����$n$l"NOR,
YEL"������Х���У��Ǽ�ֻ���ֻ�ֱ�ɡ���б�ɡ������������׹������������ʱ��$n��ȫ����·�ѱ�����"NOR,
BLU"�͵���$w"BLU"��$n$l�����£���$p����ж��֮ʱ��������ͻȻ�Ϸɻ���������$p��$l"NOR,
YEL"�Ƿ��ַ����ҵ���$nȴ������ͷ�����������һһ�����������ֱ��糤�����۾�һ�㣬��Ȼ�����ɵ���$n$l"NOR,
HIY"����ɭɭ���˵�����$w"HIY"��������ζ��������������죬�ڲ���գ�۵�˲Ϣ�䣬ҫĿ�ĵ���������������������⣬Ѹ����ƥ�Ļ�$n"NOR,
});
int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

void skill_improved(object me)
{
	int skill = me->query_skill("xiangfu-lun", 1);
	if( skill >= 200 && !me->query("ryl_add")){
		me->set("ryl_add", 1);   
		tell_object(me, HIW"\n��Ȼ����е���ϢԽתԽ�죬˲ʱ�����Ѿ���������һ���µľ��磡"NOR);
		me->add("max_jingli", skill/2+random(skill));
		me->add("max_neili", skill/2+random(skill));
	}
}

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "hammer")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( me->query_str(1) <=35)
		return notify_fail("��ı�������ѧ�����֡�\n");
	if( me->query("max_neili") < 2000)
		return notify_fail("�������������\n");
	if( me->query_skill("longxiang-boruo", 1) <= 160)
		return notify_fail("��Ҫ�еڰ˲�����������������,����ѧ�����֡�\n");
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
	level = (int) me->query_skill("xiangfu-lun",1);
        
	if( !userp(me)
	 && me->query("env/invisibility")
	 && me->query("master_user/user")){
		return ([
			"action": msg[random(sizeof(msg))],
			"damage": 180+random(100),
			"damage_type":random(2)?"����":"����",
			"dodge": 5,
			"force": 250+random(250)
		]);
	}
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
                  if(me->query_temp("xfl/wushuai"))
                    return ([
                            "action": wushuai_msg[random(sizeof(wushuai_msg))],
                            "damage_type":random(2)?"����":"����",
                            "dodge":random(25),
                            "force":350+random(200),
                            "parry":random(30),
                            "damage":240+random(120),
                            ]);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":200+random(350),
				"dodge":random(30)-10,
				"damage":180+random(50),
				"parry":random(20),
			]);
	}
}

mixed query_parry_msg(object weapon, object me, int attack_type)
{
	if (objectp(weapon = me->query_temp("weapon")) 
	&& (string)weapon->query("skill_type") == "hammer"
	&& me->query_skill_mapped("hammer") == "xiangfu-lun"
	&& me->query_skill_mapped("parry") == "xiangfu-lun")
		return parry_msg[random(sizeof(parry_msg))];
}

int practice_skill(object me)
{
	int lvl = me->query_skill("xiangfu-lun", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;
	if ( me->query("jingli") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("������ڵ���������,�޷������������֡�\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xiangfu-lun/" + action;
}


mixed hit_ob(object me, object victim,int damage)
{
	object wp1, wp2; 

	wp1 = me->query_temp("weapon");
        
	if( !objectp(wp2= victim->query_temp("weapon")) )
		return;
                
	if( ( !me->query("env/��"))
        ||  me->query_skill("xiangfu-lun", 1) < 300 
	|| !me->query("jiali")
	|| me->query("neili") < 1000 
	|| me->query_skill_mapped("parry") != "xiangfu-lun" )
		return;

	if( random(10) > 5 || random(me->query("combat_exp")) > victim->query("combat_exp")/ 2 )

{
		message_vision(HIW"$N�ֱ۱�����ʩչ�������־���"+wp1->name()+HIW"̽�������һ����ס��$n"+wp2->name()+HIW"��\n"NOR, me,victim);
		if( random(me->query_str(1)) > victim->query_str(1) ) {
			me->add("neili", -150);
			message_vision(HIR+me->query("name")+HIR"�˾�������ֻ����$N�۹ǿ���һ������Щ�ͱ����ϣ�$N��ʹ֮����һ�ɣ�"+wp2->name()+HIR"�����˹�ȥ���ڵ��ϣ�\n"NOR, victim);
                        wp2->unequip();
			wp2->move(environment(victim));
                         victim->add_busy(2); 
     victim->apply_condition("no_perform",1);
    victim->apply_condition("no_fight",2);
		}
		else if(random(me->query_str()) > victim->query_str()/3*2){           
			me->add("neili", -50);
			message_vision(HIR+me->query("name")+HIR"�˾�������$N���������ļ������������ھ�ʹ��"+wp2->name()+HIR"���ַɳ���\n"NOR, victim);
			wp2->unequip();
                        wp2->move(environment(victim));
                         victim->add_busy(2); 
     victim->apply_condition("no_fight",2);
		}
		else if( me->query_temp("shield") ){           
			me->add("neili", -50);
			message_vision(HIY"$N����ǰ�壬"+wp2->name()+HIY"ֱ�̹�ȥ������"+me->query("name")+"�����������û��˿�ȥ��\n"NOR, victim);
		}
		else message_vision(HIY"$N����ǰ�壬"+wp2->name()+HIY"ֱ��"+me->query("name")+"��"+me->query("name")+"������죬"+wp1->name()+HIY"һ�����ѣ��������˿�ȥ��\n"NOR, victim);
	}
}

