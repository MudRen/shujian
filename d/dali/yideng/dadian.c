// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��Ժ���");
	set("long", @LONG
ֻ������Ϸ�ǰ����һյ�͵ƣ�ӳ���ŷ�����ׯ�ϣ������̻����ƣ���
��Сɳ���������̷𣬴�������һ���᷿�������ǹ���Ϣ֮�ã����Ǵ��
������ſڱ��첼���ڵ��ţ����ܿ�����ͨ���δ���
LONG
	);
	set("exits", ([
		"south" : __DIR__"shiqiao",
		"north" : __DIR__"houyuan",
		"east" : __DIR__"dfang",
		"west" : __DIR__"xfang",
	]));
	set("objects", ([
		__DIR__"npc/shami" : 1+random(2),
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") != "����" && dir == "east" && !me->query("no_quest")) 
		return notify_fail("�����ǹ���ʩ����Ϣ���᷿��\n");
	if ( me->query("gender") == "����" && dir == "west" && !me->query("no_quest")) 
		return notify_fail("�����ǹ�Ůʩ����Ϣ���᷿��\n");
	return ::valid_leave(me, dir);
}
