// boat2.c С��
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","С��");
	set("long", @LONG
������һҶ����֮�ڣ�������С�쳣�����Ҳ�����ض��������ˡ���˫
�ְ⽰����������Ϫ���С�
LONG
	);
	set("exits", ([ 
		"out"  : __DIR__"xiaoxi",
	]));

	set("outdoors","�����"); 
	set("no_fight", 1); 
	setup();
}

void init()
{
	object me = this_player();
	if (me && environment(me)== this_object())
		message_vision(HIW"\n�ֻ��������Ϫ�ĺ��оſ��ʯӭ����������������һ�㣬��ס������ȥ·��\n\n"NOR,me);
}
