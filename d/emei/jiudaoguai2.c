// Room: /d/emei/jiudaoguai2.c ������ ��ʮ�ŵ���2

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "��ʮ�ŵ���" NOR);
	set("long", @LONG
���������ġ���ʮ�ŵ��ա�����·����������ǧ�۰ٻء���˵��ȥ���и�
������ķ�ɮ���ˣ���һ������·�������������������ǵ�֪�˴��о�����û
�󣬱���Ҳ���˸�������Ĳ�ľ�����ԡ����ӡ���֮���ɴ˶�����ǧ���֣���
����϶���
LONG
	);

	set("exits", ([
		"eastdown" : __DIR__"jiudaoguai1",
		"southwest" : __DIR__"jiudaoguai3",
	]));

	set("outdoors", "shaolin");
	setup();
}



