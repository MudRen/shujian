// shuitan.c
// ˮ̶

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","ˮ̶");
	set("long",@long
����һ����ˮ̶��̶��ˮ�����ޱȣ�һ�¾Ͱ��㼤���ˡ�̶ˮ��������
��ȥ������ɽʯ���ͣ�ɽ��������Ρ���֪�����������أ�
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

	if(!arg || arg == "" || arg != "up")	
	return notify_fail("��Ҫ����������\n");
	
	if( arg == "up") {
          if(me->query("jingli") < 100)
                 return notify_fail("��������ȥ������ȴ�����Լ�ȫ��������\n");
	  me->move(__DIR__"qingyinge");
          me->add("jingli", -100);
	  message_vision("$Nˮ���ܵشӽ�������������\n", me);
          me->start_busy(1);
	  return 1; }
}
