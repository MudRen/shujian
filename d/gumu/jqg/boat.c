// boat.c ����
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
	set("outdoors","�����"); 
	set("no_fight", 1); 

	set("ppl", 0);

	setup();
}

void init()
{
	object me= this_player();
	add_action("do_quit","quit");
	set("ppl", 1);
	call_out("run", 8, me);
}

void run(object me)
{
	set("ppl", 0);
	if (!me || environment(me)!= this_object()) return;
	tell_object(me, HIC"\n\nԶɽ���̣�Ϫˮտ��������Զɽ��ӳ��տ����Ϫˮ�У��������̣���Ũ������\n"+
			"Ϫ�����ۣ�С�۾������˼��������ȻҲ������Ϫ�԰�������������ټ���\n\n"NOR);
	me->move(__DIR__"boat1", 1);
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}
