// Room: /dali/nanmen.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǵ����ϳ��ţ���¥���ڸ߸ߵĳ�̨�ϣ����������㣬վ������һ����
�߾��Ǵ������Ľ��У�һ��ʯ�������ϱ����죬Զ����Ⱥɽ����֪ͨ����
��,��ǽ�µ��佫�͹ٱ����ڼ�������������ˡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"dalisouth/shanlu6",
		"north" : __DIR__"nanjie3",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "����");

	setup();
}
