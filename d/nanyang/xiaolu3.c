// Room: /d/nanyang/xiaolu3.c
// Lklv Modify 2001.10.11

inherit ROOM;
void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��Ƨ����С·��������ï�ܵĴ��֡�·����ϡ�ɼ������߹����µ�
�ۼ��������������������Ǹ���Զ�������ľ���ׯ��������ͨ����Ҽ�����ʯ
·������ƽ��û��ʲô�ˡ�
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"northeast" : __DIR__"jxzhuang",
		"west" : __DIR__"qslu",
	]));
	setup();
}
