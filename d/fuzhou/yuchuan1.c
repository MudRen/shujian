// yuchuan1.c ؤ���洬

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�洬");
	set("long", @LONG
�洬������һ�룬���Ҷ�������һģһ���ģ�������ͷ���ۻ�����Ȼ
һ������ӿ������һ�����ȣ����������������㼸�������˺�ȥ��
LONG
	);
	set("outdoors","����");

	set("exits", ([
		"north" : __FILE__,
		"west" : __FILE__,
		"south" : __FILE__,
		"out" : __DIR__"yugang",
		"east" : __DIR__"yuchuan2",
	]));

	setup();
}
