// Room: /d/shaolin/shulin1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬ�������п��ٵ�һ�յء�������ϵ�һ��������ס��һ·����
������, �Եø���ƽ���������ǡ������й١������Ĵ�լԺ, �������������
�������
LONG
	);

	set("exits", ([
		"north" : __DIR__"sjzhuang",
		"southeast" : __DIR__"yidao2",
	]));

	set("objects",([
		__DIR__"npc/boshan" : 1,
	        __DIR__"npc/zhongshan" : 1,
	        __DIR__"npc/shushan" : 1,
	        __DIR__"npc/jishan" : 1,
	        __DIR__"npc/xiaoshan" : 1,
	]));

 	set("outdoors", "̩ɽ");
	setup();
}
