
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me)
{
    
    object *list;
    string str;
    int t;
    int j;

    str = "�� " + MUD_NAME + " ��ǰ������ҹ��֮��ͳ��\n\n";
    str += "�ʺ�            ����       ���    ���ñ���     Condition     ʹ��ʱ��/ʣ��ʱ��\n";
    str += "��������������������������������������������������������������������������������������\n";
    list = users();
    j=sizeof(list);
    while( j-- ) {
        if( !environment(list[j]) || !me->visible(list[j]) || !list[j]->query_temp("ggs/started") ) continue;
        t = time()-(int)list[j]->query("ggs/start_time");       
        str = sprintf("%s%-15s %-10s %-10s %-10s%-10s%s/%-20s\n",
                str,
                list[j]->query("id"),list[j]->name(1),
                (list[j]->query("registered")==3)?"��":HIR"��"NOR,
                (list[j]->query("ggs/started"))?"����":HIR"�쳣"NOR,
                list[j]->query_condition("guigushu")?"����":HIR"�쳣������LinuX��ϵ"NOR,
                CHINESE_D->chinese_time(t),
                CHINESE_D->chinese_time(list[j]->query("ggs/left_time") -t)
            );
    }      
    str += "��������������������������������������������������������������������������������������\n";
    str = sprintf("%s���� %d λʹ���������У�ϵͳ������%s\n", str, sizeof(list),
        query_load_average() + "\n");

    write(str);
    return 1;

}

int help()
{
write(@HELP
ָ���ʽ : checkggs

���ָ������г����������ϵ���ҵĹ����״̬�����Բ鿴��û��BUG��

���ָ� finger, who
HELP
    );
    return 1;
}

