// Room: /city/dongmen.c
// YZC 1995/12/04 
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "����");
	set("long", @LONG
	���Ƕ����ţ��������Ϸ����š����š�����������֣���ǽ�����ż���
�ٸ���ʾ(gaoshi)���ٱ��Ǿ����ע���Ź������ˣ������С��Ϊ�һ����ֱ
����ʯ���������������졣�����ǽ��⣬��Լ�ɼ�һƬһ���޼ʵ����֣���
��Ī�⡣�����ǳ��������һƬïʢ�������֡�
LONG
	);
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
                "south" : __DIR__"work",
		"north" : __DIR__"ml1",
		"west" : __DIR__"dongdajie2",
	]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }
