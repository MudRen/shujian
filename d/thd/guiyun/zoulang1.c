// /u/jpei/guiyun/zoulang1.c

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
		"west" : __DIR__"zoulang2",
		"south" : __DIR__"zhongting",
	]) );
	set("no_clean_up",0);
	set("outdoors", "����ׯ");
	setup();
}
