// Room: /d/emei/jiudaoguai4.c ������ ��ʮ�ŵ���4

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
		"eastdown" : __DIR__"jiudaoguai3",
		"southwest" : __DIR__"jiulaodong",
	]));

	set("outdoors", "shaolin");
	setup();
}
