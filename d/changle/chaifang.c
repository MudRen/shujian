// Room: /d/changle/chaifang.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", YEL"��"NOR);
	set("long", @long
һ��򵥵Ĳ񷿣���ͨ�İ��ڿ���������ɵ��ӻ���õ�ľ�����ҵض�
��ǽ�ǣ��Ա��ǿ��񵶺����㡣�ź��и�ˮ�ף�ȴ�Ѿ����ˡ�ʱ��Ҳ�а���
��������
long
	);

	set("exits", ([
		"north" : __DIR__"zoulang3",
	]));

	setup();
}
