// by dubei
// Modify By River@sj 99.5.24
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
       set("short", YEL"ɽ·"NOR);
       set("long", @LONG
����һ����᫵�ɽ·��·���ϼ�����һЩ��ɳ����ϥ��Ұ�ݼ�����·����
���ˣ���������Ұ��Ʈ�������㡣������һƬ���֣���ʱ����һ�����Ұ��
����, ͷ����һЩ��֪����С����������ȥ��
LONG
    );

       set("outdoors", "����");

       set("exits", ([
           "south" : __DIR__"xiaolu4",
           "northup" : __DIR__"xiaolu2",
       ]));

       setup();
}

int valid_leave(object me, string dir)
{
	object *inv;

	if (dir == "south") {
		write("������һƬ�ֺ�����ʱ����һ�����Ұ�޽���, \n");
                inv = filter_array(deep_inventory(me), (: userp :));
		if (me->query("ygpass") && ! sizeof(inv))
			write("�������Ѿ���������������ָ�������Բ��ö��룬�Ų����߳����ֺ���\n");
		else {
			tell_room(environment(me), me->name()+"�������"CYN"����"NOR"�첽�뿪��\n"NOR, ({ me }));
			me->move(__DIR__"linhai" + (random(10) + 1));
			tell_room(environment(me), me->name()+"��"YEL"ɽ·"NOR"�첽���˹�����\n"NOR, ({ me }));
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
