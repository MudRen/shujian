// Room: huilang6.c

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
		"north" : __DIR__"huilang8",
		"east" : __DIR__"yimogong",
                "westup" : __DIR__"queridian",
                "south" : __DIR__"huilang4",
	]));
        set("outdoors", "ѩɽ");
	setup();
}
