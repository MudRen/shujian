// Room: /d/plummanor/road3.c
// By Jpei
// Update by Lklv 2001.10.9

inherit ROOM;
#include "make_maze.c"

void create()
{
	set("short", "��ʯ���·");
	set("long", @LONG
�����Ѿ�����÷��ǰ�棬ֻ����ض���÷����֦Ҷï�ܡ��������÷��ʢ
��֮ʱ����ѩ�纣����Ȼ���Ͳ�����������һ�����Ű�ǽ�Ĵ�ׯԺ��
LONG
	);
	set("outdoors","÷ׯ");

	set("item_desc", ([
		"north" : "÷����ӳ���㿴�����Ǳߵ������\n",
	]) );
	set("exits", ([
		"south" : __DIR__"door",
		"north" : __DIR__"plum_maze",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	int can_leave;
	object ob;

	can_leave = ::valid_leave(me, dir);
	if (dir == "north" && can_leave) {
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
		me->set_temp("plum_maze/x", me->query_temp("plum_maze/south_exit") + 1);
		me->set_temp("plum_maze/y", MAZE_HEIGHT);
	}
	return can_leave;
}