// /u/jpei/guiyun/shulin4.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long",@LONG
����һƬС���֡��������̲�����ï�ܵ������š���Ҷ�ķ�϶��ż����
��һֻС�񱻾�������ʮ�־��š�
LONG
);
	set("exits",([
		"northwest" : __DIR__"shulin5",
		"east" : __DIR__"shulin6",
		"south" : __DIR__"shulin3",
	]) );
	set("no_clean_up",0);
	set("outdoors", "����ׯ");
	setup();
}

