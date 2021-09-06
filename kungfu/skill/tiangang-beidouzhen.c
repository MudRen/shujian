// fumoquan-zhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	WHT"\n$N�е��������󣡡��ߵ�ʿ��ɢ���������ͻ�������񱼣��Ի����Ŀ�⣬\n"
	    +"ͻȻ֮�䣬�ߵ�����������ơ�ֻ�Ƕ�������������λ��\n\n"NOR,
	WHT"\n$N����һ�Σ���������Ȩ��λ����Хһ����������������ת��������Ҫ��$nΧ���м䡣\n\n"NOR,
	WHT"\n$n����ҡ�⡱λ�ĵ��ˣ�ֻ������һ������诡�������ͦ���ϳ塣\n\n"NOR,
	WHT"\n������������֮�����������Һ�Ӧ����Ϊ��Ԯ��$n�ȹ�������ҡ���������������\n\n"NOR,
	WHT"\n�������˺�������ŭ�ȣ���ͦ��������֦���������������$n�����ߴ�������\n\n"NOR,
	WHT"\n$N����б������ռס������λ�������ڵ��˷�������$nΧ�˹�ȥ��\n\n"NOR,
	WHT"\n$N�鴽���ڣ�������ʿٿ��ɢ������ǰ����󷨱�ã��ѽ�$nΧ���м䡣\n"
	    "���˳���ָ�أ���Ŀ����$n��Ĭ��������\n\n"NOR,
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
        if( me->query_skill("xiantian-gong",1) < 150)
		return notify_fail("���ȫ���ķ����𲻹����޷�ѧϰ�������\n");
	if( me->query_skill("quanzhen-jianfa",1) < 150)
		return notify_fail("���ȫ�潣�����𲻹����޷������������\n");
    if( me->query_int() < 36 )
		return notify_fail("������Բ������޷������������\n");
	if( me->query_skill("taoism",1) < 150 )
		return notify_fail("��ĵ�ѧ�ķ����𲻹����޷������������\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("�������ֻ��ͨ��ѧϰ(learn)����ߡ�\n");
}
