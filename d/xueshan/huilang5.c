// Room: huilang5.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ������̫��ĳ��ȣ�ͨ������Ҫ�Ĵ��ȶ��������������ڻ�����д
����ʷ�����¼��ͷ�̹��£�ɫ��������������档
LONG
	);

	set("exits", ([
		"north" : __DIR__"huilang7",
		"eastup" : __DIR__"queridian",
                "west" : __DIR__"jishantang",
                "south" : __DIR__"huilang3",
	]));
        set("outdoors", "ѩɽ");
	setup();
}
