// xilang.c ��������
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
	������һ�������ϣ������Ǵ�������һ��¥��
LONG
	);

	set("exits", ([
		"northup" : __DIR__"cangjingge",
		"east" : __DIR__"sanqingdian",
	]));
	setup();
}

