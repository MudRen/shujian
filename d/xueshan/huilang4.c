// Room: huilang4.c

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
		"north" : __DIR__"huilang6",
		"east" : __DIR__"luoweitang",
                "westup" : __DIR__"dadian",
                "south" : __DIR__"huilang2",

	]));
        set("outdoors", "ѩɽ");
	setup();
}
