/**********************************************************************************
//
//      dellease.c
//      Created by mychat 31/04/2004
//      �����ҵ�ǩ������� free of use.
//      ��Ȼ����ӭ�޸ġ��Ż��ȡ�
//
//      Email & MSN: codemake@163.com
//      �ļ�λ��/cmds/adm��
// 		
***********************************************************************************/

//#include <roomlease.h>
#include <ansi.h>
#include <room.h>

int main(object me, string arg)
{
	string roomid;
	string* leasemap=ROOMLEASE_D->query_keys();
	
	if( !arg || sscanf(arg, "%s", roomid)!=1 )
	{
		write("��������!!\n");
		if(leasemap) write(sprintf("Ŀǰ���ã�%s\n",implode(leasemap,",")));
		return 1;		
	}

	if( !ROOMLEASE_D->query_ifhavebidname(roomid) )	
		return notify_fail(HIY"û���������ҪͶ��\n"NOR );
	return ROOMLEASE_D->delete_room(roomid);
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��dellease 	roomid

--------------------------------------------------
�÷����������Ͷ������Ͳ���ɾ����������addlease������������޸�Ϊ0��
��ֹͶ�꣬Ȼ������Ͷ���������ɾ����

write by mychat@ln(codemake@163.com)
--------------------------------------------------

HELP
    );
    return 1;
}
