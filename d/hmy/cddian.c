// /d/hmy/chengdedian.c

inherit ROOM;

void create()
{
	set("short", "�ɵµ�");
	set("long", @LONG
���аڷ���һ�Ŵ��������Ϸ������ķ��ı���ǽ�Ϲ������ֻ������õ�ʮ
�����ţ��Ա�һ��ľ��ͨ�����档
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"dadian",
		"north" : __DIR__"changlang2",
		"west" : __DIR__"zhuquetang",
	]));
	setup();
}
