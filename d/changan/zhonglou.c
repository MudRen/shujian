// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/zhonglou.c

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
�����ǳ����Ƕ��������ϡ���������ֽ��ᴦ����¥����¥����Ϊľ�ʽ�
������������ɫ�����߸��ǣ����ܸ��ݣ�¥�������ʣ�����������¥�ϴ�Բ
�𶥣��������н𲭣�������������ö�Ŀ�����ڵش����ģ���������������
һƬ���ٵľ���
LONG
	);
	set("outdoors", "����");

	set("exits", ([
		"east"  : __DIR__"eastjie1",
		"south" : __DIR__"southjie1",
		"west"  : __DIR__"westjie1",
		"north" : __DIR__"northjie1",
		"northwest": __DIR__"gulou",
	]));

	set("objects", ([
		NPC_D("huolang") : 1,
	]));

	set("incity",1);
	setup();
}
