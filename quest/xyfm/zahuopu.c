// Room: /city/zahuopu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	
	set("exits", ([
		"north" : __DIR__"dongdajie1",
                "up" : __DIR__"garments",
	]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }