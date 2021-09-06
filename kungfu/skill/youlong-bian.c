
// ��yinlong-bian.c �����޷�
// By fengyue
#include <ansi.h>
inherit SKILL;

string  *msg = ({
"$N��$w������Բ���Ƴ�һ�������СС��Ȧ�ӣ���ʱ��$n�������,����һ�С�Բת���⡹��",
"$N��$w������������Ȼ���ͷ������أ�һ�С��������ס���ͷ��׼$n$l��������",
"$N��������һ�ͣ�$w��Ȼ��ɱ�ֱ��������ǹ��һʽ����������������$nֱ�̹�ȥ",
"$N��$w����һ����˿������û������������Ӻ����������������ˣ���$n����Ʈ�������������̻�",
"$N��$w�������߲�����ֱ��$n�ؿڡ�$n�������ܣ���$wȴ�Ӱ�·�佫��������$nȦ������",
"$N����һ��һ�Σ��������ɣ�$w���Ҽ缱˦��󣬶��ر�ͷ����$n����,��������������ʸ�ö���",
"�������Ӱ������$wӭ�������Ѹ�����ף�$n���μ��ˣ�ȴ����$N��ʽ��ã�һ������㱻Ȧס",
});

int valid_enable(string usage)
{ 
	return usage == "whip" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        if((int)me->query_skill("yinlong-bian",1)>=450)
        return ([
                "action":HIC +replace_string(replace_string(msg[random(sizeof(msg))], "$w", "$w"), "$w", "$w"HIC)+NOR,
                "damage":       150 + random(150),
                "damage_type":  "����",
                "dodge":        10+random(30),
                "force":        random(300) + 200,
                "parry":        random(30),
            ]);
        else

        if((int)me->query_skill("yinlong-bian",1)>=350)
        return ([
                "action":HIC +replace_string(replace_string(msg[random(sizeof(msg))], "$w", "$w"), "$w", "$w"HIC)+NOR,
                "damage":       120 + random(100),
                "damage_type":  "����",
                "dodge":        10+random(30),
                "force":        random(300) + 200,
                "parry":        random(30),
            ]);
        else
	return ([
		"action":	msg[random(sizeof(msg))],
		"damage":	100 + random(120),
		"damage_type":	"����",
		"dodge":	random(30),
		"force":	random(300) + 150,
		"parry":	random(30),
       ]);
}

int valid_learn(object me)
{
	object weapon;
	if( (int)me->query("max_neili") < 1500 )
		return notify_fail("����������㣬û�а취�������ޣ�����Щ���������ɡ�\n");
	if ((int)me->query_skill("whip", 1) < 100)
		return notify_fail("����ȴ�û��������ɡ�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	 || ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("��ʹ�õ��������ԡ�\n");
	return 1;
}
 
int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60)
		return notify_fail("����������������������ޡ�\n");
	if ((int)me->query("neili") < 30 )
		return notify_fail("����������������������ޡ�\n");
	me->receive_damage("jingli", 50);
	me->add("neili",-20);
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weap,weap1;
	int ap, dp;
	weap = victim->query_temp("weapon");
	weap1 = me->query_temp("weapon");

	if( !me->query("env/no_chan")
	 && me->query_skill("yinlong-bian", 1) > 120
	 && me->query("neili") > 700
	 && victim->query_temp("weapon")
	 && random(me->query_skill("yinlong-bian",1)) > victim->query_skill("dodge", 1)/2 
	 && random(10) > 3) {
		message_vision(HIC"ֻ��$N"+ weap1->name() + HIC"���ٶ������Ƴ�ת����������СȦ�ӣ���ʱ��" + weap->name() +HIC"������䣡\n" NOR, me );
		victim->add_busy(1);
		ap = me->query("combat_exp", 1) /1000 * me->query_str(1);
		dp = victim->query("combat_exp", 1) /1000 * victim->query_str(1);
		if (random(ap + dp ) > dp ) {
			message_vision(HIY"$N��������ôһ������ʱ����������ת�˼����߰˸�Ȧ�ӣ�"+ weap->name()+ HIY"���ֶ�����\n" NOR, victim );
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
	return __DIR__"yinlong-bian/" + action;
}

