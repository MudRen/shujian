// �置

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
		"northeast" : __DIR__"gmcong"+(random(13)+1),
		"southeast" : __DIR__"gmcong3",
		"northwest" : __DIR__"gmcong"+(random(13)+1),
		"southwest" : __DIR__"gmcong"+(random(13)+1),
	]));

	set("outdoors", "�置");
	setup();
}
 

