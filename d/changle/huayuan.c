// Room: /d/changle/huayuan.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW"��԰"NOR);
	set("long", @long
�����԰�ǵ��͵Ľ��Ϸ�񣬾���ϸ�¡�԰�л�����û��ʲô����Ʒ�֣�
Ҳ�����涷��������һ��ʯ���̾͵�С·������鲼��̦������ʪ��������
һ���������и�ͤ�ӡ�
long
	);

	set("exits", ([
		"north" : __DIR__"yongdao",
		"west" : __DIR__"xiaoting",
		"east" : __DIR__"bajiao",
	]));

	set("outdoors", "���ְ�");
	setup();
}
