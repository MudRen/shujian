// Room: /d/plummanor/plum_maze.c //÷�ֵ�·���Թ�
// By Jpei

inherit ROOM;

#include <ansi.h>
#include "make_maze.c"

int do_look(string arg);
int do_set(string arg);
int do_follow(string arg);

void create()
{
	set("short", "÷��");
	set("long", @LONG
����÷���е�һ��С·���Ĵ���ض���÷����֦Ҷï�ܵ�����ն�����ס
�ˣ����ѿ�����Χ�������
LONG
	);
//	set("outdoors","÷ׯ");

	set("exits", ([
		"north" : __FILE__,
		"south" : __FILE__,
		"west" : __FILE__,
		"east" : __FILE__,
	]));
	setup();
}

void init()
{
	object me = this_player();
	int x, y;

	x = me->query_temp("plum_maze/x");
	y = me->query_temp("plum_maze/y");
	if (!x || !y) {
		make_maze(me);
		me->set_temp("plum_maze/x", random(MAZE_WIDTH) + 1);
		me->set_temp("plum_maze/y", random(MAZE_HEIGHT - 6) + 4);
	}
	add_action("do_look", "look");
	add_action("do_set", "set");
	add_action("do_follow", "follow");
	set("exits", ([
		"north" : __FILE__,
		"south" : __FILE__,
		"west" : __FILE__,
		"east" : __FILE__,
	]));
}

int do_set(string arg)
{
	if (arg && arg[0..4] == "brief") {
		write("��Ƭ÷���������ۣ��㻹�ǲ�Ҫʹ������ʱ�ļ������ģʽ�ɡ�\n");
		return 1;
	}
	return 0;
}

int do_follow(string arg)
{
	object ob, me = this_player();

	if (!arg || arg == "none") return 0;
	if (!objectp(ob = present(arg, environment(me)))) return 0;
	if (ob == me || !ob->is_character()) return 0;
	write("��Ƭ÷���������ۣ����Ǻ��Ѹ�����һ�������ߵģ����Ǳ�׷������ˡ�\n");
	return 1;
}

int do_look(string arg)
{
	object *inv, env, me = this_player();
	int i, x, y, can_n, can_e, can_w, can_s, path, exit_num;
	string str;

	x = me->query_temp("plum_maze/x") - 1;
	y = me->query_temp("plum_maze/y") - 1;
	path = me->query_temp("plum_maze/" + x + "_" + y);
	can_n = path & LINK_UP;
	can_w = path & LINK_LEFT;
	can_e = path & LINK_RIGHT;
	can_s = path & LINK_DOWN;
	exit_num = 0;
	if (can_n) exit_num++;
	if (can_w) exit_num++;
	if (can_e) exit_num++;
	if (can_s) exit_num++;
	
	if (!arg) {
		env = this_object();
		if (x == me->query_temp("plum_maze/north_exit") && y == 0) {
			can_n = 1;
			exit_num++;
			set("long", @LONG
����÷���е�һ��С·��С·�����ͳ���÷�֣���Զ���ƺ����������ߡ�
�Ĵ���ض���÷����֦Ҷï�ܵ�����ն�����ס�ˣ����ѿ�����Χ�������
LONG
			);
		}
		else if (x == me->query_temp("plum_maze/south_exit") && y == MAZE_HEIGHT - 1) {
			can_s = 1;
			exit_num++;
			set("long", @LONG
����÷���е�һ��С·��С·���Ͼͳ���÷�֣�Զ����Լ�ֳ���ǽ���ƺ�
��һ����ׯԺ���Ĵ���ض���÷����֦Ҷï�ܵ�����ն�����ס�ˣ����ѿ���
��Χ�������
LONG
			);
		}
		else if (exit_num > 1)
			set("long", @LONG
����÷���е�һ��С·���Ĵ���ض���÷����֦Ҷï�ܵ�����ն�����ס
�ˣ����ѿ�����Χ�������
LONG
			);
		else
			set("long", @LONG
����÷���е�һ��С·�����Ѿ��ߵ���С·�ľ�ͷ��ֻ�л�ͷ�ˡ��Ĵ���
�ض���÷����֦Ҷï�ܵ�����ն�����ס�ˣ����ѿ�����Χ�������
LONG
			);
		str = sprintf( "%s - %s\n    %s%s",
			env->query("short"),
			wizardp(me)? file_name(env): "",
			env->query("long"),
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

		if (exit_num == 1) {
			if (can_n)
				str += "    ����Ψһ�ĳ����� " + BOLD + "north" + NOR + "��\n";
			else if (can_s)
				str += "    ����Ψһ�ĳ����� " + BOLD + "south" + NOR + "��\n";
			else if (can_w)
				str += "    ����Ψһ�ĳ����� " + BOLD + "west" + NOR + "��\n";
			else if (can_e)
				str += "    ����Ψһ�ĳ����� " + BOLD + "east" + NOR + "��\n";
		}
		else {
			str += "    �������Եĳ����� " + BOLD;
			if (can_n) {
				str += "north";
				exit_num--;
				if (exit_num > 1)
					str += "��";
				else
					str += NOR + " �� " + BOLD;
			}
			if (can_w) {
				str += "west";
				exit_num--;
				if (exit_num > 1)
					str += "��";
				else if (exit_num)
					str += NOR + " �� " + BOLD;
				else
					str += NOR + "��\n";
			}
			if (can_e) {
				str += "east";
				exit_num--;
				if (exit_num)
					str += NOR + " �� " + BOLD;
				else
					str += NOR + "��\n";
			}
			if (can_s) {
				str += "south";
				str += NOR + "��\n";
			}
		}

		inv = all_inventory(env);
		for (i = 0; i < sizeof(inv); i++) {
			if (inv[i] == me) continue;
			if (!me->visible(inv[i])) continue;
			str += "  " + inv[i]->short() + "\n";
		}

		write(str);
		return 1;
	}
	if (arg == "north") {
		if (x == me->query_temp("plum_maze/north_exit") && y == 0) {
			can_n = 1;
/*			set("exits/north", __DIR__"road2");
			return 0;*/
		}
		if (can_n) write("÷����ӳ���㿴�����Ǳߵ������\n");
		else write("��Ҫ��ʲô��\n");
		return 1;
	}
	if (arg == "south") {
		if (x == me->query_temp("plum_maze/south_exit") && y == MAZE_HEIGHT - 1) {
			can_s = 1;
/*			set("exits/south", __DIR__"road3");
			return 0;*/
		}
		if (can_s) write("÷����ӳ���㿴�����Ǳߵ������\n");
		else write("��Ҫ��ʲô��\n");
		return 1;
	}
	if (arg == "west") {
		if (can_w) write("÷����ӳ���㿴�����Ǳߵ������\n");
		else write("��Ҫ��ʲô��\n");
		return 1;
	}
	if (arg == "east") {
		if (can_e) write("÷����ӳ���㿴�����Ǳߵ������\n");
		else write("��Ҫ��ʲô��\n");
		return 1;
	}
	return 0;
}

int valid_leave(object me, string dir)
{
	object ob;
    int x, y, can_n, can_e, can_w, can_s, path;
	string min;

	if (objectp(ob = me->query_temp("follow"))) {
		me->set_leader(0);
		tell_object(me, ob->name() + "��÷������ת��ת��һգ�۾Ͳ����ˡ�\n");
		return 0;
	}
	if (me->query("env/brief")) {
		me->delete("env/brief");
		tell_object(me, "��Ƭ÷���������ۣ������ȡ������ʱ�ļ������ģʽ��\n");
	}
	x = me->query_temp("plum_maze/x") - 1;
	y = me->query_temp("plum_maze/y") - 1;
	path = me->query_temp("plum_maze/" + x + "_" + y);
	can_n = path & LINK_UP;
	can_w = path & LINK_LEFT;
	can_e = path & LINK_RIGHT;
	can_s = path & LINK_DOWN;

	if (dir == "north") {
		if (x == me->query_temp("plum_maze/north_exit") && y == 0) {
			me->delete_temp("plum_maze");
			me->move(__DIR__"road2");
			min = "";
			if (me->is_fighting())
				min += "��÷�ֵ���ײײ�����˹�����ģ����Щ�Ǳ���\n";
			else {
				min += me->query_condition("killer") ? "��ɫ���ŵ�" : "";
				min += "��÷�ֿ첽���˹�����\n";
			}
			tell_room(environment(me), me->name() + min, ({me}));
			return notify_fail("");
		}
		if (can_n) {
			me->add_temp("plum_maze/y", -1);
			return 1;
		}
		return notify_fail("�������û�г�·��\n");
	}
	if (dir == "south") {
		if (x == me->query_temp("plum_maze/south_exit") && y == MAZE_HEIGHT - 1) {
			me->delete_temp("plum_maze");
			me->move(__DIR__"road3");
			min = "";
			if (me->is_fighting())
				min += "��÷�ֵ���ײײ�����˹�����ģ����Щ�Ǳ���\n";
			else {
				min += me->query_condition("killer") ? "��ɫ���ŵ�" : "";
				min += "��÷�ֿ첽���˹�����\n";
			}
			tell_room(environment(me), me->name() + min, ({me}));
			return notify_fail("");
		}
		if (can_s) {
			me->add_temp("plum_maze/y", 1);
			return 1;
		}
		return notify_fail("�������û�г�·��\n");
	}
	if (dir == "west" && can_w) {
		me->add_temp("plum_maze/x", -1);
		return 1;
	}
	if (dir == "east" && can_e) {
		me->add_temp("plum_maze/x", 1);
		return 1;
	}
	return notify_fail("�������û�г�·��\n");
}
