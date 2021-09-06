// Room: /tiezhang/zoulang-2.c

#include <ansi.h>
inherit ROOM;

int get_object(object ob);
void create()
{
	set("short", "����");
	set("long", @LONG
������һ�����ȣ������Ϻܾ��������ƺ�����һ������Ļ�����������
��һ���鷿�����ư�ĵ���ƽ������������ù���
LONG
	);

	set("exits", ([
		"west" : __DIR__"zoulang-3",
		"east" : __DIR__"wztang",
		"north" : __DIR__"shufang",
	]));
	setup();
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me, string dir)
{
	object obj;
        mapping fam = me->query("family");
        object *inv = deep_inventory(me);
        if(dir == "north"){
		if(!fam || fam["family_name"]!= "���ư�")
			return notify_fail("ͻȻ�и����������������" + RANK_D->query_respect(me) +"�������ư���ˣ����ý�����ء�\n");
		if (me->query_condition("killer"))
			return notify_fail("ͨ������׼���ڡ�\n");
		obj = filter_array(inv,(:get_object:));
        	if(sizeof(obj)){
			write (HIR"�����͵͵�����˽�ȥ���������̫�࣬����һ����˩��ˤ���ڵء�\n"NOR);
			me->move(__DIR__"zoulang-2");
			me->unconcious();
			return 1;
		}
	}
	return ::valid_leave(me, dir);
}
