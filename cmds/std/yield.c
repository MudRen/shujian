// yield.c
// Created by snowman@SJ 1998

#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg) {
	     	if(me->query_temp("combat_yield"))
			arg = "no";
		else
			arg = "yes";
       	}

	if (arg == "yes") {
		if (me->is_busy())
			return notify_fail("����æ���ء�\n");
		if (me->is_perform())
			return notify_fail("������ʹ��"+me->query_perform()+"����ʱ�޷��򲻻��֡�\n");
		me->set_temp("combat_yield", 1);
		me->remove_all_enemy();
       		tell_object(me, "��������ʱ�򲻻��֡�\n");
    	}
	else if( arg == "no"){
	    	me->delete_temp("combat_yield");
	     	tell_object(me, "��������ʱ���ַ�����\n");
      	}
	else return notify_fail("�������ܻ���(yield no)���ǲ�����(yield yes)��\n");

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : yield <yes | no>
 
���ָ���������������ʱ�Ƿ��ַ�����
 
HELP
    );
    return 1;
}
