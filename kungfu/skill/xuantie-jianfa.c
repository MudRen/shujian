// ��������
// Modify By River 99.05
// Modified by darken@SJ

#include <ansi.h>;

inherit SKILL;

string  *msg = ({
"$N����ƽƽ�̳�һ�������ƺ��ޱ仯��ȴ�к��֮����$nֻ��һ�ɴ�����$w����ֱ������",
"$N���Ծ������$w�𣬽�������֮����������һ������$n�������ڽ���֮��",
"$N��̾һ�������ֺ���һ��������ָ��$n������ƽ�����̺����б仯������ʤ����",
"$NѸ������һ�����˽�֮�죬������˼��$n����֮��һȾ����Ȼ�޷��ֱ潣·��ȥ",
"$N��$w˳�̣�������������������޲��ǽ��������ţ����淵�ӹ��棬�Ѳ����κ�����",
"$N���׳�Х������Ʊ�ã�����$w����������$n���������$n���������κ���֮��", 
"$N��������$w��������ɽ������ͺ�һ�����������ǽ�Ӱ������ǧ����������$n����ζ�",
"$N����ʮ�ལ��һʱѸ�������ǻ��գ�һʱ���سٻ��������޼���Ѱ��ƽ�������ַ�˼����", 
"$N����$w������磬�޿ɵ��棬$n�����и����������纣��һ�㣬һ��һ������ӿ�������Ӳ���",
"$N����$w��ǰ����������������������֪���ƽ��ϣ�����ȴ�纣��һ����ӿ����$nϮȥ",
"$NԶԶ�ӳ�һ����$n�����������֮ǿ������һ�裬һ�ɴ�����ͷ����",
"$N����һ����������$wЮ��������ƽƽ�����Ļ���$n������Խ��Խ�죬����ͬ����֮��һ��",
"$Nһ����$w��Ȼ����������һ�㰵��ɫ��â������ŭ��һ�ߣ���$n��ȥ",
});
//���ӹ�Ĺ��Ծ ����ע�� ����û��˿������
//by tangfeng
string  *special_msg = ({
"$N���һ������������Χ��������������Ľ������ۼ�$n�������±��⽣������",
"$N���ֶ��ӣ���������ƻ��޼���Ѱ����������ȴʤ�����У�$n����Ī��",
"$N������㽣�⣬���紺��ϸ����ͣ�ȴ���಻�������޾�����$n�޴��м�",
"$N��Ȼ�������г���������ǰ����һ��Ȧ����̫����$n���к������ݴ�����֮�У��������",
"$N��������������ӽ���$nĪ������֮ʱȴ�е������ƺ���һ�㣬һ�˽���һ��һ�˸߹�һ��",
"$N�����ݺᣬ����������������������������࣬��Ȼ�������ң��������ƿգ�����$n��ȥ",
"$NĿ�⳺���ˮ�������Ŀ���$n,���г������������$nȴ�������ڴ󺣰㰵����ӿ���Կ���",
"$N����һ����������$wЮ��������ƽƽ�����Ļ���$n������Խ��Խ�죬����ͬ����֮��һ��",
});

string  *super_msg = ({
"$N���ֻӳ�һ����ȥ�Ƽ���ȴ�������š�¡¡���ķ���֮�����Ѿ��ﵽ���������ܵ����߾���",
"$N����$w�����֣��������ָ��$n??p������������ӭ�������ԭ��$N�����޽�ʤ�н��ľ���",
"$Ņ��һ��������ɺ�����ȴ��˿����Ϣ���ž��Լ����ѿ�����֮��",
"$Nһ���̵������𵭵�������������Ϣ������ȴ�Ǽ�ǿ",
"$Nÿ��һ��������Χ������Ӧ�ϣ���ʽ�������������������֮������֮����",
"$N���о��ް�㲨�����������˽�������ÿ��һ������ӿ��һ������������Ҫȥ��û����",
"$NͻȻ֮������ȫ�ޣ�ֻ�Ǽ�ƽ����һ�̣�ȴ�Ѿ����ڽ�ǰ����ʽԽ��ƽƽ����ȴ��Խ��",
"$N������磬��������ʽ������Ͷ��֮���ھ���񣬽�����Ȼ��豹����������ʤ",
});

string *parry_msg = ({
"$p�������ܣ�����$w��$P�ؿ�ֱ�̣�$N�ۼ������������֣�ȴ���ò��ܿ�$w�ķ�â��\n",
"$p��׼$P���ƣ�һ��������ǰ��$Pֻ�ñ��к��ˡ�\n",
"$p���ལ������һ����$P����ʽ��δ�����㾡���𿪡�\n",
"$p����һ�㣬������ʽ��ֻ�Ǿ���ǿ����$Pֻ������ת�أ������Ա���\n",
"$p�ϵл��ȣ�$P�������ƣ�ûһ���ܹ�ʹȫ����ͬС��ϰ�䣬��æ����һ�㡣\n",
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
	int level = me->query_skill("xuantie-jianfa", 1);
	string action_msg;
   int action_damage, action_dodge, action_force, action_parry;
	if(me->query_temp("xtjf_pfm")){
                   if(level<350)
                   return ([
                           "action": CYN+replace_string(replace_string(special_msg[random(sizeof(special_msg))], "$w", "$w"), "$w", "$w"CYN)+NOR,
                                   "damage": 200 + random(140),
                                   "dodge": random(30),
                                   "force": 250 + random(350),
                                   "parry": random(30),
                                   "damage_type": random(2)?"����":"����",
                   ]);
		if(level<450)
	   return ([
                           "action": HIC+replace_string(replace_string(special_msg[random(sizeof(special_msg))], "$w", "$w"), "$w", "$w"HIC)+NOR,
                                   "damage": 250 + random(150),
                                   "dodge": 10+random(30),
					"force": 250 + random(350),
                                   "parry": 10+random(30),
					"damage_type": random(2)?"����":"����",
			]);
		//һ����޸ģ�ע��damage��force����ֵ
		//by tangfeng
	   return ([
                   "action": HIB+replace_string(replace_string(special_msg[random(sizeof(special_msg))], "$w", "$w"), "$w", "$w"HIB)+NOR,
                                   "damage": 350 + random(200),
                                   "dodge": 20+random(30),
                                   "force": 350 + random(250),
                                   "parry": 15+random(30),
                                   "damage_type": random(2)?"����":"����",
		]);
	}
       if(level> 450 
	&& me->query("jiali")
       	&& me->query("max_neili") > 5500 
	&& me->query("neili") > 5000 
              && random(4) == 1
       	&& (random(me->query_int()) > 40 ||random(me->query_dex()) > 40)
       	&& me->query_skill_mapped("parry") == "xuantie-jianfa")
	{
		return ([
			"action": HBRED"$NǱ����������������������$w"+HBRED"֮�ϻ����̳�һ����ֻ��һ��ͦ������ȴ�ǵ��޿ɵ����޿ɱ��޼᲻�ݡ�"NOR,
				"damage": 440 + random(130),
				"dodge": random(30),
				"force": 350 + random(250),
				"parry": random(30),
				"damage_type": random(2)?"����":"����",
		]);		
	}

   if(level<350){
		action_msg = msg[random(sizeof(msg))];
           action_damage=180 + random(140);
           action_dodge=random(30)-10;
           action_force=200 + random(350);
           action_parry=random(20);
                      }
   else if(level<450){
           action_msg = RED+replace_string(replace_string(special_msg[random(sizeof(special_msg))], "$w", "$w"), "$w", "$w"RED)+NOR;
           action_damage=200 + random(160);
           action_dodge=random(30);
           action_force=200 + random(350);
           action_parry=random(20)+5;
       }
   else {
           action_msg = HIB+replace_string(replace_string(super_msg[random(sizeof(super_msg))], "$w", "$w"), "$w", "$w"HIB)+NOR;
           action_damage=260 + random(200);
           action_dodge=random(30)+5;
           action_force=250 + random(350);
           action_parry=random(20)+5;
       }
return ([
                           "action": action_msg,
                           "damage": action_damage,
                           "dodge": action_dodge,
                           "force": action_force,
                           "parry": action_parry,
				"damage_type": random(2)?"����":"����",
		]);
}

int practice_skill(object me)
{    
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if (me->query("jingli") < 50)
		return notify_fail("�����������������������\n");
	if (me->query("neili") < 20)
		return notify_fail("�����������������������\n");
	me->receive_damage("jingli", 45);
	me->add("neili", -25);
	return 1;        
}

int valid_learn(object me)
{
	if (me->query_skill("xuantie-jianfa", 1) < 200 )
		return notify_fail("������������ֻ��ͨ����ɽ������������߼��ա�\n");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xuantie-jianfa/" + action;
}

//by tangfeng
//ע������û���κ�Ч��ֻ��������������
//Ҳϣ��������ʦ��Ҫ�����޸��ƻ�ƽ��
mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon; 
	int i; 
	string msg;

	weapon = me->query_temp("weapon");
	if( !objectp(weapon) ) return;
	i = me->query_skill("xuantie-jianfa", 1);

	if(i> 150 
		&& me->query("jiali")
       	&& me->query("max_neili") > 1500 
		&& me->query("neili") > 1000 
		&& random(10) >= 7
       	&& (random(me->query_int()) > 30 ||random(me->query_dex()) > 30)
//		&& !me->query_temp("xtjf_pfm")
       	&& me->query_skill_mapped("parry") == "xuantie-jianfa"
       	&& random(me->query("combat_exp")) > victim->query("combat_exp")/3)
	{
		if(i<350)
			msg = HIB"$NŭХһ����"+weapon->name()+HIB"��ʱ��������ɫ�Ĺ�ʣ�һ����ɫ��â���̶�����\n"NOR;
		else 
		{
                        if(!random(4))
				msg = HBBLU"ͻȻ"+weapon->name()+HBBLU"����ҫ�۵Ĺ�â�������ռ�������������ӿ���ȵ�ɱ����\n"NOR;
			else
				msg = HBBLU"$N"+weapon->name()+HBBLU"��ɢ���������ν����·�ǧ��㺮�Ƿ��裬��$n���ؿ�����ش�ȥ��\n"NOR;				
                }


if(random(2))   victim->add_busy(1);
if(random(2))   victim->receive_damage("qi",i+ random(i)*2, me);
                   victim->receive_wound("qi", i+ random(i), me);

		message_vision(msg, me,victim); 
	}
}
