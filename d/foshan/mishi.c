// Room: /d/fuoshan/mishi.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "����");
	set("long", @LONG
������Ƿ����ϴ�ű�������ҡ�
LONG
	);
	set("exits", ([
		"up" : __DIR__"shufang",
	]));
	set("no_fight", 1);
	set("objects", ([
		BINGQI_D("huangjingun") : 1,
		ARMOR_D("tiancanjia") : 1,
	]));

	setup();
}
