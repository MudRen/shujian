#include <wanted.h>

int valid_leave(object me, string dir)
{
	object ob;
	if (base_name(this_object())==__DIR__"silk8" && dir == "south" && (is_wanted(me) || !userp(me)))
		return 0;

	if(me->query_temp("wait_target") && objectp(present("anran zi", environment(me))))
		return notify_fail("��Ȼ��������������ǰ���ȵ�������������ҹ�������\n");

	if(me->query_temp("xx_rob") 
	&& objectp(ob = present("hubiao biaoshi", environment(me)))
	&& ob->query("target") == me)
		return notify_fail("������ʦ������ס���ȥ·�����������������ˣ�\n");  

	if(me->query_temp("xx_rob") && objectp(present("shangdui", environment(me))))
		return notify_fail("�̶��������أ�����(qiang)����\n");  

	return ::valid_leave(me, dir);
}
