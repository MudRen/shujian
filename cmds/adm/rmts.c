
int main(object me,string arg)
{
	int i;
	
	write(sprintf("me = %O,this_player = %O , this_player(1) = %O\n",me,this_player(),this_player(1) ));
	return 1;
		
	arg = ctime(time());
	write(arg+"\n");
	return 1;
	
	write(sprintf("����λ�ã�%d, ���ȣ�%d \n",strsrch(arg,"\n"),strlen(arg)));
	return 1;
	if(sscanf(arg,"%d",i)!=1) return 0;
	write(ROOMLEASE_D->get_money_str(i)+"\n");
	return 1;
}