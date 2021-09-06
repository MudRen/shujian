// huoyan-dao.c ���浶
// by snowman@SJ

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N��Ϣת�����˾���˫�ۣ�ȫ��ǽ�һ���죬����һʽ��ʾ��������$n��������$nȫ�������ڳ��ȵ��Ʒ���",
	"skill_name" : "ʾ����",
	"lvl" : 0,
	"damage_type" : "����",
]),
([
	"action" : "$N�����Ц��һ�С�ʼ�ľ��������浶�ھ����ڼ�������ӿ����$P˫���籦���ʮ����ǰ������$n����һ��",
	"skill_name" : "ʼ�ľ�",
	"lvl" : 20,
	"damage_type" : "����",
]),
([
	"action" : "$N˫�ƺ�ʮ���ִ򿪣����С��ֱ������Ի��浶���Ϲ����۳�һ�������ʢ���Ļ��������ת��������$n����",
	"skill_name" : "�ֱ���",
	"lvl" : 50,
	"weapon" : "��������",
	"damage_type" : "����",
]),
([
	"action" : "$N�������࣬˫�ƴ�Բ��ʹ�������ȵĵ�����ۣ����С��Ʒ�ִ������һֻ�޴�����ƣ������$n��ץ����",
	"skill_name" : "�Ʒ�ִ",
	"lvl" : 70,
	"damage_type" : "����",
]),
([
	"action" : "$N����һ������Ȼʹ����ħ���ϵġ�����Բ����������쫷��Χ��$P������������$nһ��������$P��������",
	"skill_name" : "����Բ",
	"lvl" : 120,
	"damage_type" : "����",
]),
([
	"action" : "$N�����ħ�澭��˫��������������$n����������֮�£����絶�и����ġ����泣�������ƺ�Ҫ��$p��������",
	"skill_name" : "���泣",
	"lvl" : 140,
	"weapon" : "���ε���",
	"damage_type" : "����",
]),
([
	"action" : "$N�ֱ��࣬�����������֡����淨�������ĳ�������е������᲻ɢ�����������Ƶ�����ȴ��ɽ�������ӿ��$n",
	"skill_name" : "���淨",
	"lvl" : 160,
	"damage_type" : "����",
]),
([
	"action" : "$N�������ƣ�һʽ�������š���������ת������ȫ�������޷��Զ���$P����΢�㣬��������һ����ն��$n$l",
	"skill_name" : "������",
	"lvl" : 180,
	"weapon" : "��������",
	"damage_type" : "����",
]),
});
















int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����浶������֡�\n");
	if ( me->query("max_neili") < 1500)
		return notify_fail("�����������Ϊ������������ϰ���浶��\n");
	if ( me->query_con(1) < 30)
		return notify_fail("��ĸ���̫�ͣ����ܼ������浶��\n");
	if ( me->query_skill("longxiang-boruo", 1) < 100)
		return notify_fail("���浶��Ҫ������������ڰ˲����ϵĻ�����ѧϰ��\n");
	if ( me->query_skill("force") < 100)
		return notify_fail("��Ļ����ڹ����̫ǳ������ѧ���浶��\n");
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
	int i, level, j;
	level = (int) me->query_skill("huoyan-dao",1);
for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);


// 	��� pfm ran
	if( me->query_temp("hyd_ran") ) {
		return ([
			"action" : RED"$N�͵���ת�ڹ����۾���˫�ƣ����浶�ھ����ڼ�������ӿ����Ю��һ�����ȵĵ�����$nֱӿ��ȥ��"NOR,
			"force":300+random(250)+me->query_str(),
			"dodge":random(30)-10,
			"parry":random(10)+10,
			"damage_type" : "����",
		]);
		me->delete_temp("hyd_ran");
	}


if (random(me->query_skill("strike", 1)) > 100 
			 && random(me->query_skill("huoyan-dao", 1)) > 100  && !random(3)
      			 && me->query("neili") > 300 
			) {
				me->add("neili", -20);
				return ([
					"action": HBRED"$N�����浶�������߶���ֱ��$n��$nֻ��ȫ���Ʊ�һ�����˰�Χ��"NOR,
					"force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
                                        "damage": 140 +random(100),
					"damage_type": "����"
				]);
			}






if (me->query_temp("yan")) {
                           
me->add("neili", -300);

			return ([  
				"action": HIR+action[j]["action"]+NOR,
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"weapon": action[j]["weapon"],
				"force":250+random(350),
				"dodge":random(30)-10,
				"parry":random(20),
			]);
		}










	else {
 				return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"weapon": action[j]["weapon"],
				"force":250+random(350),
				"dodge":random(30)-10,
				"parry":random(20),
			]);

                         }

}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("huoyan-dao", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;
	if ( me->query("jingli") < 50 || (int)me->query("neili") < 20)
		return notify_fail("������������������˻��浶��\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"huoyan-dao/" + action;
}

int ob_hit(object ob, object me, int damage)
{
	string msg;
	int j, skill, neili, neili1;

	skill = me->query_skill("huoyan-dao", 1);
	neili = me->query("neili");
	neili1 = ob->query("neili");

	if( me->query_temp("fanzhen")) {
		me->delete_temp("fanzhen");
		return 1;
	}

	if( random(skill) > ob->query_skill("parry", 1)/2
	&& me->query("combat_exp") > ob->query("combat_exp")/2
	&& me->query_skill_mapped("parry") == "huoyan-dao"
	&& me->query_skill("longxiang-boruo", 1) > 150
	&& neili > 1000 
	&& skill > 150 
	&& random(neili) > random(neili1)/2
	&& living(me)
	&& !me->query_temp("weapon")
	&& !ob->query_temp("weapon")
	&& !ob->is_visible(me)) {       
		if( me->query_temp("dazhuan_npc") ) neili += neili/2;

		msg = "ֻ����$N��ǰ�������죬�����浶�����ƴ�ʢ��";            
		me->set_temp("fanzhen", 1);
		if ( neili >= neili1+random(neili1)+damage*2){
			msg += "��$n��ʽ�ϵ��������ƽ�������\n", 
			j = -8000;
		}
		else if(neili >= neili1+damage) {
			msg += "$P�����ﴦ����ס��һЩ$n������������\n", 
			j = -(damage/2+random(damage/2));               
		}
		else {
			msg += "$Pչ�����浶������ס��һЩ$n�Ĺ�����\n", 
			j = -damage/3; 
		}
		if ( wizardp(me)) tell_object(me, "Target damage = "+damage+" ��\n");   
		message_vision(msg, me, ob);
		return j;
	}
}

// ��� pfm ran �ĸ�������
mixed hit_ob(object me, object target)
{
	string msg;
	int j;
	j = me->query_skill("strike");


if( !me->query_temp("hyd/auto") && userp(me) )
   	
   	{  

if(  random(10)> 7 && random(me->query("neili")) > target->query("neili") &&!target->query_temp("must_be_hit") && me->query_skill("huoyan-dao") > 250) 
          {
                message_vision(HBRED "$N�����浶�似�������磬һ˫�������·��ɣ��д���һ�ɹ�����ֱ��$n!" NOR,me,target);
                target->start_busy(random(2));
                         me->set_temp("hyd/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("huoyan-dao", 1)/6);
                         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("huoyan-dao", 1)/6);
                        me->delete_temp("hyd/auto");
                        target->apply_condition("no_perform", 2+ random(2));

         }
 
else if(  random(10)> 5 && random(me->query("combat_exp")) > target->query("combat_exp") &&!target->query_temp("must_be_hit") && me->query_skill("huoyan-dao") > 300) 
 {
        	message_vision(HBRED "���浶����$N���ҹ��򣬴˿�ʹ������$n�Ƶ���·���ˣ�" NOR, me,target);
        	target->start_busy(random(2));
                   me->set_temp("hyd/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("huoyandao", 1)/6);
                         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("huoyandao", 1)/6);
                        me->delete_temp("hyd/auto");

        }

else if(  random(10)> 3 && random(me->query("int")) > target->query("int")/2 &&!target->query_temp("must_be_hit")&& me->query_skill("huoyan-dao") > 350) 
{
                message_vision(HBMAG "$N�ٺ�һЦ���������浶�������������ĳ�һ�ơ�" NOR,me, target);
target->start_busy(random(4));
                      me->set_temp("hyd/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("huoyan-dao", 1)/6);
                         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("huoyan-dao", 1)/6);
                        me->delete_temp("hyd/auto");
 
}

}






	if( !me->query_temp("hyd_ran") ) return 1;

	if( random(j) > me->query_skill("parry")/2
	 || random(me->query("neili")) > target->query("neili")/2 ) {
		msg = HIR"$nֻ��$N�Ļ��浶��ɽ�������ӿ�����������񣬸����޷��ֵ���\n"NOR;
                target->receive_wound("qi", j + random(j/2), me);
	} else {
		msg = HIY"$nֻ��$N�Ļ��浶��ɽ�������ӿ������������ȫ������׼��Ӳ����һ�ƣ�\n"NOR;
		target->recevied_damage("neili", j);
		if( !target->is_busy() )
			target->add_busy(random(2));
	}
	message_vision(msg, me, target);













}

int help(object me)
{
	write(HIR"\nѩɽ�ؼ������浶����"NOR"\n");
	write(@HELP
	
	Ҫ��	������� 1500 ���ϣ�
		������� 30 ���ϣ�
		����������ȼ� 100 ���ϣ�
		�ڹ��ȼ� 100 ���ϡ�     
HELP
	);
	return 1;
}
