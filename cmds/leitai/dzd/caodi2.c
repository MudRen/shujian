// Room: /d/dzd/caodi2.c

#include <ansi.h>

inherit __DIR__"dzd_room";

int do_zuan(string arg);

void create()
{
	set("short","�ݵ�");
	set("long",@LONG
������һƬˮ�ݽ�����ʪ�ء�������Ţ���С����紵�������쳤��֮���ֳ������ŵ�
���۰׹ǣ��ƺ��������㣬�˴���Ȼ�ƺ��ž����ˣ�ȴ�ǰ���ɱ��������Ͷ����汻һ��
Ϫ�������š�
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"north" : __DIR__"caodi3",
		"east" : __DIR__"xiliu2",
		"south" : __DIR__"caodi1",
	]));
	set("objects",([
		__DIR__"npc/snake" : 1,
	]));
	setup();	
}

void init()
{
	object room;
	::init();
	add_action("do_zuan","zuan");
	if(!room = find_object(__DIR__"caocong"))
		room = load_object(__DIR__"caocong");
	if(!wizardp(this_player()))
		tell_room(room,"͸���ݴԵķ�϶���㿴��" + this_player()->name() +"(" + this_player()->query("id")+ ")���������\n");
}

int do_zuan(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg || arg != "caocong")
		return notify_fail("��Ҫ�굽�Ķ���\n");
	message_vision(HIY"$Nһ�����굽�ԱߵĲݴԣ�˲����Ѳ�����\n"NOR,me);
	me->move(__DIR__"caocong",1);
	message_vision(HIY"$N���˴��Ĳ�ï��֮�����������������\n"NOR,me);
	return 1;
}

int valid_leave(object me,string dir)
{
	object room;
	int valid;
	
	valid = ::valid_leave(me,dir);
	if(valid && !wizardp(me) && room = find_object(__DIR__"caocong"))
		tell_room(room,"͸���ݴԵķ�϶���㿴��" + me->name() + "(" + me->query("id") + ")�뿪�����\n");
	return valid;
}
