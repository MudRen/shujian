// Room: /dali/dongjie4.c
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "̫�Ͷ���");
	set("long", @LONG
���Ǵ����̫�Ͷ��֣�����������ڴ�Ĳ�ɫʯ���̳ɣ��������̣�ɷ��
�ÿ������ھ������ᷱ�ӣ�ϰ�׸��죬��ʳ�����޲�������ԭ���������ߣ���
���������ˣ����治Զ���ܿ������������ˡ�
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"east" : __DIR__"dongmen",
		"north" : __DIR__"dongjie3",
		"south" : __DIR__"dongjie5",
	]));
	setup();
}
