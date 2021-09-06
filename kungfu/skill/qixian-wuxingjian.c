// qixian-wuxingjian.c
// modified by action@SJ 2009/1/10
//updated by Zmud@Sjmud 10/3/2009

#include <ansi.h>
#include <skill.h>

inherit SKILL;

string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ", "�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ",
"����Ѩ", "����Ѩ", "���Ѩ", "�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", }); 

string  *msg = ({
"$Nʹһ�С�����������������$w����һ�����������һ�����$n��$l",
"$N��ָ��$w��һ����һ�С����������������������ʱ����һ����������Х��ն��$n��$l",
"$Nһ�С����������������$w��â��ʱ�������ߣ��⻪���䣬ֱֱ����$n��$l",
"$N����$wһʽ�����̾�ɲ����׼$n��$lһ���̳�������ɲʱ�����ݺᣬ�Ʋ��ɵ�",
"$N��$wƾ��һָ��һ�С��������项ֱֱ�̳������ⶸȻ����������²�������â����$n��$l",
"$N����$w����һ�֣�ʹһ�С��������ơ��������ڽ������ᵯ������ʱһ�ɽ���ֱӿ$n$l��ȥ",
"$N��Ȼ���о������䣬һ�С��Ǻ���������һ�ɴ����ޱȵĽ�����$w�ϼ��������ֱ��$n",
});

string *feiyue_msg = ({
"$N��Сָ�ᵯ��һ�й�����Ȼ����$n�ĺ��ģ�$w��ס��������$n$l��ȥ",
"$N��������ָ�������޵�һ���������Ҳ���һ���������ѽ�$n����ס�ڽ���֮��",
"$N��ָ���ӣ�һʽ�������εĴ���$n�����ߣ���Ȼ��$Nһ��ת������$n���ߴ�ȥ",
"$N�����н���ɨ��ͬʱ�������������Ƶļ���������һ��֧�ϣ��о������ޱ�",
"$Nʹ�����ϣ������������ߣ���ͬ��������������������$n��$l",
"$N����ɫ���ˣ��˽�һ�ϣ�ʹ�����ϣ�$N�����ֶ���һ�������͵���$n��ȥ",
"$Nʹһ�й��ϣ�����$w����һ�����������һ�����$n��$l����ʽ��ΪƮ��",
"$N��ָ��$w��һ����һ�����ϣ����������ʱ����һ����������Х��ն��$n��$l",
"$Nһ�н��ϣ�����$w��â��ʱ�������ߣ��⻪���䣬ֱֱ����$n��$l��$n��Ȼ�޷����",
"$N����$wһʽ���϶�׼$n��$lһ���̳�������ɲʱ�����ݺᣬ�Ʋ��ɵ�������������",
"$N��$wƾ��һָ��һ��֧��ֱֱ�̳������ⶸȻ����������²�������â����$n��$l",
"$N����$w����һ�֣�ʹһ�����ϣ������ڽ������ᵯ������ʱһ�ɽ���ֱӿ$n$l��ȥ",
"$N��Ȼ���о������䣬һ�й��ϣ�һ�ɴ����ޱȵĽ�����$w�ϼ��������ֱ��$n",
});

int valid_enable(string usage)
{
	if (this_player()->query("quest/xxdf/pass")) return usage == "sword" || usage == "parry";
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 50 || me->query("neili") < 20 )
		return notify_fail("��������������������ν���\n");

	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

int valid_learn(object me)
{
	mapping fam  = me->query("family");
	object weapon = me->query_temp("weapon");

	if( !weapon || weapon->query("skill_type") != "sword" )
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("max_neili") < 800 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("xixing-dafa", 1) < 200 )
		return notify_fail("������Ǵ󷨻��̫ǳ��\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, j, level, damage;
	string str;

	level = me->query_skill("qixian-wuxingjian", 1);
	i = random(me->query_skill("sword"))+50;
	if( i<100 ) i = 100;
	j = random(40)-5;
	damage = (random(6)+1)*35;
	if( damage < 50 ) damage =50;
		
	if(me->query_temp("guangling")){
		switch(me->query_temp("guangling")){
			case 3: str = HIB"$N��ͷ���һ�֣���Ȼ�����˹���ɢ�ľ������ڣ���"HIM"����ɢ��"HIB"��������$nʹ���������������ν����������ӵ����쾡��"NOR; break;
			case 2: str = MAG"$n���˲��ܣ�����������$N�Ľ���֮�У�$nֻ�о�$N����$w"MAG"���Ϸ�����������Ĳ�����$n����ȫ����ͻ��"NOR; break;
			case 1: str = HIR"$N��$w"HIR"�ϵ�����ȴ������ǡ���෴��$N���п��ٶ�����ȴ�ӱ����У�$n�Ʊ��޷��мܣ����й����ͬС�ɣ�������ǿ"NOR; break;
		 default: str = HIR"$N��$w"HIR"�ϵ�����ȴ������ǡ���෴��$N���п��ٶ�����ȴ�ӱ����У�$n�Ʊ��޷��мܣ����й����ͬС�ɣ�������ǿ"NOR; break;
		}
		me->add_temp("guangling", -1);
		return ([
			"action":str,
                        "damage": 220 + random(150),
			"damage_type": "����",
			"dodge": random(30),
			"parry": random(30),
			"force": 350 + random(250),
		]);
	}

		if( level > 450 ) {
			return ([
        "action": WHT+replace_string(replace_string(feiyue_msg[random(sizeof(feiyue_msg))], "$w", "$w"), "$w", "$w"WHT)+NOR,
				"damage": 120 + random(120),
				"damage_type": "����",
				"dodge":  random(20),
				"parry":  random(20),
				"force":  300 + random(250),

			]);
		}

		else return ([
			"action": msg[random(sizeof(msg))],
			"damage": 100 + random(100),
			"damage_type": "����",
			"dodge":  random(30),
			"force":  250 + random(300),
		]);
	}
	
string perform_action_file(string action)
{
	return __DIR__"qixian-wuxingjian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon, weapon1;
	string name;
	int i;
	weapon = me->query_temp("weapon");
	weapon1= victim->query_temp("weapon");

	if( !objectp(weapon) ) return;

	i = me->query_skill("qixian-wuxingjian", 1);

   if(i>=350){
       if(random(i)>(int)victim->query_skill("parry",1)*2/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIG"\n$N�������࣬��סȫ�����ް�ֿ�϶��������˺���������$n�������죡\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            call_out("qxwxj_must_be_hit",2,me,victim,random(i/50));
       }
   }

   if(i>=250){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HBRED"\n$n��δ���������ǿ�У�$N������Ҳ����û��������ֻ����������޷����޷�����Ͼ϶��\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }  
   if(i>=300){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIW"\n$N����һ�𣬽����ڵ����ν������������һ�󵭵�����������$n��ȫ��Ѩ����\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
            victim->start_busy(1+random(1));
       }
   }  
   
   name = xue_name[random(sizeof(xue_name))];
   if(i>=400){
   	if(random(i)>(int)victim->query_skill("dodge",1)/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIB "\nֻ��һ�󴾺��������" + weapon->name() +HIB "��������$n" HIY "��" + name + "��"
                       NOR + HIB "��ʱ��������������ȫ�������Ҵܲ�ֹ��\n" NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->start_busy(1+random(2));
            victim->apply_condition("no_fight",1);
       }
   }  
   	 
}

void qxwxj_must_be_hit(object me,object target,int i)
{
    if(!target) return;
    if(!me) {
        target->delete_temp("must_be_hit");
        if(living(target))
            message_vision(HIY"$n�������˿������ֽŻָ���������\n"NOR,target);
        return;
    }
    if(wizardp(me) && me->query("env/qxwxj_test")) write("i is "+i+"\n"NOR);
    if(me->query_skill_mapped("sword")!="qixian-wuxingjian"
     ||me->query_skill_mapped("parry")!="qixian-wuxingjian"
     ||i<=0){
        if(living(target))
            message_vision(HIY"$n�������˿������ֽŻָ���������\n"NOR,me,target);
        target->delete_temp("must_be_hit");
        return;
    }
    call_out("qxwxj_must_be_hit",1,me,target,--i);
}
