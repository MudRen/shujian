// /u/jpei/guiyun/shulin2.c

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
		__DIR__"npc/bee" : 1,
	]));  
	set("exits",([
		"east" : __DIR__"shulin1",
		"south" : __DIR__"caodi2",
	]) );
	set("no_clean_up",0);
	set("outdoors", "����ׯ");
	setup();
}

