// /u/jpei/guiyun/zoulang5.c

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
���Ǵ�����ͨ�����䳡�����ȡ������������ۣ����������˻�
����
LONG
);
	set("exits",([
		"east" : __DIR__"zoulang4",
		"south" : __DIR__"zoulang6",
	]) );
	set("no_clean_up",0);
	set("outdoors", "����ׯ");
	setup();
}
