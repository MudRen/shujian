// Room: wofang2.c
// Lklv Modify 2001.9.21

inherit ROOM;
void create()
{
	set("short", "�Է�");
	set("long", @LONG
���߽�һ�����ң�����װ�εĺ�������������ǽ��һ�Ŵ󴲣����ϱ�����
������̻Ի͡�����һ������ͭ��¯����������Ѭ���㣬һ��Ũ���˱ǣ�
��ֻ������Ȼ�������˯��
LONG
	);
	set("objects", ([
		__DIR__"npc/wenfangwu": 1,
	]));

	set("exits", ([
		"west":__DIR__"shidetang",
	]) );

	set("incity",1);
	setup();
}
