// /u/jpei/guiyun/shulin3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",@LONG
����һƬС���֡��������̲�����ï�ܵ������š���Ҷ�ķ�϶��ż����
��һֻС�񱻾�������ʮ�־��š�
LONG
);
	set("objects",([
		__DIR__"obj/stick" : 1,
	]));  
	set("exits",([
		"west" : __DIR__"shulin1",
		"north" : __DIR__"shulin4",
		"south" : __DIR__"caodi3",
	]) );
	set("no_clean_up",0);
	set("outdoors", "����ׯ");
	setup();
}

