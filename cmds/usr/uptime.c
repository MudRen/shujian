// uptime.c
// From ES2
// Modified by Yu Jue for JY (1998-3-17)

inherit F_CLEAN_UP;

#include <localtime.h>
#include <mudlib.h>

int main(int i)
{
	write("\n"+CHINESE_MUD_NAME + "�Ѿ�����ִ����" + CHINESE_D->chinese_time(uptime()) + "��\n");
	
	if ( intp(i) || file_size("/log/static/LASTCRASH") <= 0) return 1;
	
	write("������¼��" + read_file("/log/static/LASTCRASH"));
        
        return 1;
}

int help(object me)
{
        write(
"ָ���ʽ : uptime\n\n"
"���ָ���������" MUD_NAME "�������Ϸ�Ѿ�����ִ���˶�á�\n"
    );
    return 1;
}
