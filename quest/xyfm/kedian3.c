// Room: /city/kedian3.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ�������������ưܡ�

LONG
	);

	set("exits", ([
		"out" : __DIR__"kedian2",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }