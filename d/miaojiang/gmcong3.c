// �置 gmcong

#include <room.h>
inherit ROOM;


void create()
{
	set("short", "��ľ��");
	set("long", @LONG
������һƬһ�˶�ߵĹ�ľ�ԣ������Ѿ������㼣��һ��紵������ľ��
����ɳɳ��������
LONG
	);

	set("exits", ([
		"south" : __DIR__"gmcong"+(random(13)+1),
		"north" : __DIR__"gmcong4",
		"east" : __DIR__"gmcong"+(random(13)+1),
		"west" : __DIR__"gmcong"+(random(13)+1),
	]));

	set("outdoors", "�置");
	setup();
}


