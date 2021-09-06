// Room: /d/dzd/mudi.c

#include <ansi.h>

inherit __DIR__"dzd_room";

void create()
{
	set("short","�ּ�Ĺ��");
	set("long",@LONG
�����Ǻ�ɭ�ֵ����ĵش���ȴһ����Ҳû��,������������һ����Ĺ��Ĺ��(mubei)�����ͺͺ�ģ�
�����Լ��Щ�ּ������㲻������ϸ��(kan)һ�¡�
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"east" : __DIR__"senlin5",
		"west" : __DIR__"senlin4",
		"north" : __DIR__"senlin7",
		"northeast" : __DIR__"senlin8",
		"northwest" : __DIR__"senlin6",
		"southeast" : __DIR__"senlin3",
		"southwest" : __DIR__"senlin2",	
	]));
	set("item_desc",([
		"mubei" : "����һ��Ĺ���������ͺͺ�ģ������Լ��Щ�ּ���\n",
		"fenmu" : "һ����֪���ķ�Ĺ�����泤����Ұ�ݡ�\n",
	]));
	set("play_huqin",1);
	setup();
}

void init()
{
	::init();
	add_action("do_kan","kan");
}

int do_kan(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg || arg=="" || arg!="mubei")
		return notify_fail("��Ҫ��ʲô?\n");
	message_vision(HIY"Ĺ����д��������:\n\n"NOR HIW"ʮ��������ãã����˼������������ǧ��·أ��޴���������
��ʹ���Ӧ��ʶ�������棬����˪��\n\nҹ�����κ����磬С����������ױ��������ԣ�Ω����ǧ�У�
�������곦�ϴ�������ҹ�����ɸڡ�\n\n"NOR,me);
	message_vision(HIB"�������״ʣ��㲻�ɵ��������Լ����������£���������,���Ը��ӡ�\n"NOR,me);
	me->set_temp("dzd_quest/look_bei",1);
	return 1;
}
/*
 *int valid_leave(object me,string dir)
 *{
 *	this_player()->delete_temp("look_bei");
 *	return 1;
 *}
*/