// By River@SJ

#include <room.h>
#include <wanted.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"���"NOR);
	set("long", @LONG
���λ�ھ�Զ�������ٶ�ʮ�������ʮ��������ݣ���Ϊ��ǣ���ʵֻ
�Ǹ�С����Ϊ�ش���ȥ���ĵ�Ҫ�壬����������ĺʹ��ε����ö����뾭��
��������������������֡�
LONG );
	set("exits", ([
		"northeast" : __DIR__"shamo",
		"northwest"  : "/d/group/entry/lzsroad3",
		"south" : "/d/chengdu/road1",
	]));

	set("outdoors", "�ɶ�");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northeast" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
