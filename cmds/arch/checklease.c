
#include <ansi.h>
#ifndef ROOMLEASE_D
#define ROOMLEASE_D "/adm/daemons/roomleased"
#endif


int help(object me);

int main(object me,object arg)
{
	mapping ma;
	string* leasemap;
	float x;
	if(!arg){
		leasemap=ROOMLEASE_D->query_keys();
		if(leasemap) write(sprintf("Ŀǰ���ã�%s\n",implode(leasemap,",")));
		return help(me);
	}
	
	if( !ROOMLEASE_D->query_ifhavebidname(arg))
		return notify_fail(HIY"û��������̡�\n"NOR );
	
	ma = ROOMLEASE_D->query_amap(arg);
	x = (time()-ma["settime"]) / 3600;
	if(!x || x<=0 ) x = 1.0;//����һ��Сʱ��һ��Сʱ��
	//write(sprintf("money:%d,ʱ����%d\n",ma["repayamount"],time()-ma["settime"] ));
	//x = (time()-ma["settime"])/3600;
	write(sprintf("%s �� %s ��ʼ �� %s ������ %s��ÿ��λСʱ���룺%s��\n",arg,
	ROOMLEASE_D->longtime(ma["settime"]),
	ROOMLEASE_D->longtime(time()),
	MONEY_D->money_str(ma["repayamount"]),
	MONEY_D->money_str( to_int(ma["repayamount"]/x)),
	 ));
		
	return 1;
}

int help(object me)
{
	write(@HELP
	��ʽ checklease <id>
	
	���÷���ľ�Ӫ״����
HELP);
	return 1;
}

