// dagou-bang.c �򹷰���
// Code By Looklove@SJ 2001/4/1
// Modify By Looklove 2001.4.7
// Modify By Looklove 2001.4.8
// Looklove modified at 2001.5.5
// Looklove modified at 2001.5.15
// Looklove modified at 2001.5.18
//update by jpei 2010 �������������԰�����������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
        "action": "$Nһ������������$w��ʹ��һʽ����ݾ��ߡ�����ɨ��$n��$l",
        "force": 80,
        "lvl" : 0,
        "skill_name": "��ݾ���",
        "damage_type": "����"
]),
([
        "action": "$N������Ծ������$w���һζ���һ�С�����Ѱ�ߡ���$n��$l��ȥ",
        "force": 100,
        "lvl":10,
        "skill_name": "����Ѱ��",
        "damage_type": "����"
]),
([
        "action": "$N����$wһȦ��ʹ��һ�С����Ŵ򹷡���$n����˷�Χ���ܲ�͸��",
        "force": 140,
        "lvl" : 20,
        "skill_name": "���Ŵ�",
        "damage_type": "����"
]),

([
        "action": "$N��̤��λ��ʩ�����������졹�����ֽ�$w����������$n��ȥ",
        "force": 160,
        "lvl" : 30,
        "skill_name": "��������",
        "damage_type": "����"
]),
([
        "action": "$N���һ����������ǽ��������һ������$w��ͷ����$n��$l",
        "force": 180,
        "lvl" : 50,
        "skill_name": "������ǽ",
        "damage_type": "����"
]),
([
        "action": "$Nʹ��һ�С�����˫Ȯ��������$w���������������$n��$l",
        "force": 200,
        "lvl" : 80,
        "skill_name": "����˫Ȯ",
        "damage_type": "����"
]),
([
        "action": "$N����һ����һ�С���Ȯ��·����������$w��$n��ȥ�Ʒ��˹�ȥ",
        "force": 220,
        "lvl" : 100,
        "skill_name": "��Ȯ��·",
        "damage_type": "����"
]),
([
        "action": "$Nһ�С�����ͷ����ֻ��$wͻȻ����ֱ��$n�Ķ���",
        "force": 240,
        "lvl" : 120,
        "skill_name": "����ͷ",
        "damage_type": "����"
]),
([
        "action": "ֻ��$Nʹ��һ�С�б�򹷱���������š����$wб����$n��$l",
        "force": 260,
        "lvl" : 140,
        "skill_name": "б�򹷱�",
        "damage_type": "����"
]),
([
        "action": "$N���һ����ʹ��һ�С����ع��Ρ������ֽ�$w����$n��$l",
        "force": 270,
        "lvl" : 160,
        "skill_name": "���ع���",
        "damage_type": "����"
]),
([
        "action": "$Nһ�С����붴������$w���˸���������ɨ$n��$l",
        "force": 280,
        "lvl" : 180,
        "skill_name": "���붴",
        "damage_type": "����"
]),
([
        "action": "$N�����������$wһ�ϣ�ʹһ�С�ѹ�繷��������ͷ��������$n��$l",
        "force": 300,
        "lvl" : 200,
        "skill_name": "ѹ�繷��",
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return (usage == "stick") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((string)me->query("family/master_name")!="���߹�")
                return notify_fail("�򹷰�ֻ�ܴӺ��߹���ѧ����\n");

        if ((int)me->query_skill("stick", 1) < 20)
                return notify_fail("��Ļ�������̫��, ����᲻�˴򹷰�����\n");

        if (me->query("gender") == "����")
                return notify_fail("��һ�����в�Ů֮�������ѧ�򹷰���\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);
        while (i--)
                if(level > action[i]["lvl"])
                return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, j, level, glvl, d, p;
        string msg;

        d = (int)me->query_dex() * (random(4)+1);
        p = (int)me->query_int() * (random(2)+2);
	level = me->query_skill("dagou-bang", 1);
	weapon = me->query_temp("weapon");

	if (me->query("gender")=="Ů��") glvl = level/5;
	else glvl = level/6;
	if (glvl > 100) glvl = 100;

        if( me->query_temp("shuangjue/dgb")){
                switch((int)me->query_temp("shuangjue/dgb")){
                        case 2: msg = HIG"$N��ȻбŲһ�����������һ��������$w"HIG"��ɨ��$n��$l"NOR; break;
                        case 1: msg =  HIW"$N����ͻ�䣬��ȻԾ��ֻ��$w"HIW"����һ�Ű�Ӱֱ��$n��$l��ȥ"NOR;break;
                        default: msg = HIW"$N���������Ȼһ����Х�����������Ӱ����$n��$l"NOR; break;
                }
                me->add_temp("shuangjue/dgb", -1);
                return ([
                "action": msg,
                "dodge": glvl,
                "parry": p+d,
                "damage": glvl + p/2,
                "force": level+glvl+p,
                "damage_type": "����"
                ]);
        }

        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"]) {
                        j = NewRandom(i, 20, level/5);
                        break;
                }
        if (level > 400 && userp(me))
                return ([
                        "action" : action[j]["action"],
                        "dodge":(d+p)/2,
                        "parry": glvl/2+(p+d)/2,
                        "damage": glvl/4+(p+d)/2,
                        "force" : action[j]["force"]+glvl/2+p+d,
                        "lvl" : action[j]["lvl"],
                        "damage_type" : action[j]["damage_type"],
                        ]);

        return ([
                "action" : action[j]["action"],
                "dodge":me->query("gender")=="Ů��"?level/10+d:level/15+d/2,
                "parry": glvl/2+p/2,
                "damage": glvl/4+p/2,
                "force" : action[j]["force"]+glvl/2+p+d,
                "force" : me->query("gender")=="Ů��"?action[j]["force"]:action[j]["force"]*3/2,
                "lvl" : action[j]["lvl"],
                "damage_type" : action[j]["damage_type"],
        ]);
}

int practice_skill(object me)
{
        object weapon;
        int lvl = me->query_skill("dagou-bang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        if (!objectp(weapon = me->query_temp("weapon"))
         ||(string)weapon->query("skill_type") != "stick")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( me->query("gender") == "����")
                return notify_fail("��һ�����в�Ů֮����������򹷰���\n");

        if ((int)me->query("jingli") < 40)
                return notify_fail("��ľ����������򹷰�����\n");

        if ((int)me->query("neili") < 30)
                return notify_fail("��������������򹷰���\n");

        me->receive_damage("jingli",40);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dagou-bang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int b, x, p, level, damage, quest;
	object weapon, tweapon;
	string msg;

	quest = (int)me->query("dgb/wugou");
	b = me->query_skill("bangjue", 1) + me->query("death_times",1) ;
	level = me->query_skill("dagou-bang", 1);
	weapon = me->query_temp("weapon");
	tweapon = victim->query_temp("weapon");

	if ((string)me->query_skill_mapped("parry") != "dagou-bang") return 0;
	if (!me->is_fighting(victim) || !weapon || !userp(me)) return 0;
	if ( !living(me) || !living(victim)) return 0;
	if ( damage_bonus < 100 ) return 0;
	if ( damage_bonus > 300 ) damage_bonus = 300;

	if ( random(quest+6) > 6
	 && quest > 0
	 && !me->query_temp("shuangjue")
	 && !me->query_temp("dgb/wugou")
	 && !me->query_temp("dgb/hit2")
	 && !me->query_temp("dgb/wugoua")
	 && (int)me->query("neili") >= 500
	 && random(b+quest*10) >=120 ){
		x = random(1+quest);
		me->set_temp("dgb/wugoua",1);
		if( x > 5 ) x = 5;
		switch(x) {
                        case 5: msg = HIR"$N�������޹�������䣬����ǵذ������ֻ��"+ weapon->name() +HIR"���в���$n������\n"NOR; break;
			case 4: msg = HIB"ֻ�������Ӱһͣ��$N���������޹������ı�ʹ��������"+ weapon->name() +HIB"һ��һ�ߣ�"+ weapon->name() +HIB"ͻȻ����$n��С��"NOR; break;
			case 3: msg = HIG"$Nʹ���������޹��������䣬��"+ weapon->name() +HIG"��Բ�ˣ�ͻȻֱͱ$n���۾�"NOR; break;
			case 2: msg = HIW"$N���������ʹ���������޹����ڶ��䣬����"+ weapon->name() +HIW"��ɨ��$n�Ľ���"NOR; break;
                        case 1: msg =  HIC"��Ȼ$N��������������"+ weapon->name() +HIC"б����ʹ���������޹�����һ�䣬����$n�ļ�ͷ"NOR;break;
                        case 0: msg = HIC"$N����ƫ�壬��"+ weapon->name() +HIC"��������Ӱ����Ȼʹ���ǡ������޹���"NOR; break;
                        default: msg = HIC"$N����ƫ�壬��"+ weapon->name() +HIC"��������Ӱ����Ȼʹ���ǡ������޹���"NOR; break;
		}
		damage = damage_bonus/10 + random(damage_bonus)/5*level/20+x*10;
		victim->receive_damage("qi",damage/10+x*50+level/10,me);
		victim->receive_wound("qi", damage/10+x*50+level/5,me);
		p = (int)victim->query("qi")*100/(int)victim->query("max_qi");
		msg += COMBAT_D->damage_msg(damage, "����");
		msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		me->add("neili", -(x*10+40));
		me->delete_temp("dgb/wugoua");
		message_vision(msg, me, victim);
	}
	else
	if ( random(b) >= 100
	 && victim->query("neili")
	 && !me->query_temp("shuangjue")
	 && !me->query_temp("dgb/wugoua")
	 && !me->query_temp("dgb/hit2")
	 && random(level) > 100
	 && random((int)me->query("neili")) > 400
	 && (int)me->query("max_neili") >= 1200
	 && random(20) > 17 ){
		victim->add_busy(1);
		me->set_temp("dgb/hit2",1);
		damage = damage_bonus/10 + random(damage_bonus)/10*level/40;
		if (!random(2)) {
			msg = HIM"������$N�����е�����������ǽ��δ� �����������β��������֮��$n���̽����������С�\n"NOR;
			msg += "$n�������ã����������мܣ���ǰ��Ծ���ܣ���֪$N�ĵ�����಻�ϣ�$nһ��������������!\n";
			victim->receive_damage("qi",damage/6,me);
			victim->recieve_wound("qi",damage/6,me);
			p = (int)victim->query("qi")*100/(int)victim->query("max_qi");
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
			message_vision(msg, me, victim);
		}
		else {
			msg = HIG"$N����������������ӵ�ʩ���� �����˫ȮĪ��ͷ����, ��֮��Ӱ���Ӷ��£�$n�����������м��¡�\n"NOR;
			victim->receive_damage("qi",damage/10,me);
			victim->receive_wound("qi", damage/10,me);
                        p = (int)victim->query("qi")*100/(int)victim->query("max_qi");
                        msg += COMBAT_D->damage_msg(damage, "����");
                        msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
			message_vision(msg, me, victim);
                }
		me->add("neili", -100);
		me->delete_temp("dgb/hit2");
	}
	return 1;
}

int ob_hit(object ob, object me, int damage)
{
	object wp,twp;
	string msg;
	int j, p, bj, level;

	wp = me->query_temp("weapon");
	twp = ob->query_temp("weapon");
	level = (int)me->query_skill("dagou-bang",1);
	bj = me->query_skill("bangjue",1) + me->query("death_times",1);

	if( living(me)
	 && userp(me)
	 && living(ob)
	 && !ob->query("env/invisibility")
	 && wp
	 && (string)me->query_skill_mapped("parry") == "dagou-bang"
	 && (string)wp->query("skill_type") == "stick"
	 && random(level) > 100
	 && random(bj) > 100
	 && (int)me->query("neili") > 500
	 && random(level)+level/2 > (int)ob->query_skill("parry")/2
	 && random(20) > 7) {
		me->add("neili", -50);
		if(twp) {
			msg = HIM"$n"+ twp->name() +HIM"һ�и���������$Nʹ�����⡱�־�����ӰƮƮ����ʱ���Լ�\n"NOR;
			msg += HIM"��ǰ����֮�ؾ�����ס�ˡ�$n����֮�£�ֻ�к���һ�������۱仯��\n"NOR;
			if(!ob->is_busy()){
				ob->start_busy(2);
				me->add("neili",-70);
			}
			else
				ob->add_busy(1);
			me->add("neili",-40);
			j = -damage;
		}
		else {
			msg = HIM"$n����ָ��Ҫ����$N����ͻȻֻ����Ӱ������"NOR;
			msg += HIM""+wp->name() +HIM "һ�ơ��⡱�־������������޷���\n"NOR;
			msg += HIM"�����ѱ����ص�����һ�¡�$n��æ������������ɫб�������Ͼ�����һ���亹��\n"NOR;
			if(!ob->is_busy()){
				ob->start_busy(2);
				me->add("neili",-50);
			}
			else
				ob->add_busy(1);
			ob->receive_damage("qi", damage/5 > 0?damage/5:10, me);
			ob->receive_wound("qi", damage/10 > 0?damage/10:2, me);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
			me->add("neili",-100);
			j = damage;
		}
		message_vision(msg, me, ob);
		return j;
	}
}

int help(object me)
{
        write(HIG"\n�򹷰���"NOR"\n");
        write(@HELP
        �򹷰����а����������������������⡢ת�˾������������µ�
        ؤ�������������ᡢ�顢�桢����ƣ��轫�������Ĵ�ֻ����Ӱ
        ������Ӱ����ѧ�����Ե�����������ǧ����˴򹷰����ľ�����
        ���������֡���ϰʱ�粻ͬʱѧϰ�������ս��޷���ɡ�

HELP
        );
        return 1;
}

