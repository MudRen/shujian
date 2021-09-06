// qimen-baguazhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
        HIR"\n$n�������Ű���������Ӱ�������������ط�Ծ���������ۻ����ң�\n" +
                "ͻȻ���Ա�һ��ʯͷ������һ�����ӣ�һ��������\n\n"NOR,
        HIG"\n$n�������У�ȴ��Խ��Խ���ң�һ��С�ģ�������һ����֦����\n" +
              "����������һƬ����Χ�˹��������������������Ѿ��˺����ۣ�\n\n"NOR,
        HIY"\n$n��Ҫ�����󷨣�ȴͻȻ����һ���ʯ����ת�����ܣ������Ѿ��� \n" +
              "�˵�������·�ϣ�������ʩ���㹥����\n\n"NOR,
        HIB"\n$n����������һ�����ӹ�ȥ�������ǵ���ٿ����ʧ��$n��֮���� \n" +
               "æ���ˣ���������������Ӿ�Ȼ������͵Ϯ��\n\n"NOR,
        HIM"\n$n����Ϊ������ȡ���ƣ�������ȴ����������$nͻȻ�е�����Ϯ�� \n" +
               "��æת��ӭ����\n\n"NOR,
        HIC"\n$n���˼�����ȫ��ƴ��������ȥ����������󿪣����������� \n" +
              "�ܴ죬���˵������ġ�\n\n"NOR,
        HIW"\n$nͻȻ��������ֿ��ڣ���֪�Ǽƣ�����ڼ����ȥ������������ \n" +
               "����Ǳ�������\n\n"NOR,
});


string query_action()
{
        return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
        return 8;
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
        if( me->query_skill("bihai-chaosheng",1) < 150)
                return notify_fail("��ı̺����������𲻹����޷�ѧϰ���Ű�����\n");
        if( me->query_skill("yuxiao-jian",1) < 150)
                return notify_fail("������｣�����𲻹����޷��������Ű�����\n");
        if( me->query_skill("qimen-bagua",1) < 150)
                return notify_fail("������Ű��Լ��𲻹����޷��������Ű�����\n");
        if( me->query_skill("suibo-zhuliu",1) < 150)
                return notify_fail("����沨�������𲻹����޷��������Ű�����\n");
 if( me->query_int() < 35 )
                return notify_fail("������Բ������޷��������Ű�����\n");
if( me->query_dex() < 35 )
                return notify_fail("������������޷��������Ű�����\n");
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("���Ű�����ֻ��ͨ��ѧϰ(learn)����ߡ�\n");
}

