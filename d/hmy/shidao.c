// /d/hmy/shidao.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
һ·�����У��м����һ����Լ��ߵ�ʯ��������ʯ����ǽ��һ·�϶���
���½�ͽģ�����������߶�����������·�˶����ܼ��ӡ�
LONG
	);
	set("outdoors", "��ľ��");
	set("exits", ([ 
		"southeast" : __DIR__"pingding/road5",
		"north" : __DIR__"shidao2",
	]));

	setup();
}
