// wizlist.c
// by snowman@SJ

#include <ansi.h>

inherit F_CLEAN_UP;

mapping hoodname=([
	"(admin)" :  "��"HIW" ��  ��"NOR" ��",
	"(assist)" : "��"HIR" ��  �� "NOR"��",
	"(arch)" : "��"HIY" ��  �� "NOR"��",
	"(wizard)" : "��"HIG" ��  �� "NOR"��",
	"(apprentice)" : "��"HIC" ��  ʦ "NOR"��",
	"(immortal)" : "��"HIM" ��  �� "NOR"��"
]);

int level(mixed, mixed);

int imm(string wizid)
{
	return wiz_level(wizid) == 6;
}

int main(object me, string arg)
{
        string *list, hood = "", str;
        int i, j;

        list = sort_array(SECURITY_D->query_wizlist(), (: level :));
	if (!wiz_level(me)) list = filter_array(list, (: imm :));
        str = sprintf("\n �q%-30s�������������������������������������r\n",
                WHT"�齣��2012Ŀǰ����" + chinese_number(sizeof(list)) + "λ��ʦ��"NOR);
	str = replace_string(str, "  ", "��");
	str += "��                                                                    ��";
        i = sizeof(list);
        while(i--) {
                if (hood != wizhood(list[i])) {
                        hood = wizhood(list[i]);
                        if( j ){
                        	while(j > 6) j -= 6;
                        	j = 6 - j;
                        	if( j > 0){
                        		while(j--) str += "         ";
					str += "��";
                        	}
                        	else str += "��";
                        }
                        str += sprintf("\n��%-12s��"NOR, hoodname[hood]);
                        j = 0;
                }

                j++;
                if( j > 6 && j%6==1 )
                	str += "��\n��\t\t";
		str += sprintf("%-9s", capitalize(list[i]));
        }

        if( j ){
                while(j > 6) j = j - 6;
                j = 6 - j;
                if( j > 0) {
                	while(j--) str += "         ";
			str += "��";
                }

                else str += "��";
        }
        str += "\n��\t\t\t\t\t\t\t\t      ��\n";
        str += "�t�������������������������������������������������������� "WHT"SJ-2012-"NOR" ���s";
        write(str+"\n");
        return 1;
}

int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 > ob2?-1:1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : wizlist

��; : �г�Ŀǰ���е���ʦ������
HELP
     );
     return 1;
}
