// /d/hmy/fengleitang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˴������½̷������������ճ�����֮�أ����ڲ�û���ر�İ��裬ֻ��
���ðڷ���һ��̫ʦ�Ρ�
LONG
	);
	set("exits", ([
		"east" : __DIR__"changlang5",
		"north" : __DIR__"changlang",
	]));
/*
	set("objects", ([ 
	  __DIR__"npc/tong" : 1,
]));
*/
	setup();
}
