// by xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺ�");
	set("long", @LONG
�ƺ����ɹŸ�ԭ�ϱ������ʣ���̫��ɽ������������תͷ���£��γɽ�
�µķֽ硣���������Ǹ���ɿڡ�
LONG );
	set("exits", ([
		"northwest" : __DIR__"huangtu",
		"southeast" : __DIR__"hetao",
	]));

	set("outdoors", "�ƺ�");
	setup();
}
