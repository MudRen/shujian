// home.c
// Modified by snowman@SJ 27/06/2000


#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg, workroom;

	workroom = "/u/" + geteuid(me) + "/workroom.c";
	if( file_size(workroom) <= 0 ){
		workroom = "/d/wizard/wizard_meet.c";
		if( file_size(workroom) <= 0 )
			return notify_fail("��û���Լ��Ĺ����ҡ�\n");
	}
	
	if( stringp(msg = me->query("env/msg_home")) )
		message_vision(msg + "\n", me);
	me->move(workroom);
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : home

���ô�һָ���ֱ�ӻص��Լ��Ĺ����ҡ�
������� 'msg_home' ����趨, ���ڳ����˶��ῴ���Ǹ�ѶϢ.
HELP
    );
    return 1;
}
