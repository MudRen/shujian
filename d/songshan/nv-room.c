// Room: nv-room.c
// Created by Numa 1999-11-21

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
�����ǹ���ɽ�ɸ�λŮ������Ϣ�ķ��䣬������ż��Ŵ󴲡�
LONG);
	set("exits", ([
		"south" : __DIR__"qindian",
	]));
	set("no_fight", 1);
	set("sleep_room", 1);
	set("indoors", "��ɽ");
	setup();
}
