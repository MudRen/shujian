// xiaolu1.c �ּ�С��
// by shang 97/6

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"С��"NOR);
	set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ��
������������������Ķ�����
LONG
	);
	set("outdoors", "�䵱");

	set("exits", ([
		"south" : __DIR__"yuanmen",
		"north" : __DIR__"xiaolu1",
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
	myfam =( mapping)me->query("family");

	inv = deep_inventory(me);
	if (dir == "south"){
		if (!userp(me) && me->query("hbtarget"))
			return notify_fail("\n");
		write("������һ��С�����������������ӣ�����ɭɭ���������ء�\n");
		ob = filter_array(inv,(:get_object:));        
		if (me->query_condition("killer") && me->query("family/family_name") != "�䵱��") ;
		else if (myfam && myfam["family_name"] =="�䵱��" && myfam["generation"] == 2 && ! sizeof(ob))
			write("�������߹�������С���������Ų��߳������֡�\n");
		else {
			tell_room(environment(me), me->name()+"�������"YEL"С��"NOR"�첽�뿪��\n"NOR, ({ me }));
			me->move(__DIR__"xiaolu3");
			tell_room(environment(me), me->name()+"��"YEL"С��"NOR"�첽���˹�����\n"NOR, ({ me }));
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
