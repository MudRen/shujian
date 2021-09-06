// Room: ������/dali/beimen.c
// bbb 1997/06/11
// Modify By River 98/12/
// Fix a bug by caiji@SJ 8/26/2000

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǵ������ţ�����ʹ��μ��������Ҫ�������ţ�������ɿ���һ��
����ֱ��ʯ����������ͨ����ԭ��������ǣ���������ǣ��Ǵ������
���ǡ�����گ�ڳ������������ϡ�����͹��������ϡ������˹��������ϡ���
�������������������Ķ��ϵġ�������������Դ˳�Ϊ�����������ߵ��佫
��ʿ��������ؼ���Ź��������ˣ�������ԭ���Ľ��������ڴ�������
LONG
	);

	set("exits", ([
		"south" : __DIR__"beijie3",
		"north" : __DIR__"dadao4",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "����");
	setup();
}

void init()
{
	object me = this_player();
	if( me->query("qinwang") && me->query("tls"))
		me->delete("qinwang");
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("xuncheng") && dir == "north")
		return notify_fail("�㻹��Ѳ���أ���ϸ����������ɡ�\n");
	if(objectp(present("wujiang", environment(me)))&& me->query("qinwang")) {
		message_vision(HIY"�佫���������ض�$N˵������"+(string)me->query("qinwang")+"���ߡ���\n"NOR, me); 
	}
	if(objectp(present("bing", environment(me)))&& me->query("qinwang")) {
		message_vision(HIY"�ٱ����������ض�$N˵������"+(string)me->query("qinwang")+"���ߡ���\n"NOR, me); 
	}//ԭ����"��"��Ϊ"$N" by caiji@SJ 8/26/2000
	return ::valid_leave(me, dir);
}
