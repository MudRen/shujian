
inherit ROOM;
#include <ansi.h>
int do_jump(string arg);

void create()
{
	set("short", "ѩ��");
	set("long", @LONG
������Ⱥɽ�����е�һ��ɽ�ȣ��˼��������������Ͽ�������ɽ��������ƣ�
�����ű�ѩ����Χããѩԭ��������Ұ�޵��㼣����������
LONG
	);
	set("exits", ([
		"eastdown" : __DIR__"shanlu2",
	]));
	set("objects", ([
		__DIR__"npc/laozu" : 1,
	]));
	set("outdoors", "ѩɽ");
	setup();
}

void init()
{
	object me = this_player();
	if ( me->query("xs_job") > 0) {
		me->add("job_time/ѩɽ", me->query("xs_job"));
		me->delete("xs_job");
	}
	add_action("do_jump", ({"jump", "tiao"}));
}
int do_jump(string arg)
{
	object room,me = this_player();
    if( arg == "down")
    {
		if(me->query_skill("dodge")<150) 
		{
			message_vision(HIC"\n$N����һ��������������ѩ�ȣ�ȴͻȻ���ַ��ɽ�ߣ�ȴ���˻�����\n"NOR,me);
			return 1;
		}
		if (!(room = find_object(__DIR__"xuegu2")))
			room = load_object(__DIR__"xuegu2");
		if(!room)
		{ 
			tell_object(me,HIR"\n��������ô�������ֶ�����ԭ��!\n");
			log_file("quest/LCHJ", sprintf("%s(%s)ȱ��xuegu2.c�ļ���\n", me->name(1),me->query("id")) );	
		}
		else
		{
			message_vision(HIC"\n$N����һ������ӿ��Ծ�䣬û����ѩ���漴���ϣ�Ծ��ȱߵ���ʯ��\n"NOR, me);
			me->move(room);
			me->start_busy(1);
                        tell_room(environment(me),HIC"\nֻ��һ����Ӱ������£�ԭ����"+me->name()+"��ѩ�������¡�\n"NOR, ({me}));                       
		}
		return 1;
	}
	return 0;
}
