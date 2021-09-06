#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$n��ȻŤ�������������������ö����$N�Ĺ��ơ�\n",
	"dodge"  : 120
]),
([
	"action" : "$n����һ�����ɣ���������һ��ת�ۣ�$N������Ȩ����ա�\n",
	"dodge"  : 130
]),
([
	"action" : "$nͻȻ��������Ȱ����Ử�У�ٿ���������ɿ��⡣\n",
	"dodge"  : 140
]),
([
	"action" : "$N��������$n����֪����ô$nͻȻ��ʧ��������$N�᷽��\n",
	"dodge"  : 150
])
});

mapping query_action(object me,object weapon)
{
	int zhaoshu, level;
	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("jiuyin-shenfa");
	if (level < 130 )
		zhaoshu--;
	if (level < 80 )
		zhaoshu--;
	if (level < 50 )
		zhaoshu--;
	return action[random(zhaoshu)];
}

int valid_enable(string usage){return usage == "dodge";}

int valid_learn(object me)
{
	if ((int)me->query_skill("jiuyin-zhengong", 1) <= (int)me->query_skill("jiuyin-shenfa", 1))
		return notify_fail("��ľ����湦��������޷�����������\n");
	return 1;
}
/*
string query_dodge_msg(object me)
{
	mapping action;
	action = query_action(me);
		return action["action"];
}
*/
int practice_skill(object me)
{
	if( (int)me->query("jingli") < 50 )
		return notify_fail("��ľ���̫�������ϰ��������\n");
        me->receive_damage("jingli", 40);
        return 1;
}

int ob_hit(object ob, object me, int damage)
{
	string msg;
	int skill, neili, neili1;
	int j = 0;
	skill = me->query_skill("jiuyin-shenfa", 1);
	neili = me->query("neili");
	neili1 = ob->query("neili");

	if(skill > random(ob->query_skill("dodge", 1)) 
	&& random(me->query("combat_exp")) > ob->query("combat_exp")/2
	&& me->query_skill_mapped("dodge") == "jiuyin-shenfa"
	&& neili > 500 && skill > 80
	&& me->query_temp("jiuyin/fast")){
		msg =random(2)? HIR + action[random(sizeof(action))]["action"]+NOR :
			HIC + action[random(sizeof(action))]["action"]+NOR ; 
             message_vision(HIY"$NΣ��֮��ʹ���˾����澭�ϵĹ����ڿ̲��ݻ���һ˲������$n�Ĺ�����\n"NOR,me,ob);
		msg += "���$N���������㿪�ˣ�\n", 
		j = -(damage+skill*2);
		message_vision(msg, ob, me);
		return j;
	} 
	return j;   
}

string perform_action_file(string action)
{
	return __DIR__"jiuyin-shenfa/" + action;
}
