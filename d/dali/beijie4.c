// Room: �����/dali/beijie2.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ǵ�����֣����������������ս�£�һƬ̫ƽʢ����ģ����������
���ĺ�������Ǯ������������Ǵ�����������ѩ¥�ˣ������治ʱ��������
����ζ�����������Ŵ�����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"beijie3",
		"east" : __DIR__"beijie5",
		"south" : __DIR__"jiulou",
		"north" : __DIR__"qian",
	]));

	set("outdoors", "����");

	setup();
}
