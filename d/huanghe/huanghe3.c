// by xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺӰ���");
	set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ�ĺ�ˮ�ںӴ�
�﷭���ţ������ţ�����һ�����޴�����ѡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"huanghe4",
		"west"  : __DIR__"huanghe2",
	]));
	set("objects", ([
		__DIR__"npc/bangzong" : 1,
	]));

	set("outdoors", "�ƺ�");
	setup();
}
