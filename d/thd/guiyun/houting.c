// /u/jpei/guiyun/houting.c

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
���ǹ���ׯ�ĺ�������ׯ���������˽�µĵط���������һ���鷿�����
������һ�ȴ����磻�����������˵��Է���
LONG
);
	/*  set("object",([
	__DIR__"obj/luchenfen.c" :     1,
	]));  */
	set("exits",([
		"east" : __DIR__"shufang",
		"west" : __DIR__"wofang",
		"north" : __DIR__"zoulang3",
	]) );
	set("no_clean_up",0);
	set("objects",([
		__DIR__"npc/yahuan" : 1,
	]));  
	setup();
}
