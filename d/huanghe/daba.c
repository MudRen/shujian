//Yanqi 08/10/2k

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIY"�ƺӴ��"NOR);
        set("long", @LONG
������ǻƺӴ���ˣ���ӿ�Ļƺ�ˮ����������ȥ��ˮ�ﻹ��ʱ������
�����γ�������һЩ���ľ�塢����......���������￴�˿����ܶ�������
��æ�żӹ̵̰ӡ�
LONG );
        set("exits", ([
                "southdown" : __DIR__"huanghe7",
        ]));

        set("no_get_from", 1);
	set("no_fight",1);
	set("no_sleep_room",1);
	
        set("outdoors", "�ƺ�");
        setup();
}

void init()
{
	add_action("do_qi","qi");
}

int do_qi(string arg)
{
	object me,shi;
	
	me=this_player();
	
	if (arg!="shi") return notify_fail("��Ҫ��ʲô��\n");
	
	shi=present("shi kuai",me);
	
	if (!shi) return notify_fail("��Ҫ��ʲô����\n");
	
	if (me->query_temp("newbiejob1/start"))
	{
          if ((me->query("qi")<10) || (me->query("jingli")<20)) 
		{
			me->unconcious();
			return 1;
		}
		me->add_temp("newbiejob1/over",1);
		message_vision(HIY"$N��һ���ʯ�����˵̰ӵ�һ�ţ�Ȼ���û�������á�\n"NOR,me);
		tell_object(me,HIM"��ж�����ϵľ�ʯ���о������˲��٣�\n"NOR);

		if( (int)me->query_skill("cuff", 1) < 51 ) {
			tell_object(me, HIY"��һ·���ѣ�������Լ��ĶԻ���ȭ����Щ����\n"NOR);
			me->improve_skill("cuff", me->query_int()/2 );
		}
		if( (int)me->query_skill("hand", 1) < 51 ) {
			tell_object(me, HIY"��һ·���ѣ�������Լ��ĶԻ����ַ���Щ����\n"NOR);
			me->improve_skill("hand", me->query_int()/2 );
		}

		me->add("qi",-5);
		me->add("jingli",-10);
		destruct(shi);
		return 1;
	}
	else 
	{
		tell_object(me,HIR"ͻȻһ�����Σ��㲻�ɻ��˹�ȥ��\n"NOR);
		destruct(shi);
		me->delete_temp("newbiejob1");
		me->unconcious();
		return 1;
	}
}
