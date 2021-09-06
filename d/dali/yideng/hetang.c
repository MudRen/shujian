// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", @LONG
���к�ҶƬƬ�������˼��ɾ����ɻ���䣬������ʩ����һ��ں�����
ͷʯ�ź�����һ����Ժ�����ƻֺ룬��͸�������ȣ��Ա�������ɽ����ɽ����
�и����ڣ����Ǹ�ͨ��(tongdao)��
LONG
	);
	set("outdoors", "��Դ��");
	set("exits", ([
		"north" : __DIR__"shiqiao",
		"south" : __DIR__"liang",
	]));

	setup();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me = this_player();

	if ( ! arg || arg != "tongdao" ) return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	message_vision("$Nһë�������һ��ֱ��ɽ�µĿ��ͨ����\n", me);
	me->move(__DIR__"caowu");
	tell_room(environment(me), me->name() + "��ͨ�������˹�����\n", ({ me }));
	return 1;
}
