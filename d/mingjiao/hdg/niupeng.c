// ţ�� niupeng.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ţ��");
	set("long", @LONG
�����Ǻ����ȵ�ţ���˵�򵹱���������˲���������ʹ�á���������
������ţ�Ĵ�������������
LONG
        );
	set("outdoors", "������");

	set("exits", ([
		"south" : __DIR__"kongdi",
		"northdown" : __DIR__"caojing",
	]));

	setup();
}

int get_object(object ob)
{
	return (userp(ob));
}

int valid_leave(object me, string dir)
{
	object *ob, *inv;
	mapping myfam;

	if(!me) return 0;
	myfam =( mapping)me->query("family");
	inv = deep_inventory(me);
	if (dir == "northdown"){
		write("������һƬ���ԣ�������������㻨�ݡ�\n");
		ob = filter_array(inv,(:get_object:));
		if (myfam && myfam["family_name"] =="����" && myfam["generation"] == 35 && ! sizeof(ob))
			write("�������������Ž����Ľ̻壬�߹�����Ƭ���ԣ������Ų����˽�ȥ��\n");
		else {
			tell_room(environment(me), me->name()+"�������ţ��첽�뿪��\n"NOR, ({ me }));
			me->move(__DIR__"huapu1");
			tell_room(environment(me), me->name()+"�Ӳݾ��첽���˹�����\n"NOR, ({ me }));
			if(me) me->look();
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
