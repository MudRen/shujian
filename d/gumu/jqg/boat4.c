// boat4.c ����
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
	set("outdoors","�����"); 
	set("no_fight", 1); 

	setup();
}

void init()
{
	object me= this_player();
	add_action("do_quit","quit");
	call_out("run", 8, me);
}

void run(object me)
{
	if( !me ) return;
	if (environment(me)!= this_object()) return;
	tell_object(me, HIC"\n\nԶɽ���̣�Ϫˮտ��������Զɽ��ӳ��տ����Ϫˮ�У��������̣���Ũ������\n"+
		"Ϫ�����ۣ�С�۾������˼�������������ܿ���Ϫ�԰�������������ټ���\n\n"NOR);
	me->move(__DIR__"boat5", 1);
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}
