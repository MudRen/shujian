#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @long
�������鳡�ĺ��ã�������һ�����Ӻ�һ�Ŵ���ǽ�ϵĴ��������ţ�ǽ��
����һ���껭��
long);
	set("item_desc", ([
		"picture" : "��һ��Ѱ��ũ�ҹ���ʱ�����껭��\n",
	]));

	set("exits", ([
"out" : __DIR__"shuchang",
	]));
        create_door("out", "С��", "enter", DOOR_CLOSED);
	set("incity",1);
	setup();
}
void init()
{
	add_action("do_jie","jie");
	add_action("do_jump","jump");
}
	
int do_jie(string arg)
{
	object me;
	me=this_player();
	
	if (!arg) return 0;
	if (arg !="picture") return 0;
	if (arg=="picture"){
		write("��ҿ��껭������ǽ���и�����ǡ��������һ���ˣ����̲�ס����(jump)��ȥ��\n"
		);
	this_player()->set_temp("marks/��1", 1);
	return 1;
	}
}
int do_jump(string arg)
{
	object me;
	me=this_player();
	if (me->query_temp("marks/��1")){
  message("vision", me->name() +
"�����ǽ�ϵĶ���������ȥ��ֻ���ġ�ƹ����һ���졣\n",
                    environment(me), ({me}) );
 me->move(__DIR__"szyunhe");
            message("vision", me->name() + "ͻȻ�������ˤ��������\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/��1");
	return 1;
	}
}
