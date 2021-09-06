// qishang-quan.c ����ȭ
// Modifed damage by snowman@SJ 22/08/2000

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N�ڳ��б��ߣ����ּȿ��Һݣ��������죬һȭ��׼��$n���ϵ�$lֱ������",
	"lvl" : 0,
	"damage_type" : "����"
]),
([
	"action" : "$N������֮��������һ������$n�ֱۣ��������һȭ���ѽ��ʵʵ����$n$l",
	"lvl" : 20,
	"damage_type" : "����"
]),
([
	"action" : "$N��$n����˵������Ȼ��ȭ��ȥ��ֻ�����һ�����죬��һ�������Ǵ���$n$l��",
	"lvl" : 40,
	"damage_type" : "����"
]),
([
	"action" : "$Nȭ����磬���������ȭ��������$n���ϣ���ȴ�Ʋ���ʹ�������������壬��˿����",
	"lvl" : 60,
	"damage_type" : "����"
]),
([
	"action" : "$N˫Ŀ���࣬һ��ߺ�ȣ�����ƾ�մ��˸��������������У�һȭֱ������$n��$l֮��",
	"lvl" : 80,
	"damage_type" : "����"
]),
([
	"action" : "$N���˼�������������һ�����ֱ۹Ǹ�����죬��������һ����һȭ����$n$l",
	"lvl" : 100,
	"damage_type" : "����"
]),
([
	"action" : "$Nһȭ�����������ֱۣ��ַ�ȭ������һ����������ת��������ǰ��ͦȭ�ͻ�",
	"lvl" : 120,
	"damage_type" : "����"
]),
([
	"action" : "$N˫��һ��һ�ȭ����п�ɽ������һ���������ڣ�ֱ����$n��$n�ؿ�һ����ֻ��������Ż",
	"lvl" : 140,
	"damage_type" : "����"
]),
([
	"action" : "$N���һ����˫ȭ�������������δ��ȭ�ϰ�������ŭ�����࣬��Х���Ϯ��$n",
	"lvl" : 160,
	"damage_type" : "����"
]),
([
	"action" : "$N˫Ŀ΢�أ�����Ʈ������ƮƮ������ȭ��ȴ�ǰ����ϢҲ�ޣ�$n��ز��΢����壬ȭ��������Ϯ�����",
	"lvl" : 180,
	"damage_type" : "����"
]),
});

string  *msg = ({
"$Nһȭ������ȭ���о����и������ֲ�ͬ�ľ������ֻ�$n��ȫ��������ʮ����ҪѨ",
"$N����һ��������˫ȭƽ�죬����������������ȭ���������ֲ�֮ͬ������$n��$l",
"$NĬ���񹦣�˫ȭ�����޶���ͻȻ�ڿ����г������ֲ�ͬ�ľ�����Ȼ����$n��ǰ��",
"$N��ȭһ�գ�Ĭ����Ϣ�����ֲ�ͬ�������Ŵ����ȭ���ֵ��ֿ�Ļ���$n��$l",
"$Nȭ����磬���������ȭ��������$n���ϣ���ȴ�Ʋ���ʹ�������������壬��˿����",
"ֻ��$N˫Ŀ��������������Ȼ���͵Ĵ����һ�����������£��������ޱ�֮��������$n��ȫ��",
"$Nһ����Х��˫Ŀ��죬ȭ·�󿪴��أ�ÿһȭ������������ŭ��ʯ���쾪���Ժ������ڼ������Ĵ�����",
"$N�����ŵڶ�ȭ�ֳ�������Ѹ�����磬��Ŀ�������·���ε�һ�Σ�ȴֱ��$nǰ��",
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ( !me->query_skill("jiuyang-shengong"))
	if ( me->query_skill("shenghuo-shengong", 1) < 100)
                return notify_fail("���ʥ���񹦻�򲻹����޷�ѧ����ȭ��\n");
	if ( me->query("max_neili") < 1000)
		return notify_fail("�������̫�����޷�������ȭ��\n");
	if (!me->query("xie_qishang") && me->query_skill("qishang-quan", 1) > 50)
		return notify_fail("��û��ѧ��"HIR"����ȭ��"NOR"���޷��ټ�����ϰ����ȭ��\n");
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
	int i,j, level, neili, force, jiuyang;
	string msgs;
        
	level   = (int) me->query_skill("qishang-quan", 1);
	jiuyang = me->query_skill("jiuyang-shengong", 1);
	force = me->query_skill("force");
	neili = me->query("neili");
	me->delete_temp("qishang_hit", 1);

	if (level > 100 
	 && force > 150 
	 && neili > 500 
	 && random(jiuyang) > 50
	 && me->query("max_neili") > 1200
	 && me->query("jiali") > 100
	 && random(me->query_str(1)) > 15
	 && !me->query_temp("qsq/duanhun")){
		me->set_temp("qishang_hit", 1);
		return([      
			"action": msg[random(sizeof(msg))],
			"force" : 350 + random(250),
			"dodge" : random(30),
			"force" : random(30),
			"damage_type" : random(2)?"����":"����",
		]);
	}
	if( intp(j = me->query_temp("qsq/duanhun")) && j > 0 ){
		switch(j) {
			case 5: msgs =HIR"$N˫Ŀ��������������Ȼ���͵Ĵ����һ�����������ޱ�֮��������$n��ȫ��"NOR; break;
			case 4: msgs =HIR"$Nһȭ������ȭ���о����и������ֲ�ͬ�ľ������ֻ�$n��ȫ��������ʮ����ҪѨ"NOR;break;
			case 3: msgs =HIR"$Nһ����Х��˫Ŀ��죬ȭ·�󿪴��أ�ÿһȭ������������ŭ��ʯ���쾪"NOR ;break;
			case 2: msgs =HIR"$N���һ����˫ȭ�������������δ��ȭ�ϰ�������ŭ�����࣬��Х���Ϯ��$n"NOR;break;
			case 1: msgs =HIR"$N˫Ŀ΢�أ�����Ʈ������ƮƮ������ȭ��$n��ز��΢����壬ȭ��������Ϯ�����"NOR;break;
			default:msgs =HIR"$N˫Ŀ��������������Ȼ���͵Ĵ����һ�����������ޱ�֮��������$n��ȫ��"NOR; break;
		}
		if( me->query_temp("qsq/duanhun") > 1 )
			me->add_temp("qsq/duanhun", -1);
		return ([
			"action": msgs,
			"damage_type" : "����",
			"dodge": random(30),
			"parry": random(30),
			"force": 250 + random(350),
			"damage": 150 + random(100),
		]);
	}
	for(i = sizeof(action); i > 0; i--){
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 150 +random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("qishang-quan", 1);
	int i = sizeof(action);
	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}

void skill_improved(object me)
{
	object *ob;
	int i, skill;
	skill = me->query_skill("qishang-quan", 1);
	if(me->query("max_neili") < skill * 15 && skill < 200){
		switch(random(5)){
			case 0 : 
				tell_object(me, HIR"���ͷ����ѨͻȻһ����΢��ʹ���Ƿ������ˣ�\n"NOR);
				me->add("max_neili", -(30+random(70)));
				break;      
			case 1 : 
				tell_object(me, HIR"����������ѨͻȻ��ʹ�ѵ����Ǹ������ˣ�\n"NOR);
				me->add("combat_exp", -(2500+random(4000)) );
				break;
			case 2 : 
				message_vision(HIR"$N�������ˣ�ͻȻ���Դ󷢡��޷������ˣ�\n"NOR, me);
				ob = all_inventory(environment(me));
				for(i=0; i<sizeof(ob); i++) {
					if( ob[i]== me ) continue;
					if(!ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
				}
				break;
			case 3 : 
				tell_object(me, HIR"���ϱ�����ѨͻȻһʱ�����ѵ������������ˣ�\n"NOR);
				me->add("max_jingli", -(30+random(70)));
				break;
			case 4 : 
				tell_object(me, HIR"��ͻȻ�������������������н�ľˮ�������У��޷������ˣ�\n"NOR);
				me->set_skill("qishang-quan", skill-(2+random(3)));
				break;
		}
		me->unconcious();
	}
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	string msg;
	int lvl, i;
        
	if( damage_bonus < 100 ) return 0;
	if ( victim->query("job_npc")) return 0;

	lvl= me->query_skill("qishang-quan", 1);
	i = 1;

	if( random(lvl) > 50
	&& random(10) > 6
	&& me->query("jiali") > 5
	&& random( me->query("neili") ) > 500
	&& (me->query("neili") + me->query("con") * 30 ) > victim->query("neili") ){
		if( victim->query("neili")/2 < me->query("neili") )
			victim->add_condition("qishang_poison", 2);
/*
else
                        me->add_condition("qishang_poison", 1);
*/
	}

	if( random(10) > 5
	&& lvl >= 150
	&& !me->query_temp("qsq/duanhun")
	&& me->query("neili") > victim->query("neili")/3*2
	&& me->query("neili") > 1000
	&& me->query("max_neili") > 1500
        && random(me->query("combat_exp")) > victim->query("combat_exp") /3*2
	&& me->query("jiali") > 5 
	&& me->query_skill("jiuyang-shengong", 1)){
		me->add("neili", -50);
		switch(random(7)){
			case 0 :
				msg = MAG"$N��������ʹ������ȭ�ܾ��еġ�"HIR"���ľ�"MAG"����˫ȭһ�ɸ���֮����$n��ȥ��\n"NOR;
				victim->add_condition("qishang_poison", lvl/20 );
				break;
			case 1 :
				msg =HIB"$N����һ��������ȭ��ʹ������ȭ�ܾ��еġ�"HIR"�˷ξ�"HIB"����˫ȭƮ��������$n��ʱ�о�һ������֮��ӭ�������\n"NOR;
				victim->receive_damage("jing", lvl, me);
				victim->receive_wound("jing", lvl, me);
				break;
			case 2 :
				msg =HIC"$N��ȭ����ʹ������ȭ�ܾ��еġ�"HIR"�ݸγ���"HIC"����˫ȭ�������ᣬ��$n��ȥ��\n"NOR;
				victim->add("jingli", -lvl);
				break;
			case 3 :
				msg =HIG"$N��������ʹ������ȭ�ܾ��еġ�"HIR"�����"HIG"����˫ȭ�����иգ����һ������֮������$n��ȥ��\n"NOR;
				victim->add("neili", -lvl*2);
				if( victim->query("neili") < 0) 
					victim->set("neili", 0);
				break;
			case 4 :
				msg =HIY"$N��������ʹ������ȭ�ܾ��еġ�"HIR"��ʧ��"HIY"����˫ȭ����������������ֱ��$n��ȥ��\n"NOR;
				if( !victim->is_busy() )
					victim->start_busy(2 + random(2));
				else
					victim->add_temp("lost_attack", 2);
				break;
			case 5:
				msg =HIM"$N��������ʹ������ȭ�ܾ��еġ�"HIR"���㱾�"HIM"������$n�ͳ�һ�ɺ��֮����\n"NOR;
				message_vision(msg, me, victim);
				return lvl;
				break;
			case 6:
				msg =HIR"$N���һ�����뷢���ţ�ʹ���������ܾ���������˫ȭ����������������ٱ������$n��\n"NOR;
				victim->add_condition("no_perform", 2);
				victim->add_temp("lost_attack", 2);
				break;
		}
		msg +=HIW"$nֻ����$N��һȭ֮�й����߹ɲ�ͬ��������ðٶˣ���ԥ���ѱ������������ȫ�����ܶ�����\n"NOR;
		message_vision(msg, me, victim);
	}
}
