// wuyue-jianfa.c ��������
// Update by action@SJ 2009/1/10

inherit SKILL;
#include <ansi.h>
#include <combat.h>

string *msg = ({
"$N��$w�ڿ�������һ������һ�����϶��£�ֻ�����ƶ������߹⾰���������о�Ȼ����֮������",
"$N�޵������ܺã���ľ��б��$n���أ����д������������أ�����һ�й��ؼ汸������������",
"$N$w��ת��ָ��$n�Ҽ磬�������д������������ص�����",
"$n��δ���������ǿ�У�$N������Ҳ����û��������ֻ����������޷����޷������϶",
"$N����֮ǿ������֮�������߻��Ϊһ��ʵ���޿ɷָ�",
"$N���������ѽ�$n�ȵô��ھ�����������������֮���������",
"$N���о��⾡ȥ��Ҳ��˵ȫ����ע�ڽ���֮�У����޿־���ǻ�ϲ����Ͼ",
"$N�����任�����ϳ˽������еĹ����������е��������࣬�е�С��Ѹ�ݣ��е����ͳ��ȡ�",
"$N�������ȣ����Ʒ��˷�һ�㡣����Խ��������Ҳ��Խ��",
"$n��������·����Ҳ�����洦����ÿһ���Ϻ�ȴ����$n˫���������죬�ķ����ң�ֻ��ǿ���򶨣��������",
});

string *feiyue_msg = ({
"$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ����Ůʮ�Ž��������������ʮ�Ž�����һ�У��ַ�֮�죬ֱ�Ƿ�����˼",
"$N������$n�ӳ���Ȫ��ܽ�ء����������ϸǡ�����ʯ�����������������������������ף�ڡ���ɽ����",
"$NͻȻʹ��������ɷ罣���ġ����ڤڤ�������Ƿ�λȴ����ƫ�$w����$nһ�ʣ���ͼͻ��$n�Ĺ���",
"$N����ͻ�䣬ʹ����ɽ�ġ�һ������㡹������$n��$l����֪������;��ͻȻת�򣬴��$n����֮��",
"$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲô����",
"ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�����������̩ɽʮ���̡�Ϊһ������$n",
"$N���ƺ��������裬�������������������ɽ����Ϊһ������$n������ȥ",
"$NͻȻ�˽����һ�ֹ���ġ������罣��������Ȼ��$n�����Ҵ�����",
"$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ�������ɽ���ƻ���$n",
"$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ�ġ��ٱ�ǧ������ʮ��ʽ������ʽ�����ƾ���ӿ���Թ��߲��ɵ�ĿΪ֮ѣ",
"ֻ��$N����������һ�����ǡ�������ɽ��������$w����ն�䣬ֱ����$n��$l",
"����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ�����ġ�������Ȫ��ֱ��$n��$l",
"$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����˼��",
"$n��׼$Nһ�л�ɽ�������з����ǡ������ƣ�׼�����з�����ȴ��$NͻȻ�鲽������ʹ�������䵱�����ѵ�ˮ����һ��",
"$n����$N��$l��$N���˷�����ʹ����ɽ���С�������롹��ɭɭ������������",
});
int valid_enable(string usage)
{
   if ( this_player()->query("quest/xixing")=="pass" )
		return (usage == "sword") || (usage == "parry") ;
}

int valid_learn(object me)
{
	mapping my_fam  = me->query("family");
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if(!my_fam || my_fam["master_name"] != "������")
		return notify_fail("�㲻�������еĵ��ӣ�����ѧϰ��������������\n");

	if ( me->query("max_neili") < 1000)
		return notify_fail("�������������\n");
	return 1;
}


mapping query_action(object me, object weapon)
{
	int i, j, level, damage;

	level = me->query_skill("wuyue-jianfa", 1);
	i = random(me->query_skill("sword"))+50;
	if( i<100 ) i = 100;
	j = random(40)-5;
	damage = (random(6)+1)*35;
	if( damage < 50 ) damage =50;

		if( level > 350 ) {
			return ([
        "action": WHT+replace_string(replace_string(feiyue_msg[random(sizeof(feiyue_msg))], "$w", "$w"), "$w", "$w"WHT)+NOR,
				"damage": 150 + random(120),
				"damage_type": "����",
				"dodge":  random(20),
				"parry":  random(20),
				"force":  300 + random(250),

			]);
		}

		else return ([
			"action": msg[random(sizeof(msg))],
			"damage": 130 + random(140),
			"damage_type": "����",
			"dodge":  random(30),
			"force":  250 + random(300),
		]);
	}

int practice_skill(object me)
{
	if ( me->query("jingli") < 50)
		return notify_fail("�����������������������\n");
	if ( me->query("neili") < 20)
		return notify_fail("�������������ϰ����������\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wuyue-jianfa/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon, weapon1;
	int i;
	weapon = me->query_temp("weapon");
	weapon1= victim->query_temp("weapon");

	if( !objectp(weapon) ) return;

	i = me->query_skill("wuyue-jianfa", 1);

   if(i>=350){
       if(random(i)>(int)victim->query_skill("parry",1)*2/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIG"$N�������࣬��סȫ�����ް�ֿ�϶��������˺���������$n�������죡\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            call_out("wyjf_must_be_hit",2,me,victim,random(i/50));
       }
   }

   if(i>=250){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIR"$n��δ���������ǿ�У�$N������Ҳ����û��������ֻ����������޷����޷�����Ͼ϶��\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }    
}

void wyjf_must_be_hit(object me,object target,int i)
{
    if(!target) return;
    if(!me) {
        target->delete_temp("must_be_hit");
        if(living(target))
            message_vision(HIY"$n�������˿������ֽŻָ���������\n"NOR,target);
        return;
    }
    if(wizardp(me) && me->query("env/dgjj_test")) write("i is "+i+"\n"NOR);
    if(me->query_skill_mapped("sword")!="wuyue-jianfa"
     ||me->query_skill_mapped("parry")!="wuyue-jianfa"
     ||i<=0){
        if(living(target))
            message_vision(HIY"$n�������˿������ֽŻָ���������\n"NOR,me,target);
        target->delete_temp("must_be_hit");
        return;
    }
    call_out("wyjf_must_be_hit",1,me,target,--i);
}
