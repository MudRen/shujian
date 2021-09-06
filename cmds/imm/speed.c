// quit.c

#include <ansi.h>

int main(object me, string arg)
{
        int i,j;
        object ob;

        if(!arg)
                ob = me;
        else
                ob = present(arg, environment(me));

        if (wizardp(me)) {
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob || !me->visible(ob)) return notify_fail("��Ҫ�쿴˭��EXP״̬��\n");
        } else if (ob != me)
                return notify_fail("ֻ����ʦ�ܲ쿴���˵�EXP״̬��\n");
        
        i = (ob->query("combat_exp") - ob->query_temp("combat_exp")) * 60
                / (ob->query("mud_age") - ob->query_temp("mud_age"));

        j = (ob->query("mud_age") - ob->query_temp("mud_age"))/60;

        write(sprintf("%s �ϴξ��飺%d�����ξ��飺%d��ƽ����%d/min, ����ʱ��Ϊ %d min��\n",
                                geteuid(ob), ob->query_temp("combat_exp"),
                                ob->query("combat_exp"), i ,j));
        return 1;

}

int help(object me)
{
        write(@HELP
ָ���ʽ : speed <id>

�ô�ָ����player�ľ����ٶȡ�
HELP
    );
    return 1;
}
