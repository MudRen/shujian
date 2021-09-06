// Room: /d/tianshan/shanyao.c
// By Linux

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������ɽ�İ�ɽ�����Ĵ�����ïʢ�Ĵ��֣�����һЩ��δ���ڵĻ�ѩ����
���ܵ��Ҳݺܳ������۾��ǵ�·��᫣���ʯ��ᾡ�
LONG);
	 set("exits", ([
                "east" : __FILE__,
		"south" : __FILE__,
		"west" : __FILE__,
		"north" : __FILE__,
        ]));       

	set("outdoors", "��ɽ");
	setup();
}

void init()
{
        object me = this_player();
	if ( me->query_temp("tonglao/call")){
		me->add_busy(4 + random(4));
		call_out("tonglao_help", 4, me);
	}
} 

void tonglao_help(object me)
{
        object ob;
        if (!me) return;
	if (me->query_temp("tonglao/call")){
		tell_room(environment(me), me->name()+"���Ÿ��󲼴���������ð������\n" NOR, ({ me }));
		tell_object(me,	YEL"\n�����ñ���һ������˵��������С��ֻ�뵽�������Ҹ�����Ҳ�����ˣ���\n"+
				"����������������������������\n"NOR);
		tell_object(me,	YEL"\n����һ����˫�ֲ������ˣ��ĵ�һ��������ˤ�ڵ��ϣ����С���Ӵ��һ\n"+
				"��������һ�²��ϵĺ�ʹ֮����������ղ��������Ǹ�������\n"NOR);
		ob = present("bu dai",me);
		ob->move(environment(me));
		me->delete_temp("tonglao/call");		
		return;
	}
	else return;
}

int valid_leave(object me, string dir)
{
	if (dir == "west") me->add_temp("mark/steps",-1);
	if (dir == "south") me->add_temp("mark/step",-1);
	if (dir == "east") me->add_temp("mark/steps",1); 
	if (dir == "north") me->add_temp("mark/step",1);
	if (me->query_temp("mark/step") > 8) {
		me->move(__DIR__"shanjin2");
		me->delete_temp("tonglao");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail(YEL"�㲻֪�����߻ص�ԭ����ɽ·�ϡ�\n"NOR);
	}
        return ::valid_leave(me, dir);
}
