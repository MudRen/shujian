// Room: /city/dongdajie2.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ǳ�");
	set("long", @LONG
	ɽ���صĳǳأ��ܳ�Լ4�����һ��С�ǣ������ǳ��볤����������
��Ϊ�ء��Ǹ�14�ף���7�ס�ȫ����������Ҫ���ţ����ж��ֹŴ��ķ�����������
һ��������ϵ�Ƚ������ĳǹء�
LONG
	);
        set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"dongmen",
		"south" : __DIR__"datiepu",
		"west" : __DIR__"dongdajie1",
		"north" : __DIR__"yaopu",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }