// Room: huilang2.c

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
		"north" : __DIR__"huilang4",
		"east" : __DIR__"gulou",
                "west" : __DIR__"guangchang",
	]));
        set("outdoors", "ѩɽ");
	setup();
}
