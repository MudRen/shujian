
int main(object me,string arg)
{
	int t;
	if(!arg || sscanf(arg,"%d",t)!=1) return 0;
	write(sprintf("%d\n",time()));
	write(ctime(t)+"\n");
	return 1;
}

//testjc 1081600000
//> testjc 1080750000
//Thu Apr  1 00:20:00 2004
