// Room: /d/plummanor/road2.c
// By Jpei
// Update by Lklv 2001.10.9

inherit ROOM;
#include "make_maze.c"

void create()
{
	set("short", "С·");
	set("long", @LONG
�����Ѿ�����÷��ǰ�棬ֻ����ض���÷����֦Ҷï�ܡ��������÷��ʢ
��֮ʱ����ѩ�纣����Ȼ���Ͳ����������һ��С·����������
LONG
	);
	set("outdoors","÷ׯ");

	set("item_desc", ([
		"south" : "÷����ӳ���㿴�����Ǳߵ������\n",
	]) );
	set("exits", ([
		"north" : __DIR__"road1",
		"south" : __DIR__"plum_maze",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	int can_leave;
	object ob;

	can_leave = ::valid_leave(me, dir);
	if (dir == "south" && can_leave) {
		if (objectp(ob = me->query_temp("follow"))) {
			me->set_leader(0);
			tell_object(me, ob->name() + "�߽�÷�֣�һ�ξͲ����ˡ�\n");
			return 0;
		}
		if (me->query("env/brief")) {
			me->delete("env/brief");
			tell_object(me, "��Ƭ÷���������ۣ������ȡ������ʱ�ļ������ģʽ��\n");
		}
		make_maze(me);
		me->set_temp("plum_maze/x", me->query_temp("plum_maze/north_exit") + 1);
		me->set_temp("plum_maze/y", 1);
	}
	return can_leave;
}
