// zhulin.c 
// С����

inherit ROOM;
#include <ansi.h>
#include "zhulin.h"
void create()
{
	set("short", GRN "С����" NOR);
	set("long",@long
����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��ľ��
����΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ��ѵľ�����
�ڡ�
long);
	set("outdoors", "����ɽ");
	set("exits",([
		"east" : __DIR__"zhulin",
		"west" : __DIR__"zhulin",
		"south" : __DIR__"zhulin",
		"north" : __DIR__"zhulin",
]));
	set("no_sleep_room", 1);
	setup();
}
