// Room: /u/jpei/thd/zoulang1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����Ӵ��������ҵĻ��ȡ�����ͨ�����ң�����ͨ�����䳡��
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","�һ���");

	set("exits", ([
		"east": __DIR__"hall",
		"west": __DIR__"zoulang3",
		"north": __DIR__"zoulang2",
	]) );

	setup();
}

