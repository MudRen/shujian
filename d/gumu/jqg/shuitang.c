// shuitang.c ˮ��
// By River 99.5.25
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","ˮ��");
	set("long",@LONG
�������֣�ͻȻһ������ӿ������ǰ�ޱ��޼ʵ�ȫ��ˮ�ɻ���ԭ��������
ǳǳ��һƬˮ�������ߣ�������ˮ�ɣ��⻨��ԭ���Ϸ�֮���֪���Ծ�
���ڹ���֮���ɽ�����֡�
LONG
);

	set("outdoors","�����");
	set("exits",([
		"eastup": __DIR__"shanding",
		"westdown": __DIR__"qsroad",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;
	
	i = me->query("kar") + me->query_int();

	if (dir == "eastup") {
		write("������һ��Ƭ���֣��������ټ��������ï�ܵ����֣�����֮��ȷʵ������\n");
		inv = filter_array(deep_inventory(me), (: userp :));
		if ( random(i) > 20 && ! sizeof(inv))
			write(HIW"\n�㻺�����������д������ŵ�һ���󵭵����㣬�Ǿ����׾�����\n\n"NOR);
		else {
			tell_room(environment(me), me->name()+"�����ߵ�"GRN"����"NOR"�첽�뿪��\n"NOR, ({ me }));
			me->move(__DIR__"zhulin" + (random(6) + 1));
			tell_room(environment(me), me->name()+"��ˮ���첽���˹�����\n"NOR, ({ me }));
			me->look();
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
