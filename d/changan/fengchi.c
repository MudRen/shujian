// Write By Yanyang@SJ 2001.9.26
// Room: /d/changan/fengchi.c

inherit ROOM;
#include <room.h>

void create()
{
        set("short", "���");
        set("long", @LONG
һ���ţ��������棬�װ׵�ˮ�����̰�Χ���㡣����ϡ����һ���޴��̴
ľˮ�أ�ˮ�ʱ��̣�ɢ����һ�����ص�ҩ�㣬ˮ���ϻ�Ư��һƬƬ���Ļ���
��������������ȥϴ(wash)���裬�����۾��úõķ���һ�¡�
LONG
        );
        set("exits", ([
                "west" : __DIR__"qingchi",
        ]));
        set("objects", ([
                __DIR__"npc/luotiwoman": 1,
        ]) );
        set("no_fight", 1);
        set("incity",1);
	setup();

}

void init()
{
	add_action("action", ({
		"dazuo",
		"du",
		"exercise",
		"lian",
		"practice",
		"respirate",
		"study",
		"tuna"
	}));
	add_action("do_wash", "wash");
}

int do_wash()
{
	object me=this_player();
	object weapon = me->query_temp("weapon");
	object *inv;
	int i;

	if (me->query_temp("ca_wash")>0) return notify_fail("���Ѿ�����ˮ�����ˣ�\n");
	if (weapon) 
		return notify_fail("��Ҫ��ô���Ű���ϴ�軹����������\n");

	inv= all_inventory(me);
	i = sizeof(inv);
	while (i--)
	if( inv[i]->query("equipped") && (! inv[i]->query_autoload() && inv[i]->query("id") != "bu dai"))
		return notify_fail("���ϴ����·���ôϴ�裿\n"); 
	message_vision("$N�߽�ԡ�أ���ȫ�����ݵ�ˮ�С�\n",me);
	me->set_temp("ca_wash",1);
	tell_object(me,"��е��ޱȵ���̩����\n");
	me->start_busy(20);
	call_out("overwash",10+random(5), me);
	return 1;
}

int action()
{
	write("�㻹����ϴ��ɡ�\n");
	return 1;
}

void overwash(object me)
{
	int jing,qi,neili;
	if(!me) return;

        qi=(int)me->query("max_qi");
        jing=(int)me->query("max_jing");
        neili=(int)me->query("max_neili");

        if( me && environment(me) == this_object()) {
		message_vision("$N�����ӵĴ�ԡ�������˳�����\n", me);
		me->delete_temp("ca_wash",1);
		//me->set("eff_qi",qi);
		//me->set("eff_jing",jing);
		me->set("neili",neili);
		me->set("qi",me->query("eff_qi")+me->query_temp("apply/qi"));
		me->set("jing",me->query("eff_jing")+me->query_temp("apply/jing"));
		me->start_busy(-1);
	}
	return;
}

int valid_leave(object me,string dir)
{
        if (dir == "west") {
		write("����ܻ�����С������Ĵ������߳�����\n");
		me->delete_temp("pay_wash");
	}
	return ::valid_leave(me,dir);
}
