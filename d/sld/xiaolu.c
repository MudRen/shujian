#include <wanted.h>
inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
�����������ϵ�һ��С·���������������򶫷��ĺ�����·�߳���Щ���ݣ�
��ֻ�����ڻ����з�����ȥ��һ�󺣷紵����ʹ�㾫�����ˬ�ʡ�
LONG
	);

	set("exits", ([
		"southwest" : "/d/tanggu/gangkou",
		"northeast" : __DIR__"haitan",
	]));
	set("outdoors", "����");

	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northeast" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
