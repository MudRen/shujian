#include <ansi.h>
  
int main(object me, string arg)
{
	DOBET_D->stop_dobet();
	return 1;
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��stopbetd
--------------------------------------------------
 stopbetd ֹͣ�ľּ໤��������
--------------------------------------------------

HELP
    );
    return 1;
}
