// yuchuan3.c ؤ���洬

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
		"south" : __FILE__,
		"east" : __DIR__"yuchuan4",
		"west" : __DIR__"yuchuan2",
		"north" : __FILE__,
	]));
	setup();
}

