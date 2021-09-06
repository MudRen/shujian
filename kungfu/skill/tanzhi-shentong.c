// Modified by Darken@SJ
//update by master@zitan
#include <ansi.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
string *xue_name1 = ({ 
        "��׶Ѩ",
        "�ٻ�Ѩ",
        "־��Ѩ",
        "�羮Ѩ",
        "�͹�Ѩ",
        "�ڹ�Ѩ",
        "���Ѩ",
        "����Ѩ",
});
string *xue_name2 = ({
        "����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�׺�Ѩ",
        "��̨Ѩ",
        "�縮Ѩ",
        "���Ѩ",
        "����Ѩ",
}); 
string *xue_name3 = ({
        "����Ѩ",
        "����Ѩ",
        "˿����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "��׵Ѩ",
        "����Ѩ",
        "����Ѩ",
}); 

mapping *action_finger = ({
([      "action" : "$N��ָ΢����ͻȻ������һʽ��ָ�㽭ɽ����һ�ƾ���ֱϮ$n��$l",
        "force" : 200,
        "dodge" : 5,
        "parry" : -5,
        "lvl" : 0,
        "skill_name" : "ָ�㽭ɽ",
        "damage_type" : "����"
]),
([      "action" : "$N��������ǰһ��������ͻȻ��������ָ΢������������ָ����ֱϮ$n��$l",
        "force" : 300,
        "dodge" : 0,
        "parry" : 10,
        "lvl" : 60,
        "skill_name" : "������ָ",
        "damage_type" : "����"
]),
([      "action" : "$N�ұۻӶ�����ָ����������ǰ����һ�����ߣ����ǡ�һ�´�ˮ��������$n��ǰ��",
        "force" : 400,
        "dodge" : 8,
        "parry" : -8,
        "lvl" : 120,
        "skill_name" : "һ�´�ˮ",
        "damage_type" : "����"
]),
([      "action" : "$NԾ���ڰ�գ�˫�ּ��ӣ���ָ����������ָ���ס�����ǵذ���$nӿȥ",
        "force" : 450,
        "dodge" : -3,
        "parry" : -10,
        "lvl" : 180,
        "skill_name" : "��ָ����",
        "damage_type" : "����"
]),
});

mapping *action_throwing = ({
([      "action" : "$N��ָ΢����ͻȻ������һʽ��ָ�㽭ɽ����$w�ƿ�֮��������ֱϮ$n��$l",
        "force" : 130,
        "dodge" : -5,
        "parry" : -10,
        "damage" : 60,
        "lvl" : 0,
        "skill_name" : "ָ�㽭ɽ",
        "damage_type" : "����",
        "post_action": (:call_other, WEAPON_D, "throw_weapon":)
]),
([      "action" : "$N��������ǰһ��������ͻȻ��������ָ΢������������ָ����$w��Х��ֱϮ$n��$l",
        "force" : 170,
        "dodge" : 5,
        "parry" : -15,
        "damage" : 80,
        "lvl" : 60,
        "skill_name" : "������ָ",
        "damage_type" : "����",
        "post_action": (:call_other, WEAPON_D, "throw_weapon":)
]),
([      "action" : "$N�ұۻӶ�����ָ����������$w����ǰ����һ�����ߣ����ǡ�һ�´�ˮ��������$n��ǰ��",
        "force" : 240,
        "dodge" : -5,
        "parry" : -6,
        "damage" : 110,
        "lvl" : 120,
        "skill_name" : "һ�´�ˮ",
        "damage_type" : "����",
        "post_action": (:call_other, WEAPON_D, "throw_weapon":)
]),
([      "action" : "$NԾ���ڰ�գ�˫�ּ��ӣ���ָ����������ָ���ס���������ǵص�$w����$nӿȥ",
        "force" : 320,
        "dodge" : 0,
        "parry" : -10,
        "damage" : 150,
        "lvl" : 180,
        "skill_name" : "��ָ����",
        "damage_type" : "����",
        "post_action": (:call_other, WEAPON_D, "throw_weapon":)
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="throwing" || usage=="parry"; }

int valid_learn(object me)
{
        object weapon;
        if (weapon = me->query_temp("weapon"))
        if ((string)weapon->query("skill_type") != "throwing")
                return notify_fail("ѧ��ָ��ͨ������ֻ��ְֳ�����\n");
        if ((int)me->query_skill("bihai-chaosheng", 1) < 100)
                return notify_fail("��ı̺���������򲻹����޷�ѧ��ָ��ͨ��\n");
        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������̫�����޷�����ָ��ͨ��\n");
        return 1;
}


string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action_finger)-1; i >= 0; i--)
                if(level >= action_finger[i]["lvl"])
                        return action_finger[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("finger");

        if (random(level) > 250 || random(me->query_temp("thd/is_fast")) > 350) {
                me->add("neili", -20);
                if (!weapon)
                        return ([
                                "action": HBRED "$Nһ���Ϻȣ����ο�ʼ���ٻζ�������$n���ߡ�$nһ��㵼䣬ֻ�������͡�֮�����죬���������������˷�Ϯ��$n��" NOR,
                                "force": 500,
                                "dodge" : 10,
                                "parry" : 10,
                                "damage_type": "����"
                        ]);
                else    return ([
                                "action": HIR "$Nһ���Ϻȣ����ο�ʼ���ٻζ�������$n���ߡ�$nһ��㵼䣬ֻ�������͡�֮�����죬����" + weapon->query("unit") + weapon->query("name") + "������˷�Ϯ��$n��" NOR,
                                "damage": 200,
                                "force": 380,
                                "dodge" : 8,
                                "parry" : 4,
                                "damage_type": "����"
                        ]);
        }
        if (!weapon) {
                for(i = sizeof(action_finger); i > 0; i--)
                        if(level >= action_finger[i-1]["lvl"])
                                return action_finger[NewRandom(i, 20, level/5)];
        }
        else
                for(i = sizeof(action_throwing); i > 0; i--)
                        if(level > action_throwing[i-1]["lvl"])
                                return action_throwing[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        int lvl = me->query_skill("tanzhi-shentong", 1);
        int i = sizeof(action_finger);
        mapping learned = me->query_learned();

        if (!mapp(learned)) learned = ([]);
        if (!learned["tanzhi-shentong"])
         while (i--) 
           if (lvl == action_finger[i]["lvl"])
              return notify_fail("�㽫�Ѿ�ѧ���������ʽ��ϰ��һ�飬���������ȥ��ʦ��ѧ�µ���ʽ���޷���ý����ˡ�\n");;
        if (weapon = me->query_temp("weapon"))
        if ((string)weapon->query("skill_type") != "throwing")
              return notify_fail("����ָ��ͨ������ֻ��ְֳ�����\n");
        if ((int)me->query("jingli") < 50)
              return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
              return notify_fail("���������������ָ��ͨ��\n");
        me->receive_damage("jingli", 45);
        me->add("neili", -20);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tanzhi-shentong/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl = me->query_skill("finger");
        string name1,name2, name3;
        
        if ((random(lvl) > 100 && random(me->query_dex()) > victim->query_dex()/2 ||
             random(me->query_temp("thd/is_fast")) > 200) && !victim->is_busy()) {
                name1 = xue_name1[random(sizeof(xue_name1))];
                name2 = xue_name2[random(sizeof(xue_name2))];
                name3 = xue_name3[random(sizeof(xue_name3))];
                message_vision(HIR "$n��$N�����ˡ�"HIC + name1 + HIR"������Ϣ���ң�\n" NOR,me,victim);
                victim->start_busy(random(2)+2);
                if (random(lvl) > 250) {
                        message_vision(HIY "$N��ָ΢�����ֵ�����$n�ġ�"HIC + name2 + HIY"����\n" NOR,me,victim);
                        message_vision(HIY "$nֻ����ͷ΢΢��ѣ�������ܼ��У�\n" NOR,me,victim);
                        victim->add("jing",- lvl); 
                        victim->add("jingli",- lvl); 
                }
                if (random(lvl) > 300) {
                        message_vision(HIG "$N�����ٵ���$n�ġ�"HIC + name3 + HIG"����\n" NOR,me,victim);
                        message_vision(HIG "$n����һ���ʹ�������޷����ۣ�\n" NOR,me,victim);
                        victim->add("neili",- lvl*2); 
                }
        }
}

int ob_hit(object ob, object me, int damage)
{

	object weapon;
	string msg;
      int ap,dp,skill,j;

     if(!userp(me)) return 0;
           if(me->query("family/master_name")!="��ҩʦ") return 0;
      ap = ob->query_skill("parry",1)+ ob->query_skill("dodge",1);
      dp = me->query_skill("parry", 1)+ me->query_skill("tanzhi-shentong",1);
      if( random(me->query("str"))< ob->query("str")/3 ) return 0;
	if(objectp(weapon = ob->query_temp("weapon")) ) msg = weapon->query("skill_type");
     
        if (me->query_skill("tanzhi-shentong", 1) < 250
	|| me->query_skill_mapped("finger") != "tanzhi-shentong"
	|| me->query("combat_exp") < ob->query("combat_exp")/3) return 0;

        if ( me->query("neili") < ob->query("neili") * 2/3 ) return 0;
        	
	if ( me->is_busy() ) dp *= 2;
	if ( me->query("neili") > ob->query("neili") * 2 ) dp *= 2;
	else if ( me->query("neili") > ob->query("neili") / 2 * 3 ) dp += dp/2;

	if ( skill > 550 ) dp += random(dp*2);
	if ( skill > 450 ) dp += random(dp/2*3);
	else if ( skill > 350 ) dp += random(dp);

        if ( random(dp) > ap || ( me->query("jiali") >100  && random( dp ) > ap/2 ) )
	 {
		if( me->query("neili") > ob->query("neili")* 3/2 &&  me->query("jiali") > 100  ) {
		if( weapon ){
            msg = HIG"$NͻȻ��ָ����"+weapon->name()+HIG"��һ����ֻ��$n���ڱ���,ȫ������,Ҳ�ѳֲ�ס,ֻ�ö�����"+weapon->name()+"��\n"NOR;
			                        weapon->unequip();
		     	                     weapon->move(environment(ob));
		     	                  }
	
                        else msg = HIR"$N����ܹ�,��������ָ����,ָ��Ϭ���罣! �͵ĵ�����$n���ϣ�\n"NOR;
    		      ob->receive_damage("qi", damage/2 + me->query("jiali")*2, me);
		      ob->receive_wound("qi", me->query("jiali")+1, me);
     			j = -damage;

		}


		else {
                        if( weapon ) msg = HIC"$N��׼����,��������,������$n��"+weapon->name()+HIC"������һ����\n"NOR;
                        else msg = HIC"$N����һ������ָ�ᵯ��������ס$n�Ľ�����\n"NOR;
			j = -damage;
		}

	}

	else if ( random( dp ) > ap /2 ) {
                if( weapon ) msg = HIR"$N����һת����$n�ݽ����"+weapon->name()+HIR"������һ��,ֱ���$n���ڱ���,�ֱ۷��飡\n"NOR;
		else {
                  msg = HIM"$N��������,��ָ����,�͵Ĵ�����$n���ϣ�\n"NOR;

		}
                                        COMBAT_D->report_status(ob, random(2));
		                        message_vision(msg, me, ob);
		return -damage;
	}


	else if( random( dp * 3 ) > ap  ) {
     if( weapon ) msg = HIW"$N�鼱֮�£���ָ��$n�ݽ����"+weapon->name()+HIW"����һ����ж����$pһ���־�����\n"NOR;
                else msg = HIW"$N��ָ����,$n�Ĺ����ܴ�,�����Լ���\n"NOR;
		j = -damage/2;
	}
	else if( random( dp * 4 ) > ap ) {
if( weapon ) msg = MAG"$N�������ǣ���"+weapon->name()+MAG"�͵�һ��,�����˲��־�����\n"NOR;
		else msg = HIY"$N��æ����ָ��������Ҫ��ס$n�Ľ�����\n"NOR;
		j = -damage/4;
	}

	else return 0;

	message_vision(msg, me, ob);

	return j;

}

