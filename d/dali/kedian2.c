
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ڿ͵�������ϣ�������һ��װ�޾����Ŀͷ�����ʱ��˯�����ʵ�
�ÿͽ�����������¥�µ��ƹ񴦸���Ǯ������˯����
LONG
	);

	set("exits", ([
		"out" : __DIR__"kedian",
		"north" : __DIR__"kedian3",
	]));

	setup();
}

