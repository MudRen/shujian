// Room: /city/garments.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG );
	
	set("exits", ([
		"down" : __DIR__"zahuopu",
	]));

	setup();
}

//�Ǿ���
int is_mirror() { return 1; }