#include <ansi.h>
  
int main(object me, string arg)
{
	DOBET_D->start_dobet();
	return 1;
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��startbetd
--------------------------------------------------
 startetd �ָ��ľּ໤��������
--------------------------------------------------

HELP
    );
    return 1;
}
