// Room: xiuxishi2.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIM"Ů��Ϣ��"NOR);
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵����ǽ����һ¯̴�㣬��
��������ֻ���м����һ����ʰ����������Ĵ󴲣����ϻ���һЩë̺��
���ž�������˯����Ψһ�ر�֮�����ڴ��߻���һ��ױС�����Ǹ�Ů����˯
�Ѻ���ױ����õġ�
LONG
        );
        set("tan_count", 2);

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits", ([
                "north" : __DIR__"donglang1",
        ]));
 
        setup();
}

void reset()
{
	::reset();
	set("tan_count", 2);
}

void init()
{
	
	object me;
  me = this_player();
if(me->query_temp("quest/yttlg/story2"))
	{
		tell_object(me,"��������ʹ��ŭ�����Է�й���ڴ�������һ����ʱ����������������ȥ�򶼴��һ�ٳ�������\n");
		tell_object(me,"���´�ʦ�֡���ʦ�ָ�Ԥ�����ҷ�����Ϣ����������ʱ��ֻ��������һ�˱�����˫�֣���ͣ����������ȥ��\n");
		me->move("d/wudang/dating");
		return;
	}
	add_action("do_zhao", "find");
	add_action("do_zhao", "zhao");
}

int do_zhao(string arg)
{
	object tan;
	object me;
	me=this_player();

	if ( !arg || arg != "mao tan" )
		return notify_fail("��Ҫ��ʲô\n");

	if (query("tan_count") > 0){
		message_vision("$N�ڴ��Ϸ�����ȥ�ҳ�һ��ë̺��\n", me);
		add("tan_count", -1);
		tan= new(__DIR__"obj/maotan");
		tan->move(me);
	}
	else  message_vision("$N�ڴ��Ϸ�����ȥʲôҲû���š�\n", me);
	return 1;
}
