// Room: /d/emei/fushouanxxs.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
���Ǹ����ֽӴ�����Ů���ǵ���Ϣ�ң�����Ů���ӻ�ɽ֮ǰͨ���ڴ˽���
һ�ޣ��ñ���������ɽ�����ڰ���һ�ų�������ǽ���м���ľ����
LONG
	);
	set("exits", ([
		"southdown" : __DIR__"fushouanzt",
	]));
	set("sleep_room", 1);
	set("no_fight",1);
	create_door("southdown", "С��", "northup", DOOR_CLOSED);
	setup();
}
