// LKlv modify 2001.10.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"�󱯵�"NOR);
	set("long", @LONG
�󱯵�ϵȡ��Ҵ�ȴ�֮�⣬�������ıڻ����˷��ʮ�̵ȴ�ȴ�
֮�¡�ϵ�ҷ����ڤ����������������ר�����ڣ����ϰ��ż������ţ���
����������ľ�㡣��λɮ�������Ŀ�Ͼ��������ĵ�����
LONG
 );
	set("exits", ([
		"north" : __DIR__"hguangz2",
		"west"  : __DIR__"xumidian",
		"south" : __DIR__"stoneroad1",
	]));
        set("objects",([
		CLASS_D("shaolin") + "/dao-zheng" : 1,
		__DIR__"obj/muchui" : 1,
	]));

	setup();

}

void init()
{
	object me = this_player();

	if (!me->query_temp("mx_times"))
		me->set_temp("mx_times", random(35)+10);
        add_action("do_mingxiang", "mingxiang");
}

int do_mingxiang()
{
	object me, ob;
	me = this_player();

	if ( me->query_temp("mx_times") == 0 ){
		message_vision(HIR"$N����һ�����������ϵ�����ȥ��\n"NOR, me);
		me->set_temp("mx_times", random(35)+10);
		me->unconcious();
		return 1;
        }
	me->add_temp("mx_times", -1);
	message_vision("$N�ϵع��������ϱ�Ŀڤ˼��\n", me);

	if ( random(30) ==15) {
		ob=unew(__DIR__"obj/book-xisui");
		if (ob) {
			ob->move(this_object());
			tell_object(me, RED"��ֻ����ͷһ�ȣ���ǰ�Ѷ���һ��Ѫ�ۡ�\n"NOR);
		}
	}
	return 1;
}
