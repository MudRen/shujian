// linji-jianzhen

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
        HIW"\n$n��æ���ң����������ǡ���ڤ�����Ľ��⣬��֪������Ǻá�\n\n"NOR,
        HIW"\n$n�����Ҷ㣬�����Ӳ������ҵ��ӵġ���ء�����\n\n"NOR,
        HIW"\n$n�����ҵ��ӵġ����¡����ַ�������������ͷ�󺹡�\n\n"NOR,
        HIW"\n���ҵ����á����ơ�����$n��Χ�����У��ӽ�������\n\n"NOR,
        HIW"\n���е���ͬʱʹ����֮�ġ�����$n��ʱ�����ٳ���\n\n"NOR,
        HIW"\n$n�����е��ӡ����������������������ܲ�����\n\n"NOR,
});


string query_action()
{
        return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
        return 12;
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
        if( me->query_skill("linji-zhuang",1) < 120)
                return notify_fail("����ټ�ʮ��ׯ���𲻹����޷�ѧϰ�ټý���\n");
        if( me->query_skill("huifeng-jian",1) < 120)
                return notify_fail("��Ļط���������𲻹����޷������ټý���\n");
         if( me->query_int() < 30 )
                return notify_fail("������Բ������޷������ټý���\n");
         if( me->query_dex() < 30 )
                return notify_fail("������������޷������ټý���\n");
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("�ټý���ֻ��ͨ��ѧϰ(learn)����ߡ�\n");
}

