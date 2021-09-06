// songshan-jian.c  ��ɽ����
// Lklv@SJ modified 2001.10.22
// tangfeng@SJ 2004.12
// server ����set


#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include <combat_msg.h>

int strike_hit(object me, object victim, object weapon, int damage);

mapping *action = ({
([
	"action" : "$N�ٽ�������������������һʽ���������ڡ���$w��$n��$l�����ȥ��",
	"lvl" : 0,
	"damage_type" : "����"
]),
([
	"action" : "ͻȻ�佣��һ�£�$w����һ���׺磬$Nʹ��һʽ��ǧ�����������������ӣ�$wֱ��$n��$l",
	"lvl" : 15,
	"damage_type" : "����"
]),
([
	"action" : "$N��������һ�֣�����$w�����ӳ�һ�С����ż�ɽ��������ɭȻ����$n��$l��ȥ",
	"lvl" : 30,
	"damage_type" : "����"
]),
([
	"action" : "$Nһ���ӿ��м������£���ʽ����ƽƽ���棬������һ���죬ʵ��ʯ���쾪�����ƣ�һ�С�������ɽ��$w���ش���$n��$l",
	"lvl" : 45,
	"damage_type" : "����"
]),
([
	"action" : "$Nһ��$w�԰���к��������������ֱ����һ������һ�㣬һʽ���������������ڽ�ز�������ۻ��ն��$n��$l",
	"lvl" : 60,
	"damage_type" : "����"
]),
([
	"action" : "$N��������һʽ������ء���$w��Ȼһ��������ǧ�������۶�������������$n��$l",
	"lvl" : 75,
	"damage_type" : "����"
]),
([
	"action" : "$N��תһʽ�����両�ࡹ��ٲȻ��ǹ��ꪣ���ɳǧ�$w������������$n���������ؽ���֮��",
	"lvl" : 90,
	"damage_type" : "����"
]),
([
	"action" : "$N�������£�һ�С���Х���졹��$w��Ȼ��ת���ϣ�����Ľ�����$n����Ҫ������Χס",
	"lvl" : 120,
	"damage_type" : "����"
]),
});

 

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("hanbing-zhenqi", 1) < 20)
		return notify_fail("��ĺ����������̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	string msg;
	int focus = me->query_temp("ss/focus");
	level = me->query_skill("songshan-jian",1);
	
		
	if (me->query_temp("ssj_songyang")){
		switch(me->query_temp("ssj_songyang")){
			case 2: msg = CYN"$N�������ڱ���ʹһ�С�ǧ��Ԩ������ͻȻ��ȭΪ�ƣ�����ʮ�㣬���������϶�������$n"NOR; break;
			case 1: msg = CYN"������$N�ͺ�һ����һʽ����ʤ�塹������Ю���ſ�磬��ǰб�ƣ���������ɽ���ư�ѹ��$n"NOR; break;
			default: msg= CYN"$N�������ڱ���ʹһ�С�ǧ��Ԩ������ͻȻ��ȭΪ�ƣ�����ʮ�㣬���������϶�������$n"NOR; break;
		}
		me->add_temp("ssj_songyang", -1);
		return ([
			"action": msg,
			"dodge": random(30),
			"parry": random(30),
			//�����ڹ�Ч��
			//"damage": 130 + random(140),
			//ע��focus ���ֵ15�����Բ���yun juhan�趨
			"damage": 130 + random(140)+ random(focus*6),
			"force": 350+ random(300),
			"damage_type": "����"
		]);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
 
	if (me->query_temp("ssj/leiting"))
	{
		msg = YEL"\n$N�����ĵ�֮�£������䶼�����ѣ�ֱ�Ƿ�ͬС�ɣ�����һ��ȫ������$n�̳���"NOR;
		
		return ([
                         "action": HIB+replace_string(replace_string(action[j]["action"], "$w", "$w"), "$w", "$w"HIB)+NOR+msg,
			"dodge": random(30),
			"parry": random(30),
			//"damage": 130 + random(140) + focus*5,
			//����leiting �ڹ�Ч��
			"damage": 140 + random(140) + focus*6,
			"force": 350+ random(300),
			"damage_type": random(2)?"����":"����",
            "post_action": (: strike_hit :),
		]);
	}



                   //450����pfm longfei��������
                   if(level>=450 && me->query_temp("ss_lf"))
                   return ([
                           "action": HIB+replace_string(replace_string(action[j]["action"], "$w", "$w"), "$w", "$w"HIB)+NOR,
                           "lvl": action[j]["lvl"],
                           "damage_type": action[j]["damage_type"],
                           "force": 300 +random(250)+ random(focus*3),
                           "dodge": random(30),
                           "parry": random(20)+20,
                           "damage": 150 + random(150)+ focus*3,
                   ]);
                   //350����pfm longfei��������
                   if(level>=350 && me->query_temp("ss_lf"))
			return ([
                           "action": HIC+replace_string(replace_string(action[j]["action"], "$w", "$w"), "$w", "$w"HIC)+NOR,
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
                           "force": 250 +random(300),
				"dodge": random(30),
				"parry": random(20)+20,
				//�����ڹ�Ч��
				//"damage": 80 + random(140),
                           "damage": 120 + random(140)+ random(focus*3),
			]);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 200 +random(350),
				"dodge": random(30),
				//����һ��parry
				"parry": random(20)+20,
        "damage": 120 + random(140),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("songshan-jian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;
	if ((int)me->query("jingli") < 50)
		return notify_fail("���������������ɽ������\n");
	if ( me->query("neili") < 20 )
		return notify_fail("���������������ɽ������\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}



int strike_hit(object me, object victim, object weapon, int damage)
{
	int ap, dp, lvl,damage1,focus;

	focus = me->query_temp("ss/focus");
	lvl = (me->query_skill("songshan-jian", 1)+ me->query_skill("strike") )/2;
        if(!me->query_temp("ssj/leiting")) return 0;

	if(!victim
	|| !weapon
	|| me->query("neili") < 3000
	|| lvl < 200
	|| !present(victim, environment(me))
	|| !victim->is_character()
	|| !me->is_fighting(victim)
	|| !living(victim)
	|| me->query_skill_mapped("force") != "hanbing-zhenqi"
	|| me->query_skill_mapped("strike") != "hanbing-shenzhang"
	|| me->query_skill_prepared("strike") != "hanbing-shenzhang"
	|| me->query_skill_mapped("parry") != "songshan-jian")
		{
                 me->delete_temp("ssj/leiting");
                 return 0;
                   }
		me->add_temp("apply/damage", lvl);
		victim->set_temp("must_be_hit", 1);
		weapon->unequip();
 COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),3);   
		weapon->wield();
		me->add_temp("apply/damage", -lvl);

 damage1 = (me->query("neili")- victim->query("neili"))* me->query("max_qi")/me->query("eff_qi");
           if(damage1<0 ) damage1 = - damage1/(2* (random(focus)+1));
             else damage1=damage1*( random(focus)+1);
 
                          	victim->receive_damage("qi", damage1/3 , me);
				victim->receive_wound("qi", damage1/3 , me);
                                 me->add("neili",-1000); 
                                 me->add("jingli", -50);


		victim->delete_temp("must_be_hit");
	return 1;
}



mixed hit_ob(object me, object victim, int damage)
{
	object weapon, weapon1;
	int ap, dp, focus, damage1,lvl;

	string msg;

	focus = me->query_temp("ss/focus");
        lvl = me->query_skill("songshan-jian",1);       
	if (me->query_temp("ssj/leiting"))
	{
                damage1 = (me->query("neili")- victim->query("neili"))* me->query("max_qi")/me->query("eff_qi");
          if( wizardp(me)) 
                    tell_object(me, "�ο���ֵ"+damage1+"��\n"NOR);
     	    
        
          if(damage1<0 ) damage1 = - damage1/ (random(focus)+1);
                    else damage1 =   damage1*( random(focus)+1);
                          	victim->receive_damage("qi", damage1/3 , me);
				victim->receive_wound("qi", damage1/3 , me);
                                 me->add("neili",-1000); 
                                 me->add("jingli", -50);
            msg = HIR"���С�"HIW"Ǭ��һ��"HIR"��������$N���������������ޱȣ����޿ɵ���$nֻ��һ�ɴ���ײ������ʱ������Ѫ���������\n"NOR;
  		
	message_vision(msg, me, victim);
                me->delete_temp("ssj/leiting");
                me->set_temp("strike_hit",1);
	}
	
	if (me->query_temp("ss/hb") && !victim->is_busy())
	{
		victim->add_condition("cold_poison", random(focus)+ 1);
		if ( !random(4))
			victim->add("neili",-me->query_skill("force")/2);
		if (victim->query("neili") < 0) victim->set("neili",0);
		msg = HIW"$n��$N��һ�����ˣ�һ�����������ƺ�ȫ���ѪҺ��������һ�㣡\n"NOR;
	if( !me->query_temp("ssj/db_hit"))	message_vision(msg, me, victim);
	}

	if (random(me->query_skill("songshan-jian",1) < 150)) return 0;

	weapon=me->query_temp("weapon");
	weapon1=victim->query_temp("weapon");


        if( lvl >= 300 && !random(3)
         && random(me->query_con()) > victim->query_con()/3
         && random(me->query_skill("sword")) > victim->query_skill("parry")/3 || me->query_temp("ss/fw")  )
                         {
                if( me->query_skill_prepared("strike") == "hanbing-shenzhang"
                 && me->query_skill_mapped("strike") == "hanbing-shenzhang"
                 && me->query_skill_mapped("parry") == "songshan-jian"
                 && me->query_skill_mapped("force") == "hanbing-zhenqi"
                 && me->query_skill("hanbing-shenzhang", 1) >= 200 && random(2) && !me->query_temp("ssj/db_hit") ) {
                        message_vision(HIW"ͻȻ�亮��һ����$N����"+weapon->query("name")+ HIW"һ����$n���ֱ�������������ź���һ�������������
�������Ƶ�֮�������˵��Ƿ�����˼��ֻ�������һ����$n�������ܲ������Ʊر�ն���Ľأ�"NOR, me,victim);
                        me->set_temp("ssj/db_hit",1);
                        me->add_temp("apply/attack",  me->query_skill("songshan-jian", 1)/3);
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 3);
                        me->add_temp("apply/attack", -me->query_skill("songshan-jian", 1)/3);
                        me->delete_temp("ssj/db_hit");
                       }
                        }

	if(objectp(weapon) 
		&& objectp(weapon1)
		&& me->query("env/��ɽ����") == "��") {
		ap = me->query("combat_exp")/ 1000 * me->query("str");
		dp = victim->query("combat_exp")/ 1000 * victim->query("str");
		if( random(ap + dp) > dp && weapon1->query("imbued") < 3 && weapon->query("sharpness") > 0) {
			message_vision(CYN"$NǱ���ھ���ֻ������ৡ���һ�����죬$n���е�"+weapon1->name()+CYN"�Ѿ���"+weapon->name()+CYN"���ϣ�\n"NOR, me, victim );
			weapon1->broken("���ϵ�");
			return 0;
		}
		else if ( weapon->query("sharpness") > 0) {
			 ap = me->query("combat_exp")/ 1000 * (me->query_str(1)+ me->query("jiali")+ me->query_skill("parry")/3);
			 dp = victim->query("combat_exp")/ 1000* (victim->query_str(1)+ victim->query("jiali")+ victim->query_skill("parry")/3);
			if (random(ap+ dp) > dp) {
				message_vision(CYN "$N�ؽ����ã�$n����ס�����е�"+weapon1->name()+CYN"ֱ�����죡\n"NOR, me, victim );
				victim->add_busy(random(2)+1);
				weapon1->move(environment(victim));
				victim->reset_action();
			}
		}
	}
	return 0;
}

string perform_action_file(string action)
{
	return __DIR__"songshan-jian/" + action;
}
