/**********************************************************************************
//
//      hq.c
//      Created by mychat 31/04/2004
//      �����ҵ�ǩ������� free of use.
//      ��Ȼ����ӭ�޸ġ��Ż��ȡ�
//
//      Email & MSN: codemake@163.com
//      �ļ�λ��/cmds/usr��
// 		
***********************************************************************************/
#include <ansi.h>
//#include <roomlease.h>

#ifndef ROOMLEASE_D
#define ROOMLEASE_D "/adm/daemons/roomleased"
#endif

int main(object me, string arg)
{
	string outstr;
	
        if (!wizardp(me) && me->query_temp("command_busy"))
                return notify_fail("����æ���ء�\n");
        me->set_temp("command_busy",1);
        call_out("remove_busy", 3, me);
        if(arg && arg=="me") outstr=ROOMLEASE_D->query_list(me->query("id"));
        else outstr=ROOMLEASE_D->query_list();
	if(!outstr)
		return notify_fail("û���κγ�����̵���Ϣ��Ҫ����wiz����ȥ��\n");
	me->start_more( outstr );
	return 1;
}

void remove_busy(object me)
{
        if (me) me->delete_temp("command_busy");
}


int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��hg [me]
--------------------------------------------------
  ����ǰͶ�������
  ʹ�ò���me��ʾ�鿴���Լ���ص�����
  
--------------------------------------------------

HELP
    );
    return 1;
}
