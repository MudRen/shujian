// Cmd:  zhua.c
// Created by Numa 1999-12-10
// Add Log

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        if (!me->is_robot())
	return notify_fail("�㵱ǰû�б�ϵͳ�ж�Ϊ�����ˣ�����Ҫ�ٻ�����ɱ�֡�\n");
        if (me->query_temp("robot_test"))
	return notify_fail("�㻹���Ⱥúûش�ǰ������ɡ�\n");    
   
        ob = new("/clone/npc/antirobotnew");
        ob->test_robot(me);
        tell_object(me,HIY"��������һ������ɱ�֡�\n");   
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : runner

��ָ��������ڻ�����״̬������һ������ɱ�֣�
�����Ļ�����״̬��

HELP
    );
    return 1;
}

