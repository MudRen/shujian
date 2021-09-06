// ��������
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : HIB"$Nһ�����е�$w"HIB"����ǰֱ��������һ�С�������·��ֱָ$n��$l"NOR,
	"skill_name" : "������·",
	"lvl" : 0,
	"damage_type" : "����"
]),
([
	"action" : HIM"$Nʹ���������ֻء���$w"HIM"����ҡ�ڲ�����ҡҡ�λεô���$n��$l"NOR,
	"skill_name" : "�����ֻ�",
	"lvl" : 30,
	"damage_type" : "����"
]),
([
	"action" : HIW"$Nһ�С�����Ϯ�塹��$nһ����$l�Ѿ���$N����"NOR,
	"skill_name" : "����Ϯ��",
	"lvl" : 50,
	"damage_type" : "����"
]),
([
	"action" : HIC"$NԾ�����࣬����$w"HIC"���˸����ߣ�бб���£����������졹������$n��$l"NOR,
	"skill_name" : "��������",
	"lvl" : 70,
	"damage_type" : "����"
]),
([
	"action" : HIG"$N�������֣�ͻȻ��$w"HIG"���ö��ϣ�һʽ������������Ѹ���ޱȵĹ���$n��$l"NOR,
	"skill_name" : "������",
	"lvl" : 90,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;
	if (!(weapon = me->query_temp("weapon")))
		return notify_fail("����ʱ�޷�������������\n");
	if ((string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԣ��޷�������������\n");
	if ((int)me->query("max_neili") < 60)
		return notify_fail("�������������\n");
	if ( me->query_skill("xuanyin-jian", 1) < 150 )
		return notify_fail("������������ȼ���������ϰ��\n");
	if ((int)me->query_skill("jiuyin-zhengong", 1) < 50)
		return notify_fail("��ľ����湦���̫ǳ��\n");
	if (me->query_skill_mapped("force") != "jiuyin-zhengong")
		return notify_fail("��ϰ�������������о���������ϡ�\n");
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
	int i, j, level;

	level   = (int) me->query_skill("xuanyin-jian",1);
	for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
                                "damage":       250 + random(180),
				"force":	300 + random(350),
				"dodge":	random(30),
				"parry":	random(30),
			]);
		}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60 || me->query("neili") < 30)
		return notify_fail("�����������������������\n");
	me->receive_damage("jingli", 50);
        me->add("neili", -25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xuanyin-jian/" + action;
}

int ob_hit(object ob, object me, int damage)
{
	object wp,wp1;
	string msg;
	int p,j,skill, neili, neili1, exp, exp1;
	wp = me->query_temp("weapon");
	wp1 = ob->query_temp("weapon");
	skill = me->query_skill("xuanyin-jian", 1);
	neili = me->query("neili");
	neili1 = ob->query("neili");
	exp = me->query("combat_exp");
	exp1 = ob->query("combat_exp");

	if( me->query("jiali") 
        && skill+100 > random(ob->query_skill("parry", 1)/3)
	&& wp 
	&& skill > 100
	&& me->query_skill_mapped("parry") == "xuanyin-jian"
	&& living(ob)
//        && !me->is_busy()){
   ){
		if(wp1){
			msg = HIW"$N����һ�⣬��������湦һ��\n"NOR;
			msg = replace_string(msg, "$w", wp1->name());
			if(neili >= random(neili1+damage)){
				if(random(me->query_str(1)) > ob->query_str(1)/3 && skill > 120){
					msg += HIW"$n����"+wp1->name()+HIW"��$Nһ����Щ���֣�\n"NOR;
					ob->add_busy(2+random(2));
					j = -(damage);
				}
				else{
					ob->receive_damage("qi", damage/10, me);
					ob->receive_wound("qi", damage/10, me);
					p = ob->query("qi")*100/ob->query("max_qi");
					msg += COMBAT_D->damage_msg(damage/20, "�˺�");
					msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
					j = -(damage/2+skill/2);
				}
			}
			else if(neili >= random(neili1)+damage){
				msg += "�����$n�Ĺ�������һ�衣\n";              
				j = -(damage/2+skill/2);
			}
			else{
				j = damage/2+random(damage/2);
				if(j<damage/2) msg += "�������������$n��������������ȥ��\n";
				else msg += "����Ծ���������$n��������������ȥ��\n";
				j = -j;
			}
			message_vision(msg, me, ob);
			return j;
		}
		else{
			msg = HIY"$N����һת����$n�й�ֱ����\n"NOR;
			if(neili >= neili1+random(neili1)+damage){
				ob->receive_damage("qi", damage/10, me);
				ob->receive_wound("qi", damage/10, me);
				p = ob->query("qi")*100/ob->query("max_qi");
				msg += COMBAT_D->damage_msg(damage, "����");
				msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
				j = -(damage*2+skill);
			}
			else if(neili >= random(neili1)+damage){
				msg += "�����$n�Ĺ�������һ�衣\n";              
				j = -(damage+skill);
			}
			else{
				j = damage/2+random(damage/2); 
				if(j<damage/2) msg += "�������������$nһЩ����ת�ƿ�ȥ��\n";
				else msg += "�������������$nһЩ����ת�ƿ�ȥ��\n";
				j = -j;
			}
			message_vision(msg, me, ob);
			return j;
		}
	}
}
