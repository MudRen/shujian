// Room: /city/duchang.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
	��������������ͨ��ͬ�ķ��䡣
LONG
	);
	set("exits", ([
		"down" : __DIR__"duchang",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }