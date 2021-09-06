
#include <ansi.h>
inherit F_CLEAN_UP;

string *skill_level_desc = ({ 
	BLU "����һ��" NOR,BLU "��������" NOR,BLU "����ҳ�" NOR,BLU "��ѧէ��" NOR,BLU "����ǿǿ" NOR, 
	HIB "�����ž�" NOR,HIB "����é®" NOR,HIB "��֪һ��" NOR,HIB "����ͨͨ" NOR,HIB "ƽƽ����" NOR, 
	MAG "ƽ������" NOR,MAG "��ͨƤë" NOR,MAG "��������" NOR,MAG "������" NOR,MAG "����С��" NOR, 
	HIM "����С��" NOR,HIM "������Ⱥ" NOR,HIM "�������" NOR,HIM "�������" NOR,HIM "�ڻ��ͨ" NOR, 
	CYN "�������" NOR,CYN "¯����" NOR,CYN "��Ȼ����" NOR,CYN "���д��" NOR,CYN "���д��" NOR, 
	YEL "��Ȼ��ͨ" NOR,YEL "�������" NOR,YEL "�޿�ƥ��" NOR,YEL "����Ⱥ��" NOR,YEL "����似" NOR, 
	HIY "�����뻯" NOR,HIY "��ͬ����" NOR,HIY "����Ⱥ��" NOR,HIY "�Ƿ��켫" NOR,HIY "�����ױ�" NOR, 
	HIG "��������" NOR,HIG "һ����ʦ" NOR,HIG "�������" NOR,HIG "�񹦸���" NOR,HIG "������˫" NOR, 
	HIC "��������" NOR,HIC "���춯��" NOR,HIC "������" NOR,HIC "������ʥ" NOR,HIC "�������" NOR, 
	HIW "��ǰ����" NOR,HIW "���˺�һ" NOR,HIW "��ز�¶" NOR,HIW "��ɲ�" NOR,HIR "��豹���" NOR
});

	string *knowledge_level_desc = ({
        BLU "��ѧէ��" NOR,HIB "�����ž�" NOR,MAG "��֪һ��" NOR,HIM "��������" NOR,
        CYN "������" NOR,YEL "����С��" NOR,YEL "�ڻ��ͨ" NOR,HIY "�������" NOR,
        HIY "��Ȼ���" NOR,HIG "���д��" NOR,HIG "��ͬ����" NOR,HIC "������˫" NOR,
        HIC "������" NOR,HIW "�����ױ�" NOR,HIW "������ʥ" NOR,HIR "��ǰ����" NOR
});
int main(object me)
{

        string str = "";
        int i;
	
		i = sizeof(skill_level_desc);
                while(i--) {
                        str = "    " + skill_level_desc[i] + str;
                        if (i % 5 == 0) str = "\n" + str;
                }
                str = "\n\n���ܵ������ɵ͵�������Ϊ��"+str;
                i = sizeof(knowledge_level_desc);
                while(i--) {
                        str = "    " + knowledge_level_desc[i] + str;
                        if (i % 4 == 0) str = "\n" + str;
                }
                return notify_fail("֪ʶ�������ɵ͵�������Ϊ��"+str+"\n");
}
int help(object me)
{
        string str = "\n";
		string str2 = "\n";
        int i = sizeof(skill_level_desc);
		int j = sizeof(knowledge_level_desc);

        while(i--) {
                str = "    " + skill_level_desc[i] + str;
                if (i % 5 == 0) str = "\n" + str;
        }
		while(j--) {
                str2 = "    " + knowledge_level_desc[j] + str2;
                if (j % 4 == 0) str2 = "\n" + str2;
        }
write(@HELP
ָ���ʽ : level
���ָ�����������ʾĿǰ�ļ��ܵ�������
֪ʶ�������ɵ͵�������Ϊ��
HELP);
        write(str2);
		write("\n���ܵ������ɵ͵�������Ϊ��\n");
		write(str);

    return 1;
}