// Room: huilang3.c

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
		"north" : __DIR__"huilang5",
		"eastup" : __DIR__"dadian",
                "west" : __DIR__"jieyuantang",
                "south" : __DIR__"huilang1",
	]));
        set("outdoors", "ѩɽ");
	setup();
}
