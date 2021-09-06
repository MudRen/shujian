// chufang.c (kunlun)
// cck modified on 17/6/97

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string arg);
int do_sit(string arg);
void delete_served(object me);

void create()
{
	set("short", "����");
	set("long", @LONG
�����������ɵ����ò͵ĵط��������쳤�վã�ǽ�ڶ�����Ѭ���ˡ�����
���ż������Σ���λ���ص������ڴ�Դ�ȣ��оƲ�ȭ��
LONG
	);

	set("exits", ([
		"west" : __DIR__"shilu2",
	]));

	set("objects",([
		__DIR__"npc/puren" : 1,
		FOOD_D("rice") : 2,
		FOOD_D("cha") : 1,
		FOOD_D("kaoya") : 1,
	]));

	set("no_fight", 1);

	setup();
}

void init()
{
	add_action("do_tap", "tap");
	add_action("do_tap", "knock");
	add_action("do_sit", "sit");
}

int do_tap(string arg)
{
	object me;
	object cui;

	if (!arg || (arg != "desk" && arg != "table")){
		return notify_fail("��Ҫ��ʲô��\n");
	}

	me = this_player();
	if( !objectp(cui = present("pu ren", environment(me))) )
		return notify_fail("�����������ӣ�ȴ����û�����㡣��ͻȻ�о��Լ������ġ�\n");

	if( !me->query_temp("marks/sit") )
		return notify_fail("�����������ӣ�ȴû�뵽��ΧһȺ���Ȼ�ؿ����㡣\n");

        if( me->query_temp("marks/served") ){
		  message_vision("���˲��ͷ��ض�$N˵�����ո����Ϲ�������ž�Ҫ���㲻�ۿ����۰���\n", me);
		  return notify_fail("");
	}

 	message_vision("$N��������ǰ��������������棬������æ�����к���\n", me);

	cui->serve_tea(me) ;

	me->set_temp("marks/served", 1);
        call_out("delete_served", 10, me);
	return 1;
}

void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}

int do_sit(string arg)
{
	if ( !arg || (arg != "chair") )
		return notify_fail("��Ҫ��ʲô���棿\n");

	if (this_player()->query_temp("marks/sit"))
		return notify_fail("���Ѿ����˸���λ�ˡ�\n");

	this_player()->set_temp("marks/sit", 1);
	return notify_fail("�����˸���λ���£������ϲ衣\n");
}

int valid_leave(object me, string dir)
{
        if ( dir == "west" 
	 && (present("tea", me) || present("kaoya", me) || present("rice", me))
	 && objectp(present("pu ren", environment(me))))
	 switch (random(2)){
 	  case 0:
             tell_object(me,"����������ס���㣺�����ȰѶ������������߰ɡ�");
	     return notify_fail("\n");
	     break;
	  case 1:
	     tell_object(me,"������ס����������ŷԸ�����ʳ���ô����跿��");
	     return notify_fail("\n");
	     break;
	 }
	 me->delete_temp("marks/sit");
	 me->delete_temp("tea_cup");
	 return ::valid_leave(me, dir);
}
