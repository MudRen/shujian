// Room: /u/jpei/thd/chufang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����һ����ĳ�������ҩʦ��֪ʹ����ʲô����ץ�˼���������������æ
µ�š����г������˺͵��ϵ�ζ����������ʦ����æµ�š�ż������Щ�Բ�
�����ʳ������ʱʣ�µ������������
LONG
	);
	set("no_clean_up", 0);

	set("objects",([
		__DIR__"obj/meat" : 1,
		__DIR__"obj/rice" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"neishi2.c",
		"south" : __DIR__"fanting.c",
	]));

	setup();
}


