// Created by snowman@SJ
// Modified by snowman@SJ 02/10/2000
// Modified again for tjj level > 450,  by snowman@SJ 23/02/2001
// Modified by snowman@SJ 23/04/2001. Npc cannot use ��ָ
// Add wd ���� by Lane@SJ 2005.7.8

#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include <combat_msg.h>

string  *msg = ({
"$N�ҽ���ǰһ������ϥ����$w��ǰ�����Ϸ�����һ�С�����Ͷ�֡�������$n��$l",
"ֻ��$Nһ��������$w������ǰ����һ���󻡣�ʹ��һ�С����Ǹ��¡�������$n��$l",
"$Nһʽ������ǡ��������ȦӰ��һʱ����ǧ���$wͬʱ��Ȧ�㣬�ֲ����������",
"$Nһ�С������пա���˫����㣬��ǰ����Ծ�䣬����$w������ǰ���£�Ʈ�ݵص���$n��$l",
"$N�������ȣ�ת��沽�������ҽŸ�����һ�С��Ʒ��붴����$w�й�ֱ��������$n��$l",
"$Nһ�С�����ʽ�������Ծ����أ���$w�س飬���Ʋ������������ֹ���$n��$l",
"$N����һ�С����ӳ�ˮ��������$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
"$n���μӿ죬���б��м���$N����$N����Ȧת���⣬���潣ת������һ�С�ʨ��ҡͷ��",
"$N��һ�����鲽������$w˳�ƻ���һ����Բ�����һʽ��С���ǡ�������$n��$l",
"$N��ʹ̫�����⻭��������Ȧ��������������һ��������һ�㡸С���ǡ��Ƶ罣�Ǽ���$n����",
"$N�ҽŶ���������$w��󳷣�����ǰƽƽ��������һ�С�����ʽ��������$n��$l",
"$Nʹһ�С���ɨ÷���������岻ͣ����ת������$w����ת�������׵糸����$n��$lɨȥ",
"$N���ǰ��һ��������$wһ�С�˳ˮ���ۡ����������಻�ϣ���ǰ����$n��$l",
"$Nһ��������������һ���鲽���������ҡ����ֽ��������಻������$n��$l",
"$N��ִ��������â��˸����̤ƫ��һʽ��˳ˮ���ۡ�����һƬ��͵����⻮��$n���",
"$N΢һ����һ�С�̽��ʽ�����ҽŶ�������ϥ����$w��ǰ����$n��$l",
"$N�ҽź�һ����һת������$w��󷴻���һ�С�����չ�᡹��Ĩ��$n��$l",
"$N˫�Ų�������������˫�ֳ�$w��һ�С���Գ�׹�������ǰƽƽ�̳�������$n��$l",
"$N��ǰ����������һ�С�Ұ��������������$w��ǰƽ���������������$n��$l",
"$N�ҽ���ǰ�沽��һ�С��������¡���$w�������һ���󻡣���ǰ����$n��$l",
"ֻ��$N����������֮�ɻ�������������������$w��ӯ���������ʽ��",
"$N��ɫ���أ���Ŷ�������ϥ����˫��������һ�С�����ͷ������������$n��$l",
"$N���̤ʵ���ҽ���㣬һ�С�����ָ·��������$w����һ�Ž���������$n��$l",
"$N˳��һ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ$n��$l",
"$N$wȦת��Ȼ����$n�������ƣ����˳��һʽ��ӭ�絧��������������ͣ�ȴ��ɱ������",
"$Nһ�С�������β�����ҽű��鲽�����ֻ��գ�˳�ƴ���$w���½���$n��$l",
"$N�����ң�˳�ְγ�����$w��һ��̫��������Բת���⡹��бб���˸�Ȧ�ӣ�����$n��$l",
"$N�����ǰ��һ����$w�ɺ�һ��Բ��ǰ����һ�С�ӭ�絧����������$n��$l",
"$Nʹһ�С�������ˮ�����ҽ����س���$w�������Һ󳷣�ͻȻ����ǰ������$n��$l",
"$N�鲽������һ�С����ѵ�ˮ��������$w���������һ��������$n��ȫ���Ѩ",
"$N��ǰ����һ�������ֽ���������$wʹ��һʽ��ָ���롹������ֱ��$n��$l",
"$Nһ�С������Ӳ�����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
"$n�����ħ������$Nչ������Ĺ�����$N���ء�ָ���롹���ݻ���,ٿȻ���һ�����š�",
"$Nһ�С�ȴ���齣�������Ծ����أ���$p��ǰ������$w�س飬���ֹ���$n��$l",
"$N���Ȱ�����ף�һ�С�����Ʊա������˸�������������ָ��ת������$n��$l",
"$N����š���������鱧��һ�С�����հ�ա���$w�й�ֱ��������ƽ�͵ش���$n��$l"
});

string *parry_msg = ({
"$p���ֽ���б����$w��������˸���Ȧ��ƽ����$P$W֮�ϣ�����������$W��ʱһ����\n",
"$p����$wбָ��̫��ԲȦ��$W��һ����$P��������ж��һ�ԣ�",
"$p�������֣�����ǰ��������ԲȦ���������໤סȫ�����ް�ֿ�϶������$P֮���ƻ��������Ρ�\n",
"$p��$w�����֣�����ǰ��������ԲȦ��$P��$p�������࣬��סȫ�����ް�ֿ�϶��\n",
"ֻ��$pʹ��������ǧ��֮�ɾ���$wб������$P��$W����һ�ԣ�\n",
"$p����ʮ�н���������ƣ�����ǧ�ٱ�������סȫ��Բת���⣬���ް��������\n",
"$p���ж�ȻȦת������������ɫ��Ȧ����ȦСȦ����ȦбȦ��һ��δ������һ��������ȫ�������Ȧ֮�С�\n",
"$n��������$P����$N���潣ת������Ȧת���׵ػ��⣡\n",
"$p����δ��ʹ�ϣ���ȻȦת��ͻȻ֮�䣬$P��ǰ�����˼�����ɫ��Ȧ����ȦСȦ����ȦбȦ����˸���ѡ�$P�۾�һ����ֻ�û��С�\n",
"$p��������ר־����һ��̫������ʹ��Բת���⣬�����쳣����ס�Ż���ʹ$P������ա�\n",
"$p��̫�����С��������衹��ʽ�⿪��$P��$p����ʱ�������ᣬ����ڼҽ�������������$p���֣�����һ����\n"
});

string *taiji_msg = ({
"$N����������һʽ���ֻ����ҡ������鸧�����ֳ������ֻ�������㽣������$n����ʵ����",
"$NĿ��Զ�����·ɣ���̾һ������������$w�������������������ƾ��Ƕϣ����������콣Ӱ",
"����$N�������¿��ϡ�����������ʵ�ѵ���̫�������ľ���",
"$N����$w��ʹ�ü��죬ȴ˿����������������֮�����������֮�����Ѵ��ڻ���",
"$N���������Ҫ֮���������˳�������ս��ǿ��$w�������ھ�������ǿ",
"̫�������������������̫��ȭ������ʵ�ǽ����Ƿ��켫�Ľ�����$N����һ���˿������಻������������",
"$N��������������ﳤ����������$n������$P$wһ��������һ�ƽ�������",
"$N����$n��ʽ������������֮�ơ���ׯ��֮�Σ��������ն���������������������˸����",
"$N�����ٻ������ǽ���������֮�٣�ʵ������",
"$N����$w������ǰ��������һ���Σ�һ��ɭɭ������ֱ����$n��ͻȻ֮�䣬$N�������֣�����һ����$n��$l��ȥ",
"$N����ͻ�䣬���������������Լ����������ʹ����������������������������⵴������������",
"$N����Ѹ�ݣ����ǽ���������֮�٣�ʵ������",
"$N$w����һ�д�����Լ�֮�ۣ�����֮�޷棬���������ᴫ�ڵ�̫���������⡹�ľ�������",
"$N��Ȼ�����У����ж�δ��ʹ�ϣ���ȻȦת�����������˳�һ�㣬����ӿ��$n",
"$N��ʽ����Ʈ��֮���������й��ӻ�񣬽��ϵ������ƺ�ֻ���ӵ�һ���ɣ������ȴ�������Դ�����ز�¶",
"�������������$N����$w���˳�ȥ����������ƽ�̣������������",
"$N˫��ע��$n������$w���������߰��ԣ��ν�һ���й�ͦ�������ƻ���������ʵ��������ϳ�̫��֮�������ܱٽ����",
"$N����û����ʽ��������ȫ�ǡ����ڽ��ȡ����಻����֮�⣬һ˿˿����$n",
"$N������Ȧ��һ�㺮�Ǵ���$n",
"����$N������$w������������ֻ��˸���Բ������$n",
"$N����һ�ӣ�$w��������б����������һ�������ƿ�������֤�������Ѵﷴ�ӹ���ľ���",
"$N$w�ڿ��л��ɴ�Ȧ�����ֽ�������������Ҳ��������΢��",
"$N����̤�ϣ��������֣�һ�С��������¡���һ������ʵʵ�������ֽ����У������Ϲ�â��˸�������͵ķ�����΢����",
"$N���ӻ�����ת�����ֳֽ������������𣬽��������ǰ������������ԣ�˫�۳ɻ�������$w�������Ȼ��������",
"$Nһ���̵�����������������������죬������ǿ",
"$N�������Ž���������$w��ס�Ķ���������$n�����ߴ�ҪѨ�����⼱��������������δ�",
"$N���ֽ���б����$w�����������Բ������������ֱ��$n$l",
"$N����һ���˿�������$w�������಻������������",
"$N����$wʹ����Ӧ�֣��켫���������о��棬�����鶯����ò��⣬ͻȻ���󷭽���ֱ��$n��$l�̵�",
"$N$w�ݳ���˳��$n��·���£��Լ�֮�ۣ�����֮�޷棬ʵ�ѵ���̫�������ľ���",
"$N����Ԧ����ǧ���򻯣������޾���ÿһ�ж�����ƽ����ʵ�������Դ�����ز�¶",
"$N��$w����һ����ԲȦ��ÿһ�о����Ի��δ̳����Ի����ջ�",
"$N����Ԧ�������ڽ��ȣ����಻�������п��������̣������࣬ʵ��ǧ���򻯣������޾�",
"$N������Х�������ݺ�仯������޷���$w����������ʹ֮����������������ɵ�",
"$N���о��ް�����ң������˽���$wÿ��һ�У����Ʒų�һ��ϸ˿��Ҫȥ��ס$n",
"$N�������У���˵����ȥȥֻ��һ�У�Ȼ����һ��ȴ����Ӧ������",
"$N�������¿��ϡ�������������̫���������Ҫ֮���������˳���������һ���˿������಻��",
"$N����$w������ǰ��������һ���Ρ�$nֻ��һ��ɭɭ������ֱ�ƹ���",
"$N������������������$w��ס������ͻȻƽ�̣����⼱��������������δ���$P��һ����������$n�����ߴ�ҪѨ",
"$N����δ��ʹ�ϣ���ȻȦת��ͻȻ֮�䣬$n��ǰ�����˼�����ɫ��Ȧ����ȦСȦ����ȦбȦ����˸����",
});

int taiji_hit(object me, object victim, object weapon, int damage);
int super_hit(object me, object victim, object weapon, int damage);

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
	int i, j, level, damage;
	string str;

	level = me->query_skill("taiji-jian", 1);
	i = random(me->query_skill("force"))+50;
	if( i<100 ) i = 100;
	j = random(40)-5;
	damage = (random(6)+1)*35;
	if( damage < 50 ) damage =50;

	if( me->query_temp("tjj/sanhuan") ) {
		switch(me->query_temp("tjj/sanhuan")){
			case 3: str = HIC"$Nʹ�����������¡�����ʽһ�䣬���ָ����ѣ������н������������������һ��Բ����$w"HIC"��$n��������"NOR; break;
			case 2: str = HIW"Ȼ��$N�ƽ�һ�����������У��������У�ͬ��һ�����Żӳ�����������������һ��ͣ�ٵĺۼ�"NOR; break;
			case 1: str = HIM"������ӣ�$N���е�$w"HIM"��һ�λӳ�����$n$l���������������������������������ͬ�����ϵ�������֮��"NOR; break;
			default: str = HIC"$Nʹ�����������¡�����ʽһ�䣬���ָ����ѣ������н������������������һ��Բ����$w"HIC"��$n��������"NOR; break;
		}
		if( me->query_temp("tjj/sanhuan") > 1 )
			me->add_temp("tjj/sanhuan", -1);
		return ([
			"action":str,
			"damage":240 + random(130),
			"damage_type": "����",
			"dodge": random(30),
			"parry": random(30),
			"force": 350 + random(250),
		]);
	}

	else if( me->query_temp("tj/̫��") || level > 350 ) {
		if( weapon ) {
			switch(weapon->query("material")){
				case "wood":
				case "bamboo":
				case "paper":
					weapon->set_temp("no_weapon_cut", 1); break;
				default: break;
			}
		}
		if( level > 450 ) {
			if( level > 400 ) level = 400;
			return ([
				"action": WHT+replace_string(replace_string(taiji_msg[random(sizeof(taiji_msg))], "$w", "$w"), "$w", "$w"WHT)+NOR,
				"damage": 150 + random(120),
				"damage_type": "����",
				"dodge":  random(20),
				"parry":  random(20),
				"force":  300 + random(250),
				"post_action": (: taiji_hit :),
//                                "post_action": (: super_hit :),

			]);
		}
		if( level > 350 ) {
			if( level > 400 ) level = 400;
			return ([
				"action": taiji_msg[random(sizeof(taiji_msg))],
				"damage": 140 + random(130),
				"damage_type": "����",
				"dodge":  random(20),
				"parry":  random(20),
				"force":  280 + random(270),
				"post_action": (: super_hit :),
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
	else if( me->query_temp("tjj/powerup") >= 1 ){
		me->add_temp("tjj/powerup", -1);
		str = HIW+msg[random(sizeof(msg))]+NOR;
		if( objectp(weapon) )
			str = replace_string(str, "$w", weapon->name()+HIW);
		return ([
			"action":str,
			"damage": 200 + random(100),
			"damage_type": "����",
			"dodge": random(40),
			"parry": random(40),
			"force": 350 +random(300),
		]);
	}

	if( random(50) >= 45 ) me->add_temp("tjj/powerup", 1);

	return ([
		"action":msg[random(sizeof(msg))],
		"damage": 80 + random(140),
		"damage_type": "����",
		"dodge": random(30)-10,
		"parry": random(20),
		"force": 200 + random(350),
	]);
}

int taiji_hit(object me, object victim, object weapon, int damage)
{
	int ap, dp, lvl;

	if( me->query_temp("taiji_jianjue") ) {
		me->delete_temp("taiji_jianjue");
		return 0;
	}
	lvl = me->query_skill("taiji-jian", 1);

	if( !victim
	 || !weapon
	 || lvl < 450
	 || !present(victim, environment(me))
	 || !victim->is_character()
	 || !me->is_fighting(victim)
	 || victim->query("env/invisibility")
	 || !living(victim)
	 || me->query_skill_mapped("force") != "yinyun-ziqi"
	 || me->query_skill_mapped("cuff") != "taiji-quan"
	 || me->query_skill_prepared("cuff") != "taiji-quan"
	 || me->query_skill_mapped("parry") != "taiji-jian")
		return 0;

	ap = COMBAT_D->skill_power(me, "cuff", 1)/100;
	if( lvl >= 450 ) ap = ap * 15/10;
if( me->query("quest/wdjiuyang/pass") ) ap = ap *2;
	dp = COMBAT_D->skill_power(victim, "parry", 2)/100;

	if( random( ap + dp ) > dp
	&& ((damage == RESULT_DODGE && !victim->query_temp("weapon"))
	|| (damage == RESULT_PARRY && victim->query_temp("weapon"))) ){
		me->add_temp("apply/damage", lvl/6);
		me->add_temp("apply/attack", lvl/4);
		weapon->unequip();
		message_vision(HIW"$PĬ��������"NOR+HBBLU"��̫�����������ޣ����¿����ʸ��ᡣ��"NOR+HIW"һ�����У�������ת"HIR"��̫����"HIW"������˳���Ƴ�����"NOR, me, victim);
         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 3);
		weapon->wield();
		me->add_temp("apply/damage", -lvl/6);
		me->add_temp("apply/attack", -lvl/4);

		me->add_temp("taiji_jianjue", 1);
		me->add_temp("jianjue", 1);
	}
	return 1;
}

int super_hit(object me, object victim, object weapon, int damage)
{
	int ap, dp, lvl;

	if( random(10) != 5 ){
		if( !wizardp(me) ) return 0;
		if( me->query("env/combat") != "verbose")
			return 0;
	}

	if( !userp(me) && !me->query("taiji_quest") ) return 0;

	lvl = me->query_skill("taiji-jian", 1);

	if(!victim
	|| !weapon
	|| me->query("neili") < 7000
	|| lvl < 400
	|| !present(victim, environment(me))
	|| !victim->is_character()
	|| !me->is_fighting(victim)
	|| victim->query("env/invisibility")
	|| !living(victim)
	|| me->query_skill_mapped("force") != "yinyun-ziqi"
	|| me->query_skill_mapped("cuff") != "taiji-quan"
	|| me->query_skill_prepared("cuff") != "taiji-quan"
	|| me->query_skill_mapped("parry") != "taiji-jian")
		return 0;

	ap = COMBAT_D->skill_power(me, "cuff", 1)/100;
	if( lvl >= 450 ) ap = ap * 13/10;
	dp = COMBAT_D->skill_power(victim, "parry", 2)/100;

	if( random( ap + dp ) > dp
	&& ((damage == RESULT_DODGE && !victim->query_temp("weapon"))
	|| (damage == RESULT_PARRY && victim->query_temp("weapon"))) ){
		me->set_temp("tjj/super_hit", 1);
		me->set_temp("hit_ob_hit", 1);
		me->add_temp("apply/damage", lvl/3);
		victim->set_temp("must_be_hit", 1);
		weapon->unequip();
 COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),3);    // super ����������
		weapon->wield();
		me->delete_temp("tjj/super_hit");
		me->delete_temp("hit_ob_hit");
		me->add_temp("apply/damage", -lvl/3);
		victim->delete_temp("must_be_hit");
	}

	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 50 || me->query("neili") < 20 )
		return notify_fail("�������������̫��������\n");

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

	if( !mapp(fam) || fam["family_name"] != "�䵱��" || fam["generation"] != 2 )
		return notify_fail("̫����ֻ�ܴ��䵱�����ᴦѧ����\n");

	if( (int)me->query("max_neili") < 800 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("yinyun-ziqi", 1) < 100 )
		return notify_fail("������������̫ǳ��\n");

	if( me->query_skill("taiji-jian", 1) > me->query_skill("taiji-quan", 1)+30 )
		return notify_fail("���̫��ȭ���̫ǳ��\n");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon, weapon1;
	int i;
	weapon = me->query_temp("weapon");
	weapon1= victim->query_temp("weapon");

	if( !objectp(weapon) ) return;

	if( me->query_temp("tjj/sanhuan") ) return;

	i = me->query_skill("taiji-jian", 1);

	if( me->query("env/̫������") && weapon1 && i > 150 && me->query("jiali") && living(victim)
	 && me->query("max_neili") > 1200 && me->query("neili") > 1000 &&( random(10) >= 5 || me->query("quest/wdjiuyang/pass"))
	 && random(me->query_int(1)) > 30 && !me->query_temp("tjj/powerup")
	 && me->query_skill_mapped("parry") == "taiji-jian"
	 && random(me->query("combat_exp")) > victim->query("combat_exp")/3 
) {
		message_vision(HIM"$N���ֽ���б����"+weapon->name()+HIM"������Բ��ƽ����$n"+weapon1->name()+HIM"�����ϣ�����������"+weapon1->name()+HIM"��ʱһ����\n"NOR, me,victim);
		if( random(me->query("str")) > victim->query("str")/2) {
			me->add("neili", -50);
			message_vision(HIR"$N��ʽ����ɬ�ͣ�ֻ��������"+weapon1->name()+HIR"���Ʋ��ϵ�������������һ���ѳֲ��������ַɳ���\n"NOR, victim);
			weapon1->unequip();
			weapon1->move(environment(victim));
		}
		else {
			message_vision(HIY"$Nһ��ʹ���������˵ò��㣬��"+weapon->name()+HIY"������ת����Ȧ�ӣ�����"+weapon1->name()+HIY"һ����Щ���֣�\n"NOR, victim);
			victim->add_busy(2);
		}
	}
	else if( me->query_temp("tj/̫��") || i > 350 ) {
		if(  i < 350 ) return i/5;

		switch(weapon->query("material")) {
			case "wood":
			case "bamboo":
			case "paper":
					if( i > 450 ) i = 450;
if(me->query("quest/wdjiuyang/pass"))
i = i *15 /10;


					if( me->query_temp("jianjue") > 0 ) me->add_temp("jianjue", -1);

					if( me->query("quest/wdjiuyang/pass") && me->query_temp("jianjue") < 1 && damage_bonus > 100
					 && !victim->is_busy() /* && !victim->query_temp("lost_attack") && random(3)*/ )
                               

 {

						if( random(i) > 280
						 && random(me->query_dex()) > victim->query_con()/2 ) {
							me->add_temp("jianjue", 2);
							victim->add_temp("lost_attack", 1+random(3));
							message_vision(HIC"$NԽ��Խ���£���$n������ʽ����ɬ�ͣ�\n"NOR, victim, me);
                                                me->set_temp("tjj/super_hit", 1);  //���ӽ�ָ

							i = i*3/2;
                                                

						}
						else 	if( random(i) > 270
						 && random(me->query("combat_exp")) > victim->query("combat_exp")*2/5 ) {
							me->add_temp("jianjue", 2);
							victim->add_busy(1+random(2));
							if( !userp(victim) ) victim->add_busy(random(2));
							message_vision(HIW"$Nֻ����ȫ�����¶������������ƣ��·���׹���У���ʹ������ʩչ������\n"NOR, victim, me);
							i = i*3/2;
						}
						else 	if( random(i) > 260
						 && random(me->query_skill("sword")) > victim->query_skill("parry")/3 ) {
							message_vision(CYN"$n�Ľ�������Ⱥɽ֮�������磬���಻��������ƺƴ�ӣ�������Ϣ��"NOR, victim, me);
							me->add_temp("jianjue", 2);
							me->add_temp("apply/attack",  i/5);
							COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(5)?1:3);
							me->add_temp("apply/attack",  -i/5);
						}
						else 	if( random(i) > 250
						 && random(me->query_str()) > victim->query_con()/2 ) {
							me->add_temp("jianjue", 2);
							victim->receive_damage("qi", me->query_skill("sword")*3/2, me);
							victim->receive_wound("qi", me->query_skill("sword"), me);
							message_vision(HIB"$n�󿪴��أ��Ƶ��ۻ룬����̩ɽѹ��֮�ƹ���$NҪ����\n"NOR, victim, me);
						}
						else 	if( random(i) > 250
						 && random(me->query_int()) > victim->query_int()/3 ) {
							me->add_temp("jianjue", 2);
							victim->receive_damage("jing", me->query_skill("sword")*2/3, me);
							victim->receive_damage("jingli", me->query_skill("sword"), me);
							victim->receive_damage("neili", me->query_skill("sword")*2, me);
							message_vision(HIY"$Nֻ����ǰͻ�Ľ�����䣬����������ɽ�������鶯���𣬲�������һ�������ⰵ����\n"NOR, victim, me);
						}
					}
	
					if( weapon->query("weapon_prop/damage") < 40  )
						i += MIN(me->query_skill("force"),600) * 2 + (me->query("jiali") * (6+random(8)));
					else
						i += MIN(me->query_skill("force"),600) + (me->query("jiali") * (4+random(6)));

					break;
			default:
					if( i > 450 ) {
						if( random(i) > 300
						 && !victim->query_temp("lost_attack")
						 && !victim->is_busy()
						 && random(me->query_int(1)+me->query_dex(1)) > random(victim->query_int(1)*2) ){
							victim->add_temp("lost_attack", 1);
							message_vision(HIC"$NԽ��Խ���£���$p������ʽ����ɬ�ͣ�\n"NOR, victim, me);
							i += random(i);
						}
    						//i = i * 13/10;
						i += MIN(me->query_skill("force"),600) + (me->query("jiali") * (4+random(6)));
						break;
					}
					else {
						i = me->query_str(1);
						i -= random(i);
						break;
					}
		}
             
		if( wizardp(me) && (string)me->query("env/combat")=="verbose" )
			tell_object(me, GRN"TJJ i = "+i+" \n"NOR);
		return i;
	}
victim->delete_temp("must_be_hit");
}

int ob_hit(object ob, object me, int damage)
{
	object weapon, wp;
	string msg, wpname,*limbs;
	int ap, dp, j = 0, skill;

	if( ob->query("env/invisibility") ) return 0;

	if( me->query_skill("yinyun-ziqi", 1) < 80
	 || me->query_skill_mapped("force") != "yinyun-ziqi"
	 || me->query_skill_mapped("parry") != "taiji-jian"
	 || me->query("combat_exp") < ob->query("combat_exp")/2 ) return 0;

	if( skill = me->query_skill("taiji-jian", 1) < 80 ) return 0;

	if( me->query("neili") < ob->query("neili")/4 ) return 0;

	if( !objectp(wp = me->query_temp("weapon") )
	 || wp->query("skill_type") != "sword") return 0;

	if( skill > 350 || me->query_temp("tj/̫��") ){
		switch(wp->query("material")){
			case "wood":
    			case "bamboo":
    			case "paper":
				wp->add_temp("no_weapon_cut", 1); break;
			default: break;
		}
	}

	if( me->query_temp("fanzhen") ) {
		me->delete_temp("fanzhen");
		return 1;
	}

	if( objectp(weapon = ob->query_temp("weapon")) )
		msg = weapon->query("skill_type");
	else {
		mapping prepare = ob->query_skill_prepare();
		if (!sizeof(prepare)) msg = "unarmed";
		else msg = keys(prepare)[0];
	}

	ap = COMBAT_D->skill_power(ob, msg, SKILL_USAGE_ATTACK) / 100;
	if( !weapon ) ap *= 2;
	if( ob->query("neili") > me->query("neili") * 2 ) ap *= 2;

	dp = COMBAT_D->skill_power(me, "parry", SKILL_USAGE_DEFENSE) / 100;
	if( me->query_temp("tj/̫��") ) dp *= 2;
	if( random(10) < 3 ) me->set_temp("fanzhen", 1);

	ap = ABS(ap);
	dp = ABS(dp);

	if( skill > 550 ) dp = dp * 2 + random(dp) * 3;
	else if( skill > 450 ) dp = dp * 2 + random(dp);
	else if( skill > 350 ) dp = dp + random(dp) * 2;

	if( me->is_busy() ) dp /= 3;

	wpname = wp->name();

	if( random( dp ) > ap && !me->is_busy() ) {
		limbs = ob->query("limbs");
		if( weapon ) {
        		msg = parry_msg[random(sizeof(parry_msg))];
        		msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
        		msg = replace_string(msg, "$W", weapon->name());
        		msg = replace_string(msg, "$w", wpname);
         		message_vision(msg, ob, me);
		}
		else {
			msg = "$N����������"+wpname+"һ��������������$n����ʽǰ����";
			if( random(me->query_skill("taiji-jian", 1)) > ob->query_skill("parry") ){
				msg += "$n���һ�������������У��Լ������˷���֮�ϣ�\n";
				ob->receive_damage("qi", damage/3 , me);
				ob->receive_wound("qi", damage/3 , me);
				j = (int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi");
				msg += damage_msg(damage, "����") + "( $n"+eff_status_msg(j)+" )\n";
				msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
				msg = replace_string(msg, "$w", "����");
			}
			else msg += "$n���һ������æ����վ����\n";
			message_vision(msg, me, ob);
		}
		return -50000;
	}

	else if( random(ap + dp) > ap ) {
		if( weapon ) msg = "$N�鼱֮�½�"+wpname+"һ����ƽ����"+weapon->name()+"֮�ϣ���������ǧ��֮�ɾ�ж����$pһ���־�����\n";
		else msg = "$N��æ��"+wpname+"һ�ᣬ��ס��$nһ����������\n";
		j = -damage/2;
	}

	else if( random(ap + dp + dp) > ap ) {
		if( weapon ) msg = "$N�������ǣ���"+wpname+"��"+weapon->name()+"һ������ж��֮��ж����һЩ������\n";
		else msg = "$N��æ����"+wpname+"�ĳ����պ��Ŀ���$nһ���ֵľ�����\n";
		j = -damage/4;
	}

	else return 0;

	message_vision(msg, me, ob);
	return j;
}
