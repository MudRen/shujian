// huashan-jianfa.c ��ɽ����
// modified by darken@SJ
// Update by lsxk@hsbbs 2007/7/26

inherit SKILL;
#include <combat.h>
#include <ansi.h>
mapping *action_male = ({
([
	"action" : "$Nһ�С����Ƴ�ᶡ�����һ�����ԣ���ʱ����һƬ������$w���Ե���$n��$l",
	"lvl" : 0,
	"skill_name" : "���Ƴ��",
	"parry":0,
	"damage_type" : "����"
]),
([
	"action" : "$Nʹ�����з����ǡ������Ʒ����������ӯ�鶯��$w��˸����������$n��$l",
	"lvl" : 10,
	"skill_name" : "�з�����",
	"parry":10,
	"damage_type" : "����" 
]),
([
	"action" : "$Nһ�С������������������ߣ�$w���϶��»���һ���󻡣���$n������ȥ",
	"lvl" : 30,
	"skill_name" : "������",
	"parry":10,
	"damage_type" : "����"
]),
([
	"action" : "$N��ǰ����һ��������$w�������ƼȻ�����������������$NͻȻ����һת��ʹ�����׺���ա�ֱ��$n��$l",
	"lvl" : 50,
	"skill_name" : "�׺����",
	"parry":0,
	"damage_type" : "����"
]),
([
	"action" : "$N���е�$wһ�Σ��������ߣ�һ������������һƬ��Ӱ��һ�С�����ӭ�͡�ֱ��$n��$l",
	"lvl" : 80,
	"skill_name" : "����ӭ��",
	"parry":30,
	"damage_type" : "����"
]),
([
	"action" : "$N����$wб�η�����һʽ���ޱ���ľ������һ�³��м��죬����������ã�ֱ��$n��$l",
	"lvl" : 110,
	"skill_name" : "�ޱ���ľ",
	"parry":20,
	"damage_type" : "����"
]),
([
	"action" : "$NͻȻ���ֺ��������Ž������գ��ƺ�Ҫײ���Լ������ţ�ͻȻһʽ����ɽ������,�������$n",
	"lvl" : 140,
	"skill_name" : "��ɽ����",
	"parry":30,
	"damage_type" : "����"
]),
([
	"action" : "$N�ұ����ᣬ����$w�������ߣ�����һ̧��һ�С��Ű�ɭɭ��ֻ��$nײ������",      
	"lvl" : 180,
	"skill_name" : "�Ű�ɭɭ",
	"parry":40,
	"damage_type" : "����"
]),
});

mapping *action_famale = ({
([
	"action" : "$Nʹ�����з����ǡ������Ʒ����������ӯ�鶯��$w��˸����������$n��$l",
	"lvl" : 0,
	"skill_name" : "�з�����",
	"parry":10,
	"damage_type" : "����"
]),
([
	"action" : "$N��ǰ����һ��������$w�������ƼȻ�����������������$NͻȻ����һת��ʹ�����׺���ա�ֱ��$n��$l",
	"lvl" : 10,
	"skill_name" : "�׺����",
	"parry":0,
	"damage_type" : "����"
]),
([
	"action" : "$N���е�$wһ�Σ��������ߣ�һ������������һƬ��Ӱ��һ�С�����ӭ�͡�ֱ��$n��$l",
	"lvl" : 30,
	"skill_name" : "����ӭ��",
	"parry":30,
	"damage_type" : "����"
]),
([
	"action" : "$N����$wб�η�����һʽ���ޱ���ľ������һ�³��м��죬����������ã�ֱ��$n��$l",
	"lvl" : 50,
	"skill_name" : "�ޱ���ľ", 
	"parry":20,
	"damage_type" : "����"
]),
([
	"action" : "$N��������һʽ������ء���$w��Ȼһ��������ǧ�������۶�������������$n��$l",
	"lvl" : 80,
	"skill_name" : "�����",
	"parry":20,
	"damage_type" : "����"
]),
([
	"action" : "$N��תһʽ�����両�ࡹ��ٲȻ��ǹ��ꪣ���ɳǧ�$w������������$n���������ؽ���֮��",
	"lvl" : 110,
	"skill_name" : "���両��",
	"parry":30,
	"damage_type" : "����"
]),
([
	"action" : "$N��������һ�֣�����$w�����ӳ�һ�С���˫�޶ԡ�������ɭȻ����$n��$l��ȥ",
	"lvl" : 140,
	"skill_name" : "��˫�޶�",
	"parry":20,
	"damage_type" : "����"
]),
([
	"action" : "$N��̾һ��������$w����һ����һʽ���仨���⡹��$w��ȻԾ��ٿ�Ļ��������¶���һ���ƮȻ����$n��$l",
	"lvl" : 180,
	"skill_name" : "�仨����",
	"parry":40,
	"damage_type":  "����"
]),
});

mapping *action_19 = ({
([
   "action":HIW"$Nʹһʽ������˳��Ȼ��������$w"+HIW"����΢�񣬻ó�һ���׹����$n��$l"NOR,
	"lvl" : 10,
	"skill_name" : "����˳��Ȼ",
	"damage_type":  "����"
]),
([
   "action":HIC"$N����ǰ��ʹ������ȥ�����С��������������ޣ�$w"+HIC"��������$n��$l��ȥ"NOR,
	"lvl" : 15,
	"skill_name" : "��ȥ������",
	"damage_type":  "����"
]),
([
   "action":HIM"$Nһʽ��־�����Զ��������Ʈ�����ߣ��˷�����������$w"+HIM"ңҡָ��$n��$l"NOR,
	"lvl" : 20,
	"skill_name" : "־�����Զ",
	"damage_type":  "����"
]),
([
   "action":HIG"$N��������Ծ��һʽ�������γ�����������ˮ��һкǧ�����$nȫ��"NOR,
	"lvl" : 25,
	"skill_name" : "�����γ�",
	"damage_type":  "����"
]),
([
	"action":HIY"$N����$w"+HIY"�й�ֱ����һʽ�����Ǳ��ҹ����������Ϣ�ض�׼$n��$l�̳�һ��"NOR,
	"lvl" : 30,
	"skill_name" : "���Ǳ��ҹ",
	"damage_type":  "����"
]),
([
	"action":HIR"$N����$w"+HIR"һ����һʽ������ϸ��������������Ϣ�ػ���$n��$l"NOR,
	"lvl" : 40,
	"skill_name" : "����ϸ����",
	"damage_type":  "����"
]),
([
   "action":HIW"$N����$w"+WHT"бָ���죬��â���£�һʽ������������������׼$n��$lбб����"NOR,
	"lvl" : 50,
	"skill_name" : "����������",
	"damage_type":  "����"
]),
([
	"action":HIR"$N��ָ�����㣬����$w"+HIR"�Ƴ�����ѩ����â��һʽ������һ��졹����$n���ʺ�"NOR,
	"lvl" : 60,
	"skill_name" : "����һ���",
	"damage_type":  "����"
]),
([
	"action":HIC"$N���Ƶ�����һʽ�����Ļ���������$w"+HIC"�Ի���Ծ�����缲�������$n���ؿ�"NOR,
	"lvl" : 70,
	"skill_name" : "���Ļ�����",
	"damage_type":  "����"
]),
([
   "action":HIC"$N����һ���εض���һʽ��������ͬ�ԡ���$w"+HIC"�ó������Ӱ����$n����Χס"NOR,
	"lvl" : 80,
	"skill_name" : "������ͬ��",
	"damage_type":  "����"
]),
([
	"action":HIM"$N�������Ʈ�䣬һʽ�����֪���⡹������$w"+HIM"ƽָ����������$n����"NOR,
	"lvl" : 90,
	"skill_name" : "���֪����",
	"damage_type":  "����"
]),
([
	"action":HIG"$N����΢����������һ�С��ߴ���ʤ�������йǽ�����쫷�����$nȫ��"NOR,
	"lvl" : 100,
	"skill_name" : "�ߴ���ʤ��",
	"damage_type":  "����"
]),
([
	"action":HIY"$Nļ��ʹһ�С���Ҷ����ɽ������ʱ�����м���Ѫ������$nȫ��"NOR,
	"lvl" : 110,
	"skill_name" : "��Ҷ����ɽ",
	"damage_type":  "����"
]),
});

mapping *action_kf = ({
([
	"action":HBCYN"$N����$w"+HBCYN"���������ͻȻ���ڿ���һ����һ�С�Ȫ��ܽ�ء������а�������֮����$w"+HBCYN"��·������ȣ���̼侹Ȼ���Ƶ���$n����"NOR,
	"lvl" : 0,
	"skill_name" : "Ȫ��ܽ��",
	"damage_type":  "����"
]),
([
	"action":HBCYN"$Nȫ�����Է�������·��ʹ��һ�С������ϸǡ����仯Ī��ع���$n�����ƾ���˿�������Ѱ"NOR,
	"lvl" : 10,
	"skill_name" : "�����ϸ�",
	"damage_type":  "����"
]),
([
   "action":HBCYN"$N����$w"+HBCYN"�ζ�����ʯ��������ʹ��������������������$n�Ƶ��ľ���ѣ����֪$N�������˶�����"NOR,
	"lvl" : 20,
	"skill_name" : "ʯ������",
	"damage_type":  "����"
]),
([
   "action":HBCYN"$N$w"+HBCYN"������仯������һ�С���������������������֮���£������޶�������׽����$n��һ���ۻ����ң��ٸ����Ӧ��"NOR,
	"lvl" : 30,
	"skill_name" : "��������",
	"damage_type":  "����"
]),
([
	"action":HBCYN"$NͻȻ��������б��ܳ���ʹ�������ף�ڡ�����$w"+HBCYN"�����Ȼ֮���������⻷��ת����ʱ֮���ѽ�$n����һ�Ž���֮��"NOR,
	"lvl" : 50,
	"skill_name" : "���ף��",
	"damage_type":  "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ( me->query("max_neili", 1) < 100)
		return notify_fail("�������������\n"); 
   if ( me->query_skill("zixia-gong", 1) < 20 && me->query_skill("huashan-qigong",1)<20)
		return notify_fail("�����ϼ�񹦻��̫ǳ��\n");
	if ( me->query_skill("sword", 1) < 10 )
		return notify_fail("��Ļ���������������죬�޷�ѧϰ��ɽ������\n");
	if ( me->query_skill("poyu-quan", 1) < 15)
		return notify_fail("�������ȭ̫�����޷�ѧϰ����ɽ�����ľ��衣\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level, j, r_force, r_dodge, r_damage;
   string str;

	level = me->query_skill("huashan-jianfa",1);

	if( me->query_temp("hsj_19")) {
		for(i = sizeof(action_19); i > 0; i--) { 
			if(level >= action_19[i-1]["lvl"]) {
				j = NewRandom(i, 20, level/5);
				return ([
					"action": action_19[j]["action"],
					"lvl": action_19[j]["lvl"],
					"damage_type": action_19[j]["damage_type"],
					"force": 150 + random(300),
					"dodge": random(30),
					"parry": random(30),
					"damage": 100+ random(100),
				]);
			}
		}
	}
	if( me->query_temp("hsj_kf") ) {
		for(i = sizeof(action_kf); i > 0; i--) {
			if(level >= action_kf[i-1]["lvl"]) {
				j = NewRandom(i, 20, level/5);
				return ([
					"action": action_kf[j]["action"],
					"lvl": action_kf[j]["lvl"],
					"damage_type": action_kf[j]["damage_type"],
					"force": 200 + random(350),
					"dodge": random(30)-random(10),
					"parry": random(30)-random(10),
					"damage": 100 + random(100),
				]);
			}
		}
	}
	if( me->query_temp("hsj_wushuang")) {
		for(i = sizeof(action_kf); i > 0; i--) {
			if(level >= action_kf[i-1]["lvl"]) {
				j = NewRandom(i, 20, level/5);
				return ([
					"action": HIW"$n���һ��������һ��������ѽ������ʱ$w"+HIW+"�����Ѵ�����������$N������ǰ���ͣ�$w"+HIW+"����\n"+
						"������$n�����ţ��ۼ���һ������$n���϶Դ�������ֱû����"NOR,
					"lvl": action_kf[j]["lvl"],
					"damage_type": action_kf[j]["damage_type"],
					"force": 200 + random(350),
					"dodge": random(30)-10,
					"parry": random(20),
					"damage": 150 + random(150),
				]);
			}
		}
	}
    if( me->query("gender") != "Ů��" ) {
           for(i = sizeof(action_male); i > 0; i--) {
           if(level >= action_male[i-1]["lvl"]) {
                  j = NewRandom(i, 20, level/5);
		if(me->query_temp("hsjf/luomu")){
			str=HIC+replace_string(action_male[j]["action"],"$w","$w"HIC)+NOR;
			r_force = 200+random(150);
			r_dodge = 30+random(30);
			r_damage = 150 + random(200);
		}
        else if(me->query_temp("hsqg/yjs")){
			str=HIG+replace_string(action_male[j]["action"],"$w","$w"HIG)+NOR;
			r_force = 200+random(150);
			r_dodge = 10+random(20);
			r_damage = 100 + random(150);
		}
        else if(me->query_temp("hsjf/lianhuan")){
			str=HIW+replace_string(action_male[j]["action"],"$w","$w"HIW)+NOR;
			r_force = 200+random(150);
			r_dodge = 10+random(20);
			r_damage = 100 + random(150);
		}
        else if(me->query_temp("zxg/zixia")){
			str=MAG+replace_string(action_male[j]["action"],"$w","$w"MAG)+NOR;
			r_force = 200 + random(150);
			r_dodge = 10+random(30);
			r_damage = 120 + random(180);
		}
		else{
			str=action_male[j]["action"];
			r_force = 200 + random(250);
			r_dodge = random(30)-10;
			r_damage = 80 + random(140);
		}
//                   for(i = sizeof(action_male); i > 0; i--) {
//                   if(level >= action_male[i-1]["lvl"]) {
//                           j = NewRandom(i, 20, level/5);
                           return ([
                                   "action": str,
                                   "lvl": action_male[j]["lvl"],
                                   "damage_type": action_male[j]["damage_type"],
                                   "force": r_force,
                                   "dodge": r_dodge,
                                   //"parry": random(20),
                                   "parry": action_male[j]["parry"],
                                   "damage": r_damage,
                           ]);
						}
           }
   }

   for(i = sizeof(action_famale); i > 0; i--) {
           if(level >= action_famale[i-1]["lvl"]) {
                   j = NewRandom(i, 20, level/5);
	if(me->query_temp("hsjf/luomu")){
		str=HIC+replace_string(action_famale[j]["action"],"$w","$w"HIC)+NOR;
		r_force = 200+random(150);
		r_dodge = 30+random(30);
		r_damage = 150 + random(200);
	}
    else if(me->query_temp("hsqg/yjs")){
		str=HIG+replace_string(action_famale[j]["action"],"$w","$w"HIG)+NOR;
		r_force = 200+random(150);
		r_dodge = 10+random(20);
		r_damage = 100 + random(150);
	}

   else if(me->query_temp("hsjf/lianhuan")){
			str=HIW+replace_string(action_male[j]["action"],"$w","$w"HIW)+NOR;
			r_force = 200+random(150);
			r_dodge = 10+random(20);
			r_damage = 100 + random(150);
		}
    else if(me->query_temp("zxg/zixia")){
		str=MAG+replace_string(action_famale[j]["action"],"$w","$w"MAG)+NOR;
		r_force = 200 + random(150);
		r_dodge = 10+random(30);
		r_damage = 120 + random(180);
	}
	else{
		str=action_famale[j]["action"];
		r_force = 200 + random(250);
		r_dodge = random(30)-10;
		r_damage = 80 + random(140);
	}
//   for(i = sizeof(action_famale); i > 0; i--) {
//           if(level >= action_famale[i-1]["lvl"]) {
//                   j = NewRandom(i, 20, level/5);
                   return ([
                           "action": str,
                           "lvl": action_famale[j]["lvl"],
                           "damage_type": action_famale[j]["damage_type"],
                           "force": r_force,
                           "dodge": r_dodge,
                           //"parry": random(20),
                           "parry": action_famale[j]["parry"],
                           "damage": r_damage,
                   ]);
           }
    }
}


int practice_skill(object me)
{
	int lvl = me->query_skill("huashan-jianfa", 1);
	int i;

	if ( me->query("gender") != "Ů��") {
		i = sizeof(action_male);
		while (i--) if (lvl == action_male[i]["lvl"]) return 0;
	}
	else {
		i = sizeof(action_famale);
		while (i--) if (lvl == action_famale[i]["lvl"]) return 0;
	}

	if ( me->query("jingli") < 50)
		return notify_fail("���������������ɽ������\n");
	if ( me->query("neili") < 20)
		return notify_fail("�������������ϰ��ɽ������\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"huashan-jianfa/" + action;
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
	int p, ap, dp;
	string msg;

	ap = me->query("combat_exp") /1000 * me->query_int(1);
	dp = ob->query("combat_exp") /1000 * ob->query_int(1);

	p = (int)me->query("qi")*100/(int)me->query("max_qi");

	if ( me->query_skill("huashan-jianfa", 1) < 120
	|| me->query_skill_mapped("sword") != "huashan-jianfa"
	|| me->query_skill_mapped("parry") != "huashan-jianfa"
	|| me->query_skill_prepared("cuff") != "poyu-quan" 
	|| p > 20 
	|| me->is_busy())
		return 0;

	if ( (20 - p) > random(10) && weapon ) {
		msg = "$N����"+weapon->name()+"��$nһ�������ַɳ���\n"NOR;
		weapon->move(environment(me));
		msg += HIW"$N���һ����������ָ���̣�����ָʹ��һ�С��������á���\n"NOR;
		if (random(ap) > dp/10 ) {
			msg += HBRED"�������$n������Ѩ��\n"NOR;
                        ob->add_busy(5+random(3));
		} 
		else {
			msg += HBGRN"���$n�����ϵ�������������\n"NOR;
		}
		message_vision(msg, me, ob);
		return -damage;
	}
	return 0;
}

int hit_ob(object me, object ob, int damage)
{
        object weap;
        weap = ob->query_temp("weapon");

	if(me->query_temp("hsj_kf") ){
      if( random((int)me->query_skill("huashan-jianfa", 1)) > ob->query_skill("parry",1)*2/5
        && me->query("neili") > 2000
        && random(4)==1 ){
                   if ( weap && me->query("quest/huashan")=="����" ){
               		message_vision(HIR "$N�������֮�죬$nһ����������" + weap->name() +HIR"�ѱ�"HIG"���콣"HIR"֮�������͡�\n" NOR, me,ob ); 
               		if (random((int)me->query_skill("parry", 1)) > (int)ob->query_skill("parry", 1)/2 ){
                 		message_vision(HIY "$nԽ���ż�������" + weap->name() + HIY"��Խ�ǲ���ʹ����ͻȻ$Nһ�����У�$n����" + weap->name() + HIY"�����ֶ���!\n" NOR, me,ob );
                 		weap->unequip();
                 		weap->move(environment(me));
                 		ob->reset_action();
                           ob->add_busy(2);
               		}
               		else{ 
                 		message_vision(HIW "$n�ۿ�$N��ʹ�Ľ�����Ҫ˳�Լ����е�" + weap->name() + HIW"֮��ն������$n�鼱֮��ֻ�ܽ����е�" + weap->name() + HIW"���¡�\n" NOR, me,ob );
                 		weap->unequip();
                 		ob->reset_action();
                           ob->add_busy(2);
                           }
               		me->add("neili", -30);
             	}
        }

	}
        return 0;
}
