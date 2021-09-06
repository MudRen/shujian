//ROOM: /d/dzd/senlin2.c

#include <ansi.h>

inherit __DIR__"dzd_room";

int do_tiao(string arg);

void create()
{
	set("short","��ɭ��");
	set("long",@LONG
����һƬһ���޼ʡ���������ԭʼɭ�֣����˺ϱ��Ĵ������滨��ݾ�Ŀ���ǡ�
��ľ���Ӵ���һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ���һ
�߽�������������ɭ�ֵģ��ƺ�˭���۾���ע�����㣬��ĸо������㣬�øϿ��뿪��
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"east" : __DIR__"senlin3",
		"west" : __DIR__"senlin1",
		"northeast" : __DIR__"mudi",	
		"northwest" : __DIR__"senlin4",
		"southeast" : __DIR__"shulin3",
		"southwest" : __DIR__"shulin2",
	]));
	setup();
}

void init()
{
	object room;
	object me = this_player();
	::init();
	add_action("do_tiao","tiao");
	if(!room = find_object(__DIR__"shuding1"))
		room = load_object(__DIR__"shuding1");
	if(!wizardp(this_player()))
		tell_room(room,"͸����Ҷ�ķ�϶���㿴��" + me->name() + "(" + me->parse_command_id_list()[0] + ")���������¡�\n");
}

int do_tiao(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg || arg != "tree")
		return notify_fail("��Ҫ�����Ķ���\n");
	message_vision(HIY"$N����һ������������������ȥ��\n"NOR,me);
	me->move(__DIR__"shuding1",1);
	message_vision(HIY"$N����������ת���������������ϡ�\n"NOR,me);
	return 1;
}

int valid_leave(object me,string dir)
{
	object room;
	int valid;
	
	valid = ::valid_leave(me,dir);
	if(valid && !wizardp(me) && room = find_object(__DIR__"shuding1"))
		tell_room(room,"��͸����Ҷ�ķ�϶������" + me->name() + "(" + me->parse_command_id_list()[0] + ")�뿪�����¡�\n");
	return valid;
}