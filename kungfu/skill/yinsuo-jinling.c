// yinsuo-jinling.c ��������
// By River
#include <ansi.h>
inherit SKILL;

string  *msg = ({
"$N�����������$w����˦�˳�����ֱ��$n��$l��������Ϣ�����Ⱦ�û�������",
"$N�ֳ�$w��ʸ�����߻���$n���ټ���ö���򲻶Ϸ�������֮����������������",
"$n�����ý����з����������죬���䲻��ȴ��ʮ�ֹ��죬�������ҡ�ǡ�",
"$N����һ�䣬ת��һ��$w��$n��֮�£�����������$w�������缱�Ӷ���",
"$N����΢����$w������ȥ�����¶��ϣ�����$n����$l���ġ��Ϲ�Ѩ��",
"$N��������$w����ˮ�߰����Ѷ������������죬$n�����ϵġ����Ѩ������$w����",
"$N΢΢һЦ��ǰһ��������$wһ����$w��ز���裬�ñȲʷﳯ��һ�����$n",
});

int valid_enable(string usage)
{ 
	return usage == "whip" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
    if(me->query_temp("sanwu/buwei")){
        if((int)me->query_skill("yinsuo-jinling",1)<350)
        return ([
                "action":       msg[random(sizeof(msg))],
                "damage":       180 + random(120),
                "damage_type":  "����",
                "dodge":        5+random(30),
                "force":        random(330) + 180,
                "parry":        random(30),
            ]);
        if((int)me->query_skill("yinsuo-jinling",1)<450)
        return ([
                "action":HIW +replace_string(replace_string(msg[random(sizeof(msg))], "$w", "$w"), "$w", "$w"HIW)+NOR,
                "damage":       200 + random(140),
                "damage_type":  "����",
                "dodge":        10+random(30),
                "force":        random(300) + 200,
                "parry":        random(30),
            ]);
        else
        return ([
                "action":HIR +replace_string(replace_string(msg[random(sizeof(msg))], "$w", "$w"), "$w", "$w"HIR)+NOR,
                "damage":       150 + random(200),
                "damage_type":  "����",
                "dodge":        20+random(30),
                "force":        random(300) + 200,
                "parry":        random(30),
            ]);
        }
        if(me->query_temp("juan") && (int)me->query_skill("yinsuo-jinling",1)>=350)
        return ([
                "action":HIG +replace_string(replace_string(msg[random(sizeof(msg))], "$w", "$w"), "$w", "$w"HIG)+NOR,
                "damage":       220 + random(150),
                "damage_type":  "����",
                "dodge":        10+random(30),
                "force":        random(300) + 200,
                "parry":        random(30),
            ]);
        else
	return ([
		"action":	msg[random(sizeof(msg))],
		"damage":	160 + random(100),
		"damage_type":	"����",
		"dodge":	random(30),
		"force":	random(300) + 150,
		"parry":	random(30),
       ]);
}

int valid_learn(object me)
{
	object weapon;
	if( (int)me->query("max_neili") < 500 )
		return notify_fail("����������㣬û�а취����������, ����Щ���������ɡ�\n");
	if ((int)me->query_skill("yunu-xinjing", 1) < 100)
		return notify_fail("�����Ů�ľ��ڹ����̫ǳ��\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	 || ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("��ʹ�õ��������ԡ�\n");
	return 1;
}
 
int practice_skill(object me)
{
	if ( me->query("jingli") < 40)
		return notify_fail("��������������������塣\n");
	if ( me->query("neili") < 20)
		return notify_fail("��������������������塣\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weap,weap1;
	int ap, dp;
	weap = victim->query_temp("weapon");
	weap1 = me->query_temp("weapon");

	if( !me->query("env/no_chan")
	 && me->query_skill("yinsuo-jinling", 1) > 120
	 && me->query("neili") > 700
	 && victim->query_temp("weapon")
	 && random(me->query_skill("yinsuo-jinling",1)) > victim->query_skill("dodge", 1)/2 
	 && random(10) > 7) {
		message_vision(HIY"ֻ��$N���ٻ���"+ weap1->name() + HIY"��ת����������СȦ�ӣ�������֮����ס�Է���" + weap->name() +HIY"��\n" NOR, me );
		victim->add_busy(1);
		ap = me->query("combat_exp", 1) /1000 * me->query_dex(1);
		dp = victim->query("combat_exp", 1) /1000 * victim->query_str(1);
		if (random(ap + dp ) > dp ) {
			message_vision(HIY"$N�����ֱ�����һק��"+ weap->name()+ HIY"ȴ�޷���"+weap1->name()+HIY"�Ĳ������ѿ����鼱֮��ֻ�÷��������еı��С�\n" NOR, victim );
			weap->move(environment(me));
			victim->reset_action();
		}
		else {
			message_vision(HIY"$N�����ɾ���"+ weap->name()+ HIY"˳�ŷ��������ת���£��⿪��"+weap1->name()+HIY"�Ĳ��ơ�\n" NOR, victim );
			victim->add("neili", -50);
		}
		me->add("neili", -(20+random(30)));
	}
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yinsuo-jinling/" + action;
}
