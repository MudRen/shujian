//getstr.c

inherit F_CLEAN_UP;

int main(object me,string str)
{
	if(!wizardp(me)) return 0;
	if(!str) return notify_fail("���ë����\n");
	str = replace_string(str,"\"","");
	write(sprintf("�ַ� [%s] ����=%d\n",str,strlen(str)));
	return 1;
}
int help(object me)
{
	if(!wizardp(me)) return 0;
	write(@HELP
	��ʽ��getstr �ַ�
	����ַ����ȣ���ʦר�á�
	
	һ�����飺����ȹر�zMUD���Զ�����������ʹ�ø�ָ�
		  �������ַ����ϼ�""
HELP
);
	return 1;
}
