// shenghuo-fumozhen.c


#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	HIR"\nͻȻ֮�䣬�������λζ���ͬʱ�۽�����ֻ��������$n����ץȥ��\n\n"NOR,
	HIR"\n$n�����ӳ��������˺�ɨ��ȥ���������˽��²�֪����ƶ���������䡣$nһ��\n"
		+"���գ��ѱ����˵�����ͬʱץס���죬һ��֮�£�����ԶԶ���˳�ȥ��\n\n"NOR,
	HIR"\n���˲����ȹ֣�����������ϵ�����ۣ�����һ����������ͷ����һ�㡣\n\n"NOR,
	HIR"\n����$Nֱ�۶�ǰ����ָ����$n�ʺ�$n����һ�⣬���Ż���һ�ȣ�ͻȻ������\n"
		+"���𣬺����ѱ���������ץס������������\n\n"NOR,
	HIR"\n$n����һת������ܿ��������ĵ�һ�죬�����ѱ�$nNһ����С�\n\n"NOR,
	HIR"\n$N˫������ʥ����Ӻ�ɨ��ͻȻ�����������Ľ��$n��֪���Ǻ����⣬��ǰ\n"
		+"�׹⼱�����Ҽ��ѱ�ʥ�������ػ��С�\n\n"NOR,
	HIR"\n$N�����ǰ��˫��ʥ�����໥һ�����һ�죬$n����һ�������ӴӰ����ֱ��\n"
		+"������������в��һ����ʹ���ѱ�������һ�š�\n\n"NOR,
	HIR"\n��ʱ�����˾���������������������ͻȻ֮�䣬$n�ؿ�һʹ���ƺ���һö��ϸ��\n"
		+"�������һ�¡�\n\n"NOR,
	HIR"\n$nֻ��������ھ�ͬʱ�󳷣�ͻȻ֮�䣬һ�������絶���罣����ذ�����䣬ֱ\n"
		+"�������ؿڵġ�����Ѩ���С�\n\n"NOR,
	HIR"$n��������ǰ�̳������ѱ�$Nһ�ѱ�ס��"NOR,
	HIR"$Nһ�������������ѧ�ĵ�����һ�б������$n��磬��֪ʥ�����ڰ�;�ŹŹֹ�\n"
		+"��ת�˸��䣬�ĵ�һ�죬�����������󾱡�"NOR,
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
	if(! me->query_skill("jiuyang-shengong"))
	if( me->query_skill("shenghuo-shengong",1) < 150)
		return notify_fail("���ʥ���񹦼��𲻹����޷�ѧϰʥ���ħ��\n");
	if( me->query_skill("shenghuo-lingfa",1) < 150)
		return notify_fail("���ʥ������𲻹����޷�����ʥ���ħ��\n");
	if( me->query_int(1) < 32 )
		return notify_fail("������Բ������޷�����ʥ���ħ��\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("ʥ���ħ��ֻ��ͨ��ѧϰ(learn)����ߡ�\n");
}
