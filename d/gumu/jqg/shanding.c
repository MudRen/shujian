// shanding.c ɽ��
// By River 99.5.25
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","ɽ��ƽ��");
	set("long",@LONG
ɽ�����ܲ�ľ������Σ������ƽ���һ·�����Ƿ����ʤ���˴����Ǹ���
��������֮�أ��Ų����У�ֻ��·���ɺ���������¹��Ⱥ������С�ã����Ǽ�
�˲���������һ��ɽ·��֪ͨ���δ���������һ��Ƭ���֡�
LONG
);
	set("outdoors","�����"); 
	set("exits",([
		"southdown": __DIR__"shanjing1",
		"west": __DIR__"xshiwu",
		"east": __DIR__"shanlu4",
		"northdown": __DIR__"shuitang"
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;
	
	i = me->query("kar") + me->query_int();

	if (dir == "northdown") {
		write("������һ��Ƭ���֣��������ټ��������ï�ܵ����֣�����֮��ȷʵ������\n");
		inv = filter_array(deep_inventory(me), (: userp :));
		if ( random(i) > 20 && ! sizeof(inv))
			write(HIW"\n�㻺�����������д������ŵ�һ���󵭵����㣬�Ǿ����׾�����\n\n"NOR);
		else {
			tell_room(environment(me), me->name()+"�����ߵ�"GRN"����"NOR"�첽�뿪��\n"NOR, ({ me }));
			me->move(__DIR__"zhulin" + (random(6) + 1));
			tell_room(environment(me), me->name()+"��ɽ��ƽ�ؿ첽���˹�����\n"NOR, ({ me }));
			me->look();
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
