// Room: /dali/xiulou.c
// bbb 1997/06/11
// Modify By River 98/12/

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"��¥"NOR);
	set("long", @LONG
�����¥�ѿ��˼�ʮ���ˣ�������ϰ�������������ԭѧ������֯������
������ҵ꣬�ö���Ǯ�˶������������װ�������������������ƥ���ͱ�
֯�Լ��Ĳ�ƥ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"xijie2",
	]));

	set("objects", ([
		__DIR__"npc/women": 1,
		//"/d/zhiye/obj/zhibuji":1,
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
		me->set_temp("dali_xc/xiulou",1);
}
