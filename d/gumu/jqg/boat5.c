// boat5.c С��
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","С��");
	set("long", @LONG
������һҶ����֮�ڣ�������С�쳣�����Ҳ�����ض��������ˡ���˫
�ְ⽰��������˳Ϫ���¡�
LONG
	);
	set("exits", ([ 
		"out"  : __DIR__"xibian",
	]));

	set("no_fight", 1); 
	set("outdoors","�����"); 
	setup();
}

void init()
{
	object ob = this_player();
	if (ob && environment(ob)== this_object())
		message_vision(HIW"\n�ֻ��������Ϫ�����ۣ�С�۾������˼�������ֻص�Ϫ�ߡ�\n\n"NOR,ob);
}
