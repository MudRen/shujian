
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me)
{
    
    object *list;
    string str,str2;
    int t;
    int j;
    int i;
	
    str = "�� " + MUD_NAME + " ��ǰ�齣��ҳɳ��ٶ�״̬ͳ��\n\n";
    str += "�ʺ�      ����                 �ϴξ���          ���ξ���      ƽ���ٶ�(��/Сʱ)       ����ʱ��\n";
    str += "����������������������������������������������������������������������������������������������������\n";
    list = filter_array(objects(), (: userp :));
    j=sizeof(list);
    while( j-- ) {
        if( !environment(list[j]) 
        || !me->visible(list[j]) 
        || !interactive(list[j])  ) continue;
        
        if((list[j]->query("mud_age") - list[j]->query_temp("mud_age"))<=0) continue;
        i = (list[j]->query("combat_exp") - list[j]->query_temp("combat_exp")) * 60
                / (list[j]->query("mud_age") - list[j]->query_temp("mud_age"));
        str2 = sprintf("%d",i); 
        if (i < 20) continue;
        t = list[j]->query("mud_age") - list[j]->query_temp("mud_age");
                   
        str += sprintf("%-9s%-23s%-16d %-16d%-3s��%-16d%s\n",
                list[j]->query("id"),
                list[j]->is_robot()?(HIG+list[j]->name(1)+NOR):list[j]->name(1),
                list[j]->query_temp("combat_exp"), 
                list[j]->query("combat_exp"),
                i>100?(HIR+str2+NOR):str2,
                i*60,
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

