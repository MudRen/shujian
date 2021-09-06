// Room: /d/dzd/shidong4.c

#include <ansi.h>

int do_tie(string arg);

inherit __DIR__"dzd_room";

void create()
{
	set("short","����ʯ��");
	set("long",@LONG
��Ȼ�γɵ�����ʯ���������еĵضκ�ֱ���еĵض��ֺ��䣻�еĵض�����԰�еľ���
���ȣ�����ǰ�������г���ɽǰ����·֮�棻���еĵض����������ľ�������������������
��������һ��֮�С����й����������������ȷ紵����
LONG
	);
	set("exits",([
		"southeast" : __DIR__"shidong3",
		"southwest" : __DIR__"shidong1",
		"south" : __DIR__"shidong2",
	]));
	setup();
}

void init()
{
	object room;
	::init();
	add_action("do_tie","tie");
	if(!room = find_object(__DIR__"shibi"))
		room = load_object(__DIR__"shibi");
	if(!wizardp(this_player()))
		tell_room(room,"͸��΢���Ĺ��ߣ��㿴��" + this_player()->name() +"("+this_player()->query("id")+")������ʯ����\n");
}

int do_tie(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg || arg != "shibi")
		return notify_fail("��Ҫ�����Ķ�ȥ��\n");
	message_vision(HIY"$N����һ����������һֻ�޴�������ӵض������������һ��͹���ʯ���ϡ�\n"NOR,me);
	me->move(__DIR__"shibi",1);
	message_vision(HIY"$N����������ת������ڻ�һ�������������ʯ���ϡ�\n"NOR,me);
	return 1;
}

int valid_leave(object me,string dir)
{
	object room;
	int valid;
	
	valid = ::valid_leave(me,dir);
	if(valid && !wizardp(me) && room = find_object(__DIR__"shibi"))
		tell_room(room,"͸��΢���Ĺ��ߣ��㿴��" + me->name() + "(" + me->query("id") + ")�뿪��ʯ����\n");
	return valid;
}
