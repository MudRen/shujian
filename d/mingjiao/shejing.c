// shejing.c  ɳĮ����
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIG"ɳĮ����"NOR);
	set("long", @LONG
����һƬ��Χ������ݵ�ƽ�ء�������һ����ʯͷ��������ʯ����������
һ��Ϊ�˺�ˮ�õ�ʯ�룬������ר�Ź���ס��������Ϣ֮�ء�
LONG);
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"dashaqiu",
		"west" : __DIR__"bank",
		"north" : __DIR__"shanjiao",
//		"south" : "/d/chengdu/road6",
        ]));
	set("objects",([
		__DIR__"npc/shangren" : 2,
        ]));
        set("outdoors", "���̹�����");
	setup();
}

void init()
{
        object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("mj/shejing"))
           me->set_temp("mj/shejing",1);
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;
	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if (current_water<max_water) {
		me->set("water", current_water+20);
		message("vision", me->name()+"ſ��ʯ��������ʯ��Ҩ��һ��ˮ�ȡ�\n", environment(me), ({me}) );
		write("�����һ��ʯ���е�Ȫˮ����ʱһ���ޱ������ĸо�ӿ����ͷ��\n");
	}
	else write("��Ȼ�㻹��ȣ���ȷʵ�Ȳ����ˣ�\n");
	return 1;
}
