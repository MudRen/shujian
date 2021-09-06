// cool980724
// Modify By River 98/12
// COOL@SJ,9908
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�յ�");
	set("long", @LONG
�㶨�˶��񣬿�����ǰ��һ���յأ���ͺͺ��ʲô��û�����յر����
����һ������,������������������ǽ��
LONG
	);
	set("outdoors", "����");

	set("exits", ([
		"north" : __DIR__"muwu2",
	]));

	setup();
}

void init()
{
	object me,obj;
	me=this_player();
	if ( interactive(me)
	 && !present("duan yanqing",this_object())
	 && me->query_temp("quest/�����˲�/�貨΢��ƪ/kill")){
		obj=new(__DIR__"npc/dyq");
	  obj->set_name("������", ({ "duan yanqing", "duan","yanqing"}) );
	  obj->set("title",HIC"�Ĵ����"NOR);
	  obj->set("nickname",HIG"�����ӯ"NOR);
		obj->move(this_object());
	}
	add_action("do_jump", "jump");
	add_action("do_tiao", "tiao");
}

int do_jump(string arg)
{
	object me;
	me = this_player();
	if (!arg || arg !="wall") 
		return notify_fail("��Ҫ������ȥ��\n");
	if (random(me->query_skill("dodge",1)) < 60){ 
		write("����������һ���������������ã�û������ǽ��ˤ��������\n");
		write("�����˵���!\n");
		me->add("qi", -100);
		me->add("jingli", -80);
		me->receive_wound("qi", 50);
		return 1;
	}
	else {
		write("��һ�������������ɵ������˴���ǽ��\n");
		message("vision",me->name() + "һ������������ǽ��\n",environment(me), ({me}) );
		me->start_busy(1);
		me->move(__DIR__"shanlin-6");
		message("vision",me->name() + "����ǽ�������˹�����\n",environment(me), ({me}) );
		return 1;
	}
}

int valid_leave(object me,string dir)
{
	if( dir == "north" 
	&& objectp(present("duan yanqing", environment(me))))
		return notify_fail("�����쵲ס��·�����޷���ȥ!\n");   
	if ( interactive(me = this_player()) 
	 && this_player()->query_temp("quest/�����˲�/�貨΢��ƪ/kill")
	 && (dir =="north")){
		this_player()->delete_temp("quest/�����˲�/�貨΢��ƪ/kill");
		this_player()->set_temp("quest/�����˲�/�貨΢��ƪ/kill_duan",1);
		return 1;
	}
	return ::valid_leave(me,dir);
}
