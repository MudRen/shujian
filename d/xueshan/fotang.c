// Room: fotang.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "��®����");
	set("long", @LONG
һ�������С���á�Ъɽ�������������������Σ��ĽǴ���ͭ�壬ÿ��
�綯��������ࡣ����һ��Ȫˮ����Լ���ɣ�ˮƽ�羵���ɼ�ë����Ȫ����
����ӳ�����������ž�������С·һͷͨ���ɽ����һ����ͷ���Ⱥ���ľ�š�
LONG
	);

	set("exits", ([
		"west" : __DIR__"lingtalin",
		"southeast" : __DIR__"fanyinge",
	]));

	setup();
	create_door("southeast", "����ľ��", "northwest", DOOR_CLOSED);
}
