// Room: /d/changle/dating.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"����"NOR);
	set("long", @long
������һ����ɱ����֮�������ü�Ϊ�����������ʮ��֮�ڡ�ֻ������
���ϵ������λεľ������п���һ�Ż�Ƥ���Ρ���ʱ�а��ھ����������
��Ϣ�����ص�ͷ�߹���
long
	);

	set("exits", ([
                "north" : __DIR__"zoulang4",
                "out" : __DIR__"damen",
	]));

	set("objects", ([
		__DIR__"npc/chen": 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "chen chongzhi" &&  dir != "north" ) return 0;
	return ::valid_leave(me, dir);
}
