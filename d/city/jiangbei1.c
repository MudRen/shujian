// Room: /d/city/jiangbei1.c

#include <ansi.h>

#define SHIP_TO __DIR__"jiangnan1"
#define BOAT __DIR__"boat1"

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();

void create()
{
	set("short", "��������");
	set("long", @LONG
��ǰ��һ�����η����Ĵ�(river)�� �������������۾����������ɴ���
������������һ�����������̯����Ҿͽ������ڰ��ߣ�֧һ��ľ�壬���ϰ�
���˻�����������㡣��Զ����һ���ڶɣ����ٹ����Ͷ�������ȴ��ɴ���
LONG
	);

	set("exits", ([
		"east" : __DIR__"jiangbei",
	]));

	set("item_desc", ([
		"river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
	]));

	set("outdoors", "����");
	set("coor/x",90);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_yell", "yell");
	add_action("du_jiang", "dujiang");
}

int do_yell(string arg)
{
	object room, me;
	me = this_player();

	if (arg == "boat") arg = "����";
	if (arg != "����") arg = "��";
	if (me->query("age") < 16  )
		message_vision("$Nʹ�����̵���������һ������" + arg + "��\n", me);
	else if (me->query("neili") > 500)
		message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ���˳�ȥ��\n", me);
	else
		message_vision("$N������������Хһ������" + arg + "����\n", me);
	if (arg == "����")
	{
		if (room = load_object(BOAT))
		if (!room->query("start"))
			room->arrive("jiangbei1");
		else if (query("exits/enter"))
			message_vision("����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n", me);
		else message_vision("������ԶԶ����һ�������ȵȰ���������ˡ�������\n", me);
	} else message_vision("������ԶԶ����һ���������" + arg + "��������\n", me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir =="enter") {
		if (me->query("can_ride")) return 0;
		if (me->query_temp("ride_horse"))
			return notify_fail("�����ϴ����㲻�´����ˣ�\n");
		me->set_temp("side", "jiangbei1");
	}

	return ::valid_leave(me, dir);
}

int du_jiang()
{
	object me = this_player();

	if (!living(me)) return 0;

	write("�����ˮ̫��̫������ɲ���ȥ��\n");
	return 1;

}
