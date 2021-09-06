// liuyang-zhang.c ��ɽ������

// modified by action@SJ 2009/2/5
//modified by zhuifeng@SJFY 2010/0717

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : HIY"$Nһ�С�"+YEL+"�����۽�"+HIY+"�������Ƶ�������֮�ϣ�����$nС��Ҫ��֮��"NOR,
        "force" : 170,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "skill_name" : "�����۽�",
        "damage_type" : "����"
]),
([  "action" : HIY"$Nһ�С�"+RED+"�����ƶ���"+HIY+"���� ��ɫ���أ� ˫����ƮƮ������$n���"NOR,
        "force" : 200,
        "dodge" : 15,
        "parry" : 20,
        "lvl" : 10,
        "skill_name" : "�����ƶ���",
        "damage_type" : "����"
]),
([  "action" : HIY"$Nһ�С�"+MAG+"��б��·��ϼ��"+HIY+"����˫�ƻû�һƬ��Ӱ����$n��������"NOR,
        "force" : 240,
        "dodge" : 30,
        "parry" : 15,
        "lvl" : 20,
        "skill_name" : "��б��·��ϼ��",
        "damage_type" : "����"
]),
([  "action" : HIY"$Nһ�С�"+HIC+"��������"+HIY+"�������ٵ���$n��$l�������ƣ���ʽʮ������"NOR,
        "force" : 360,
        "dodge" : 10,
        "parry" : 30,
        "lvl" : 30,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([  "action" : HIY"$Nһ�С�"+WHT+"����һ���ͽ���"+HIY+"���� ֻ�������û�����ǧ��Ӱ����$n����"NOR,
        "force" : 350,
        "dodge" : 40,
        "parry" : 50,
        "lvl" : 40,
        "skill_name" : "����һ���ͽ���",
        "damage_type" : "����"
]),
([  "action" : HIY"$N˫��ƽ�ӣ�һ�С�"+HIW+"��ϼ������"+HIY+"������$n���ؿڣ�ֻ��$n��æ��ס�ؿ�"NOR,
        "force" : 400,
        "dodge" : 30,
        "parry" : 15,
        "lvl" : 50,
        "skill_name" : "��ϼ������",
        "damage_type" : "����"
]),
([  "action" : HIY"$Nһ�С�"+RED+"���ղγ���"+HIY+"����ֻ��һƬ��Ӱ����$nǰ�أ���ʱ$n��������"NOR,
        "force" : 420,
        "dodge" : -1,
        "parry" : 50,
        "lvl" : 60,
        "skill_name" : "���ղγ���",
        "damage_type" : "����"
]),
([  "action" : HIY"$N������Σ�����һ�С�"+RED+"��ϼ��Ѧ�"+HIY+"����Ȼ����$n��ͷ����������ϼ��"NOR,
        "force" : 260,
        "dodge" : 15,
        "parry" : 35,
        "lvl" : 70,
        "skill_name" : "��ϼ��Ѧ�",
        "damage_type" : "����"
]),
([  "action" : HIY"$Nʩ����"+HIC+"���������"+HIY+"���� ���ֺ�ɨ$n��$l�� ������Ȼ����$n���ؿ�"NOR,
        "force" : 280,
        "dodge" : 50,
        "parry" : 25,
        "lvl" : 80,
        "skill_name" : "���������",
        "damage_type" : "����"
]),
([  "action" : HIY"$Nʩ����"+YEL+"�������"+HIY+"����˫��ͬʱ����$n��$l�����Ǽ䣬$n��Ȼ͹������"NOR,
        "force" : 300,
        "dodge" : 5,
        "parry" : 25,
        "lvl" : 90,
        "skill_name" : "�������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) 
{
	object me;
	me = this_player(); 
	
           if(me->query("marry/id") || me->query("/quest/xiaoyao/pass")) 
		return combo=="zhemei-shou"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɽ�����Ʊ�����ơ�\n");
		
	if ((int)me->query_skill("strike", 1) < 30)		
		return notify_fail("��Ļ����ƹ���򲻹����޷�ѧϰ��\n");
		
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("���������Ϊ̫�����޷���ϰ��ɽ�����ơ�\n");
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
		string msg;
level = me->query_skill("liuyang-zhang",1);

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
						if ( me->query_temp("ruyi/wanshi")){
				return ([
					"action":MAG+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"MAG), NOR, MAG)+NOR,
					"damage": 60+random(120),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			if ( me->query_temp("ryd/xiaoyao")){
				return ([
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
					"damage": 100+random(100),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
if ( me->query_temp("lyz/jiutian")){
				return ([
					"action":HIB+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIB), NOR, HIB)+NOR,
					"damage": 90+random(50),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
if(me->query_temp("baihong")){
		switch(me->query_temp("baihong")){						
 case 5: msg = HIW"\n$N����ȫ��������������棬һ�С�"HIR"��������"NOR+HIW"��ȫ�����·����޴�Ĺ�â��ʹ$n���������¯֮��ʹ�����"NOR;break;
 case 4: msg = HIG"\n$N�����˾������澭�����������棬������ת�ھ����ߵ��ﻯΪ˪��ʹ����"HIB"��ʢ��˥"NOR+HIG"������ǿ��������Ȼ����"NOR;break;
 case 3: msg = HIC"\n$N����ӥ�������ʹ����"HIY"�������"NOR+HIC"���Թ����������$n���ķ������䲻��˫���˹���$n�����˻���ȥ"NOR;break;
 case 2: msg = HIM"\n$Nʹ����"HIW"������ѩ"NOR+HIM"����$N���η���ȫ��ɢ��������˪������ѩ��������裬$N�û���������͵Ϯʹ���ܴ�"NOR; break;
 case 1: msg = HIC"\n$N�۾�˫���˾����棬����ǿ�������ʹ����"HIR"�����ƻ�"NOR+HIC"���������ƾ�����$nȫ���������ᾢ�������������"NOR; break;
default: msg = HIY"\n$Nʹ��һ�С�"HIR"��������"NOR+HIY"������ǿ�������������಻��������Ϣ֮����������ɽ����֮�Ƴ�$n�����Ȼ��ȥ"NOR;break;
			
		}
		me->add_temp("baihong", -1);
		return ([
			"action":msg,
					"damage": 80+random(80),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(60),
					"force": 200+random(300),
				]);
			}
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
				"dodge" : random(25)-5,
				"parry": 50+random(60),
				"damage" : 80 + random(80),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
		}
	}
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("������������������ơ�\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
	        return __DIR__"liuyang-zhang/" + action;
}

mixed hit_ob(object me, object target, int damage_bonus)
{
	    int i,j;
	    i= me->query_skill("liuyang-zhang", 1);
	    j=1+random(1);
	    
      if(i>=200)
      {      
      if(userp(me)
      	&&random(me->query_dex(1))>target->query_dex(1)/2
        &&random(6)
      	&&!target->query_condition("shengsi_poison")
      	&&!me->query_temp("lyz/baihong")
       || (random(3)&&me->query_temp("xiaoyao_jianwu", 1))) 
      	 {
            message_vision(WHT"$N��ˮ������������У��p�h�h������$n�����Ѩ��\n"NOR,me,target);
            message_vision(BLU"$nҲ��΢΢һ���������ߴ�Ѩ����ͬʱ�����ѵ���ֱ��ǧǧ����ֻ����ͬʱ��ҧ��һ�㡣\n"NOR,me,target);
            target->add_condition("shengsi_poison",1);
          }
      }
     if (random(me->query_con(1))>target->query_con(1)/2
      	       &&random(3)
      	       &&!target->query_temp("absorb")
      	       &&!me->query_temp("lyz/baihong") || (random(3)&&me->query_temp("xiaoyao_jianwu", 1)))
      	   {
      	   	message_vision(HIB"$nһ��֮�£���������������ͻ�����������м�й������ȫ���������һ�㣬���ǻ̿��޼���\n"NOR,me,target);
      	   	target->add("neili",-j);
      	   	target->start_busy(1+random(2));
      	   	me->add("neili",j);
      	   	target->set_temp("absorb",8);
      	  }
if( me->query_temp("xiaoyao_jianwu")&& me->query_skill("liuyang-zhang",1)>=550 ){ 
             target->add_condition("shengsi_poison",1);
                   target->add_busy(1+random(2));
             target->apply_condition("no_fight",1);
             target->apply_condition("no_perform",1);
             target->apply_condition("no_exert",1);
}
   
}


