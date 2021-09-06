// ansi.c

#include <ansi.h>

inherit F_CLEAN_UP;

//string frame = "��������������������������������������������������������\n";
string frame = "������������������������������������������������������\n";

string pattern = "�٢ڢ�";

int main(object me)
{
	string *bgcolor = ({BBLK, BRED, BGRN, BYEL, BBLU, BMAG, BCYN, BWHT});
	string *fgcolor = ({BLK,RED,GRN,YEL,BLU,MAG,CYN,WHT,HIR,HIG,HIY,HIB,HIM,HIC,HIW});
	string *nfgcolor = ({"BLK","RED","GRN","YEL","BLU","MAG","CYN","WHT","HIR","HIG","HIY","HIB","HIM","HIC","HIW"});
	string output;
	int i,n;

	output = MUD_NAME+"ANSI��ɫ״̬���ԣ�\n";
	output += frame;
	output += "     BBLK  BRED  BGRN  BYEL  BBLU  BMAG  BCYN  BWHT\n";
	for(i=0;i<sizeof(fgcolor);i++)
	{
		output += sprintf("%-4s",nfgcolor[i]);
		for(n=0;n<sizeof(bgcolor);n++)
			output += sprintf("%s%s%s"+NOR,fgcolor[i],bgcolor[n],pattern);
		output += NOR+"\n";
	}
	output += NOR+frame;
	write(output);
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : ansi

���ָ�������������ANSI��ɫ��״̬������ʹ�õĻ��������
�е�Ч���ġ�

HELP
        );
        return 1;
}