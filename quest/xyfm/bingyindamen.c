// Room: /city/bingyindamen.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ķϴ���");
	set("long", @LONG
	���ﲻ֪ͨ������ưܲ�����������ǰ����ԥ�Ƿ�Ҫ��ȥ��

LONG
	);
	set("exits", ([
		"south" : __DIR__"bingyin",
		"north" : __DIR__"xidajie1",
	]));

	setup();
}

//�Ǿ���
int is_mirror() { return 1; }