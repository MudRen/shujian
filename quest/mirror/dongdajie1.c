// Room: /city/dongdajie1.c
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
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"zahuopu",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"shuyuan",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }