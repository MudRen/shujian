// by xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺӰ���");
	set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ�ĺ�ˮ�ںӴ�
�﷭���ţ������ţ�����һ�����޴�����ѡ��ƺ�����������ܵ�����̩ɽ��
�赲��ת���򱱡�
LONG );
	set("exits", ([
		"west"      : __DIR__"huanghe3",
		"northeast" : __DIR__"huanghe5",
	]));

	set("outdoors", "�ƺ�");
	setup();
}
