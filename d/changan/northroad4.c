// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/northroad4.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����������·������̫��·�����˲��࣬����һ����į�ĸо���
������һ��Ƭ��ũ���������һ�ۿ�������ͷ��ɣ���֡�
LONG
	);
	set("outdoors", "����");

	set("exits", ([
		"south": "/d/zhiye/nongtian0",
		"north": "/d/zhiye/sanglin0",
		"northup"  : __DIR__"northroad5",
		"southwest"  : __DIR__"northroad3",
	]));

	setup();
}

int valid_leave(object me,string dir)
{
	if( me->query("no_quest")
	 && ( dir == "south" || dir == "north")){
		return notify_fail("\n");
	}
	return ::valid_leave(me, dir);
}
