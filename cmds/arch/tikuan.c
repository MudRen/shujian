/**********************************************************************************
//
//      tikuan.c
//      Created by mychat 31/04/2004
//      �����ҵ�ǩ������� free of use.
//      ��Ȼ����ӭ�޸ġ��Ż��ȡ�
//
//      Email & MSN: codemake@163.com
//      �ļ�λ��/cmds/usr��
// 		
***********************************************************************************/
#include <ansi.h>
#ifndef ROOMLEASE_D
#define ROOMLEASE_D "/adm/daemons/roomleased"
#endif
//#include <roomlease.h>

int main(object me, string arg)
{
	mapping leasemap;	
	string roomid;
	int amount;
	int irepayamount;
		
	if (!arg || sscanf(arg, "%s %d", roomid, amount) != 2)
		return notify_fail("�����ʽ��tikuan <���̴���> <����(���ҵ�λΪ����)>\n");

	if (!wizardp(me) && me->query_temp("command_busy"))
                return notify_fail("����æ���ء�\n");
        me->set_temp("command_busy",1);
        call_out("remove_busy", 3, me);
	
	if( !ROOMLEASE_D->query_ifhavebidname(roomid) )	
		return notify_fail(HIY"û���������ĵ��̡�\n"NOR );

	leasemap=ROOMLEASE_D->query_amap(roomid);
	
	if( leasemap["leaser"]!=me->query("id") )
		return notify_fail(HIY"������̲������㣬���ˮ���㣿\n"NOR );
	
	amount=amount*100;
	irepayamount=ROOMLEASE_D->sum_by_discount(leasemap["repayamount"],leasemap["discount"]);
	if( amount>(irepayamount-leasemap["payamount"]) )
		return notify_fail(HIY"���̵����滹û��ô���أ�\n"NOR );

	return ROOMLEASE_D->tikuan(me, roomid, amount);
	//return 1;
}

void remove_busy(object me)
{
        if (me) me->delete_temp("command_busy");
}


int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��tikuan
--------------------------------------------------
  �������ĵ���������Ԥ֧Ǯ������У�����Ҫ����
  һ����������
  
--------------------------------------------------

HELP
    );
    return 1;
}
