// zhemei-shou.c ��ɽ��÷��
// Create by action@SJ 2009/1/10
// modified by zhuifeng@SJFY 2010/07/17

#include <ansi.h>
inherit SKILL;  

mapping *action = ({
([  "action" : MAG"$Nһ�С�"+NOR+HIG+"��÷��Թ"+NOR+MAG+"����˫�ֺ�ӣ�ץ��$n"NOR,
    "lvl" : 0,
    "skill_name" : BLK "��÷��Թ" NOR,
    "damage_type" : "����"
]),
([  "action" : MAG"$Nһ�С�"+NOR+YEL+"�ƻ���Գ�"+NOR+MAG+"��������ԾȻ����ץ��$n��ͷ��"NOR,
    "lvl" : 30,
    "skill_name" : RED "�ƻ���Գ�" NOR,
    "damage_type" : "����"
]),
([  "action" : MAG"$Nһ�С�"+NOR+GRN+"��ɽһ�����ı�"+NOR+MAG+"����˫�ַ׷ɣ�$nֻ���ۻ�����"NOR,
    "lvl" : 60,
    "skill_name" : GRN "��ɽһ�����ı�" NOR,
    "damage_type" : "����"
]),
([  "action" : MAG"$Nһ�С�"+NOR+YEL+"÷��ѩ�串��ƻ"+NOR+MAG+"����˫�ֺϻ���$nֻ���޴��ɱ�"NOR,
    "lvl" : 90,
    "skill_name" : YEL "÷��ѩ�串��ƻ" NOR,
    "damage_type" : "����"
]),
([  "action" : MAG"$Nһ�С�"+NOR+HIC+"������÷��ѩ��"+NOR+MAG+"����˫��ƮȻץ��$n"NOR,
    "lvl" : 120,
    "skill_name" : HIC "������÷��ѩ��" NOR,
    "damage_type" : "����"
]),
([  "action" : MAG"$N˫��ƽ�٣�һ�С�"+NOR+HIW+"����������ŪӰ"+NOR+MAG+"������$n",
    "lvl" : 150,
    "skill_name" : HIW "����������ŪӰ" NOR,
    "damage_type" : "����"
]),
([  "action" : MAG"$Nһ�С�"+NOR+WHT+"��������ֱ����"+NOR+MAG+"��������$n���ƺ�$n��ȫ��������"NOR,
    "lvl" : 180,
    "skill_name" : WHT "��������ֱ����" NOR,
    "damage_type" : "����"
]),
([  "action" : MAG"$N������Σ�����һ�ǡ�"+MAG+"����δ�϶��Ⱦ�"+NOR+MAG+"������$n��ͷ��"NOR,
    "lvl" : 210,
    "skill_name" : MAG "����δ�϶��Ⱦ�" NOR,
    "damage_type" : "����"
]),
([  "action" : MAG"$Nʩ����"+NOR+RED+"����Ц��"+NOR+MAG+"�������ֺ�ɨ$n��$l�����ֹ���$n���ؿ�"NOR,
    "lvl" : 240,
    "skill_name" : RED "����Ц��" NOR,
    "damage_type" : "����"
]),
([  "action" : MAG"$Nʩ����"+NOR+YEL+"��ʯ���"+NOR+MAG+"��������һ������$n"NOR,
    "lvl" : 270,
    "skill_name" : YEL "��ʯ���" NOR,
    "damage_type" : "����"
])
});

int valid_enable(string usage) { 

	  return usage=="parry"|| usage=="hand"; }
	
	
int valid_combine(string combo) 
   {
	    object me,victim;
	   me = this_player(); 

           if(me->query("marry/id") || me->query("/quest/xiaoyao/pass")) 
		return combo=="liuyang-zhang"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɽ��÷�ֱ�����֡�\n");
	if ((int)me->query_skill("hand", 1) < 50)
		return notify_fail("��Ļ����ֹ���򲻹����޷�ѧϰ��\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������̫�����޷�����ɽ��÷�֡�\n");
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
level = (int) me->query_skill("zhemei-shou",1);

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if ( me->query_temp("zms/piaomiao")){
				return ([
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
					"damage": 100+random(100),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}

if(me->query_temp("tanmei")){
		switch(me->query_temp("tanmei")){						
			case 2: msg = HIG "$nͻȻ�ŵ�һ���������޵���ζ����Գ����֮��$N��˫������$p�ؿ�������                        
"HIW"���� ѩ��"NOR; break;
      case 1: msg = HIC "$N˫�ּ��ӣ�����ҡ�ڣ��ó�����"HIW"÷��"HIC"����ѩ�Ƶ���$n������                                    
"HIM"��ɢ���㡿"NOR; break;
default: msg = MAG "$N΢΢һЦ��ʹ��"HIG"����÷.��ѩ.ɢ���㡿"MAG"������$n���ᵯ����������Ҫ��ȥ÷�������¶�飡       
"HIW"���� ÷��"NOR;break;
			
		}
		me->add_temp("tanmei", -1);
		return ([
			"action":msg,
					"damage": 100+random(80),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
				"dodge" : random(25)-5,
				"parry": 200+random(100),
				"damage" : 80 + random(100),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("���������������ɽ��÷�֡�\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -20 );
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zhemei-shou/" + action;
}

mixed hit_ob(object me, object target, int damage_bonus)
{
	int i,j;

	i = me->query_skill("zhemei-shou", 1);

if(i>=150||(random(3)&&me->query_temp("xiaoyao_jianwu", 1))){
	                switch (random(4)) {
	    case 0:
           message_vision(HIR"��ʱ$N����������������ң�����ַ��ӵ����쾡�£������������ۣ���������Ȼ����ң����ѧ������������\n"
                             "��Ȼ��Ȼ��Ҳʹ�˳�������ʹ�����������տ̶���$N�������գ��Թ���$nҪ����ֱ����$n���òҿ��ޱȣ�\n"NOR,me,target);
          j = i*(2+random(4));
          if( j>=target->query("qi") )  j=target->query("qi")/3;
            target->receive_damage("qi",j );
             target->receive_wound("qi",j/2 );
            break;
      case 1:
            message_vision(HIB"$N����ת�˸�СȦ���ȿ���׼����ֻ��ָ����$n���󣬴�Ĵָ��Сָ���ű㼴��£����ס$n���ţ�$n��ʱ�������ã�\n"NOR,me,target);
            target->add_busy(1);
  
       break;
       case 2:
            message_vision(HIC"$N����һ�䣬������������֮����������Ϣ����$n�ġ�����Ѩ����������ȭ�ͻ�����������$n�ؿڵġ�����Ѩ����\n"NOR,me,target);
            target->add_busy(1+random(2));
            
       
       break;
        case 3:
            message_vision(HIM"$N΢΢һЦ��ʹ����ɽ�ɽ^�С���ɽ��÷�֡���������������е��������ᵯ����������Ҫ��ȥ÷�������¶�飡\n"NOR,me,target);
       if( i>=target->query("qi") )  i=target->query("qi")/5;
            target->receive_damage("qi",i);
       break;
   }  
}
   
}
