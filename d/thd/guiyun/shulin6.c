// /u/jpei/guiyun/shulin6.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long",@LONG
����һƬС���֡��������̲�����ï�ܵ������š���Ҷ�ķ�϶��ż����
��һֻС�񱻾�������ʮ�־��š�
LONG
);
	set("objects",([
		__DIR__"obj/shizi" : 1,
	]));  
	set("exits",([
		"west" : __DIR__"shulin4",
	]) );
	set("no_clean_up",0);
	set("outdoors", "����ׯ");
	setup();
}

