// Room: /city/nanmen.c
// YZC 1995/12/04 
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "����");
	set("long", @LONG
	�����ϳ��ţ���ǽ�������˹���ƣ������˻������̸��и�ҵ�Ĺ�棬
�ٸ��ĸ�ʾ(gaoshi)��˲�̫��Ŀ���ٱ��Ǳ������Ļ���Ц�����������ƺ�����
��������ִ�ڡ�һ����ֱ����ʯ�������ϱ��������졣
LONG
	);
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west" : __DIR__"work3",
		"north" : __DIR__"nandajie2",
	]));

	setup();
}

//�Ǿ���
int is_mirror() { return 1; }
