// /u/jpei/guiyun/zoulang3.c

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����������������������ȡ������������ۣ����������˻�����
LONG
);
	/*  set("object",([
	__DIR__"obj/luchenfen.c" :     1,
	]));  */
	set("exits",([
		"east" : __DIR__"zoulang2",
		"south" : __DIR__"houting",
        "north" : __DIR__"wofang1",
	]) );
	set("no_clean_up",0);
	set("outdoors", "����ׯ");
	setup();
}
