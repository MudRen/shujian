// Room: /u/jpei/thd/zoulang2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����Ӵ��������ҵĻ��ȡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","�һ���");

	set("exits", ([
		"north": __DIR__"neishi1.c",
		"south": __DIR__"zoulang1.c",
	]) );

	setup();
}

