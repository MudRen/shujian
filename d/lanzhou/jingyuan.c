// By River@SJ

#include <room.h>
#include <wanted.h>

inherit ROOM;

void create()
{
	set("short", "��Զ");
	set("long", @LONG
��Զ�Ǹ�����С�ĳ��򣬻�ɳ�������ʮ��ĵط���һ���ŵ��������
������ס�ˡ������������һ��ϴ�����ޣ��ۼ��˲��ٴӱ�����������
Щ�����˵�ǵ����Ƴ��������ͻ�ʺ��������ͱ�ʱ���֡���Ҳ�Ǿ�Զ����
�������������������ߵ�ɽ��
LONG );
	set("exits", ([
		"northeast"  : __DIR__"kongdong",
		"southwest" : "/d/group/entry/lzroad1",
		"eastup"    : __DIR__"lpshan",
//		"south"     : __DIR__"shamo",
	]));

	set("outdoors", "����");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
