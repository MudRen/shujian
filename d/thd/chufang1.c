// /u/jpei/thd/chufang1.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ��һ��������������õĳ�������Ӧ������ÿ�յķ�ʳ�����г����
��˺͵��ϵ�ζ����������ʦ����æµ�š�ż������Щ�Բ������ʳ������ʱ
ʣ�µ������������
LONG
	);

	set("exits", ([
		"south" : __DIR__"fanting1",
	]));
	
	set("objects",([
		__DIR__"obj/meat" : 2,
		__DIR__"obj/baozi" : 1,
		__DIR__"obj/rice" : 1,
	]));
	
	setup();
}
