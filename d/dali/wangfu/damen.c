// Room: /dali/damen.c
// bbb 1997/06/11
// update by cool 98.2.20
// Modify By River 98/12
inherit ROOM;
#include <wanted.h>
void create()
{
	set("short", "������������");
	set("long", @LONG
����һ����̻Ի͵ĸ�ۡ������ǰ������죬�ֱ�����ǡ����ϡ�,����
�������֣�������д���ǡ�����������,վ�˲����ױ���ʿ���ſ���վ�����ˣ�
��������Ϣ������ֻ���������㵽��������ɵ�Ҳ����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "south" : __DIR__"dating",
	    "west" : "/d/dali/dongjie5",
	]));

	set("objects", ([
	     "/d/dali/npc/bing" : 2,
	]));
	setup();
	"/clone/board/dali_b.c"->foo();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
