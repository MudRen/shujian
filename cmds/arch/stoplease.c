/**********************************************************************************
//
//      stoplease.c
//      Created by mychat 31/04/2004
//      �����ҵ�ǩ������� free of use.
//      ��Ȼ����ӭ�޸ġ��Ż��ȡ�
//
//      Email & MSN: codemake@163.com
//      �ļ�λ��/cmds/adm��
// 		
***********************************************************************************/
#include <ansi.h>
#include <room.h>
//#include <roomlease.h>

#ifndef ROOMLEASE_D
#define ROOMLEASE_D "/adm/daemons/roomleased"
#endif
  
int main(object me, string arg)
{
	if(arg=="-s")
	{
		if(ROOMLEASE_D->start_lease()) write("��ҵ��Ӫ���������ָ���\n");
		else write("�ָ�ʧ�� ���� δ���رգ�\n");
		return 1;
	}
	ROOMLEASE_D->stop_lease();
	write("��ҵ��Ӫ����ֹͣ���У�\n");
	return 1;
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��stoplease [-s]
	-s ��ʾ���¿�ʼ
--------------------------------------------------
 stoplease ֹͣroomleased��callouts,�Ա�update

write by mychat@ln(codemake@163.com)
--------------------------------------------------

HELP
    );
    return 1;
}
