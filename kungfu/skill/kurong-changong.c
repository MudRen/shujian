// By Spiderii�޸ı�ǣ�����autoЧ��
#include <ansi.h>
#include <combat.h>

inherit FORCE;

#include "force.h"

string *xue_name = ({
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",});

mapping *action = ({
([
	"action": "$N�����������������޳���,������ת�����ƴ�в�������$w�����ľ�����$n��ȥ",
        "weapon" : "��Ե",
	"lvl" : 0,
	"skill_name" : "�����޳�",
	"damage_type": "����"
]),
([
	"action": "$N˫���������У��Ϻȣ����������ҡ�����������һ�����۳������һ����ǽֱ����$n",
	"lvl" : 40,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([
	"action": "$N˫�ƽ�����հ���,����һ�𣺡��������֡���һ����$n��$l��ȥ",
	"lvl" : 60,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([
	"action": "$NĴָ�������ģ�Ĭӽ���������޾���,������̧��������$n��$l��ȥ",
	"lvl" : 80,
	"skill_name" : "�����޾�",
	"damage_type": "����"
]),
([
	"action": "$Nһ����ȣ����Ǽٷǿա�,�����ĳ�һ����ɽ����������",
	"lvl" : 100,
	"skill_name" : "�Ǽٷǿ�",
	"damage_type": "����"
]),
([
	"action": "$N��Ц��Ц������һ�ƣ�����һ����һ����ת��������$n���Ű�Χ",
        "weapon" : "�Ʒ�",
	"lvl" : 120,
	"skill_name" : "�ǿݷ���",
	"damage_type": "����"
]),
([
	"action": "$N˫�ֺ�ʲ����������������١���˫�ƽ�������Ƴ����������ص�����ֱ����$n",
	"lvl" : 140,
	"skill_name" : "�������",
	"damage_type": "����"
]),
});

int valid_enable(string usage) {
	  if (this_player()->query("family/family_name")=="������"|| this_player()->query("cw_mp/������") ) return usage == "force" || usage=="strike" || usage =="parry"; }

void skill_improved(object me)
{
	int skill = me->query_skill("kurong-changong", 1);
	if( skill >= 200 && !me->query("kr_add")){
		me->set("kr_add", 1);
		tell_object(me, GRN"\n��Ȼ�������һ�������ɵ�����������\n"+
				"��һ����Ϊ�������λ���Ӱ��\n"+
				"����¶����磬Ӧ�����ǹۡ�\n"+
				"���������Ϊ����һ���µľ��磡\n"NOR);
		me->add("max_neili", skill+random(skill));
	}
}

string query_skill_name(int level)
{
	int i = sizeof(action);
	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me,object weapon)
{
	int i, level, j;
	level = (int) me->query_skill("kurong-changong",1);

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if( me->query_temp("pf_rong") && me->query("jiali") && random(2)) {
				return ([
					"action" : YEL+action[j]["action"]+NOR,
					"force" : 300 + random(200),
					"dodge": random(35),
					"parry": random(35),
					"damage": 40 + random(40),
					"damage_type" : "����",
				]);
			}
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"weapon": action[j]["weapon"],
				"force":150+random(300),
				"dodge":random(30),
				"parry":random(30),
			]);
		}
	}
}

int valid_learn(object me)
{
	int i, l;
	int t = 1, j;
	mapping myfam = (mapping)me->query("family");
	for (j = 1; j < i / 10; j++) t *= 2;

	i = (int)me->query_skill("kurong-changong", 1);
	l = (int)me->query_skill("buddhism", 1);

	if (i > 120 && i <180 && l < i - 10)
		return notify_fail("����������Ҫ���ķ�ѧ���裬��ķ�ѧ������\n");

	if (!me->query_skill("kurong-changong", 1))
	if (me->query_skill("qiantian-yiyang",1) < 140)
		return notify_fail("���Ǭ��һ������򻹲������޷�������������\n");

	if ( me->query_skill("qiantian-yiyang", 1)
	 && me->query_skill("kurong-changong", 1) > me->query_skill("qiantian-yiyang", 1))
	 	return notify_fail("�㲻ɢ��Ǭ��һ�������������ϰ����������\n");

	if ( me->query("gender") != "����" )
		return notify_fail("���ͯ��֮�壬������ϰ���������ڹ���\n");

	if ((me->query("class") != "bonze" || me->query("menggu"))&& !me->query("cw_mp/������") )
		return notify_fail("����ҷ���ӣ�������ϰ����������\n");

	if (me->query_skill("yiyang-zhi",1) < 140)
		return notify_fail("����������Ҫһ��ָ����Ϊ��ܡ�\n");

	if ((int)me->query_skill("kurong-changong", 1) > me->query_skill("force", 1) + 10
	 && me->query_skill("kurong-changong", 1) >= 200 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	if (( !mapp(myfam) || myfam["master_name"] != "���ٳ���")&& !me->query("cw_mp/������") )
		return notify_fail("�㱲�ݲ�������������ϰ����������\n");
	return 1;
}

int practice_skill(object me)
{
	if((int)me->query_skill("kurong-changong", 1) >= 200 ) {
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200) {
			me->improve_skill("kurong-changong", me->query_int());
			me->add("neili", -100);
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("�����ڵ���Ϊ��������߿��������ˡ�\n");
	}
	else return notify_fail("�����������������ϰ��\n");
}

string exert_function_file(string func)
{
	return __DIR__"kurong-changong/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIG + me->name()+"�����ɬ֮����˫Ŀ�ʹ�����" NOR,
		"start_my_msg" : "����ϥ���£���Ŀ��ʲ��Ĭ�˿���������ֻ����������������ʼ�����ڻ����ζ���\n",
		"start_other_msg" : me->name()+"��ϥ���£���Ŀ��ʲ�������ƺ�������һ������֮�С�\n",
		"halt_msg" : "$N˫��һ�֣�������ȭ����������Ѹ�ٽ������ڡ�\n",
		"end_my_msg" : "������������������һ�����죬�����������ڵ������̧�����۾���\n",
		"end_other_msg" : "ֻ��"+me->name()+"���������۾����������ֵ���������ȥ��\n"
	]);
}

int ob_hit(object ob, object me, int damage)
{
	string msg;
	int ap, dp, j, neili, neili1;
	object weapon;

	if( damage < 100) return 0;

	neili = me->query("neili");
	neili1 = ob->query("neili");
/*
	if(me->query_temp("kurong-changong")) {
		me->delete_temp("kurong-changong");
		return 0;
	}

	if( me->query_temp("fanzhen")) {
		me->delete_temp("fanzhen");
		return 0;
	}
*/
	if (me->query_skill("parry") < 300
//	 || me->query_skill_mapped("parry") != "kurong-changong"
	 || me->query_skill_mapped("force") != "kurong-changong"
	 || me->query("combat_exp") < ob->query("combat_exp")/2
	 || neili < 400 ) return 0;

	weapon = ob->query_temp("weapon");

	if(objectp(weapon))
		msg = weapon->query("skill_type");
	else {
		mapping prepare = ob->query_skill_prepare();
		if (!sizeof(prepare)) msg = "unarmed";
		else msg = keys(prepare)[0];
	}

	ap = COMBAT_D->skill_power(ob, msg, SKILL_USAGE_ATTACK) / 1000;
	if ( weapon ) ap *= 2;
	if ( ob->query("neili") > me->query("neili") * 2 ) ap += ap/2;
        
	dp = COMBAT_D->skill_power(me, "parry", SKILL_USAGE_DEFENSE) / 1000;
	if ( me->is_busy() ) dp /= 2;   
	if ( me->query("neili") > ob->query("neili") * 2 ) dp *= 2;  
	else if ( me->query("neili") > ob->query("neili") / 2 * 3 ) dp += dp/2;
         
	if ( random(10) < 3 ) me->set_temp("fanzhen", 1);

	ap = ABS(ap);
	dp = ABS(dp);

	if ( me->query_temp("krcg_kurong"))
		dp += ap/2 + random(ap/2);

	if ( wizardp(me))
		tell_object(me, sprintf("ap: %d, dp: %d\n", ap, dp));

        if( random(dp) > ap || ( userp(me) && me->query_skill("kurong-changong",1) >= 600 ) ) {
		msg = WHT "$NĬ�˿��������ġ��ݡ��ִ󷨣�������ӵ�����͸������������ȫ��������$N���������ϡ�\n" NOR;
		tell_object(ob, HIG "��ֻ������ͻȻ����һ�࣬���������ӭ��������\n" NOR);
		msg +=WHT "$nһ�д���$N�����ϣ�ֻ���ƺ�����һ����ľ�ϡ�\n"NOR;
		if(neili >= neili1*2 + random(damage)) {
			msg +=WHT "���$n�Ĺ�����$N�Ŀ������������ˣ�\n"NOR,
			j = -damage;
		}
		else if( neili > neili1 + random(damage) ) {
			msg += WHT"���$n�Ĺ�����$N������һ�룡\n"NOR,
			j = -damage/3*2;
		}
		else {
			msg += WHT"���$Nֻ������$n��һС��������\n"NOR,
			j = -damage/3;
		}
		message_vision(msg, me, ob);
		return j;
	}
}
