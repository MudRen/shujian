// tianmo-jue.c 

inherit SKILL; 

#include <ansi.h> 

void create() { seteuid(getuid()); } 

string type() { return "knowledge"; } 

int practice_skill(object me) 
{
        return notify_fail("��ħ��ֻ�ܿ�ѧϰ����ߡ�\n");
}

void skill_improved(object me) 
{
        tell_object(me, HIR "ɱ!ɱ!ɱ����Ҫɱ������������!\n" NOR);
        me->add("shen", -200);
}
