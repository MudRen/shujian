// Room: huilang8.c

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
		"east" : __DIR__"boluomiyuan",
                "westup" : __DIR__"zhudubadian",
                "south" : __DIR__"huilang6",
	]));
        set("outdoors", "ѩɽ");

	setup();
}
