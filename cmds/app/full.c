// full.c for apprentice
// write by Look@SJ

#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me,string str)
{
        if (!geteuid()) seteuid(getuid());
        if (!str)
                me = this_player();
        else	me = present(lower_case(str), environment(this_player()));
        
        if (!me) return notify_fail ("����û������Ҫ�ָ����ˡ�\n");
        
        // reincarnate �Ѿ���ȫ�ָ������Բ�����һ����set�ˡ�
        me->reincarnate();
	me->set("neili", me->query("max_neili")*2);
        if (wizardp(me)) me->clear_condition();

        if (me != this_player())
            	message_vision(WHT"ֻ��һ����â��$N������$n���ϣ��ָ���$p���е�������\n"NOR,this_player(), me);
        else
                write(WHT"���״̬�ָ���ϣ�\n"NOR);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: full [���ID]
 
�ָ�������в��������ֵ��

HELP );
        return 1;
}
