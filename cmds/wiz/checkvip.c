
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me)
{
    
    object *list;
    string str;
    int t;
    int j;

    str = "�� " + MUD_NAME + " ��ǰ������״̬ͳ��\n\n";
    str += "�ʺ�      ����                 ��ʼʱ��                                   ����ʱ��\n";
    str += "����������������������������������������������������������������������������������������������������\n";
    list = users();
    j=sizeof(list);
    while( j-- ) {
        if( !environment(list[j]) || !me->visible(list[j]) || list[j]->query("registered")<3 ) continue;
        t = list[j]->query("vip/vip_time") - time();     
        str += sprintf("%-9s %-10s %-50s%-50s\n",
                list[j]->query("id"),
                list[j]->name(1),
                CHINESE_D->chinese_date(list[j]->query("vip/vip_start_time"),1),                
                CHINESE_D->chinese_time(t)
            );
        
    }      
    str += "����������������������������������������������������������������������������������������������������\n";
    str = sprintf("%s���� %d λʹ���������У�ϵͳ������%s\n", str, sizeof(list),
        query_load_average() + "\n");

    write(str);
    return 1;

}

int help()
{
write(@HELP
ָ���ʽ : checkvip

���ָ������г����������ϵ���ҵĹ��״̬�����Բ鿴��û��BUG��

���ָ� finger, who
HELP
    );
    return 1;
}

