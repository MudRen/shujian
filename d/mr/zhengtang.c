// /d/mr/migong4.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","����");
	set("long",@LONG
�����ǹ���Ľ�ݵĵ����Թ�����Ȼ��ͨ��һ����Ҫ�ĵط������ܵ�ǽ����
����¶ˮ�������κ������ǣ���һ�߽�������ʧ�˷���
LONG);

	set("exits",([
		"south" : __DIR__"didao2",
	]));

	setup();
}
