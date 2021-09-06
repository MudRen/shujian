// lingshe-quanfa.c  ����ȭ��

inherit SKILL;

#include <ansi.h>

mapping *action = ({
([      "action" : "$Nһʽ��"+RED+"���߳���"+NOR+"����������Σ���������ͻȻ����$n�ı����Ѩ",
        "force" : 170,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "skill_name" :"���߳���",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�Σ�һʽ��"+YEL+"��ͷ��β"+NOR+"������������$n�ļ�ͷ����ȭ����$n���ؿ�",
        "force" : 230,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 10,
        "skill_name" :"��ͷ��β",
        "damage_type" : "����"
]),
([     "action" : "$Nһʽ��"+HIG+"��������"+NOR+"�������ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
        "force" : 300,
        "dodge" : 15,
        "parry" : 20,
        "lvl" : 20,
      "skill_name" :"��������",
        "damage_type" : "����",
]),
([      "action" : "$N�������У�����ֱ����һʽ��"+HIY+"������Ӱ"+NOR+"������Ʈ��������$n������",
        "force" : 280,
        "dodge" : 20,
        "parry" : 25,
        "lvl" : 30,
          "skill_name" :"������Ӱ",
        "damage_type" : "����"
]),
([     "action" : "$Nʹһʽ��"+HIB+"�������"+NOR+"������ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
        "force" : 290,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 40,
       "skill_name" :"�������",
        "damage_type" : "����"
]),
([       "action" : "$Nһʽ��"+GRN+"��������"+NOR+"����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
        "force" : 310,
        "dodge" : 5,
        "parry" : 3,
        "lvl" : 50,
       "skill_name" :"��������",
        "damage_type" : "����"
]),
([     "action" : "$N˫�ֱ�ȭ��һʽ��"+YEL+"������ӿ"+NOR+"������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
        "force" : 340,
        "dodge" : 10,
        "parry" : 3,
        "lvl" : 65,
         "skill_name" :"������ӿ",
        "damage_type" : "����"
]),
([    "action" : "$Nһʽ��"+WHT+"��������"+NOR+"����ȭ���������֣��������ޣ�����������$n�ĵ���",
        "force" : 400,
        "dodge" : 5,
        "parry" : 0,
        "lvl" : 80,
        "skill_name" :"��������",
        "damage_type" : "����"
]),
});
int valid_enable(string usage) { 
if( this_player()->query("oyf/hamagong",1 ) > 1 )
return usage == "cuff" || usage == "parry";}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ��������֡�\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("�������̫���ˣ�����������ȭ����\n");
	if ( me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦���̫ǳ������ѧ����ȭ����\n");
	if ( me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ������ѧ����ȭ����\n");
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
        int i,level,f_force,s;
        s = random(5);
        f_force=me->query_skill("force");
 
        if( (me->query_temp("lsqf/ls") || me->query_temp("lszf/bb")) && s > 3 ) {
          	
                return ([
                "action": CYN "$N�ֱ�������ը�������綾�߰����꣬����һ�ɾ޴�ı�����������һ��"+HIR+"���߳���"+NOR+"��"NOR,
                                        "force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
					"damage": 250 +random(140),
                "damage_type": "����"]);
        }
         
    else if( (me->query_temp("lsqf/ls") || me->query_temp("lszf/bb")) && s > 2 ) { 
                return ([
                "action": WHT "$N���ɨȥ��$n����۵�������$N�ֱۺ��䣬�ڵ�һȭ��������$n���֮�ϡ�"NOR,
                                        "force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
					"damage": 240 +random(140),
                "damage_type": "����"]);
        }

     else if( me->query_temp("lsqf/ls") || me->query_temp("lszf/bb")) {
                return ([
                 "action": WHT "$N�ֱ���Ȼ�鶯����,��ȭ�ķ�λ������˼������⧷���"NOR,
                                        "force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
					"damage": 230 +random(140),
                "damage_type": "����"]);
        }
        
       
        level   = (int) me->query_skill("lingshe-quanfa",1);
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�����������������ȭ����\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"lingshe-quanfa/" + action;
}


mixed hit_ob(object me, object victim)
{
  

        int lvl = me->query_skill("hand"),attack,lb;
        attack=lvl/100;
        if(attack>4) attack=4;
		attack=random(attack);
        	if(attack<=1) attack=1;
        lb = random(12);

   if( lb > 7 && !me->query_temp("lsqf/auto") )
          {
                message_vision(WHT "$N�����۽������ֿ������磬��ָһ������$n�ؿڣ�����һ��"+HIW+"��������"+WHT+"��\n$N�����ֺ��һȭ��" NOR,me,victim);
                victim->start_busy(random(4));
                         me->set_temp("lsqf/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("lingshe-quanfa", 1)/8);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("lingshe-quanfa", 1)/8);
                        me->delete_temp("lsqf/auto");
                        victim->apply_condition("no_perform", 2+ random(2));

         }
     
   else if( lb > 6 && !me->query_temp("lsqf/auto") )
 {
        	message_vision(MAG "$N������ϣ����������������һ�ܣ�$n��$N���������Ի������㱣���ʱ�ְ���һ�¡�" NOR, me,victim);
        	victim->start_busy(random(2));
                   me->set_temp("lsqf/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("lingshe-quanfa", 1)/9);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("lingshe-quanfa", 1)/9);
                        me->delete_temp("lsqf/auto");

        }

   else if( lb > 5 && !me->query_temp("lsqf/auto") )
{
        	message_vision(HIY "�����ţ�$N���з�����˻˻����������˫�ְ�������ָ��������״�����缱�籩��㹥����"+
			   chinese_number(attack+1)+"�С�" NOR,me, victim);
                    	victim->start_busy(random(attack+1)+1 );
                      me->set_temp("lsqf/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("lingshe-quanfa", 1)/9);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("lingshe-quanfa", 1)/9);
                        me->delete_temp("lsqf/auto");
 
}
}
