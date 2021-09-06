// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�ؾ����¥");
	set("long", @LONG
ǧ������������ִ��ԭ����֮ţ�����Դ�Ħ�������£������˲ı�������
���в��ٸ�ɮ�������棬�㼯�����ճ��������µ�������ʮ�����ա����־�
���������ڴˡ���¥���濪����ȷ��ͨ�硣�м����������Ŵ���ܡ��������
�а������Թ��Ķ�����λ��ɮ��ִ�������ڱ�Ŀ��˼��
LONG
	);

	set("exits", ([
		"down" : __DIR__"cjlou",
	]));
	set("cant_hubiao", 1);
	set("objects",([
		CLASS_D("shaolin") + "/hui-zhen" : 1,
		__DIR__"obj/wuji1" : 1,
		__DIR__"obj/wuji2" : 1,
		__DIR__"obj/wuji3" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if ((ob = present("huizhen zunzhe", this_object())) && living(ob))
		if (dir == "down" ) {
			foreach(ob in deep_inventory(me))
				if (ob->id("shaolin wuji"))
					return notify_fail("����˵�����书�ؼ�ֻ���ڲؾ�������ϰ������Я�������\n");
		}
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_jump", ({ "jump", "tiao" }));
	add_action("do_tui", ({ "tui", "push" }));
} 

int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "chuang" ) return 0;
	if ( !arg ) return 0;
	if (!me->query_temp("marks/��"))
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���ء�\n");
	if( (int)me->query_skill("dodge",1) < 100 ) {
		message_vision(HIR"$N�ƿ�����������Ծ��ֱ�����⣬�����Ṧ������ˤ��������\n"NOR, me);
		me->unconcious();
		return 1;     
	}
	message_vision("$N�ƿ�����������Ծ��������һգ�۾Ͳ����� ��\n", me);
	me->move(__DIR__"xiaojin1");
	tell_room(environment(me), me->name() + "�Ӳؾ������Ծ�˹�����\n", ({ me }));
	me->delete_temp("marks/��");
	return 1;
}

int do_tui(string arg)
{
	object me = this_player();

	if( !arg || arg !=  "chuang") return 0;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	write("������Ľ��ؾ���Ĵ����ƿ���\n");
	me->set_temp("marks/��", 1);
	return 1;
}
