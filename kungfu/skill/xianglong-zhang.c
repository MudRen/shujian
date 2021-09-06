// xianglong-zhang.c ����ʮ����
// Rebuild By looklove 2001.4.6
// Modify by looklove 2001.5.2 for rumo
// Modify by Looklove 2001.5.6 for slbw
// Modify by Looklove 2001.7.20 for fz
// Modify at 2001.10.05 for bxsj
// Modify By lsxk@hsbbs 2007/7/13 add no_fight condition

#include <ansi.h>
inherit SKILL;
#include <combat.h>

string *parry_msg = ({
"$n�����������С�������β�������Ʒ�����$N���������׺ݣ�����Ӳ�ӣ�����ܿ���\n",
"ֻ��$n����Բ��������ֱ�ƣ�������ǰ��һ�д��Ƿ�����ȴ����˫��֮�䲼��һ����ڡ�\n",
"$n���²��ҵ�����˫�Ƶ���ƽ�ƣ����Լ�ȫ������������֮�¡��ص�����Ԩͣ���ţ����ް��������\n",
"$nֻ���Է�����֮ǿ�޷����ܣ�����֮�£�$n˫��һ�գ����һ����˫�����Ӳ����$N��һ�С�\n",
"$n����һת�����Ƽܿ���$N��������ʽ�����ư��������䣬�Ż�������\n",
"$n���г��񣬱�����$N����ʽ��˫��һ�ģ�����һЦ�䣬�ѷ�ס�˶Է�����ʽ��\n",
});

string query_parry_msg(object weapon, object victim)
{
	if( victim->query_temp("weapon")
	 || victim->query_skill("xianglong-zhang", 1) < 100
	 || victim->query_skill_prepared("parry") != "xianglong-zhang" )
		return SKILL_D("parry")->query_parry_msg(weapon);
	else
		return parry_msg[random(sizeof(parry_msg))];
}

mapping *action = ({
([
	"action": "$N˫��΢����˫��ƽƽ�ᵽ��ǰ���ұۻ���ԲȦ������һ����ʹ������ʮ���Ƶĵ�һ�С������лڡ�����$n",
	"lvl" : 0,
	"skill_name": "�����л�",
	"damage_type": "����"
]),
([
	"action": "����$N���ƻ��أ�����һ�࣬��ת����$n�����ƽ�����һ�ڣ�һ�С�������β����������$n",
	"skill_name": "������β",
	"lvl" : 10,
	"damage_type": "����"
]),
([
	"action": "����$Nһ��δ�꣬һ���������ƻ��ջ��أ��������Һ��ƶ���������һ�С����������Ѹ���ޱȵ�����$n��$l",
	"lvl" : 20,
	"skill_name": "��������",
	"damage_type": "����"
]),
([
	"action": "$N�������������˫������ƽ�ƣ�ʩ�����轥��½�������������ƽ����ʵ����������ȴ���������ķ���������ѹ��$n",
	"lvl" : 30,
	"skill_name": "�轥��½",
	"damage_type": "����"
]),
([
	"action": "$N���ƾ۳�ȭ״��һʽ�ڴ���$n���ֱۣ����Ž�����ǰ����Ѹ���Ƴ�������һ�С�Ǳ�����á��������ۻ�ӿ��$n",
	"lvl" : 40,
	"skill_name": "Ǳ������",
	"damage_type": "����"
]),
([
	"action": "��������$N������ǰ�������������������һ�С�����󴨡����⽵�����Ʒ��絶���У�Ѹ���ޱȵؿ���$n��$l",
	"weapon" : "�������Ʒ�",
	"skill_name": "�����",
	"lvl" : 50,
	"damage_type": "����"
]),
([
	"action": "$N˫���ಢ������ͻȻǰԾ��ʹ����ͻ�����������У�������ɽ��������$n�����Ƴ������޿ɱ�",
	"skill_name": "ͻ������",
	"lvl" : 60,
	"damage_type": "����"
]),
([
	"action": "ͻ��$N��Ȼ���һ�����й����Ŵ󿪣�˫��һ��һ�������������˵ľ�������һ�е�ն��$n������һ�С��𾪰��",
	"skill_name": "�𾪰���",
	"lvl" : 70,
	"damage_type": "����"
]),
([
	"action": "$N��ǰһ����һ�С���Ծ��Ԩ��������˫����$n�����ĳ���һ�˽���һ�ˣ��Ʒ�������������ɳʯ",
	"skill_name": "��Ծ��Ԩ",
	"lvl" : 80,
	"damage_type": "����"
]),
([
	"action": "$N������ǰ�ƶ���˫�Ʒ�ʹ��ʽ��˫��ȡˮ�����������Ʒ�һ��һ�ң���ȴ�����Ⱥ�ͬʱѹ��$n$l",
	"skill_name": "˫��ȡˮ",
	"lvl" : 90,
	"damage_type": "����"
]),
([
	"action": "$N���΢�������η����ڰ�����ĳ�����Ծ��Ԩ����˫����������һ����ƾ�����$n��$l����",
	"weapon" : "����",
	"skill_name": "��Ծ��Ԩ",
	"lvl" : 110,
	"damage_type": "����"
]),
([
	"action": "$N��������ʹ��һ�С�ʱ����������˫��һ��һ����һ��һ�£�һǰһ����$n���������������ҿ�������",
	"skill_name": "ʱ������",
	"lvl" : 130,
	"damage_type": "����"
]),
([
	"action": "$Nʹ��һ�С����Ʋ��꡹�����ƽ����������ĳ������������ס$n�˵���·�����Ƹ���бб������$n��$l",
        "weapon" : "����������",
	"skill_name": "���Ʋ���",
	"lvl" : 140,
	"damage_type": "����"
]),
([
	"action": "$N������ǰ��ʹ��һ�С��������ڡ���˫�ƿ��������������$n�����������������ϵ�ɳʯ�������裬��ʵǱ����С",
	"skill_name": "��������",
	"lvl" : 160,
	"damage_type": "����"
]),
([
	"action": "$N����һת��ͻȻ����$n��ǰ������бת��סȫ�������˾�һ�С���ս��Ұ������Ȼ����$n��$l",
	"weapon" : "��Ե",
	"skill_name": "��ս��Ұ",
	"lvl" : 170,
	"damage_type": "����"
]),
([
	"action": "$Nһ�����ȣ���ǰ�Ż��󿪣�˫���ಢ������$n�͵���ȥ������һ�����յġ���˪�����������Լ������ض�����",
	"skill_name": "��˪����",
	"lvl" : 180,
	"damage_type": "����"
]),
([
	"action": "$N���Ƶʹ�������̧�ߣ�ʹ��һ�С�����ެ���������ۻ�����������һ��һ��ͬʱ���м��$n��ѹ��ȥ",
	"skill_name": "����ެ",
	"lvl" : 190,
	"damage_type": "����"
]),
([
	"action": "$NͻȻһԾ�����գ����μ�����ת���Ӹ����£�˫��ʹ��һ�С��������졹����������ӿ�����ֱ�����µ�$nѹȥ",
	"lvl" : 200,
	"skill_name": "��������",
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("������ʮ���Ʊ�����֡�\n");
	if( (string)me->query("family/master_name") != "���߹�" )
		return notify_fail("����ʮ����ֻ�ܴӺ��߹���ѧ����\n");
	if( (int)me->query_skill("huntian-qigong", 1) < 100 )
		return notify_fail("��Ļ���������򲻹����޷�������ʮ���ơ�\n");
	if( me->query("gender") == "����" )
		return notify_fail("��һ�����в�Ů֮������ѧϰ�����ƣ�\n");
	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("�������̫�����޷�ѧ����ʮ���ơ�\n");
	if( (int)me->query_str(1) < 27 )
		return notify_fail("��û����׳�ı����޷�ѧ����ʮ���ơ�\n");
	if( (int)me->query_con(1) < 26 )
		return notify_fail("��û���ۺ�������޷�ѧ����ʮ���ơ�\n");
	return 1;
}

string query_skill_name(int level)
{
	int i = sizeof(action);
	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, j, pw, lvl, tmp, deads, m;	
	
	lvl = (int)me->query_skill("xianglong-zhang", 1);
	if( lvl > 300 ) lvl = 300;
	tmp = 2 + random(lvl/5);
	if( tmp < 10 ) tmp = 5 + random(5);
	if( tmp > 99 ) tmp = 99;
	pw = (int)me->query("xlz/power");

	deads = (int)me->query("death_times");
	deads -= 100;
	deads = deads/3 + random(deads/2);

	if( me->query("combat_exp") < 1000000 ) m = 30;
	else if( me->query("combat_exp") < 3000000 ) m = 60;
	else if( me->query("combat_exp") < 5000000 ) m = 90;
	else if( me->query("combat_exp") < 7000000 ) m = 120;
	else if( me->query("combat_exp") < 9000000 ) m = 150;
	else m = 180;

	if( deads < 0 ) deads = 0;
	if( deads > m ) deads = m;

	if( me->query_temp("shuangjue/xlz") ) {
		string msg;		
		switch(me->query_temp("shuangjue/xlz")) {
			case 2: msg = HIR"ֻ��$N��һ��������ǰ��������ͻȻ���У��������Ю���Ʒ���$n��$l��ȥ"NOR; break;
//			case 1: msg = HIM"��Ӱһ�գ�$nֻ�����ۻ����ң�ֻ��$Nһ����ȣ����������ģ�����"NOR; break;
			case 1: msg = HIY"$N���Ȱ������ϣ������ϲ������һ������Ȼһ���ĳ����˵��Ǹɾ�����"NOR;break;
			default: msg = HIR"ֻ��$N��һ��������ǰ��������ͻȻ���У��������Ю���Ʒ���$n��$l��ȥ"NOR; break;
		}
		me->add_temp("shuangjue/xlz", -1);
		return ([
			"action": msg,
			"dodge":  random(30),
			"parry":  random(30),
			"damage": 50 + random(50),
			"force":  random(deads)+300+random(200),
			"damage_type": "����"
		]);
	}

	if( me->query_temp("slbw") ) {
		me->delete_temp("slbw");
		return ([
			"action" : HIC"����$NӲ����$p��һ�У����ƽ��������һ�ڣ�һ�С�������β�����䲻��ذ�����$n��$l�ϣ�"NOR,
			"force" : me->query("gender")=="����"?600:450,
			"dodge":  me->query("gender")=="����"?30:20,
			"parry":  me->query("gender")=="����"?30:20,
			"damage_type" : "����",
		]);
	}
	else if( me->query_temp("xlz/hanglong") ) {
		me->delete_temp("xlz/hanglong");
		return ([
                   "action": HIR"\n$N�е��������У�������΢�������ƻ��˸�ԲȦ��ƽ�Ƴ�ȥ�����ǽ���ʮ�����еġ������лڡ�!"NOR,
			"dodge": -30 + 10 * tmp,
			"parry": -25 + 10 * tmp,
			"strike": 10 + 10 * tmp, 
			"force": 500 + 20 * tmp,
			"damage": 50 + 10 * tmp,
			"damage_type": random(2)?"����":"����"
		]);
	}

	else if( (int)me->query_temp("xlz/py_power") > 0 ) {
		string msg;
		if( random(3) )
			msg = HIR"$nֻ����Ϣ���ͣ�$N��������ŭ����ӿ���Ʋ��ɵ�����ͬһ�����ε���ǽ���������"NOR;
		else
			msg = HIR"��ʱ�䣬ֻ����ؼ��ɳ��ʯ��$n��ǰ�·�ɽ�����ѣ�ֻ���ö��ߺ�����ҡҡ��׹��"NOR;
		me->add_temp("xlz/py_power", -1);
		return ([
			"action": msg,
			"force" : me->query("gender")=="����"?600:450,
			"dodge":  me->query("gender")=="����"?30:20,
			"parry":  me->query("gender")=="����"?30:20,
			"damage_type" : "����",
		]);
	}

	//force add 50 
	for(i = sizeof(action); i > 0; i--) {
		if( lvl > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, lvl/5);
			if( me->query_temp("xlz/xiao") && me->query("jiali") >= 50 )
				return ([
					"action" : HIY+action[j]["action"]+NOR,
					"force" :  me->query("gender")=="����"?500+random(350):380+random(350),
					"dodge": random(30)+10,
                                   "damage": 300+random(50),
					"parry": me->query("gender")=="����"?30:10,
					"lvl" : action[j]["lvl"],
					"weapon" : action[j]["weapon"],
					"damage_type" : action[j]["damage_type"],
				]);
			else if( (me->query("xlz/super") || me->query_temp("xlz/super") ) && random(10) > 5 )
				return ([
					"action" : HIW+action[j]["action"]+NOR,
					"force" : me->query("gender")=="����"?450+random(350):350+random(320),
					"dodge": me->query("gender")=="����"?random(30):random(30)-5,
					"parry": me->query("gender")=="����"?random(30):random(25),
					"lvl" : action[j]["lvl"],
					"weapon" : action[j]["weapon"],
					"damage_type" : action[j]["damage_type"],
				]);
			else if( random(pw) > 5 || me->query_temp("xlz/power"))
				return ([
					"action" : HIC+action[j]["action"]+NOR,
					"force" : me->query("gender")=="����"?450+random(350):350+random(320),
					"dodge": me->query("gender")=="����"?random(30):random(30)-5,
					"parry": me->query("gender")=="����"?random(30):random(25),
					"lvl" : action[j]["lvl"],
					"weapon" : action[j]["weapon"],
					"damage_type" : action[j]["damage_type"],
				]);
			else return ([
					"action" : action[j]["action"],
					"force" : me->query("gender")=="����"?250+random(350):230+random(320),//250-50 /5*4
					"dodge":  random(30)-10,
					"parry": random(20),
					"lvl" : action[j]["lvl"],
					"weapon" : action[j]["weapon"],
					"damage_type" : action[j]["damage_type"],
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = (int)me->query_skill("xianglong-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if( me->query("jingli") < 50 )
		return notify_fail("�������̫���ˡ�\n");
	if( me->query("neili") < 20 )
		return notify_fail("�����������������ʮ���ơ�\n");
	me->receive_damage("jingli", 40);
	me->receive_damage("neili", 15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xianglong-zhang/" + action;
}

void skill_improved(object me)
{
	int lvl, x;

	lvl = me->query_skill("xianglong-zhang", 1);
	x = me->query_int();
	if( wizardp(me) ) lvl +=300;

	// ף���߻���ħ :)
	if( random((int)me->query("xlz/zouhuo") ) > 20
	 && random(lvl) > 300
	 && !me->query("xlz/super")
	 && random((int)me->query("neili")) > 8000
	 && random(x)< 5 ) {
		me->add("xlz/zouhuo",-2);
		me->add("max_neili",-5);
		me->add("xlz/rumo",1);
		me->set_temp("xlz/rumo",1);
		message_vision(HIR"$N��Ȼ�о�˫�ֲ���ʹ����һ��ǿ���������������Ҵڣ��þò�ƽϢ������$N�������Ѿ������ۿۡ�\n"NOR, me);
		tell_object(me, HIR"\nͨ���ڹ����ƣ���Ŀǰ�߻���ħ�Ĵ����½�����"+me->query("xlz/zouhuo")+" �Ρ�\n"NOR);
		log_file("skills/xlz",sprintf("%8s%-10s��%5d����ħ�۳�5�������������ǰ���飺%d��\n",
                    me->name(),"("+me->query("id")+")",me->query("xlz/zouhuo"),me->query("combat_exp")), me);
	}

        // Power ����Ļ���
	else if ( random(lvl) > 300
	 && lvl < 400
	 && random(x)>20
	 && !me->query("xlz/super")
	 && !me->query_temp("xlz/super")
	 && random(me->query_str()) > 25
	 && random((int)me->query("neili")) > 7000
	 && random(35)==1
	 && !me->query_temp("xlz/rumo") ) {
		message_vision(HIW"$N�о�����·���ʹ�����������$N�Ľ���ʮ���ƹ������˺ܴ���ߣ�\n"NOR, me);
		if( (int)me->query("xlz/power") < 20 )
			me->add("xlz/power",1);
		if( !me->query("xlz/power") )
			me->set("xlz/power",1);
		me->set_temp("xlz/power",1);
		me->add("max_neili", x/3 + random(lvl/50));
		log_file("skills/xlz",sprintf("%8s%-10s������Power���𡣵�ǰ�������%d����ǰ���飺%d��\n",
                    me->name(),"("+me->query("id")+")",me->query("max_neili"),me->query("combat_exp")), me);
        }

	if( random(lvl) > 450
	 && me->query("con") > 20
	 && random(x) > 30
	 && !me->query("xlz/super")
	 && !me->query_temp("xlz/power")
	 && (string)me->query("gender")=="����"
	 && me->query("xlz/zouhuo")
	 && !me->query_temp("xlz/zouhuo")
	 && random(40)==1 ) {
		message_vision(HIR"ͻȻ�䣬$N�о�˫�Ʒ��ȣ�˫�ֲ���ʹ��������������\n"NOR, me);
		// ���ϵ�· grin
		if( me->query_skill("huntian-qigong") < 100 ) {
			me->start_busy(10);
			if( (int)me->query("max_neili") > 100 )
			me->add("max_neili",-30);
                	me->add("xlz/zouhuo",1);
			me->set_temp("xlz/zouhuo",1);
			// û�л���������������ȥ���� !
			if( random(5)==1 ) {
				me->set_temp("last_damage_from","ǿ������ʮ�����߻���ħ��");
				me->die();
			}
			else {
				message_vision(HIR"$N���˺ô󾢲Ž��Ҵڵ��ھ����˻����������߻���ħ��$N�����Լ��þò��ܶ�����\n"NOR, me);
				tell_object(me, HIR"\n��Ŀǰ�Ѿ���"+me->query("xlz/zouhuo")+" ����Щ�߻���ħ��\n"NOR);
				log_file("skills/xlz",sprintf("%8s%-10s��%5d����Щ�߻�۳�30�������������ǰ���飺%d��\n",
					me->name(),"("+me->query("id")+")",me->query("xlz/zouhuo"),me->query("combat_exp")), me);
			}
		}
		// Super ��������
		else if( random((int)me->query_con()) > 60 && random((int)me->query("neili")) > 13500 ) {
			me->set("xlz/super",1);
			me->add("max_neili", x + random(lvl/4));
			me->delete("xlz/zouhuo");
			me->delete("xlz/rumo");
			message_vision(HIW"$N���յ����˫�����Ҵڵ��ھ����˻������о������������̲�ס������Х��\n"NOR, me);
			log_file("skills/xlz",sprintf("%8s%-10s������Super���𡣵�ǰ�������%d����ǰ���飺%d��\n",
				me->name(),"("+me->query("id")+")",me->query("max_neili"),me->query("combat_exp")), me);
                }
                // �߻���ħ
		else {
			me->start_busy(10);
			if( (int)me->query("xlz/zouhuo") < 100 )
				me->add("max_neili",-2);
			me->add("xlz/zouhuo",1);
			me->set_temp("xlz/zouhuo",1);
			message_vision(HIR"$N���˺ô󾢲Ž��Ҵڵ��ھ����˻����������߻���ħ��$N�����Լ��þò��ܶ�����\n"NOR, me);
			tell_object(me, HIR"\n��Ŀǰ�Ѿ���"+me->query("xlz/zouhuo")+" ����Щ�߻���ħ��\n"NOR);
			log_file("skills/xlz",sprintf("%8s%-10s��%5d���߻�۳�2�������������ǰ���飺%d��\n",
				me->name(),"("+me->query("id")+")",me->query("xlz/zouhuo"),me->query("combat_exp")), me);
                }
        }
}

int ob_hit(object ob, object me, int damage)
{
	int i, p, x, neili, lvl, jl, ap, dp;
	object wp, twp;
	string msg;

	lvl = (int)me->query_skill("xianglong-zhang", 1);
	wp = me->query_temp("weapon");
	twp = ob->query_temp("weapon");
	x = (int)me->query("xlz/power");
	ap = (int)me->query("combat_exp");
	dp = (int)ob->query("combat_exp");

	if( me->query_temp("fanzhen")) {
		me->delete_temp("fanzhen");
		return 0;
	}

	if( objectp(wp) || me->is_busy() ) return 0;
	if( me->query_skill_prepared("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("parry") != "xianglong-zhang" )
		return 0;

// ���� ,hehe
	if( random(me->query_con(1) + x ) > ob->query_con(1)/2
	&& random(ap) > dp/3
	&& random(lvl) > 200
	&& random(me->query("neili")) > 1000
	&& userp(me)
	&& random(2) ) {
		me->set_temp("xlz/fz", 1);
		if( objectp(twp) ) {
			msg = HIR"$N����һ����ͻȻ����һ������Ե�ⷭ���˾���" + twp->name() + HIR"�ϱ��ġ�\n"NOR;
			if( me->query_str(1) > ob->query_str(1)*2/3
			 && random(me->query("neili")) > ob->query("neili") / 3 ) {
				msg += HIR"$nֻ���û��ڷ��飬����" + twp->name() + HIR"��Щ���ֶ�����\n"NOR;
				ob->add_busy(1+random(2));
				damage = -6000;
			}
			else {
				msg += HIR"$n��һ�ϵ�$N�д�һ�У�" + twp->name() + HIR"���һ�У����˿�ȥ��\n"NOR;
				damage = -4000;
			}
			message_vision(msg, me, ob);
		}
		else {
			msg = HIR"$N�ۼ���һ�����޴��ɱܣ�˫��һ����ֱ��$n���ţ��õľ������ܾ��˵Ĵ򷨡�\n"NOR;
			if( random(me->query_str(1)) > ob->query_str(1)/2
			 && random(me->query("neili")) > ob->query("neili")/4 ) {
				msg += HIR"$n����ʽ�Ѿ����ϣ��޷��ջأ�����֮��ֻ�ú�$NӲƴ��һ�С�\n"NOR;
				damage = 10 + damage/2;
				ob->receive_damage("qi", damage/2, me);
				ob->receive_wound("qi", damage/5, me);
				p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
				msg += COMBAT_D->damage_msg(damage, "����");
				msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
				me->add("neili",-50);
			}
			else if( random(me->query_con(1)) > ob->query_str(1)/2
			 && random(me->query("neili")) > ob->query("neili")/2 ) {
				msg += HIR"$n���һ�������ã�������æ���л�ס��ǰ�Ŀ��š�\n"NOR;
				ob->add_busy(random(2));
				damage = -5000;
			}
			else {
				msg += HIR"$n���һ������Ͼ����$N����æ����ܿ�$N���Ʒ硣\n"NOR;
				damage = -4000;
			}
			message_vision(msg, me, ob);
        	}
		me->delete_temp("xlz/fz");
		me->set_temp("fanzhen", 1);
		return damage;
	}

/*	// ���ţ��͹�����, grin Quest ��ʱ�ر�
	if( !objectp(twp)
	 && random(ap) > dp/2
	 && random(lvl) > 50
	 && lvl > 100
	 && random(me->query("neili")) > 1000 ) {
		i = me->query_skill("parry", 1);
		me->add("neili",-100);
		me->set_temp("xlz/3hit",1);
		damage = -damage;

         	if(!me->query_temp("xlz/xiao")){
         		me->set_temp("xlz/xiao", 1);
         		me->add_temp("apply/parry", i/5);

         		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

         		me->delete_temp("xlz/xiao");
         		me->add_temp("apply/parry", -i/5);
         	}
         	else if (!me->query("xlz/super")){
         		me->set_temp("xlz/super", 1);
         		me->add_temp("apply/strength", i/15);
         		me->add_temp("apply/parry", i/15);
         		me->set_temp("double_attack", 1);

         		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);

         		me->delete_temp("double_attack");
         		me->delete_temp("xlz/super");
         		me->add_temp("apply/strength", -i/15);
         		me->add_temp("apply/parry", -i/15);
         	}
		else {
			me->set_temp("xlz/power", 1);
			me->add_temp("apply/strength", i/20);
			me->add_temp("apply/parry", i/10);

			COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);

         		me->delete_temp("xlz/power");
         		me->add_temp("apply/strength", -i/20);
         		me->add_temp("apply/parry", -i/10);

         	}
         	me->delete_temp("xlz/3hit",1);
         	me->set_temp("fanzhen", 1);
         	return damage;
         }
*/
// slbw
	if( !objectp(twp)
	 && random(me->query_str(1)) > ob->query_str(1)/2
	 && random(ap) > dp/2
	 && random(lvl) > 200
	 && me->query("neili") > 800
	 && me->query("qi") < me->query("max_qi")/2
	 && userp(me)
	 && random(3) ) {

		i = me->query_skill("parry", 1);
		jl = me->query("jiali");
		neili = me->query("neili");

		me->set_temp("slbw", 1);
		ob->set_temp("slbw_hit", 1);
		me->set("jiali", me->query_skill("force") + 200);

		me->add_temp("apply/attack", lvl/2);
		me->add_temp("apply/strength", i/4);
		me->add_temp("apply/parry", i/5);
		me->set("slbw", jl);
		damage = -damage;

		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 3);

		if( me->query("neili") < neili )
			me->set("neili", neili-100);
		me->set("jiali", me->query("slbw"));
		ob->delete_temp("slbw_hit");
		me->delete("slbw");
		me->delete_temp("slbw");

		me->add_temp("apply/attack", -lvl/2);
		me->add_temp("apply/strength", -i/4);
		me->add_temp("apply/parry", -i/5);
		me->set_temp("fanzhen", 1);
		return damage;
	}
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int i;

//	paiyun �ص�����׷��

	if( !me->query("paiyun_power") ) return;
	if( !me->query_temp("xlz/py_add") ) return;

	me->add_temp("xlz/py_add", -1);

	if( damage_bonus < me->query_skill("strike")*3 ) return;
	message_vision(HBRED"$Nǰ������δ�������������ֵ���$n��֮�£����Ƴ�ӭ����ʱ�۶����۽�Ǿ��顣\n"NOR, me, victim);
	i = me->query_skill("strike") * (2+random(3));
   victim->set_temp("no_fight",1);
   victim->apply_condition("no_fight",3);
	if( i > damage_bonus*2/3 ) i = damage_bonus*2/3;
	return i;
}

int help(object me)
{
	write(HIW"\n����ʮ���ƣ�"NOR"\n");
	write(@HELP
	����ʮ���ƣ�Ϊؤ�������ഫ���֮����������ƥ������Ҹ���һ��Ĺ���
	��������ʱ�ı�������ȫ��һ�����������ҡ��ų�������Ե��Ŀ��֡�

	ѧϰҪ��
		���������ȼ� 100 ���ϣ�
		���� 1000 ���ϣ�
		�������� 27 ���ϣ�
		������� 26 ���ϣ�
		�ɺ��߹��״�������պ�ɵá�
HELP
	);
	return 1;
}
