// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIG"������"NOR);
	set("long", @LONG
����һ�Ҹ����ûʵ���������ǽ�Ϲ����������󵶡�������������ذ�׵�
�ȱ������ݽǻ�����һ����¯��¯��������յ�һƬͨ�졣¯��վ��һλ��̬
���������ʦ�����������պã�����Ҳ����
LONG
);
	set("exits", ([ 
		"east" : __DIR__"xijie7",
	]));

	set("objects", ([
		"/d/zhiye/npc/zhujian-shi" : 1,
		"/d/zhiye/obj/zhujianlu" : 1,
	]));
	set("no_zhiye", 1);
	set("incity", 1);
	set("no_fight", 1);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
		me->set_temp("dali_xc/yanzhi",1);
}
