// Room: /dali/dalics.c
// bbb 1997/06/11
// update by cool
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǵ������Ĺ㳡���Ǵ�����������ڡ����������������У����ϸ�
�ǵƻ�ͨ����æµ��һ�������������ϲ����������һ�ߣ��㳡�������ֶ���
�Ķ��У����ٽ�������켣���С�
LONG
	);
	set("outdoors", "����");
	set("exits", ([ 
		"south" : __DIR__"qsjie1",
		"north" : __DIR__"beijie3",
		"east" : __DIR__"jiulou",
		"west" : __DIR__"fengwei",
	]));
	set("objects", ([
		__DIR__"npc/liumang" : 1,
		__DIR__"npc/guo" : 1, 
	]));
	setup();
}
