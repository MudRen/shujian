// find string in file
// Created by Numa@Sj 2000.2.21
// Modified by Numa@Sj 2000.7

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string str)
{
        mixed *dir_info;
        string arg, file;
        int i, j = 0;
        
        if (!str)
                return notify_fail("ָ���ʽ��fstring <�ַ���>\n"); 
        if (me->query("cwd") == 0 || me->query("cwd") == "/" )
                return notify_fail("�����޷����ҡ�\n"); 
        dir_info = get_dir(me->query("cwd"),-1);
        arg = CYN"��ʼ��"RED+me->query("cwd")+CYN"Ŀ¼�²��Һ����ַ���\""GRN+str+CYN"\"���ļ���\n";
        arg += HIW"����������������������������������������������������������������������\n"NOR;
        for (i=0;i<sizeof(dir_info);i++)
        {
                if (dir_info[i][1] == -2)
                        continue;
                if (file_size(me->query("cwd")+dir_info[i][0]) <= 0)
                        continue;
                file = read_file(me->query("cwd")+dir_info[i][0]);
                if (strsrch(file,str)>=0) {
                        arg += me->query("cwd")+dir_info[i][0] +"\n";
                        j += 1;
                }
        }
        arg += HIW"�������������������������������������������������������������� SJ ����\n"NOR;
        if (j == 0)
                arg += RED"δ�ҵ����������������ļ���\n"NOR;
        else
                arg += CYN"���ҵ�"RED+j+CYN"�����������������ļ���\n"NOR;
        me->start_more(arg);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: fstring <�ַ���>

���ָ������������ұ�Ŀ¼����Щ�ļ�����ĳ�ַ�����

HELP
        );
        return 1;
}

