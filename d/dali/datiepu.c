// Room: /dali/datiepu.c
// bbb 1997/06/11
// Modify By River 98/12/	  
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR"������"NOR);
	set("long", @LONG
������һ��������ӣ��ӻ�¯��ð���Ļ�⽫ǽ��ӳ��ͨ�죬���ӵĽ���
������˸�ʽ���������Ʒ��δ���Ʒ�����ǳ�ͷ�����������ӵȣ���������
�������õ��������졣
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"nanjie1",
	]));

	set("objects", ([
		__DIR__"npc/tiejiang": 1,
		//"/d/zhiye/obj/datielu":1,
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
		me->set_temp("dali_xc/datiepu",1);
}
