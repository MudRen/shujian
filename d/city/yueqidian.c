// Room: /d/city/yueqidian.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�ҹ����ɫ�������ꡣ�����ǽ�Ϲ����˸�����ֵ����������˳�
������ɪ�����⣬��������ǽв������ֵġ����ϰ�վ�ڹ�̨���棬������һ
֧���ڱȻ��š����������ݳǵ�����ͤ��������Ʒ��ͤ��
LONG
	);

	set("exits", ([
		"east" : __DIR__"yuelaoting",
		"south" : __DIR__"pinqiting",
		"north" : __DIR__"dongdajie3",
	]));

	set("objects", ([
		__DIR__"npc/xiao" : 1,
	]));
	set("incity",1);
	setup();
}
