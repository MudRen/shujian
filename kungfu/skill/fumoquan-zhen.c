// fumoquan-zhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	HIY"\n$nͻ����������������״����һ��Ϯ�����Ⱦ��ް�����ף�һ��֮�£�\n " + 
		"�����ŵع�����ֻ��������������Ϻ��Ӷ�������಻���ߣ�ȥ��\n" +
		"�漱��ȴ�Ǿ��޾��硣\n\n"NOR,
	HIY"\n$n���������࣬����һ���������ؿڵ㵽���Ǻ�������һ����ֱ�ı��У�\n" +
		"�糤ì����˰������̶�����ͬʱ������������Ҳ����������\n\n"NOR,
	HIY"\n$n��Ҫ����Ȧ�ӣ�����������������ɵ�Ȧ������ͭǽ�������ƣ���\n" + 
		"���γ�����������أ���Ȼ�޷�����\n\n"NOR,
	HIY"\n����������ɵ�Ȧ���������������$n��ס�������������Ǳ���Ȧ���˳�ȥ��\n\n"NOR,
	HIY"\n��ɮͻȻ�������ߺȣ��������޼���ת������Ӱ�ݺᣬ�����ƻá�\n\n"NOR,
	HIY"\n��ɮ����һ������������ī��һ�㣬Χ��������Ȧ�ӡ�\n\n"NOR,
	HIY"\n��������ͨ������޹⣬�趯֮ʱ�Ʋ������Ӱ�ӡ�\n\n"NOR,
	HIY"\n���������ƻ�ʵ����ȴ���ް�������������ȣ�˵�����Ĺ��졣\n\n"NOR,
	HIY"\n����������������������צ��ī�����ƣ��������ϣ��ִ�������$n�˵���\n\n"NOR,
	HIY"\nͻȻ֮�䣬����ˤ�ڵ��µĺ�����ͷ���𣬱���һ�������Ķ��ߺ��ط��ɣ�\n" +
		"��Х��������$n���ŵ�ȥ����ͷδ����������Ю��������Է�һ�����ϡ�\n\n"NOR,
});


string query_action()
{
	return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
	return 3;
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
	if( me->query_skill("yijin-jing",1) < 150)
		return notify_fail("����׽���𲻹����޷�ѧϰ��ħȦ��\n");
	if( me->query_skill("riyue-bian",1) < 150)
		return notify_fail("������±޷����𲻹����޷������ħȦ��\n");
    if( me->query_int() < 36 )
		return notify_fail("������Բ������޷������ħȦ��\n");
	if( me->query_skill("buddhism",1) < 150 )
		return notify_fail("��������ķ����𲻹����޷������ħȦ��\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("��ħȦ��ֻ��ͨ��ѧϰ(learn)����ߡ�\n");
}
