// hanbing-zhenqi.c ��������
// Created by Numa 1999
// Modified by Numa 2000.1.5
// Modified by Numa 2000.1.25
// Modified by darken@SJ
// Lklv@SJ 2001.10.22 modified

#include <ansi.h>
inherit FORCE;
#include "/kungfu/skill/force.h"
#include <combat.h>

int valid_enable(string usage) {
	  if (this_player()->query("family/family_name")=="��ɽ��"|| this_player()->query("cw_mp/��ɽ��") ) return usage == "force"; }

int valid_learn(object me)
{
	int i = me->query_skill("hanbing-zhenqi", 1);

		mapping fam  = me->query("family");
	if ((!fam || fam["family_name"] != "��ɽ��" )&& !me->query("cw_mp/��ɽ��") )
			 	return notify_fail("�㲢����ɽ�ɵ��ӣ����ϰ���˺���������\n");


	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");
	if ( i > me->query_skill("force", 1) + 10
	 && i >= 200 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");
        return 1;
}

void skill_improved(object me)
{
        int pl1,pl2;

        pl1 = me->query_skill("hanbing-zhenqi", 1);
        pl2 = me->query_skill("hanbing-shenzhang", 1);
        if (pl1>=220 && !me->query("ss/hbzq_220")){
                tell_object(me, HIW"\n��Ȼ����о����ں���Խ��Խʢ��ȫ���ƺ�������ѣ�����̹ǣ�\n"NOR);
                tell_object(me, HIW"\n����һ�ᣬ���ں����𽥾��ڵ��ﴦ��ȫ����Ϊ֮һ�񣬹�����Ϊ���������\n"NOR);
                me->delete("ss/hb_improve");
                me->add("max_neili", pl1 + random(pl2));
                me->set("ss/hbzq_220", 1);
        }
}

int ob_hit(object ob, object me, int damage)
{
	int skill, ap, dp, p;
	object weapon;
	string msg;

	skill = me->query_skill("hanbing-zhenqi", 1);
	
	if ( damage < 100 ) return 0;
	if ( me->query_temp("fanzhen")) {
		me->delete_temp("fanzhen");
		return 0;
	}

	if ( skill < 220
	 || me->query("combat_exp") < ob->query("combat_exp")/2
	 || me->is_busy()
	 || ! me->query_temp("hbzq/huti")) return 0;

	weapon = ob->query_temp("weapon");

	if(objectp(weapon))
		msg = weapon->query("skill_type");
	else {
		mapping prepare = ob->query_skill_prepare();
		if (!sizeof(prepare)) msg = "unarmed";
		else msg = keys(prepare)[0];
	}

	ap = COMBAT_D->skill_power(ob, msg, SKILL_USAGE_ATTACK) / 1000;
	dp = COMBAT_D->skill_power(me, "parry", SKILL_USAGE_DEFENSE) / 1000;

	if ( weapon && !me->query_temp("weapon")) ap *= 2;

	if ( me->query_temp("weapon"))
		dp = dp *2/3;

	if ( wizardp(me))
		tell_object(me, sprintf("ap = %d, dp = %d.\n", ap ,dp));

	if ( random(dp + ap) > ap && !random(3)) {
		msg = HIB"ͻȻ֮�䣬$n����һ�Σ�һ�����������˿���һ�Բ����ĵ�����$N��\n"+
			"$n���ӷ��������㲻���������Ǹ��˷���Ѩ��һ�㣬ԭ���Ǳ�$N�Ļ��庮���������ˡ�\n"NOR;
		ob->receive_damage("jing", skill * 2, me);
		ob->receive_wound("jing", skill, me);
		msg += COMBAT_D->damage_msg(damage, "����");
		if ( random(2))
			ob->add_condition("cold_poison", 5);
		else
			ob->add_busy(random(2));
		me->set_temp("fanzhen", 1);
		p = ob->query("eff_jing")*100/ob->query("max_jing");
		msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		message_vision(msg, me, ob);
		return -damage/(2+random(2));
	}
	return 0;
}

int practice_skill(object me)
{
	int i = me->query_skill("hanbing-zhenqi", 1);

	if (i >= 200){
		if (i < 220)
			return notify_fail("��ĺ������أ���Ҫ������������ˡ�\n");
		if ((int)me->query("potential", 1) > 5
		 && (int)me->query("neili", 1) > 200){
			me->improve_skill("hanbing-zhenqi", (int)me->query_int());
			me->add("neili", -100);
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else
			return notify_fail("�����ڵ���Ϊ��������ߺ��������ˡ�\n");
	}
	return notify_fail("�����ڵĺ���������Ϊֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
       return __DIR__"hanbing-zhenqi/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIW + me->name()+"���Ϻ������֣�������΢������" NOR,
		"start_my_msg" : "�����󽣾���������������������������ת����\n",
		"start_other_msg" : HIB + me->name()+"���˸���ϥ���������ƣ�ȫ��������һƬ����֮�ڡ�\n"NOR,
		"halt_msg" : "$N˫��һ��������ѹ����Ϣվ��������\n",
		"end_my_msg" : "�㽫��������������֮�ư�����һ�ܣ��о����������ˡ�\n"NOR,
		"end_other_msg" : HIW"ֻ��"+me->name()+"��������˫��վ�𣬻�?�ɢ����һ�ɱ���ĺ�����\n"NOR,
		"heal_msg" : HIW"$N���𺮱���������ʼ�����������ˡ�\n"NOR,
		"heal_finish_msg" : HIY"$N��Ϣһͣ��ȴ�������Ѿ�ȫ���ˡ�\n"NOR,
		"heal_unfinish_msg" : "$Nüͷһ�壬���ۡ����³�һ����Ѫ���������˻�û��ȫ�á�\n",
		"heal_halt_msg" : "$N��������Ϣһѹ��Ҳ�������ϵ���������վ��������\n",
		]);
}

