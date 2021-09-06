// Room: /d/emei/shierpan3.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "ʮ����" NOR);
	set("long", @LONG
����ʯ�׶��۶��䣬�ųơ�ʮ���̡������·���и������أ�����������
���л���(clap)���ɴ����Ͽɴﻪ�϶��������������֡�
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([ 
  "eastdown" : __DIR__"shierpan2",
  "southwest" : __DIR__"shierpan4",
]));
	setup();
}
int valid_leave(object me, string dir)
{
 if (dir == "southwest" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex"));
      me->receive_damage("jingli",  (int)me->query("dex"));
     return 1; }     return ::valid_leave(me, dir);

} 
void init()
{
	add_action("do_clap", "clap");
}

int do_clap()
{
	object me;
	me = this_player();

        if (me->is_busy() || me->is_fighting())
	return notify_fail("����æ���ģ�\n");

	if((int)me->query("jingli", 1) < 15 )
	return notify_fail("��̫���ˣ����Ǻú���Ϣ�ɡ�\n");

	if( (int)me->query_skill("strike", 1) > 40 ) {
	message_vision("$N����������ػ��ơ�\n", me);
	me->receive_damage("jingli", 15);
	return 1;
	}
	if( (int)me->query_skill("strike", 1 ) < 40 ) {
	message_vision("$N����������ػ��ơ�\n", me);
	me->receive_damage("jingli", 10+random(10));
	me->improve_skill("strike", (int)me->query("str"));
	return 1;
	}
}