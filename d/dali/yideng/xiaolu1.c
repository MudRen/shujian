// By River 2002.6.3

inherit ROOM;
#include <ansi.h>
#include <wanted.h>

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
��·����ɽ���������·������խ���м�һ����С��������һ����ǿ��
ȥ��˳ɽ·��ȥ���˴��·�����ɽ���ڣ��˴��Խ���û�������ˡ�
LONG
	);
	set("outdoors", "��Դ��");
	set("exits", ([
		"northeast" : __DIR__"fanpu",
		"southwest" : __DIR__"xiaolu2",
	]));
	set("objects", ([
		NPC_D("caiyaoren") : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "southwest" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
