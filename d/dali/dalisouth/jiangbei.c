// lane@SJ 2005.5.20 fixed bug

#include <ansi.h>
inherit ROOM;
#define SHIP_TO __DIR__"jiangnan"
#define BOAT __DIR__"duchuan"

void create()
{
	set("short", "���׽���");
	set("long", @LONG
��һ������ȥ��֮��ǰ��ŭ����ӿ��ˮ���ļ�������һ����(river����
����ɽʯ���������Ρ�룬�������ƣ����ǵ������׽��ϡ�������ʮ���ɸߣ�
��Ҫ�ߵ�������ȴҲ��ʵ���ס� 
LONG);

	set("exits", ([
		"east" : "/d/foshan/road6",
	]));

	set("item_desc", ([
		"river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
	]));

	set("outdoors", "����");
	set("coor/x",-100);
	set("coor/y",-530);
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

	if( arg == "boat" ) arg = "����";
	if( arg != "����" ) arg = "��";
	if( me->query("age") < 16 )
		message_vision("$Nʹ�����̵���������һ������" + arg + "��\n", me);
	else if( me->query("neili") > 500 )
		message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ���˳�ȥ��\n", me);
	else
		message_vision("$N������������Хһ������" + arg + "����\n", me);

	if( arg == "����" ) {
		if( room = load_object(BOAT) )
		if( !room->query("start") )
			room->arrive("jiangbei");
		else if( query("exits/enter") )
			message_vision("����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n", me);
		else message_vision("������ԶԶ����һ�������ȵȰ���������ˡ�������\n", me);
	} else {
		message_vision("������ԶԶ����һ���������" + arg + "��������\n", me);
		message_vision("��Ȼ��շ���һ�ţ���$N����һ����ͷ��һ���������ȵ������˴���ֹ��������\n", me);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if( dir == "enter" ) {
		if( me->query("can_ride") ) return 0;
		if( me->query_temp("ride_horse") )
			return notify_fail("�����ϴ����㲻�´����ˣ�\n");
		me->set_temp("side", "jiangbei");
	}

	return ::valid_leave(me, dir);
}

int du_jiang()
{
	object me = this_player();
	object room;
	int cost = 600;

	room = load_object(BOAT);

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("����æ���أ�\n");

	if( me->query_temp("ride_horse") )
		return notify_fail("���������㲻��ʩչ��һέ�ɽ����ľ��� ��\n");

	if( me->query_skill("dodge") < 270 )
		return notify_fail("�����Ϊ������\n");

	if( me->query("max_neili") < 3500 )
		return notify_fail("���������Ϊ����������֧�֣���\n");

	if( me->query("neili") < 1000 )
		return notify_fail("������������ˣ�\n");

	if( me->query("jingli") < 1200 )
		return notify_fail("��ľ��������ˣ�\n");

	if( me->query_encumbrance()/100 > me->query("neili") + cost )
		return notify_fail("�����ô�صİ�������·�������⣬��˵���ˣ�\n");

	if( query("exits/enter") ) return notify_fail("�д������������Cool����\n");

	if( room->query("exits/out") ) return notify_fail("����̫���ˣ����û����;�����ĵط�����û����Խ��ȥ��\n");

	me->receive_damage("neili", 300);
	me->receive_damage("jingli", 150);
	tell_room(environment(me), HIC+me->name()+"���˽�������Ʒ�������ų���ƮƮ������Ծ�����׽���\n" NOR, ({me}));
	write("��һ����Ϣ����׼�˽��жɴ�λ�ã�ʹ����һέ�ɽ����Ṧ��Ҫ��Խ���׽���\n");
	me->move(BOAT);
	me->start_busy(3);
	if( me->query("neili") < 1000 || me->query("jingli") < 1200 ) {
		write("�㻹��������ȴ�������������ˡ�\n");
		tell_room(environment(me), HIC+me->name()+"����ƮƮ���ӽ����Ϸ�Ծ������վ�ڴ��ϣ���ڴ�ڴ�������\n" NOR, ({me}));
		return 1;
	}
	tell_room(environment(me), HIC+me->name()+"����ƮƮ���ӽ����Ϸ�Ծ�������ڴ���һ�㣬����԰�Ծ����\n" NOR, ({me}));
	write("���ڽ��жɴ�������һ�㣬������������԰���\n");
	me->move(SHIP_TO);
	tell_room(environment(me), HIC"ֻ��"+me->name()+"����ƮƮ�Ӷ԰�Ծ������̬���������ڰ��ߡ�\n"NOR, ({me}));
	me->receive_damage("neili", 300);
	me->receive_damage("jingli", 150);
	return 1;
}
