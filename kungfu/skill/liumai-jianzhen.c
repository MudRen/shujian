// liumai-jianzhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
        HIG"\n$n�������е�ס�˹��ƣ�ȴ�о�����������Ϯ�����ƺ�Խ��Խ�죬Խ��Խ�࣬\n" +
                "�������Σ���Ӱ���٣�ʵ�����Եֵ���\n\n"NOR,
        HIG"\n��ɮ��$n��ͼ���ӳ��������󣬸�����ָһ�����漴�������ν���׷�����ϣ�\n" + 
                "$n�����������ν�������Ȼ�޷�����\n\n"NOR,
        HIG"\nȴ��$n��Χ�����ݺύ����������ת��Ѹ����磬$nû��˿����ʱ��˼����ֻ�Ǳ����ĵֵ���\n\n"NOR,
        HIG"\n��ɮ���Է��У��������ң�ȴ�����·�����ֱ��������������������ȼ����󻺣��޲���������ɱ������\n\n"NOR,
        HIG"\nһ�����ν����������ҷ����������������������������ϣ��仺�����Σ�ȴ���޼᲻�ߡ�\n\n"NOR,
        HIG"\nֻ�����ƿ�֮�����죬��������������������������ң���ס��$n�����г�·��\n\n"NOR,
        HIG"\n����������������������������Ǳ�����������Σ��޴���ĥ��\n\n"NOR,
        HIG"\n��������������˷���$n�˵��������磬�籩�磬�ƿ�֮������\n\n"NOR,
        HIG"\nͻȻ֮�䣬���������ޱȵĽ��������������½����޴ӵֵ���\n" +
                "��$n��ȥ������û���������Ѵ���������˺������\n\n"NOR, 
});


string query_action()
{
        return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
        return 6;
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
        if( me->query_skill("yiyang-zhi",1) < 160)
                return notify_fail("���һ��ָ���𲻹����޷�ѧϰ��������\n");
        if( me->query_skill("liumai-shenjian",1) < 30)
                return notify_fail("��������񽣼��𲻹����޷�������������\n");
    if( me->query_int() < 35 )
                return notify_fail("������Բ������޷�������������\n");
        if( me->query_skill("buddhism",1) < 150 )
                return notify_fail("��������ķ����𲻹����޷�������������\n");
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("��������ֻ��ͨ��ѧϰ(learn)����ߡ�\n");
}
