// By River@SJ

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��񹵵��Ʋ���������������Ҫ���Ƚ�ƽ̹���ٵ�����ȫ�����֣�ʱ����
�Է򿳲�����������д�����
LONG );
	set("exits", ([
		"southeast" : __DIR__"gulang",
		"north"     : __DIR__"wuqiao",
	]));
	set("objects", ([
		__DIR__"npc/qiaofu" : 1,
	]));

	set("outdoors", "����");
	setup();
}
