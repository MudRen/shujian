#include <ansi.h>
#include <room.h>
#include <wanted.h>

inherit ROOM;
void create()
{
	set("short",GRN"����"NOR);
	set("long",@long
�׻�˵ : ��������, �����պ����������Ǵ��������̫���� �����̲���
Ư��һҶҶ��С��, һ�����ö���С�������ź��ϵ���粻ʱƯ����Ķ��С�
long);
	set("outdoors","Ľ��");
	set("exits", ([
		"west" : __DIR__"hubian1",
		"southeast" : __DIR__"shiqiao",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "southeast" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
