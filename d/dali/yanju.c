inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"����"NOR);
	set("long", @long
���Ǽ��ª��С���ӣ���������������עĿ�����ǿ����ղ�Ϣ�İ�ҩ����
�������һ�㲻������ҩ����ֻ���չ���ҩ�˲ɻ�����ҩ��ԭ�ϣ��ӹ��ɿ���
������ҩ��ҩ��ԭ�ϡ�
long	);

	set("exits", ([
		"west" : __DIR__"beijie5",
	]));

//	set("objects", ([
//		"/d/zhiye/obj/yaoguo" : 1,
//		"/d/zhiye/npc/yaochang-zhu" : 1,
//	]));
	set("no_fight", 1);
	set("no_zhiye", 1);
	set("incity", 1);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
		me->set_temp("dali_xc/yanju",1);
}
