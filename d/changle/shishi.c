// Room: /d/changle/yongdao.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"ʯ��"NOR);
	set("long", @long
�谵��ʯ��û�д��������ǳ��ְ�˽������ü����ҡ���Χ�ڷ��ż�����
�ߣ�ǽ����Щ�¾ɲ�һ��Ѫ�ۣ����˲����������������ǳ�ʪ��ͷ����ʱ����
ˮ�顣
long
	);

	set("exits", ([
		"west" : __DIR__"yongdao",
	]));

	set("objects", ([
		__DIR__"npc/zhan": 1,
	]));

	setup();
}
