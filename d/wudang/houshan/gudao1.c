// /d/wudang/gudao1.c  �ŵ�

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"�ŵ�"NOR);
	set("long", @LONG
������һ���˼������Ĺŵ��ϣ�����Ұ�ݹ�����·��ʱ��ʱ�֣�������ͷ
����ʱ�����е�����һ������! �����ϵ��������ߣ��������������ϣ�һ����
�����ͷ��������һ��һ�£��ò����ˡ�
LONG                           
        );
	set("exits", ([
		"eastup" : __DIR__"gudao2",
		"westdown" :"/d/wudang/shanlu2",
	]));

	set("objects",([
		__DIR__"../npc/snake" : 1,
	]));
	set("outdoors","�䵱");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "westdown" && me->query("id") == "lao hu")
		return 0;
	return ::valid_leave(me, dir);
}
