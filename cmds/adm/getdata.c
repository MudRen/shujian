
int help(object me);

int main(object me,string arg)
{
	mixed ret;	
	if(!arg) return help(me);
	ret = dbquery("SELECT U_Data FROM Data WHERE U_ID=" 
		+ save_variable(arg));	
	write(arg+"\n");
	if(!ret){
		return notify_fail("��ȡ���ݿ�ʧ�ܡ�\n");
	}
	if(sizeof(ret)>0)
	{
		for(int i =0;i<sizeof(ret);i++){
			if(bufferp(ret[0][0])) arg = read_buffer(ret[0][0]);
			else arg = ret[0][0];
			write(sprintf("����%d��%s\n",i,arg));
		}
		return 1;
	}
	write("û�ж�ȡ���κ����ϡ�\n");
	return 1;
}
int help(object me)
{
write(@HELP
	getdata [string]
	���磺
	getdata /data/login/c/ciwei.o
HELP
);
	return 1;	
}