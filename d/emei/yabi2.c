// yabi2.c
// �±�

inherit ROOM;
#include <ansi.h>
void create()
{	
	set("short", "�±�");
	set("long",@long
��վ���±��ϵ�ʯ��䣬Ҫ������ס�±�ͻ���ĵط��Ų�����ˤ��ȥ��ʯ
�������ɳʯ��ľ��ʲôҲû�С�
long);
	setup();
}

void init()
{
	add_action("do_pa", "pa");
}
int do_pa(string arg)
{
	object me = this_player();

	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("����æ���ģ�\n");

	if(!arg || arg == "" || arg != "down")	{
	write(HIR"��һ��û����ƽ�⣬ֻ���ö��ߺ����������죬����ɿ������׺ȥ....\n"NOR, me);
	write(HIC"ֻ������ͨһ�����������һ����ˮ̶�У���ཹ�ེ��˺ü���ˮ....\n"NOR, me);
	write("�����ϵ�Ǯ�ﶼ����ˮ�У���Ҳ�Ҳ����ˡ�\n");
	me->move(__DIR__"shuitan");
	me->unconcious();
	me->set("water", 666);
	return 1;
}
	
	if( arg == "down") {
	message_vision("$N�����±����±���ȥ��\n", me);
	me->move(__DIR__"shangu");
	message_vision("$N�������´���������\n", me); 
	return 1; }
}