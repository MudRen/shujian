/* 
   wuxiang-zhi.c �����ָ
   �������޺�ȭ(luohan-quan)����
   ȡ�Է�ʮ���֡�����ǻۣ����磬�Ժ���ӱ��Բ������
   2/3/98 by snowman
*/

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N��˫��£������֮�У�һ�С��������١�����������������ӿ��������$n",
	"weapon" : "ָ��",
	"lvl"   : 0,
	"skill_name" : "��������" ,           
	"damage_type" : "����"
]),
([
	"action" : "$N΢΢һЦ��һ�С��ǻ�����١����������ڣ�ָ�����������������ĥ��͸���޷����",
	"weapon" : "ָ��",
	"lvl"   : 10,
	"skill_name" : "�ǻ������" ,           
	"damage_type" : "����"
]),
([
	"action" : "$N����վ����˿������������$n��ǰ���һ������������������С���������١�",
	"weapon" : "����ָ��",
	"lvl"   : 30,
	"skill_name" : "���������" ,           
	"damage_type" : "����"
]),
([
	"action" : "$Ņͷ���죬һָ���Ժ�����١���Ϯ$n$l������ȴ��˿���������������·���һ��",
	"weapon" : "ָ��",
	"lvl"   : 60,
	"skill_name" : "�Ժ������" ,           
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С�ӱ������١���$n������ŵ�һ�ƿ�֮����ȴ��$P΢Ц��ͷ��ȴ�����κζ���",
	"weapon" : "ָ��",
	"lvl"   : 100,
	"skill_name" : "ӱ�������" ,           
	"damage_type" : "����"
]),
([
	"action" : "��������������$n��ɫͻ�䣬$Nȴ�������ڣ����޶����ֵļ�������������С�Բ������١�",
	"weapon" : "ָ��",
	"lvl"   : 200,
	"skill_name" : "Բ�������" ,           
	"damage_type" : "����"
]),
});

int valid_enable(string usage)
{
	if ( this_player()->query("wxz/quest"))
		return usage=="finger" ||  usage=="parry"; 
}

int valid_combine(string combo)
{
	if(this_player()->query_skill("wuxiang-zhi", 1) >= 200
	&& this_player()->query_skill("luohan-quan",1) >= 200
	&& this_player()->query_con(1) > 45
	&& this_player()->query_int(1) > 45)
		return combo=="luohan-quan";
}

int valid_learn(object me)
{
	if (!me->query("wxz/done")) 
		return notify_fail("��ͻȻ�о��Լ�����ԪѨ�����е���ľ������һ���ľ���\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ָ������֡�\n");
	if ( me->query_skill("yijin-jing", 1) < 180)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧ�����ָ��\n");
	if ( me->query("max_neili") < 3000 )
		return notify_fail("�������̫�����޷��������ָ��\n");
	if ( me->query_skill("wuxiang-zhi",1) < 200)
		return notify_fail("��������ָ��Ϊ������Ŀǰ���޷�������ϰ��\n");
	if ((int)me->query_int(1) > 47)
               return 1;
	if ( me->query_skill("mohe-zhi", 1) < 160
	|| me->query_skill("nianhua-zhi", 1) < 160
	|| me->query_skill("yizhi-chan", 1) < 160 )
		return notify_fail("�㻹δ���ջ�����ָ�����޷�ѧϰ�����ָ��\n");
	return 1;
}

void skill_improved(object me)
{
	int skill;
	int neili=me->query("max_neili");
	int poison;

	skill = me->query_skill("wuxiang-zhi", 1);
	if( skill<=100 && skill%20==0 && me->query("wxz/improve")<skill ) {
		tell_object(me, HIG"������һ�󣬲�������������Щ���ҡ�\n"NOR);
		tell_object(me,"��������ķ��˲��ˡ�\n");
		me->set_skill("buddhism",me->query_skill("buddhism",1)-1);
		me->set("wxz/improve",skill);
		return;
	}
	if( skill>100 && skill<=150 && skill%10==0 && me->query("wxz/improve")<skill ) {
		tell_object(me, HIG"���Ȼ������Щ��˼����������վ��������\n"NOR);
		me->set_skill("buddhism",me->query_skill("buddhism",1)-1);
		tell_object(me,"��������ķ��˲��ˡ�\n");
		me->set("wxz/improve",skill);
		return;
	}
	if( skill>150 && skill<=200 && skill%5==0 && me->query("wxz/improve")<skill ) {
		tell_object(me, HIG"���ķ����ң��������ĵ�����һ��ɱ����\n"NOR);
		me->set_skill("buddhism",me->query_skill("buddhism",1)-1);
		tell_object(me,"��������ķ��˲��ˡ�\n");
		me->set("wxz/improve",skill);
		return;
	}

	if( skill > 200 ) me->add("wxz/poison",skill+random(skill));
	else return;
	poison=me->query("wxz/poison");
	if (neili/poison>=10) tell_object(me, HIG"��ͻȻ�о��Լ�С���ϡ����š�����̫�ҡ���Ѩ������ʹ��\n"NOR);
	else if(neili/poison>=5) tell_object(me, HIG"��ͻȻ�о��Լ�����ԪѨ�����е���ľ������һ���ľ���\n"NOR);
	else if(neili/poison>=2) {
		tell_object(me, HIG"��ͻȻ�о��Լ����ס���Ȫ���縮����Ѩ�����������ܴ̣�ʹ���ɵ���\n"NOR);
		me->unconcious();
	} else if(neili/poison==1) {
		tell_object(me, HIG"��ͻȻ�о�������Ϣ�Ҵܣ��޷����ƣ���ǰһ�ڣ��赹�ڵء�\n"NOR);
		me->add("max_neili", -skill/2);
		me->set_skill("force",me->query_skill("force",1)-1);
		me->set_skill("yijin-jing",me->query_skill("yijin-jing",1)-1);
		me->unconcious();
	} else if(neili/poison==0) {
		tell_object(me, HIG"��ͻȻ�о�������Ϣ���ȣ����ˮ�㵽�������Ҵܣ�������ǰһ�ڣ����ڵ��ϡ�\n"NOR);
	/*		
		me->set("max_neili",0);
		me->delete_skill("force");
		me->delete_skill("yijin-jing");
		me->delete_skill("dodge");
		me->delete_skill("shaolin-shenfa");

		me->unconcious();
		*/
		me->die();
                log_file("skills/wxjz",sprintf("%s(%s)��������پ�����϶�����\n", me->query("name"),getuid(me)), me);
		message("channel:chat",	HIC"���������š�"+ me->query("name") +"��Ϊǿ�������书��������϶�����\n" NOR,users());
	}
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level   = (int) me->query_skill("wuxiang-zhi",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 200 + random(350),
				"dodge": random(30)-10,
				"parry": random(20),
				"weapon": action[j]["weapon"],
			]);
		}
	}
}

int practice_skill(object me)
{
	if (!me->query("wxz/done")) 
		return notify_fail("��ͻȻ�о��Լ����ס���Ȫ���縮����Ѩ�����������ܴ̣�ʹ���ɵ���\n");

	if ( me->query("jingli") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("������������������ָ��\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wuxiang-zhi/" + action;
}

int help(object me)
{
	write(
@HELP
�����ָ
    ȡ�Է�ʮ���֡�����ǻۣ����磬�Ժ���ӱ��Բ������
    �ϳ˷��Ź��򣬵������ż������ߣ����ڻ���۽϶����Ϊ�������۵����������
    ����ʱ���⣬��ʹ�������𣬿�����������ʦ��̷�������֮��������۶�࣬��
    ��������ֿ��º������������������ֱ������߻���ħ������з�
    ���Ժ��޺�ȭ(luohan-quan)�������������Ҫ�������� 46���������� 46��������
    ����� 200 ����
HELP
	);
	return 1;
}
