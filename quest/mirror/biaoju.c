// Room: /city/biaoju.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "����¥");
	set("long", @LONG
����¥�ڶ����ϽӶ��޳Ǳ��Ǵ���������ʮ���꣨1584�꣩�����򽨶��޳����ӹسǣ�
���в��⣬����¥�����
LONG
	);
	set("exits", ([
		"south" : __DIR__"zhengting",
		"north" : __DIR__"xidajie2",
	]));

	setup();
}
//�Ǿ���
int is_mirror() { return 1; }