// boat3.c С��
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
	if (!me || environment(me)!= this_object()) return;
	tell_object(me, HIC"\n\n����һ��С���ѻ���һ����խ��Ϫˮ֮�У����벻�������Ȼ���ж��졣\n"+
			"����ɽ�������Ϫ��ɽʯ��ˮ�治�����ߣ�����ú��Բ��У�С��ʼ�ܻ��롣\n"+
			"̧ͷ���죬ֻ��һ�ߣ���ɫ�������ģ�ֻ�����¾�������Ϣ������͸�����ա�\n\n"NOR);
	me->move(__DIR__"boat4", 1);
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}
