// /d/hmy/changlang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ·�߹���ֻ��������������ʿ�������ԣ����и�ͦһ�����λεĳ�����
����ƽ�٣�����֮�˶�Ҫ������ͷ���������ٱ�������ֻҪ��һ��ͻȻ���䣬
�㲻�������촦��
LONG
	);
	set("exits", ([
		"east" : __DIR__"dadian",
		"south" : __DIR__"fleitang",
		"north" : __DIR__"baihutang",
		"west" : __DIR__"qiandian",
	]));
	set("objects", ([ 
		__DIR__"npc/chou" : 1,
	]));

	setup();
}
