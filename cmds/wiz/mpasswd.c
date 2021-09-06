// mpasswd.c
// by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int cap, low, num, spec, n, len, sz;
	string passwd;
	string Random_Passwd ="ABCasdh3aejbnDEFGHIJKL1234567890mnopqr5stHJGHJHJuvwxyza2454bcdefghi1jkl9MNOPQRS4TUVWytu9XYZ";

	len = atoi(arg);

	if( (len < 12) || (len > 20) )
		return notify_fail("�������ֻ�� 12-20 λ��\n");

	sz = sizeof(Random_Passwd);

	do
	{
		cap=0; low=0; num=0; passwd = "";
		for(int i=0;i<len;i++)
		{
			n = random(sz);
			if( Random_Passwd[n] <='Z' && Random_Passwd[n] >='A' )
				cap++;
			else if( Random_Passwd[n] <='z' && Random_Passwd[n] >='a' )
				low++;
			else if( Random_Passwd[n] <='9' && Random_Passwd[n] >='0' )
				num++;
			else
				spec++;
			passwd += Random_Passwd[n..n];
		}
	}
	while(!cap || !low || !num);

	printf("��ϣ���� %d λ����������£�\n%s\n\n", len, passwd);

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: mpasswd ��������λ��

���ָ�������ʦ����һ��ָ��λ������
����ʦ����Ҫ���������롣
�����λ��Ϊ 12-20 λ��

HELP
	);
	return 1;
}
