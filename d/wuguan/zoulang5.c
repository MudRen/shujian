//zoulang5.c
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ȣ��ȶ�����Ž��������ķ羰��ÿ��������ɫ�����Ӽ����
Ҳ�������ߵľ��룬���ɫ�������ߣ��ۻ�ɫ�ĵ�ש�����������棬Ѿ�ߡ�ū
����������ȥ����æ���Լ������飬������һ�㵡���������߾�����ݵĴ�����
���������ȵ����죬������һ�䲻С��ƫ����
LONG
	);

	set("exits", ([
		"westup" : __DIR__"dating",
		"east" : __DIR__"zoulang6",
		"north" : __DIR__"pianting1",
	]));

	setup();
}