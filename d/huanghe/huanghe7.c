// by XiaoYao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺӰ���");
	set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ӵ���������ɫ�ĺ�ˮ�ھ�������
��ȥ��ʹ������������ˮʱ�Ŀ�����
LONG );
	set("exits", ([
		"northeast" : __DIR__"huanghe8",
		"southwest" : __DIR__"huanghe6",
		"northup" : __DIR__"daba",
		"northwest" : __DIR__"yyd/damen",
	]));

	set("outdoors", "�ƺ�");
	setup();
}
