// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"���ׯ"NOR);
        set("long", @LONG
һ���š��ϰ�������ӭ�����ˣ��������ܴ���������ĳ�д�඼
�Ǵ���ԭ�����ģ�����Ҳ��һЩ���ز���ƥ��
LONG
);
	set("exits", ([
		"east" : __DIR__"xijie3",
	]));

	set("objects", ([
		__DIR__"npc/dasao": 1,
		__DIR__"npc/nvdianzhu": 1,
	]));
	set("incity", 1);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
		me->set_temp("dali_xc/chouduan",1);
}
