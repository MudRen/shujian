// Room: /d/emei/jiudaoguai1.c ������ ��ʮ�ŵ���1

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
		"northeast" : __DIR__"qianfoan",
		"westup" : __DIR__"jiudaoguai2",
	]));

	set("outdoors", "shaolin");
	setup();
}



