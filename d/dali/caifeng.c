// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC"�÷��"NOR);
	set("long", @LONG
�����Ǵ�����ڵ�һ��С�÷�꣬�������ղ���ô�����������ڽ���һ�ң�
���⵹�����ԡ������ıڹ��ſ��������õ��·�������һЩ����Ʒ���ϰ���ͷ
�󺹵�æ�Ųü����ϡ�
LONG
      );
	set("exits", ([
		"east" : __DIR__"xijie1",
	]));

	set("objects", ([
		"/d/zhiye/npc/caifeng" : 1,
		"/d/zhiye/obj/caifengzhuo":1,
	]));
	set("no_zhiye", 1);
	set("no_fight", 1);
	set("incity", 1);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
		me->set_temp("dali_xc/caifeng",1);
}
