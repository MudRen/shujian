// /u/jpei/guiyun/zoulang4.c

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
		"west" : __DIR__"zoulang5",
		"north" : __DIR__"zhongting",
	]) );
	set("no_clean_up",0);
	set("outdoors", "����ׯ");
	setup();
}
