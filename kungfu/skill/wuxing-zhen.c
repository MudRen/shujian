// zhenwu-qijiezhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	HIR"\n$n��$N���˴�ȥ�������㵲�һ���������ʮ�˰�ԴԴ���ϣ����ɵô��һ����\n"
	    +"���±�Ԫ��һ�����в��У��������н�����\n\n"NOR,
	HIG"\nֻ��������Ӱ�������裬��ʱ$nͻ����Χ����$N������Ӱ���Σ��������ϡ�\n\n"NOR,
	HIY"\n$n������Խ��Խ�����紩����������ת����ʱһ���������ߣ���֪ͻȻ������\n"
	    +"���������һ����Ȼ��ȭ�򵽡�\n\n"NOR,
	HIB"\n$n��ǰ��һ��˫�ֺϱ��������ⲫ�����������˱ܣ������нŸպ��ߵ����յ�\n"
	    "�ٺ���Ҳû�С�\n\n"NOR,
	HIM"\n$Nһ�����ƣ�һ�����ҿ粽��һ������ת�����Ʋ�������̼��ѽ�$nΧ�����ġ�\n\n"NOR,
	HIC"\n$nһ���Χ���������Ӳ�����������˱�������������������һ�˳��֣���������\n"
	    + "����������ϣ��������˻������ܣ�������ֹ��\n\n"NOR,
	HIW"\n$n�������ã�����ǿ�����գ�ʼ���Ѳ�����Χ�����Է�������ȥ������������\n"
	    "ֻ�÷�������������˿����Ͼȥ�����󷨣�\n\n"NOR,
});


string query_action()
{
	return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
	return 5;
}

void create()
{ 
	seteuid(getuid()); 
}

string type() 
{ 
        return "array"; 
}

int valid_learn(object me) 
{
	if( me->query_skill("force",1) < 160)
		return notify_fail("��Ļ����ڹ����𲻹����޷�ѧϰ������\n");
	if( me->query("combat_exp") < 800000)
		return notify_fail("��ľ��飬�����޷�����������ľ��衣\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("���޷�ͨ����ϰ��������������Ϊ��\n");
}
