// Room: /gaibang/xinglin.c
// by pishou
// Lklv update 2001.9.26

inherit ROOM;

void create()
{
	set("short", "�ﾶ");
	set("long", @LONG
��ǰ�������۶��������������۵����������µ��ﾶ����һ�����Ǽ���
������ﾶ�ߵ����Ӹ۽��棬һ�ɽ���ˮ���������⡣�ﾶ������һ��Ƭ
�����֣������Ͽ������ʻ���
LONG
	);
	set("outdoors","����");

	set("exits", ([
		"east" : "/d/suzhou/qsgdao6",
		"north" : __DIR__"xinglin1",
	]));
	setup();
}
